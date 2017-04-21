#pragma once
using namespace System;
#include "SkeinCore.h"
#define SKEIN_EX
namespace Skein
{
	/// <summary>
	/// 
	/// </summary>
	public ref class SkeinEx
	{
	internal:
		array<UInt64>^ _state = nullptr;
		UInt64 _hashBitLength = 0;  // this is nullable to help determine if the class has been properly initialized
		Byte _treeMaxLevels = 0;
		Byte _treeLeaf = 0;
		Byte _treeNode = 0;
		// in order of importance
		// personalizations cannot be added after a public key, a public key cannot be added after a master key, and a nonce
		// cannot be added after a master key, etc.
		// all four can be used, but it must be in the order listed.
		bool _hasPersonalization = false;
		bool _hasAPublicKey = false;
		bool _hasAMasterKey = false;
		bool _hasNonce = false;
	protected:
		// Between the 3 state sizes of Skein (specifically the Skein[StateSize]Ex classes), these are the only variables that change.
		// This is by design, as the classes are essentially identical save for some very specific values (initializers, some documentation,
		// and these variables).  
		//========================================================start state dependant variables
		property Byte QWORDWIDTH {virtual Byte get() abstract; };
		property UInt16 DEFAULTHASHBITLENGTH {UInt16 get() { return QWORDWIDTH * 64; }};
		//========================================================end state dependant variables
	public:
		/// <summary>
		/// Gets a boolean indicating if a personalization has been applied to this instance.
		/// </summary>
		property bool IsPersonalized {bool get() { return _hasPersonalization; } };
		/// <summary>
		/// Gets a boolean indicating if a public key has been applied to this instance.
		/// </summary>
		property bool HasAPublicKey {bool get() { return _hasAPublicKey; } };
		/// <summary>
		/// Gets a boolean indicating if a Master Key has been applied to this instance.
		/// </summary>
		property bool HasAMasterKey {bool get() { return _hasAMasterKey; } };
		/// <summary>
		/// Gets a boolean indicating if a NONCE has been applied to this instance.
		/// </summary>
		property bool HasANonce {bool get() { return _hasNonce; } };


		/// <summary>
		/// Default initializaion constuctor.  
		/// Equivalent to using Initialize() to prepare for hashing.
		/// </summary>
		SkeinEx() { Initialize(); }

		/// <summary>
		/// Initialize with a given hashBitLength.
		/// </summary>
		/// <param name="hashBitLength">[OPTIONAL] The length in bits of the final output. Default=256, must be >= 8 and multiple of 8</param>
		/// <param name="key">[OPTIONAL] If the hash operation is to be keyed (MAC), the key is passed here as an array of bytes. Default=null</param>
		SkeinEx(UInt64 hashBitLength, array<Byte>^ key)
		{
			Initialize(hashBitLength, key, nullptr, 0, 0, 0);
		}

		/// <summary>
		/// Reset the object and clear out any existing data (Securely).  Must be reinitialized in order to hash new data.  Allows for object reuse.
		/// </summary>
		~SkeinEx()
		{
			Clear();
		}

		/// <summary>
		/// Default initializaion constuctor.  Default=no tree-hashing, no personalization.
		/// </summary>
		virtual void Initialize()
		{
			Clear();
			_state = gcnew array<UInt64>(QWORDWIDTH);
			//_state = SkeinCore.GetInitialUnkeyedState(WORDWIDTH);
			SkeinCore::ProcessConfig(_state, DEFAULTHASHBITLENGTH, 0, 0, 0);
			if (_state[0] == 0 && _state[1] == 0 && _state[2] == 0 && _state[3] == 0)
				throw gcnew InvalidOperationException("FAILURE TO INITIALIZE STATE! INTERNAL ERROR! THIS SHOULD NEVER HAPPEN!");
			_hashBitLength = DEFAULTHASHBITLENGTH;
			_treeLeaf = 0;
			_treeNode = 0;
			_treeMaxLevels = 0;
		}

		/// <summary>
		/// Initialize with a key for MAC operations, and a given hashBitLentgh output.
		/// NOTE:  Tree hashing process produces unique values when compared to straight-hashing.  See the Skein white paper for more details.
		/// When using Tree Hashing, all three related variables must be greater than 0, and the Tree Max Level must be greater than 1.
		/// </summary>
		/// <param name="hashBitLength">[OPTIONAL] The length in bits of the final output. must be >=8 and multiple of 8</param>
		/// <param name="key">[OPTIONAL] The key, as a byte array, against which to hash (MAC operations). Default=null</param>
		/// <param name="personalization">[OPTIONAL] This string will be processed into the hash to make the output unique to a particular usage. Default=null</param>
		/// <param name="treeLeaf">[OPTIONAL] Tree Hashing: specifies the width of the leaves in the first pass of a tree-hash. Default=0</param>
		/// <param name="treeNode">[OPTIONAL] Tree Hashing: specifies the width of the nodes in level 2 and higher of the tree-hash. Default=0</param>
		/// <param name="treeMaxLevels">[OPTIONAL] Tree Hashing: specifies the max level to process data, must be >= 2. Default=0</param>
		virtual void Initialize(UInt64 hashBitLength,
			array<Byte>^ key,
			String^ personalization,
			Byte treeLeaf,
			Byte treeNode,
			Byte treeMaxLevels)
		{
			Clear();
			_state = SkeinCore::Initialize(QWORDWIDTH, hashBitLength, key, treeLeaf, treeNode, treeMaxLevels);
			if (_state[0] == 0 && _state[1] == 0 && _state[2] == 0 && _state[3] == 0)
				throw gcnew InvalidOperationException("FAILURE TO INITIALIZE STATE! INTERNAL ERROR! THIS SHOULD NEVER HAPPEN!");
			if (!String::IsNullOrWhiteSpace(personalization))
			{
				SkeinCore::ProcessPersonalization(_state, personalization);
				_hasPersonalization = true;
			}
			_hashBitLength = hashBitLength;
			_treeLeaf = treeLeaf;
			_treeNode = treeNode;
			_treeMaxLevels = treeMaxLevels;

		}

		virtual array<Byte>^ ComputeHash(array<Byte>^ data)
		{
			return ComputeHash(data, 0);
		}
			/// <summary>
			/// Produce a hash against an array of bytes.
			/// After the result is calculated, the state is wiped (one-time use computation).
			/// </summary>
			/// <param name="data">The data, as a byte array, to be hashed.</param>
			/// <param name="lastByteBitCount">[OPTIONAL] If the last byte contains fewer than 8 actual data bits (packed in the high end of the byte),
			/// indicate how many bits to process. Default=0, must be less than 8.</param>
			/// <returns>The byte array containing the resulting hash.</returns>
		virtual array<Byte>^ ComputeHash(array<Byte>^ data, Byte lastByteBitCount)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (data == nullptr)
				data = gcnew array<Byte>(0);
			if (_treeLeaf == 0 && _treeNode == 0 && _treeMaxLevels == 0)
				SkeinCore::ProcessMessage(_state, data, lastByteBitCount, 0, true);
			else
				SkeinCore::ProcessMessage(_state, data, lastByteBitCount, _treeLeaf, _treeNode, _treeMaxLevels);
			array<Byte>^ result = SkeinCore::ProcessStandardOutput(_state, _hashBitLength);
			_hashBitLength = 0;
			Clear();
			return result;
		}

		/// <summary>
		/// Produce a hash against a string.
		/// After the result is calculated, the state is wiped (one-time use computation).
		/// </summary>
		/// <param name="data">The string to be hashed.</param>
		/// <returns>The byte array containing the resulting hash.</returns>
		virtual array<Byte>^ ComputeHash(String^ data)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			SkeinCore::ProcessMessage(_state, data);
			array<Byte>^ result = SkeinCore::ProcessStandardOutput(_state, _hashBitLength);
			_hashBitLength = 0;
			Clear();
			return result;
		}

		/// <summary>
		/// Produce a hash against a string.
		/// After the result is calculated, the state is wiped (one-time use computation).
		/// </summary>
		/// <param name="data">The string to be hashed.</param>
		/// <returns>The byte array containing the resulting hash.</returns>
		virtual array<Byte>^ ComputeHash(ArraySegment<Byte> data)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			SkeinCore::ProcessMessage(_state, data, 0, 0, true);
			array<Byte>^ result = SkeinCore::ProcessStandardOutput(_state, _hashBitLength);
			_hashBitLength = 0;
			Clear();
			return result;
		}

		/// <summary>
		/// Wipe out the state to prevent leaking information.
		/// The appropriate Initialize() method must be called afterwards in order to produce more hashes.
		/// NOTE:  This is done automatically after a ComputeHash operation.
		/// </summary>
		void Clear()
		{
			if (_state != nullptr)
				SkeinCore::ClearQWords(&_state[0], _state->Length);
			_state = nullptr;
			_hashBitLength = 0;
			_treeLeaf = 0;
			_treeNode = 0;
			_treeMaxLevels = 0;
			_hasPersonalization = false;
			_hasAPublicKey = false;
			_hasNonce = false;
			_hasAMasterKey = false;
		}

		//#region Advanced Methods

		//	#region - Personalization

			/// <summary>
			/// Apply a personalization to this instance of the hash function to make it unique to a given application or process.
			/// This must be done before applying a public key and/or nonce.
			/// </summary>
			/// <param name="personalization">String containing the personalization</param>
		void Personalize(String^ personalization)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (IsPersonalized)
				throw gcnew InvalidOperationException("An instance cannot be personalized more than once.");
			if (HasAPublicKey || HasANonce || HasAMasterKey)
				throw gcnew InvalidOperationException("Personalization can only be done before processing a public key, master key, and/or a nonce.");
			_hasPersonalization = true;
			SkeinCore::ProcessPersonalization(_state, personalization);
		}

		/// <summary>
		/// Apply a personalization to this instance of the hash function to make it unique to a given application or process.
		/// This must be done before applying a public key and/or nonce.
		/// </summary>
		/// <param name="personalization">The personalization as an array of bytes.</param>
		void Personalize(array<Byte>^ personalization)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (IsPersonalized)
				throw gcnew InvalidOperationException("An instance cannot be personalized more than once.");
			if (HasAPublicKey || HasANonce || HasAMasterKey)
				throw gcnew InvalidOperationException("Personalization can only be done before processing a public key, master key, and/or a nonce.");
			_hasPersonalization = true;
			SkeinCore::ProcessPersonalization(_state, personalization);
		}

		/// <summary>
		/// Use this to tie the hash process to a particular public key.  Especially useful and secure when creating signed message digests.
		/// NOTE:  This instance does not store any information about the keys or their order!  They are folded in the moment the method returns.
		/// </summary>
		/// <param name="publicKeyMaterial">The public key to attach to the hashing instance as an array of bytes.</param>
		void AddPublicKey(array<Byte>^ publicKeyMaterial)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (HasAPublicKey)
				throw gcnew InvalidOperationException("Only one public key can be attached to a given hashing instance.");
			if (HasANonce || HasAMasterKey)
				throw gcnew InvalidOperationException("A public key cannot be added after processing a master key or nonce.");
			_hasAPublicKey = true;
			SkeinCore::ProcessPublicKey(_state, publicKeyMaterial);
		}

		/// <summary>
		/// Use this to tie a Master Key to the hash process.  Normally used for derived passwords for related processes.
		/// </summary>
		/// <param name="masterKey">The master password from which this output will be derived.</param>
		void AddMasterKey(array<Byte>^ masterKey)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (HasAMasterKey)
				throw gcnew InvalidOperationException("Only one Master Key can be attached to a given hashing instance.");
			if (HasANonce)
				throw gcnew InvalidOperationException("A master key cannot be added after processing a nonce.");
			_hasAMasterKey = true;
			SkeinCore::ProcessKeyId(_state, masterKey);
		}

		/// <summary>
		/// Use this to tie a NONCE to the hash process.  Normally used for randomization or random hashing.  
		/// Most NONCE's cannot/should not be used for more than one hash process for security reasons.
		/// </summary>
		/// <param name="nonce">The NONCE to attach to the hashing instance as an array of bytes.</param>
		void AddNonce(array<Byte>^ nonce)
		{
			if (_state == nullptr || _hashBitLength == 0)
				throw gcnew InvalidOperationException("Not initialized.  Call appropriate Initialize method first.");
			if (HasANonce)
				throw gcnew InvalidOperationException("Only one Nonce can be attached to a given hashing instance.");
			_hasNonce = true;
			SkeinCore::ProcessNonce(_state, nonce);
		}
	};//end class
}
