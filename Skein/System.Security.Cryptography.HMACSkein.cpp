#pragma once
#include "SkeinCore.h"
#include <msclr\lock.h>
using namespace System::IO;
using namespace Skein;
using namespace System::Threading;
using namespace msclr;
#define SKEIN_HASH_ALGORITHM
namespace System {
	namespace Security {
		namespace Cryptography {

			/// <summary>
			/// The base, abstract class from which all SSC.SkeinX HashAlgorithms are derived.
			/// </summary>
			public ref class HMACSkein : Security::Cryptography::HMAC
			{
			internal:
				MemoryStream^ _buffer = nullptr;
				UInt64 _bufferRunningCount = 0;
				Object^ _bufferLock = gcnew Object();
				array<Byte>^ _key = nullptr;
				array<Byte>^ _hashResult = nullptr;
				array<UInt64>^ _localState = nullptr;
				int _algState = 0;
			protected:
				/// <summary>
				/// The width, in QWORDS, of the internal state array (4, 8, or 16 only);
				/// </summary>
				property Byte QWORDWIDTH { virtual Byte get() abstract; };
				/// <summary>
				/// The default hash length in bits of the HashAlgorithm. 
				/// </summary>
				property UInt16 DEFAULTHASHBITLENGTH {UInt16 get() { return (UInt16)(QWORDWIDTH * 64); } };
			public:
				/// <summary>
				/// The resulting hash from a ComputeHash or HashFinal call as a byte array.
				/// </summary>
				property array<Byte>^ Hash {array<Byte>^ get() override { return _hashResult; } };
				/// <summary>
				/// The Key used during the hashing process.  Must be set before attempting to process any data.
				/// </summary>
				property array<Byte>^ Key { 
					array<Byte>^ get() override 
					{
						if (_key == nullptr) return nullptr;
						array<Byte>^ stuff = gcnew array<Byte>(_key->Length);
						Buffer::BlockCopy(_key, 0, stuff, 0, _key->Length);
						return stuff;
					}
					void set(array<Byte>^ value) override 
					{ 
						if (value == nullptr || value->Length == 0)
							_key = gcnew array<Byte>(0); // check for this during processing;
							//throw gcnew ArgumentException("Key value cannot be null or empty.", "Key");
						if (_algState != 0)
							throw gcnew CryptographicUnexpectedOperationException(
								"Cannot change Key during processing. Wait for the process to complete, or reinitialize the object.");
						Initialize();
						_key = gcnew array<Byte>(value->Length);
						Buffer::BlockCopy(value, 0, _key, 0, _key->Length);
						_localState = SkeinCore::Initialize(QWORDWIDTH, DEFAULTHASHBITLENGTH, _key);
					}
				};
				/// <summary>
				/// The number of bits in the default hash or digest output.
				/// </summary>
				property int HashSize {int get() override { return DEFAULTHASHBITLENGTH; } };
				property bool CanReuseTransform {bool get() override { return false; } };
				property bool CanTransformMultipleBlocks {bool get() override { return true; } };
				property int OutputBlockSize {int get() override { return sizeof(UInt64) * QWORDWIDTH; } };
				property int InputBlockSize {int get() override { return sizeof(UInt64) * QWORDWIDTH; } };
				property int BlockSizeValue {int get() new { return InputBlockSize; }};
				property int State {int get() override { return _algState; }};

				/// <summary>
				/// Default initializer that creates an object for later hashing with no key and a default output length.
				/// </summary>
				HMACSkein() { Initialize(); }
				
				void Initialize() override
				{
					if (Hash != nullptr)
						SkeinCore::ClearBytes(&_hashResult[0], _hashResult->Length);
					if (_localState != nullptr)
						SkeinCore::ClearQWords(&_localState[0], _localState->Length);
					if (_key != nullptr)
						SkeinCore::ClearBytes(&_key[0], _key->Length);
					Threading::Thread::MemoryBarrier();
					_hashResult = nullptr;
					_key = nullptr;
					if (_buffer != nullptr)
					{
						//_buffer->Dispose();
						_buffer = nullptr;
					}
					_algState = 0;
				}

				void HashCore(array<Byte>^ array, int ibStart, int cbSize) override
				{
					if (_localState == nullptr)
						throw gcnew InvalidOperationException("SkeinHashAlgorithm not initialized.  Call Initialize first!");
					if (array == nullptr)
						throw gcnew ArgumentNullException("array");
					if (array->Length == 0)
						return;
					if (ibStart >= array->Length)
						throw gcnew ArgumentOutOfRangeException("ibStart");
					if (cbSize < 1)
						throw gcnew ArgumentOutOfRangeException("cbSize");
					if (ibStart + cbSize > array->Length)
						throw gcnew ArgumentOutOfRangeException("length");
					_algState = -1;
					//because the final input block needs to have the Final flag set, don't send bytes
					//  to be processed until there is more than one block's worth, let HashFinal do the final hashing, full block or not.
					if (_buffer == nullptr)
						_buffer = gcnew MemoryStream(array, ibStart, cbSize, true, true);
					else
						_buffer->Write(array, ibStart, cbSize);
					int processedBytes = 0;
					if (_buffer->Length > InputBlockSize)
					{
						lock::lock(_bufferLock);

						// lock this process so that the bytes are processed in the correct order and the counts are correct
						int blocks = (int)(_buffer->Length / InputBlockSize);
						if (_buffer->Length % InputBlockSize == 0) // length is exact multiple of inputblock size? do one less block, always save one for HashFinal
							blocks--;
						for (; blocks > 0; blocks--)
						{
							SkeinCore::ProcessMessage(_localState, gcnew ArraySegment<Byte>(_buffer->GetBuffer(), (int)processedBytes, InputBlockSize), 0, _bufferRunningCount, false);
							processedBytes += InputBlockSize;
							_bufferRunningCount += (UInt64)InputBlockSize;
						}
						MemoryStream^ _tempBuffer = gcnew MemoryStream((int)_buffer->Length - processedBytes);
						_tempBuffer->Write(_buffer->GetBuffer(), processedBytes, _tempBuffer->Capacity);
						//_buffer->Dispose();
						_buffer = gcnew MemoryStream(_tempBuffer->GetBuffer(), 0, (int)_tempBuffer->Length, true, true);
						//_tempBuffer->Dispose();
						_tempBuffer = nullptr;
					}
				}

				array<Byte>^ HashFinal() override
				{
					if (_localState == nullptr)
						throw gcnew InvalidOperationException("HashAlgorithm not initialized.  Call Initialize first!");
					else {
						lock::lock(_bufferLock);

						if (_buffer != nullptr && _buffer->Length > 0)
							SkeinCore::ProcessMessage(_localState, _buffer->GetBuffer(), 0, _bufferRunningCount, true);
						_hashResult = SkeinCore::ProcessStandardOutput(_localState, DEFAULTHASHBITLENGTH);
						SkeinCore::ClearQWords(&_localState[0], _localState->Length);
						Threading::Thread::MemoryBarrier();
						_localState = nullptr;
						_algState = 0;
						return _hashResult;
					}
				}

				void Clear() new
				{
					if (_localState != nullptr)
						SkeinCore::ClearQWords(&_localState[0], _localState->Length);
					Threading::Thread::MemoryBarrier();
					_localState = nullptr;
					if (_buffer != nullptr)
						_buffer->Close();
					if (_hashResult != nullptr)
						SkeinCore::ClearBytes(&_hashResult[0], _hashResult->Length);
					Threading::Thread::MemoryBarrier();
					_hashResult = nullptr;
				}
			};

		}
	}
}