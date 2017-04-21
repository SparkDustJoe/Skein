// SkeinCore.h
#pragma once
using namespace System;
#ifndef THREEFISH_CORE_H
#include "ThreeFishCore.h"
#endif // !THREEFISH_CORE_H
#define SKEIN_CORE_H
namespace Skein
{
	public ref class SkeinCore
	{
		//CONSTANTS
	public:
        // flags and version
		//static void Skein::SkeinCore::ClearQWords(interior_ptr<UInt64> inWords, int length);
		//static void Skein::SkeinCore::ClearBytes(interior_ptr<Byte> inBytes, int length);
		#include "Clear.cpp"
        static const UInt32 SKEIN_VERSION = 0x00000001;     // base major version ONE (1)
        static const UInt32 SKEIN_SCHEMA_ID = 0x33414853;   // (0x33414853) = "SHA3" in ASCII per the white paper
        static const UInt64 SKEIN_VS = (UInt64)(((UInt64)SKEIN_VERSION << 32) + SKEIN_SCHEMA_ID);

        static const UInt64 SKEIN_TREELEVEL_MULTIPLIER = 0x1000000000000;
        static const UInt64 SKEIN_FLAG_FIRST = 0x4000000000000000;     //=First block in a series of data blocks.
        static const UInt64 SKEIN_FLAG_FINAL = 0x8000000000000000;     //=Last block in a series of data blocks. Not mutually exclusive with First.
        static const UInt64 SKEIN_FLAG_PAD = 0x0080000000000000;       //=The last block in a series of data blocks has an incomplete byte, top loaded.

        // block types being passed in
        static const UInt64 SKEIN_TYPE_KEY = 0x0000000000000000;        // =Skein being used for MAC, this is the Key block. (optional but done FIRST)
        static const UInt64 SKEIN_TYPE_CONFIG = 0x0400000000000000;     // =Standard config. (ALWAYS DONE, this can be precomputed and stored/reused:
                                                                        // IF AND ONLY IF there is no key (or the key is constant) AND the hashbitlength
                                                                        //   doesn't change.
                                                                        // i.e. if Key is always "blah" AND hashBitLength is always 160, precompute,
                                                                        // or there is no Key and hashBitLength is always 256, precompute, etc.
        static const UInt64 SKEIN_TYPE_PER_STR = 0x0800000000000000;    // =(optional) Personalization string. 
                                                                        // Use the Personalization string like a message block
                                                                        // after the config to narrow the scope of the particular
                                                                        // hash calculation.
        static const UInt64 SKEIN_TYPE_PUB_KEY = 0x0C00000000000000;    // =(optional) Processing a public key here will tie any hash operations to that
                                                                        // public key.  This is usefull for message signatures, encrypted or otherwise.
        static const UInt64 SKEIN_TYPE_KEY_DER_ID = 0x1000000000000000; // =(optional) Key derivation identifier.
                                                                        // Pass the master key in the Key stage, then pass the 
                                                                        // ID (or username) of the requested derived key in this stage.
        static const UInt64 SKEIN_TYPE_NONCE = 0x1400000000000000;      // =(optional) Message nonce.
                                                                        // Use for RNG or Stream Cipher modes, or key derivations (think "salt").
                                                                        // Generally Nonces are used only ONCE in a given context, and then disposed.
        static const UInt64 SKEIN_TYPE_MSG = 0x3000000000000000;        // This block is message data.
        static const UInt64 SKEIN_TYPE_OUTPUT = 0x3F00000000000000;     // This block is part of the output transform.
        
        //CLASS-WIDE COMMON METHODS/FUNCTIONS

        /// <summary>
        /// Process a Skein UBI block.  This function is common to a number of UBI blocks that have a similar flow.
        /// Key, Personalization String, Public Key, Key Derivation ID, Nonce, and Message type blocks (not Config, or Output blocks). 
        /// </summary>
        /// <param name="state">The state of the current Skein instance.</param>
        /// <param name="data">The data to be processed.</param>
        /// <param name="typeFlag">What type of block is going to be processed.</param>
        /// <param name="lastByteBitCount">If the last byte of the block is incomplete/partial, 
        /// the number of actual bits packed into the high end of the byte.</param>
        static void ProcessGeneric(array<UInt64>^ state, UInt64 typeFlag, array<Byte>^ data, Byte lastByteBitCount, UInt64 offset, bool isLast)
        {   // used for key, message, personalization, nonce
			return ProcessGeneric(state, typeFlag, gcnew ArraySegment<Byte>(data), lastByteBitCount, offset, isLast); 
        }

		/// <summary>
		/// Process a Skein UBI block.  This function is common to a number of UBI blocks that have a similar flow.
		/// Key, Personalization String, Public Key, Key Derivation ID, Nonce, and Message type blocks (not Config, or Output blocks). 
		/// </summary>
		/// <param name="state">The state of the current Skein instance.</param>
		/// <param name="data">The data to be processed.</param>
		/// <param name="typeFlag">What type of block is going to be processed.</param>
		/// <param name="lastByteBitCount">If the last byte of the block is incomplete/partial, 
		/// the number of actual bits packed into the high end of the byte.</param>
		static void ProcessGeneric(array<UInt64>^ state, UInt64 typeFlag, ArraySegment<Byte>^ data, Byte lastByteBitCount, UInt64 offset, bool isLast)
		{   // used for key, message, personalization, nonce
			
			array<UInt64>^ transport = gcnew array<UInt64>(state->Length);
			array<UInt64>^ tweak = (offset == 0) ?
				gcnew array<UInt64>{0, SKEIN_FLAG_FIRST + typeFlag} :
				gcnew array<UInt64>{0, typeFlag};
			int byteWidth = state->Length * sizeof(UInt64);
			ArraySegment<Byte>^ _data = data;
			if (_data == nullptr)
			{
				_data = gcnew ArraySegment<Byte>(gcnew array<Byte>(0), 0, 0);
				//return ProcessGeneric(state, typeFlag, gcnew array<Byte>(0), 0, offset, isLast);
			}
			for (long i = 0; (i * byteWidth) < _data->Count || (i == 0 && _data->Count == 0 && typeFlag != SKEIN_TYPE_KEY); i++)
			{
				//process a block  
				long currentPosition = i * byteWidth;
				long nextPosition = currentPosition + byteWidth;
				tweak[0] = (UInt64)currentPosition + offset;
				if ((nextPosition < _data->Count) || (nextPosition == _data->Count && lastByteBitCount == 0))
				{
					tweak[0] += (UInt64)byteWidth;
					if (currentPosition + (long)byteWidth == _data->Count && isLast)
					{
						tweak[1] += SKEIN_FLAG_FINAL;
					}
					System::Buffer::BlockCopy(_data->Array, _data->Offset + currentPosition, transport, 0, byteWidth);
				}
				else
				{
					if (isLast == false)
						throw gcnew InvalidOperationException("Cannot have partial block that isn't the last block!");
					Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
					//the tweak0 represents a RUNNING total of bytes, so if this is the last block, take the full length
					//NOTE: as in the reference implementation, this implementation only supports 64 bits of length information,
					// not the full 96 that are normally available as per the white paper.
					tweak[0] = (unsigned long)data->Count + offset;
					tweak[1] += SKEIN_FLAG_FINAL;
					System::Buffer::BlockCopy(_data->Array, _data->Offset + currentPosition, transport, 0, _data->Count - currentPosition);
					if (lastByteBitCount > 0)
					{
						tweak[1] += SKEIN_FLAG_PAD;
						Byte newLastByte = (Byte)_data->Array[_data->Offset + _data->Count - 1]; // grab the original last byte
						newLastByte &= (Byte)(0xFF << (8 - lastByteBitCount)); // mask unwanted bits
						newLastByte |= (Byte)1 << (7 - lastByteBitCount); //append a single bit
						int newLastBytePosition = (_data->Count - 1 + byteWidth) % byteWidth;
						//put the augmented last byte back into the transport
						System::Buffer::SetByte(transport, newLastBytePosition, newLastByte);
					}					
				}
				//now transform
				switch (state->Length)
				{
					case 4: Skein::ThreeFishCore::Process256(transport, state, tweak, true, state); break;
					case 8: Skein::ThreeFishCore::Process512(transport, state, tweak, true, state); break;
					case 16: Skein::ThreeFishCore::Process1024(transport, state, tweak, true, state); break;
				}
				tweak[1] &= ~SKEIN_FLAG_FIRST; // we're not on the first block anymore, so knock off that flag
			}
			Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
			Skein::SkeinCore::ClearQWords(&tweak[0], 2);
		}

        /// <summary>
        /// Initialize a Skein instance with a given state width and ultimate hashBitLength.
        /// The Hash Bit Length is configured into an instance at the very beginning, it must be known on initialization.
        /// </summary>
        /// <param name="stateWordWidth">4, 8, or 16 words, for 256-, 512- and 1024-bit state widths, respectively.</param>
        /// <param name="hashBitLength">The length, in bits, of the final output hash.</param>
        /// <param name="keyData">If the Skein transform is to be keyed, this key is supplied here, else null.</param>
        /// <returns>The initialized state of the transform.</returns>
        static array<UInt64>^ Initialize(Byte stateWordWidth, UInt64 hashBitLength, array<Byte>^ keyData)
        {
            //MAC OPERATION, USING A KEY
            if (stateWordWidth != 4 && stateWordWidth != 8 && stateWordWidth != 16)
                throw gcnew ArgumentException("Initialize:  stateWordWidth must be length 4 (256bit), 8 (512bit), or 16 (1024bit)", "stateWordWidth");
            if (hashBitLength < 1)
                throw gcnew ArgumentOutOfRangeException("hashBitLenth", "Initialize:  hashBitLength cannot be Zero or negative.");
            if (hashBitLength % 8 != 0)
                throw gcnew ArgumentException("Initialize:  hashBitLength must be byte aligned (evenly divisible by 8)", "hashBitLength");
            //if (keyData == null || keyData.Length < 1) // MUST BE CHECKED BY CALLER!!!
            //    throw new ArgumentException("Initialize:  keyData cannot be null or empty if specified", "keyData");
			
            array<UInt64>^ state = gcnew array<UInt64>(stateWordWidth);
            if (keyData != nullptr && keyData->Length > 0)
                ProcessGeneric(state, SKEIN_TYPE_KEY, keyData, 0, 0, true);
            ProcessConfig(state, hashBitLength, 0, 0, 0);

            return state;
        }

        /// <summary>
        /// Initialize a Skein instance with a given state width and ultimate hashBitLength.
        /// The Hash Bit Length is configured into an instance at the very beginning, it must be known on initialization.
        /// </summary>
        /// <param name="stateWordWidth">4, 8, or 16 words, for 256-, 512- and 1024-bit state widths, respectively.</param>
        /// <param name="hashBitLength">The length, in bits, of the final output hash.</param>
        /// <param name="keyData">If the Skein transform is to be keyed, this key is supplied here, else null.</param>
        /// <param name="treeLeaf"></param>
        /// <param name="treeNode"></param>
        /// <param name="treeMaxLevels"></param>
        /// <returns>The initialized state of the transform.</returns>
        static array<UInt64>^ Initialize(Byte stateWordWidth, Int64 hashBitLength, array<Byte>^ keyData, Byte treeLeaf, Byte treeNode, Byte treeMaxLevels)
        {
            //MAC OPERATION, USING A KEY
            if (stateWordWidth != 4 && stateWordWidth != 8 && stateWordWidth != 16)
                throw gcnew ArgumentException("Initialize:  stateWordWidth must be length 4 (256bit), 8 (512bit), or 16 (1024bit)", "stateWordWidth");
            if (hashBitLength % 8 != 0)
                throw gcnew ArgumentException("Initialize:  hashBitLength must be byte aligned (evenly divisible by 8)", "hashBitLength");
            //if (keyData == null || keyData.Length < 1) // MUST BE CHECKED BY CALLER!!!
            //    throw new ArgumentException("Initialize:  keyData cannot be null or empty if specified", "keyData");

            array<UInt64>^ state = gcnew array<UInt64>(stateWordWidth);
            if (keyData != nullptr && keyData->Length > 0)
                ProcessGeneric(state, SKEIN_TYPE_KEY, keyData, 0, 0, true);
            ProcessConfig(state, hashBitLength, treeLeaf, treeNode, treeMaxLevels);

            return state;
        }

        /// <summary>
        /// INTERNAL FUNCTION - THIS IS USED ONLY BY THE INITIALIZE FUNCTIONS, NOT BY THE END CODER
        /// Process the Configure step of a Skein transform (after an optional key has already been processed).
        /// NOTE:  If treeLeaf, treeNode, or treeMaxLevels is non-zero, they ALL must be non-zero, treeMaxLevels must be greater than 1.
        /// NOTE:  Tree hashing MUST NOT be used for RNG's.
        /// </summary>
        /// <param name="state">The state of the transform to be configured.</param>
        /// <param name="hashBitLength">The output hash bit-length of the transform.  This value must be known at the beginning.</param>
        /// <param name="treeLeaf">[OPTIONAL] The size of the leaf in a tree hashing operation.  Zero if not used.</param>
        /// <param name="treeNode">[OPTIONAL] The size of a node in a tree hashing operation.  Zero if not used.</param>
        /// <param name="treeMaxLevels">[OPTIONAL] The maximum number of levels in a tree hashing operation.  Zero if not used.</param>
        static void ProcessConfig(array<UInt64>^ state, UInt64 hashBitLength, Byte treeLeaf, Byte treeNode, Byte treeMaxLevels)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessPersonalization:  state failed sanity check (incorrect length)");
            if ((treeLeaf == 0 || treeNode == 0 || treeMaxLevels == 0) && (treeLeaf + treeNode + treeMaxLevels > 0))
                throw gcnew ArgumentException("ProcessConfig:  when using tree hashing, Leaf, Node, and MaxLevels cannot be zero");
            if (treeMaxLevels < 2 && treeLeaf + treeNode > 0)
                throw gcnew ArgumentOutOfRangeException("treeMaxLevels", "ProcessConfig:  when tree hashing, treeMaxLevels must be greater than 1");

            array<UInt64>^ transport = gcnew array<UInt64>(state->Length);
			array<UInt64>^ tweak = gcnew array<UInt64>(2);
			tweak[0]=32UL;
			tweak[1]=SKEIN_FLAG_FIRST + SKEIN_FLAG_FINAL + SKEIN_TYPE_CONFIG;

            transport[0] = SKEIN_VS;
            transport[1] = (UInt64)hashBitLength;
            transport[2] = (UInt64)((treeMaxLevels << 16) + (treeNode << 8) + treeLeaf);

            //SkeinDebug.WriteData2File(ref transport, "debug", "configTRANSPORT", "This is the transport input of the config.");
            //SkeinDebug.WriteData2File(ref tweak, "debug", "configTWEAK", "This is the tweak input of the config.");

            switch (state->Length)
            {
                case 4: ThreeFishCore::Process256(transport, state, tweak, true, state); break;
                case 8: ThreeFishCore::Process512(transport, state, tweak, true, state); break;
                case 16: ThreeFishCore::Process1024(transport, state, tweak, true, state); break;
            }
			Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
            //SkeinDebug.WriteData2File(ref state, "debug", "configAFTER", "This is the result of the config.");
        }

        /// <summary>
        /// Process Personalization step of an initialized Skein transform.
        /// </summary>
        /// <param name="state">The state of the transform to be personalized.</param>
        /// <param name="data">The personalization data to be injected into the transform.</param>
        static void ProcessPersonalization(array<UInt64>^ state, array<Byte>^ data)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessPersonalization:  state failed sanity check (incorrect length)");
            if (data == nullptr || data->Length < 1)
                throw gcnew ArgumentException("ProcessPersonalization:  data cannot be null or empty", "data");

            ProcessGeneric(state, SKEIN_TYPE_PER_STR, data, 0, 0, true);
        }

        /// <summary>
        /// Process Personalization step of an initialized Skein transform.
        /// </summary>
        /// <param name="state">The state of the transform to be personalized.</param>
        /// <param name="personalization">The personalization string (which will be UTF-8 processed) to be injected into the transform.</param>
        static void ProcessPersonalization(array<UInt64>^ state, System::String^ personalization)
        {
			if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessPersonalization:  state failed sanity check (incorrect length)");
			if (System::String::IsNullOrWhiteSpace(personalization))
                throw gcnew ArgumentException("ProcessPersonalization:  personalization cannot be null or empty", "personalization");
            array<Byte>^ _data = (gcnew System::Text::UTF8Encoding())->GetBytes(personalization);
            
            ProcessGeneric(state, SKEIN_TYPE_PER_STR, _data, 0, 0, true);
			Skein::SkeinCore::ClearBytes(&_data[0], _data->Length);
        }//*/

        /// <summary>
        /// Process a message or some data and tie it to a public key.
        /// </summary>
        /// <param name="state">The state of the transform which will be tied to the given public key.</param>
        /// <param name="data">The public key data as an array of bytes.</param>
        static void ProcessPublicKey(array<UInt64>^ state, array<Byte>^ data)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessPersonalization:  state failed sanity check (incorrect length)");
            if (data == nullptr || data->Length < 1)
                throw gcnew ArgumentException("ProcessPublicKey:  data cannot be null or empty", "data");

            ProcessGeneric(state, SKEIN_TYPE_PUB_KEY, data, 0, 0, true);
        }

        /// <summary>
        /// Process a key or message and derive a new key from the master key injected into the transform.
        /// The master key must have been passed as the key during Initialize step.
        /// </summary>
        /// <param name="state">The state of the transform that will process key data.</param>
        /// <param name="data">The user ID to be injected into the transform as an array of bytes.</param>
        static void ProcessKeyId(array<UInt64>^ state, array<Byte>^ data)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessKeyId:  state failed sanity check (incorrect length)");
            if (data == nullptr || data->Length < 1)
                throw gcnew ArgumentException("ProcessKeyId:  data cannot be null or empty", "data");

            ProcessGeneric(state, SKEIN_TYPE_KEY_DER_ID, data, 0, 0, true);
        }

        /// <summary>
        /// Process a nonce that will "tweak" the transform for a particular message or circumstance.
        /// </summary>
        /// <param name="state">The state of the transform to be tweaked.</param>
        /// <param name="data">The data to be injected into the transform for tweaking it as an array of bytes.</param>
        static void ProcessNonce(array<UInt64>^ state, array<Byte>^ data)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessNonce:  state failed sanity check (incorrect length)");
            if (data == nullptr || data->Length < 1)
                throw gcnew ArgumentException("ProcessNonce:  data cannot be null or empty", "data");

            ProcessGeneric(state, SKEIN_TYPE_NONCE, data, 0, 0, true);
        }

        /// <summary>
        /// Process a message that will be transformed.
        /// </summary>
        /// <param name="state">The state that is ready to process a message.</param>
        /// <param name="data">The data of the message in a byte array.</param>
        /// <param name="lastByteBitCount">[OPTIONAL] If the last byte of data has only a few bits packed into the high end, pass the number of bits to process, else 0.</param>
        static void ProcessMessage(array<UInt64>^ state, array<Byte>^ data, Byte lastByteBitCount, UInt64 offset, bool isLast)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessMessage:  state failed sanity check (incorrect length)");
            if (lastByteBitCount > 7)
                throw gcnew ArgumentOutOfRangeException("lastByteBitCount", "ProcessMessage:  the last byte count cannot exceed 7 bits. " +
                    "If the last byte is complete (no padding), pass zero.");

			ProcessGeneric(state, SKEIN_TYPE_MSG, data, lastByteBitCount, offset, isLast);
		}

		/// <summary>
		/// Process a message that will be transformed.
		/// </summary>
		/// <param name="state">The state that is ready to process a message.</param>
		/// <param name="data">The data of the message in a byte array segment.</param>
		/// <param name="lastByteBitCount">[OPTIONAL] If the last byte of data has only a few bits packed into the high end, pass the number of bits to process, else 0.</param>
		static void ProcessMessage(array<UInt64>^ state, ArraySegment<Byte>^ data, Byte lastByteBitCount, UInt64 offset, bool isLast)
		{
			if (!ValidateState(state))
				throw gcnew ArgumentException("ProcessMessage:  state failed sanity check (incorrect length)");
			if (lastByteBitCount > 7)
				throw gcnew ArgumentOutOfRangeException("lastByteBitCount", "ProcessMessage:  the last byte count cannot exceed 7 bits. " +
					"If the last byte is complete (no padding), pass zero.");
			ProcessGeneric(state, SKEIN_TYPE_MSG, data, lastByteBitCount, offset, isLast);
		}
	

        /// <summary>
        /// Process a message that will be transformed.
        /// </summary>
        /// <param name="state">The state that is ready to process a message.</param>
        /// <param name="message">The message to be transformed (it will be UTF-8 processed regardless).</param>
        static void ProcessMessage(array<UInt64>^ state, System::String^ message)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessMessage:  state failed sanity check (incorrect length)");

            System::Text::UTF8Encoding^ myEncoder = gcnew System::Text::UTF8Encoding();
            array<Byte>^ _data = myEncoder->GetBytes(message);
            ProcessGeneric(state, SKEIN_TYPE_MSG, _data, 0, 0, true);
			Skein::SkeinCore::ClearBytes(&_data[0], _data->Length);
            System::GC::Collect();
        }

        /// <summary>
        /// Finalize the transform and retrieve the hash as an array of bytes.  This will destroy the state upon completion.
        /// This is not to be used for RNG or PRNG operations.
        /// </summary>
        /// <param name="state">The state from which to extract the hash.</param>
        /// <param name="hashBitLength">The length in bits of the final hash.  THIS MUST MATCH THE VALUE PASSED TO THE INITIALIZE STEP! </param>
        /// <returns>The resulting hash as an array of bytes.</returns>
        static array<Byte>^ ProcessStandardOutput(array<UInt64>^ state, UInt64 hashBitLength)
        {
            if (!ValidateState(state)) 
                throw gcnew ArgumentException("ProcessStandardOutput:  state failed sanity check (incorrect length)");
            if (hashBitLength % 8 != 0)
                throw gcnew ArgumentException("ProcessStandardOutput:  hashBitLength must be byte aligned (evenly divisible by 8)", "hashBitLength");

            // Why the 8?  I have no idea, but I'm assuming that it means 8 bytes (64 bits)
            // It is not explained in the white paper
			array<UInt64>^ tweak = gcnew array<UInt64>(2);
			tweak[0]=8UL;
			tweak[1]=SKEIN_FLAG_FIRST + SKEIN_TYPE_OUTPUT + SKEIN_FLAG_FINAL;
            array<UInt64>^ transport = gcnew array<UInt64>(state->Length);

            //SkeinDebug.WriteData2File(ref transport, "debug", "stdoutputTRANSPORT", "Transport for the output.");
            //SkeinDebug.WriteData2File(ref tweak, "debug", "stdoutputTWEAK", "Tweak for the output.");
            //SkeinDebug.WriteData2File(ref state, "debug", "stdoutputSTATE", "State for the output.");

            //BEGIN OUTPUT
            int byteCount = (int)((hashBitLength + 7) >> 3);
            short byteWidth = (short)(state->Length * sizeof(UInt64));
            array<Byte>^ result = gcnew array<Byte>(hashBitLength / 8LL);
            for (int i = 0; (i * byteWidth) < result->Length; i++)
            {   //use the input array for a counter, only the state and tweak are used and remain constant
				Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
                transport[0] = (UInt64)i;
                switch (state->Length)
                {
                    case 4: ThreeFishCore::Process256(transport, state, tweak, true, transport); break;
                    case 8: ThreeFishCore::Process512(transport, state, tweak, true, transport); break;
                    case 16: ThreeFishCore::Process1024(transport, state, tweak, true, transport); break;
                }
                //dump the transport to the output, then discard
                int nextPosition = (i + 1) * byteWidth;
                int currentPosition = i * byteWidth;
                if (nextPosition <= result->Length)
                    System::Buffer::BlockCopy(transport, 0, result, currentPosition, (int)byteWidth);
                else
                    System::Buffer::BlockCopy(transport, 0, result, currentPosition, (int)result->Length - currentPosition);
            }
            //zero out and drop used memory
			Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
			Skein::SkeinCore::ClearQWords(&state[0], state->Length);
			Skein::SkeinCore::ClearQWords(&tweak[0], 2);
            //END OUTPUT
            return result;
		}

        // all Tree Hashing specific functions are broken out here for clarity
        // this does not include Config or Initialize as those functions are used for both Tree and Straight hashing

//#pragma warning "This function may be updated to a Thread-based function with callback.  You have been warned."
        /// <summary>
        /// 
        /// </summary>
        /// <param name="state"></param>
        /// <param name="data"></param>
        /// <param name="startPos"></param>
        /// <param name="endPos"></param>
        /// <param name="lastByteBitCount"></param>
        static void ProcessTreeLeaf(array<UInt64>^ state, array<Byte>^ data, int startPos, int endPos, Byte lastByteBitCount)
        {   // this is the first function in the tree hashing stack
            // startPos and endPos are checked by the caller!!!!

            array<UInt64>^ transport = gcnew array<UInt64>(state->Length);
            array<UInt64>^ tweak = gcnew array<UInt64>(2);
			tweak[0] = 0;
			tweak[1] = SKEIN_FLAG_FIRST + SKEIN_TYPE_MSG + SKEIN_TREELEVEL_MULTIPLIER;

            int stateByteWidth = state->Length * sizeof(UInt64);
            int blockWidth = endPos - startPos;

            for (int i = 0; (i * stateByteWidth) < blockWidth || (i == 0 && blockWidth == 0); i++)
            {
                //process a block  
                int currentPosition = i * stateByteWidth;
                tweak[0] = (UInt64)(currentPosition + startPos);
                if (currentPosition + stateByteWidth >= blockWidth)
                {
					Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
                    tweak[0] = (UInt64)endPos;

                    tweak[1] += SKEIN_FLAG_FINAL;
                    if (lastByteBitCount > 0)
                    {
                        tweak[1] += SKEIN_FLAG_PAD;
                        Buffer::BlockCopy(data, currentPosition + startPos, transport, 0, (blockWidth - currentPosition) - 1);
                        Byte newLastByte = data[blockWidth + startPos - 1];
                        newLastByte &= (Byte)(0xFF << (8 - lastByteBitCount));
                        newLastByte += (Byte)(Math::Pow(2, (7 - lastByteBitCount)));
                        int newLastBytePosition = (blockWidth - 1 + Buffer::ByteLength(transport)) % Buffer::ByteLength(transport);

                        Buffer::SetByte(transport, newLastBytePosition, newLastByte);
                    }
                    else
                        Buffer::BlockCopy(data, currentPosition + startPos, transport, 0, blockWidth - currentPosition);

                }
                else
                {
                    tweak[0] += (UInt64)stateByteWidth;
                    Buffer::BlockCopy(data, currentPosition + startPos, transport, 0, stateByteWidth);
                }
                //now transform
                switch (state->Length)
                {
					case 4: ThreeFishCore::Process256(transport, state, tweak, true, state); break;
					case 8: ThreeFishCore::Process512(transport, state, tweak, true, state); break;
					case 16: ThreeFishCore::Process1024(transport, state, tweak, true, state); break;
				}
                tweak[1] &= ~SKEIN_FLAG_FIRST;
            }
			Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
			Skein::SkeinCore::ClearQWords(&tweak[0], tweak->Length);
            //TODO:  When this becomes a threaded function, do the callback magic here with "state"
            return;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="state"></param>
        /// <param name="data"></param>
        /// <param name="level"></param>
        /// <param name="lengthOffset"></param>
        static void ProcessTreeNode(array<UInt64>^ state, array<UInt64>^ data, unsigned int level, UInt64 lengthOffset)
        {
            array<UInt64>^ transport = gcnew array<UInt64>(state->Length);
            array<UInt64>^ tweak = gcnew array<UInt64>(2);
			tweak[0] = lengthOffset;
			tweak[1] = SKEIN_FLAG_FIRST + SKEIN_TYPE_MSG + (SKEIN_TREELEVEL_MULTIPLIER * level);

            int stateByteWidth = Buffer::ByteLength(state);
            int dataByteWidth = Buffer::ByteLength(data);

            for (int i = 0; i * stateByteWidth < dataByteWidth; i++)
            {
                //process a block  
                tweak[0] += (UInt64)stateByteWidth;
                if (((i + 1) * stateByteWidth) >= dataByteWidth)
                    tweak[1] += SKEIN_FLAG_FINAL;
                Buffer::BlockCopy(data, i * stateByteWidth, transport, 0, stateByteWidth);
                //now transform
                //SkeinDebug.WriteData2File(ref tweak, "debug", "ProcessTreeNodeTWEAK, lengthOffset=" + lengthOffset.ToString() + " i=" + i.ToString(),
                //    "The transport of the node being processed at i=" + i.ToString());
                //SkeinDebug.WriteData2File(ref state, "debug", "ProcessTreeNodeSTATE, lengthOffset=" + lengthOffset.ToString() + " i=" + i.ToString(),
                //    "The transport of the node being processed at i=" + i.ToString());
                switch (state->Length)
                {
					case 4: ThreeFishCore::Process256(transport, state, tweak, true, state); break;
					case 8: ThreeFishCore::Process512(transport, state, tweak, true, state); break;
					case 16: ThreeFishCore::Process1024(transport, state, tweak, true, state); break;
                }
                tweak[1] &= ~SKEIN_FLAG_FIRST;
            }
			Skein::SkeinCore::ClearQWords(&transport[0], transport->Length);
			Skein::SkeinCore::ClearQWords(&tweak[0], tweak->Length);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="state"></param>
        /// <param name="data"></param>
        /// <param name="lastByteBitCount"></param>
        /// <param name="treeLeaf"></param>
        /// <param name="treeNode"></param>
        /// <param name="treeMaxLevels"></param>
        static void ProcessMessage(array<UInt64>^ state, array<Byte>^ data, Byte lastByteBitCount, Byte treeLeaf, Byte treeNode, Byte treeMaxLevels)
        {
            if (lastByteBitCount > 7)
                throw gcnew ArgumentOutOfRangeException("lastByteBitCount", "ProcessMessage:  the last byte count cannot exceed 7 bits. " +
                    "If the last byte is complete (no padding), pass zero.");
            if (treeMaxLevels < 2 && treeLeaf > 0 && treeNode > 0)
                throw gcnew ArgumentOutOfRangeException("treeMaxLevels", "ProcessMessage:  treeMaxLevels must be greater than 1 when doing tree hashing.");
            //SkeinDebug.WriteData2File(ref state, "debug", "statePREPROCESS", "This is the state BEFORE ANYTHING IS DONE TO THE MESSAGE!");
            array<UInt64>^ stateTemp;
            int stateByteSize = Buffer::ByteLength(state);
            int leafQWordSize = (int)Math::Pow(2, treeLeaf);
            int leafByteSize = leafQWordSize * stateByteSize;
            int level1NodeCount = (int)Math::Ceiling((double)data->Length / leafByteSize);

            int startingPosition = 0;
            int endingPosition = 0;

            //do leaves of level 1 first straight through
            array<UInt64>^ leaves = gcnew array<UInt64>(level1NodeCount * state->Length);
            for (int i = 0; i < level1NodeCount; i++)
            {
                startingPosition = i * leafByteSize;
                if (startingPosition + leafByteSize >= data->Length) // near the end?
                    endingPosition = startingPosition + (data->Length - startingPosition);  // yes
                else
                    endingPosition = startingPosition + leafByteSize;  // no, in the middle or end block exact size
                stateTemp = (array<UInt64>^)state->Clone();
                //TODO:  Make this a thread call!            
                ProcessTreeLeaf(stateTemp, data, startingPosition, endingPosition, (Byte)(i == level1NodeCount - 1 ? lastByteBitCount : 0));
                Buffer::BlockCopy(stateTemp, 0, leaves, stateByteSize * i, stateByteSize);
                //pump stateTemp into leaves here <================
				Skein::SkeinCore::ClearQWords(&stateTemp[0], stateTemp->Length);

            }
            //TODO:  Join the threads here before moving up the tree
            //SkeinDebug.WriteData2File(ref leaves, "debug", "leavesafterlevelONE", "These are the leaves after LEVEL ONE processing.");
            int currentLevel = 2;
            array<UInt64>^ workingNodes = (array<UInt64>^)leaves->Clone();
			Skein::SkeinCore::ClearQWords(&leaves[0], leaves->Length);
            do
            {
                if (workingNodes->Length == state->Length)
                {
					Skein::SkeinCore::ClearQWords(&state[0], state->Length);
					Buffer::BlockCopy(workingNodes, 0, state, 0, Buffer::ByteLength(stateTemp));
					Skein::SkeinCore::ClearQWords(&workingNodes[0], workingNodes->Length); // clean up memory
                    //SkeinDebug.WriteData2File(ref state,"debug", "leaves.lengthEQstate.length", "This is the state after the last process when the leaves are the correct length from the previous run.");
                    return; // complete!  We only needed one level of tree hashing to accomplish the task!
                }
                else
                {
                    int nodeQWordSize = state->Length * (int)Math::Pow(2, (double)treeNode);
                    int nodeByteCount = nodeQWordSize * sizeof(UInt64);
                    if (currentLevel == treeMaxLevels)
                    {
                        stateTemp = (array<UInt64>^)state->Clone();
                        ProcessTreeNode(stateTemp, workingNodes, (unsigned int)currentLevel, 0);
						Skein::SkeinCore::ClearQWords(&workingNodes[0], workingNodes->Length);
						Skein::SkeinCore::ClearQWords(&state[0], state->Length);
                        Buffer::BlockCopy(stateTemp, 0, state, 0, Buffer::ByteLength(stateTemp));
						Skein::SkeinCore::ClearQWords(&stateTemp[0], stateTemp->Length);
                        //SkeinDebug.WriteData2File(ref state, "debug", "currentLevelEQtreeMaxLevels", "This is the state after the last process when the maxTreeLevels threshold is hit.");
                        return; // complete!  We topped-out on the tree (upper level constraint) 
                    }
                    else
                    {
                        int intPutNodeCount = workingNodes->Length / state->Length;
                        int outPutNodeCount = (int)Math::Ceiling(intPutNodeCount / Math::Pow(2, treeNode));
                        int currentOutPutNode = 0;
                        array<UInt64>^ outPutNodes = gcnew array<UInt64>(outPutNodeCount * state->Length);
                        for (int i = 0; i < workingNodes->Length; i += nodeQWordSize)
                        {
                            stateTemp = (array<UInt64>^)state->Clone();
                            array<UInt64>^ tempNode;
                            if (workingNodes->Length - i >= nodeQWordSize)
                            {   // still working with full nodes
                                tempNode = gcnew array<UInt64>(nodeQWordSize);
                                Buffer::BlockCopy(workingNodes, currentOutPutNode * nodeByteCount, tempNode, 0, nodeByteCount);
                            }
                            else
                            {   // got a node that isn't the full size
                                tempNode = gcnew array<UInt64>(workingNodes->Length - i);
                                Buffer::BlockCopy(workingNodes, currentOutPutNode * nodeByteCount, tempNode, 0, Buffer::ByteLength(tempNode));
                                //throw new Exception("Code Stop Here for Problem in SkeinLib.SkeinCore.ProcessMessage()");
                            }
                            ProcessTreeNode(stateTemp, tempNode, (unsigned int)currentLevel, (UInt64)(currentOutPutNode * nodeByteCount));
                            //SkeinDebug.WriteData2File(ref stateTemp, "debug", "stateTemp", "This is the state after the last process." +
                            //    " currentOutPutNode=" + currentOutPutNode.ToString() + 
                            //    " currentLevel=" + currentLevel.ToString());
                            Buffer::BlockCopy(stateTemp, 0, outPutNodes, stateByteSize * currentOutPutNode++, stateByteSize);
							Skein::SkeinCore::ClearQWords(&stateTemp[0], stateTemp->Length);
							Skein::SkeinCore::ClearQWords(&tempNode[0], tempNode->Length);
                        }
                        workingNodes = (array<UInt64>^)outPutNodes->Clone();
						Skein::SkeinCore::ClearQWords(&outPutNodes[0], outPutNodes->Length);
                    }
                }
            } while (currentLevel++ <= treeMaxLevels);

        }

		private:
        /// <summary>
        /// Check the state of a given instance to be sure that it has been initialized to the correct size.
        /// </summary>
        /// <param name="state">The array to be checked.</param>
        /// <returns>If the state is configured correctly, true, else false.</returns>
        static bool ValidateState(array<UInt64>^ state)
        {
			if (state == nullptr)
				return false;
            if (state->Length == 4 || state->Length == 8 || state->Length == 16)
                return true;
            else
                return false;
        }
	};
};
