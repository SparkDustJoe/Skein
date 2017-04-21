#pragma once

	/// <summary>
	/// Zero out an array of 64-bit unsigned words in a secure manner.
	/// This function prevents optimization from removing the zeroizing of memory arrays.
	/// This has been tested in x86 and x64, the JIT compiler will remove .Initialize calls
	/// in the interest of performance, this function prevents that.
	/// WARNING! Will cross referencial boundries and Zero out arrays that may be referenced in multiple places to the same memory space! Use with caution!
	/// </summary>
	/// <param name="inWords">Array to be zeroed out.</param>
	static void Skein::SkeinCore::ClearQWords(interior_ptr<UInt64>inWords, int length)
	{
		if (inWords == nullptr)
			return;
		for (int i = 0; i < length; i++)
		{
			// CRUCIAL!!!!
			// this extra stuff is to prevent the compiler from optimizing these steps out (tested and confirmed!)
			// this also helps to secure memory when disposing arrays.

			//old way
			//inWords[i] = 0;
			//inWords[i] |= 0xFFFFFFFFFFFFFFFF;
			//inWords[i] ^= inWords[i];

			//new way
			*(inWords + i) = 0xFFFFFFFFFFFFFFFF;
			*(inWords + i) = *(inWords + i) ^ 0xFFFFFFFFFFFFFFFF;
		}
		//if (nullify)
		//{
		//	???????
		//}
	}

	/// <summary>
	/// Zero out an array of bytes in a secure manner.
	/// This function prevents optimization from removing the zeroizing of memory arrays.
	/// This has been tested in x86 and x64, the JIT compiler will remove .Initialize calls
	/// in the interest of performance, this function prevents that.
	/// WARNING! Will cross referencial boundries and Zero out arrays that may be referenced in multiple places to the same memory space! Use with caution!
	/// </summary>
	/// <param name="inBytes">Array to be zeroed out.</param>
	static void Skein::SkeinCore::ClearBytes(interior_ptr<Byte> inBytes, int length)
	{
		if (inBytes == nullptr)
			return;
		for (int i = 0; i < length; i++)
		{
			// CRUCIAL!!!!
			// this extra stuff is to prevent the compiler from optimizing these steps out (tested and confirmed!)
			// this also helps to secure memory when disposing arrays.

			//old way
			//inBytes[i] = 0;
			//inBytes[i] |= 0xFF;
			//inBytes[i] ^= inBytes[i];

			// new way
			*(inBytes + i) = 0xFF;
			*(inBytes + i) ^= *(inBytes + i);
		}
		//if (nullify)
		//{
		//	??????
		//}
	}
