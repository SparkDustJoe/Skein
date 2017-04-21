#pragma once
#include "System.Security.Cryptography.SkeinHashAlgorithm.cpp"
#include "System.Security.Cryptography.HMACSkeinXManaged.cpp"
using namespace System;

namespace System {
	namespace Security {
		namespace Cryptography
		{
			public ref class PBKDF2HMACSkein512 : DeriveBytes
			{
			internal:
				//Internal variables and public properties
				int _blockSize = -1;  // the byte width of the output of the HMAC algorithm       
				array<Byte>^ _P = nullptr;
				int _C = 0;
				System::Security::Cryptography::HMACSkein512Managed^ _hmac = nullptr;
				array<Byte>^ _S = nullptr;
				// if you called the initializer/constructor specifying a salt size,
				// you will need this property to GET the salt after it was created from the crypto rng!
				// GET THIS BEFORE CALLING GETBYTES()!  OBJECT WILL BE RESET AFTER GETBYTES() AND
				// SALT WILL BE LOST!!
				// the core function of the PBKDF which does all the iterations
				// per the spec section 5.2 step 3
				array<Byte>^ _F(UInt32 I)
				{
					//NOTE: SPEC IS MISLEADING!!!
					//THE HMAC FUNCTIONS ARE KEYED BY THE PASSWORD! NEVER THE SALT!
					array<Byte>^ bufferU = nullptr;
					array<Byte>^ bufferOut = nullptr;
					array<Byte>^ _int = IntToBytes(I);
					_hmac = gcnew HMACSkein512Managed();
					_hmac->Key = (_P); // KEY BY THE PASSWORD!
					_hmac->TransformBlock(_S, 0, _S->Length, _S, 0);
					_hmac->TransformFinalBlock(_int, 0, _int->Length);
					bufferU = _hmac->Hash;
					bufferOut = gcnew array<Byte>(bufferU->Length);
					Buffer::BlockCopy(bufferU, 0, bufferOut, 0, bufferU->Length);
					for (int c = 1; c < _C; c++)
					{
						_hmac->Initialize();
						_hmac->Key = _P;  // KEY BY THE PASSWORD!
						bufferU = _hmac->ComputeHash(bufferU);
						_Xor(&bufferOut[0], bufferU);
					}
					return bufferOut;
				}

				// XOR one array of bytes into another (which is passed by reference)
				// this is the equiv of data ^= newData;
				void _Xor(interior_ptr<Byte> data, array<Byte>^ newData)
				{
					for (int i = newData->GetLowerBound(0); i <= newData->GetUpperBound(0); i++)
						*(data +i) ^= newData[i];
				}

				// convert an unsigned int into an array of bytes BIG ENDIEN
				// per the spec section 5.2 step 3
				static array<Byte>^ IntToBytes(UInt32 i)
				{
					array<Byte>^ bytes = BitConverter::GetBytes(i);
					if (!BitConverter::IsLittleEndian)
					{
						return bytes;
					}
					else
					{
						Array::Reverse(bytes);
						return bytes;
					}
				}
				
			public:
				property array<Byte>^ Salt
				{ array<Byte>^ get()
				{
					array<Byte>^ value = gcnew array<Byte>(_S->Length);
					Buffer::BlockCopy(_S, 0, value, 0, value->Length);
					return value;
				}};

				// Constructors
				PBKDF2HMACSkein512(String^ Password, array<Byte>^ Salt, int IterationCount)
				{
					Initialize(Password, Salt, IterationCount);
				}

				PBKDF2HMACSkein512(array<Byte>^ Password, array<Byte>^ Salt, int IterationCount)
				{
					Initialize(Password, Salt, IterationCount);
				}

				PBKDF2HMACSkein512(String^ Password, int SizeOfSaltInBytes, int IterationCount)
				{
					Initialize(Password, SizeOfSaltInBytes, IterationCount);
				}

				PBKDF2HMACSkein512(array<Byte>^ Password, int SizeOfSaltInBytes, int IterationCount)
				{
					Initialize(Password, SizeOfSaltInBytes, IterationCount);
				}

				//All Construtors call the corresponding Initialize methods
				void Initialize(String^ Password, array<Byte>^ Salt, int IterationCount)
				{
					if (String::IsNullOrWhiteSpace(Password))
						throw gcnew ArgumentException("Password must contain meaningful characters and not be null.", "Password");
					if (IterationCount < 1)
						throw gcnew ArgumentOutOfRangeException("IterationCount");
					Initialize((gcnew System::Text::UTF8Encoding())->GetBytes(Password), Salt, IterationCount);
				}

				void Initialize(array<Byte>^ Password, array<Byte>^ Salt, int IterationCount)
				{
					//all Constructors/Initializers eventually lead to this one which does all the "important" work
					if (Password == nullptr || Password->Length == 0)
						throw gcnew ArgumentException("Password cannot be null or empty.", "Password");
					if (Salt == nullptr)
						Salt = gcnew array<Byte>(0);
					if (IterationCount < 1)
						throw gcnew ArgumentOutOfRangeException("IterationCount");
					array<Byte>^ inpValue = gcnew array<Byte>(Password->Length);
					Buffer::BlockCopy(Password, 0, inpValue, 0, Password->Length);
					_P = inpValue;
					inpValue = gcnew array<Byte>(Salt->Length);
					Buffer::BlockCopy(Salt, 0, inpValue, 0, Salt->Length);
					_S = inpValue;
					_C = IterationCount;
					//determine _blockSize
					_hmac = gcnew HMACSkein512Managed();
					_hmac->Key = gcnew array<Byte>(1);
					array<Byte>^ test = _hmac->ComputeHash(gcnew array<Byte>(1));
					_blockSize = test->Length;

				}

				void Initialize(String^ Password, int SizeOfSaltInBytes, int IterationCount)
				{
					if (String::IsNullOrWhiteSpace(Password))
						throw gcnew ArgumentException("Password must contain meaningful characters and not be null.", "Password");
					if (IterationCount < 1)
						throw gcnew ArgumentOutOfRangeException("IterationCount");
					Initialize((gcnew System::Text::UTF8Encoding())->GetBytes(Password), SizeOfSaltInBytes, IterationCount);
				}

				void Initialize(array<Byte>^ Password, int SizeOfSaltInBytes, int IterationCount)
				{
					if (Password == nullptr || Password->Length == 0)
						throw gcnew ArgumentException("Password cannot be null or empty.", "Password");
					if (SizeOfSaltInBytes < 0)
						throw gcnew ArgumentOutOfRangeException("SizeOfSaltInBytes");
					if (IterationCount < 1)
						throw gcnew ArgumentOutOfRangeException("IterationCount");
					// You didn't specify a salt, so I'm going to create one for you of the specific byte length
					array<Byte>^ data = gcnew array<Byte>(SizeOfSaltInBytes);
					RNGCryptoServiceProvider^ rng = gcnew RNGCryptoServiceProvider();
					rng->GetBytes(data);
					// and then finish initializing...
					// Get the salt from the Salt parameter BEFORE calling GetBytes()!!!!!!!!!!!
					Initialize(Password, data, IterationCount);
				}

				~PBKDF2HMACSkein512()
				{
					//*DOOT* clean up in aisle 5! *KEKERKCRACKLE*
					Reset();
				}

				// required by the Derive Bytes class/interface
				// this is where you request your output bytes after Initialize
				// state of class Reset after use!
				array<Byte>^ GetBytes(int ByteCount) override
				{
					if (_S == nullptr || _P == nullptr)
						throw gcnew InvalidOperationException("Object not Initialized!");
					if (ByteCount < 1)// || ByteCount > uint.MaxValue * blockSize)
						throw gcnew ArgumentOutOfRangeException("ByteCount");

					int totalBlocks = (int)Math::Ceiling(ByteCount / _blockSize);
					int partialBlock = (int)(ByteCount % _blockSize);
					array<Byte>^ result = gcnew array<Byte>(ByteCount);
					array<Byte>^ buffer = nullptr;
					// I'm using TT here instead of T from the spec because I don't want to confuse it with
					// the generic object T
					for (int TT = 1; TT <= totalBlocks; TT++)
					{
						// run the F function with the _C number of iterations for block number TT
						buffer = _F((UInt32)TT);
						//IF we're not at the last block requested
						//OR the last block requested is whole (not partial)
						//  then take everything from the result of F for this block number TT
						//ELSE only take the needed bytes from F
						if (TT != totalBlocks || (TT == totalBlocks && partialBlock == 0))
						{
							Buffer::BlockCopy(buffer, 0, result, _blockSize * (TT - 1), _blockSize);
						}
						else
						{
							Buffer::BlockCopy(buffer, 0, result, _blockSize * (TT - 1), partialBlock);
						}
					}
					Reset();  // force cleanup after every use!  Cannot be reused!
					return result;
				}

				// required by the Derive Bytes class/interface
				void Reset() override
				{
					_C = 0;
					_P->Initialize(); // the compiler might optimize this line out! :(
					Threading::Thread::MemoryBarrier();
					_P = nullptr;
					_S->Initialize(); // the compiler might optimize this line out! :(
					Threading::Thread::MemoryBarrier();
					_S = nullptr;
					if (_hmac != nullptr)
						_hmac->Clear();
					_blockSize = -1;
				}
			};
		}
	}
}