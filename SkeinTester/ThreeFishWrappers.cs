using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Skein;
namespace SkeinTester
{
    public static class ThreeFishWrappers
    {
        public static byte[] ThreeFish256Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return ThreeFishBytes(4, data, key, tweak);
        }

        public static byte[] ThreeFish512Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return ThreeFishBytes(8, data, key, tweak);
        }

        public static byte[] ThreeFish1024Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return ThreeFishBytes(16, data, key, tweak);
        }

        public static byte[] InvThreeFish256Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return InvThreeFishBytes(4, data, key, tweak);
        }

        public static byte[] InvThreeFish512Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return InvThreeFishBytes(8, data, key, tweak);
        }

        public static byte[] InvThreeFish1024Bytes(byte[] data, byte[] key, byte[] tweak = null)
        {
            return InvThreeFishBytes(16, data, key, tweak);
        }

        /// <summary>
        /// Run the ThreeFish transform on a block of bytes of arbitrarty length.
        /// Padding is always applied using System.Security.Cryptography.PaddingMode.ANSIX923 mode.
        /// </summary>
        /// <param name="data">The data to be transformed.  Cannot be null or empty.</param>
        /// <param name="key">The key byte array against which to transform the data.  Cannot be null and must be length 32.</param>
        /// <param name="tweak">[OPTIONAL] The tweak used during the ThreeFish transform.  Must be of length less than/equal to 16 bytes.  Default = Null (no tweak)</param>
        /// <returns>The resulting transformed data in a byte array.  The length of the resulting array will be longer than the input array.</returns>
        static byte[] ThreeFishBytes(int wordwidth, byte[] data, byte[] key, byte[] tweak = null)
        {
            int BYTEWIDTH = wordwidth * 8;
            if (data == null || data.Length < 1)
                throw new ArgumentNullException("data", "data MUST be at least length 1 and not null");
            if (key == null || key.Length != BYTEWIDTH)
                throw new ArgumentException("key MUST be length " + BYTEWIDTH.ToString() + " and not null", "key");
            if (tweak != null && tweak.Length > 16)
                throw new ArgumentException("tweak MUST not exceed length 16", "tweak");

            int totalBlocks = (int)Math.Ceiling((double)data.Length / BYTEWIDTH);
            byte paddingLength = (byte)(BYTEWIDTH - (data.Length % BYTEWIDTH));
            if (paddingLength == 0 || paddingLength == BYTEWIDTH)
            {
                totalBlocks++;
                paddingLength = (byte)BYTEWIDTH;
            }
            byte[] localLastData = new byte[BYTEWIDTH];
            if (totalBlocks == 1)
                Buffer.BlockCopy(data, 0, localLastData, 0, data.Length);
            else
                if (data.Length % BYTEWIDTH != 0)
                Buffer.BlockCopy(data, (totalBlocks - 1) * BYTEWIDTH, localLastData, 0, data.Length % BYTEWIDTH);
            localLastData[localLastData.GetUpperBound(0)] = paddingLength;

            UInt64[] localKey = new UInt64[wordwidth];
            Buffer.BlockCopy(key, 0, localKey, 0, key.Length);
            UInt64[] localTweak = new UInt64[] { 0, 0 };
            if (tweak != null)
                Buffer.BlockCopy(tweak, 0, localTweak, 0, tweak.Length);
            byte[] finalResult = new byte[totalBlocks * BYTEWIDTH];
            UInt64[] tempData = new UInt64[wordwidth];
            for (int block = 0; block < totalBlocks; block++)
            {
                if (block + 1 == totalBlocks)
                    Buffer.BlockCopy(localLastData, 0, tempData, 0, BYTEWIDTH);
                else
                    Buffer.BlockCopy(data, block * BYTEWIDTH, tempData, 0, BYTEWIDTH);
                Skein.ThreeFishCore.Process256(tempData, localKey, localTweak, false, tempData);
                Buffer.BlockCopy(tempData, 0, finalResult, block * BYTEWIDTH, BYTEWIDTH);
            }
            SkeinCore.ClearQWords(ref tempData[0], tempData.Length);
            SkeinCore.ClearBytes(ref localLastData[0], localLastData.Length);
            SkeinCore.ClearQWords(ref localKey[0], localKey.Length);
            SkeinCore.ClearQWords(ref localTweak[0], localTweak.Length);
            //System.GC.Collect();
            return finalResult;
        }

        /// <summary>
        /// Run the Inverse ThreeFish transform on a block of bytes, recovering the original length.
        /// Padding assumed to be always applied using System.Security.Cryptography.PaddingMode.ANSIX923 mode.
        /// </summary>
        /// <param name="data">The data to be untransformed.  Cannot be null or empty.  Must be length which is a multiple of 32.</param>
        /// <param name="key">The key byte array against which the data was originally transformed.  Cannot be null and must be length 32.</param>
        /// <param name="tweak">[OPTIONAL] The tweak used during the original ThreeFish transform.  Must be of length less than/equal to 16 bytes.  Default = Null (no tweak)</param>
        /// <returns>The resulting transformed data in a byte array.  The length of the resulting array will be shorter than the input array.</returns>
        static byte[] InvThreeFishBytes(int wordwidth, byte[] data, byte[] key, byte[] tweak = null)
        {
            int BYTEWIDTH = wordwidth * 8;
            if (data == null || data.Length % BYTEWIDTH != 0 || data.Length == 0)
                throw new ArgumentNullException("data", "InvThreeFish256Bytes:  data MUST be at a length which is a multiple of " +
                    BYTEWIDTH.ToString() + " and not null or empty");
            if (key == null || key.Length != BYTEWIDTH)
                throw new ArgumentException("key MUST be length " + BYTEWIDTH.ToString() + " and not null", "key");
            if (tweak != null && tweak.Length > 16)
                throw new ArgumentException("tweak MUST not exceed length 16", "tweak");

            int totalBlocks = data.Length / BYTEWIDTH;

            UInt64[] localKey = new UInt64[wordwidth];
            Buffer.BlockCopy(key, 0, localKey, 0, key.Length);
            UInt64[] localTweak = new UInt64[] { 0, 0 };
            if (tweak != null)
                Buffer.BlockCopy(tweak, 0, localTweak, 0, tweak.Length);
            byte[] interimResult = new byte[Buffer.ByteLength(data)];
            UInt64[] tempData = new UInt64[wordwidth];
            for (int block = 0; block < totalBlocks; block++)
            {
                Buffer.BlockCopy(data, block * BYTEWIDTH, tempData, 0, BYTEWIDTH);
                //InvThreeFish256Internal(tempData, localKey, localTweak, ref tempData);
                ThreeFishCore.InvProcess256(tempData, localKey, localTweak, tempData);
                Buffer.BlockCopy(tempData, 0, interimResult, block * BYTEWIDTH, BYTEWIDTH);
            }
            SkeinCore.ClearQWords(ref tempData[0], tempData.Length);
            SkeinCore.ClearQWords(ref localKey[0], localKey.Length);
            SkeinCore.ClearQWords(ref localTweak[0], localTweak.Length);

            // not going to do any error checking (besides the obvious) that could give away information.
            byte finalPaddingLength = interimResult[interimResult.GetUpperBound(0)];
            byte[] finalResult = new byte[data.Length - finalPaddingLength];
            Buffer.BlockCopy(interimResult, 0, finalResult, 0, finalResult.Length);
            SkeinCore.ClearBytes(ref interimResult[0], interimResult.Length);
            //System.GC.Collect();
            return finalResult;
        }
    }
}
