// this is included by ThreeFishCore.h
#pragma once
#include "ThreeFishCore.h"
#define MIX(X, Y, N) { *X += *Y; *Y = _rotl64(*Y, N); *Y ^= *X; };
#define INVMIX(X, Y, N) { *Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y; };
namespace Skein
{
	void Skein::ThreeFishCore::Process512(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, bool feed, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(8);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];
		UInt64 buf4 = input[4];		UInt64 buf5 = input[5];		UInt64 buf6 = input[6];		UInt64 buf7 = input[7];

		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = key[4];	UInt64 locKey5 = key[5];	UInt64 locKey6 = key[6];	UInt64 locKey7 = key[7];
		UInt64 locKey8 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey8 ^= key[i];	}

		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);

		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==512========================================================================================
		//KEYINJECT 0
		buf0 += locKey0;
		buf1 += locKey1;
		buf2 += locKey2;
		buf3 += locKey3;
		buf4 += locKey4;
		buf5 += locKey5 + locTweak0;
		buf6 += locKey6 + locTweak1;
		buf7 += locKey7 + 0;
		//Rounds 0 through 3
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 1
		buf0 += locKey1;
		buf1 += locKey2;
		buf2 += locKey3;
		buf3 += locKey4;
		buf4 += locKey5;
		buf5 += locKey6 + locTweak1;
		buf6 += locKey7 + locTweak2;
		buf7 += locKey8 + 1;
		//Rounds 4 through 7
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 2
		buf0 += locKey2;
		buf1 += locKey3;
		buf2 += locKey4;
		buf3 += locKey5;
		buf4 += locKey6;
		buf5 += locKey7 + locTweak2;
		buf6 += locKey8 + locTweak0;
		buf7 += locKey0 + 2;
		//Rounds 8 through 11
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 3
		buf0 += locKey3;
		buf1 += locKey4;
		buf2 += locKey5;
		buf3 += locKey6;
		buf4 += locKey7;
		buf5 += locKey8 + locTweak0;
		buf6 += locKey0 + locTweak1;
		buf7 += locKey1 + 3;
		//Rounds 12 through 15
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 4
		buf0 += locKey4;
		buf1 += locKey5;
		buf2 += locKey6;
		buf3 += locKey7;
		buf4 += locKey8;
		buf5 += locKey0 + locTweak1;
		buf6 += locKey1 + locTweak2;
		buf7 += locKey2 + 4;
		//Rounds 16 through 19
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 5
		buf0 += locKey5;
		buf1 += locKey6;
		buf2 += locKey7;
		buf3 += locKey8;
		buf4 += locKey0;
		buf5 += locKey1 + locTweak2;
		buf6 += locKey2 + locTweak0;
		buf7 += locKey3 + 5;
		//Rounds 20 through 23
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 6
		buf0 += locKey6;
		buf1 += locKey7;
		buf2 += locKey8;
		buf3 += locKey0;
		buf4 += locKey1;
		buf5 += locKey2 + locTweak0;
		buf6 += locKey3 + locTweak1;
		buf7 += locKey4 + 6;
		//Rounds 24 through 27
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 7
		buf0 += locKey7;
		buf1 += locKey8;
		buf2 += locKey0;
		buf3 += locKey1;
		buf4 += locKey2;
		buf5 += locKey3 + locTweak1;
		buf6 += locKey4 + locTweak2;
		buf7 += locKey5 + 7;
		//Rounds 28 through 31
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 8
		buf0 += locKey8;
		buf1 += locKey0;
		buf2 += locKey1;
		buf3 += locKey2;
		buf4 += locKey3;
		buf5 += locKey4 + locTweak2;
		buf6 += locKey5 + locTweak0;
		buf7 += locKey6 + 8;
		//Rounds 32 through 35
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 9
		buf0 += locKey0;
		buf1 += locKey1;
		buf2 += locKey2;
		buf3 += locKey3;
		buf4 += locKey4;
		buf5 += locKey5 + locTweak0;
		buf6 += locKey6 + locTweak1;
		buf7 += locKey7 + 9;
		//Rounds 36 through 39
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 10
		buf0 += locKey1;
		buf1 += locKey2;
		buf2 += locKey3;
		buf3 += locKey4;
		buf4 += locKey5;
		buf5 += locKey6 + locTweak1;
		buf6 += locKey7 + locTweak2;
		buf7 += locKey8 + 10;
		//Rounds 40 through 43
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 11
		buf0 += locKey2;
		buf1 += locKey3;
		buf2 += locKey4;
		buf3 += locKey5;
		buf4 += locKey6;
		buf5 += locKey7 + locTweak2;
		buf6 += locKey8 + locTweak0;
		buf7 += locKey0 + 11;
		//Rounds 44 through 47
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 12
		buf0 += locKey3;
		buf1 += locKey4;
		buf2 += locKey5;
		buf3 += locKey6;
		buf4 += locKey7;
		buf5 += locKey8 + locTweak0;
		buf6 += locKey0 + locTweak1;
		buf7 += locKey1 + 12;
		//Rounds 48 through 51
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 13
		buf0 += locKey4;
		buf1 += locKey5;
		buf2 += locKey6;
		buf3 += locKey7;
		buf4 += locKey8;
		buf5 += locKey0 + locTweak1;
		buf6 += locKey1 + locTweak2;
		buf7 += locKey2 + 13;
		//Rounds 52 through 55
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 14
		buf0 += locKey5;
		buf1 += locKey6;
		buf2 += locKey7;
		buf3 += locKey8;
		buf4 += locKey0;
		buf5 += locKey1 + locTweak2;
		buf6 += locKey2 + locTweak0;
		buf7 += locKey3 + 14;
		//Rounds 56 through 59
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 15
		buf0 += locKey6;
		buf1 += locKey7;
		buf2 += locKey8;
		buf3 += locKey0;
		buf4 += locKey1;
		buf5 += locKey2 + locTweak0;
		buf6 += locKey3 + locTweak1;
		buf7 += locKey4 + 15;
		//Rounds 60 through 63
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 16
		buf0 += locKey7;
		buf1 += locKey8;
		buf2 += locKey0;
		buf3 += locKey1;
		buf4 += locKey2;
		buf5 += locKey3 + locTweak1;
		buf6 += locKey4 + locTweak2;
		buf7 += locKey5 + 16;
		//Rounds 64 through 67
		MIX(&(buf0), &(buf1), 46);			MIX(&(buf2), &(buf3), 36);			MIX(&(buf4), &(buf5), 19);			MIX(&(buf6), &(buf7), 37);
		MIX(&(buf2), &(buf1), 33);			MIX(&(buf4), &(buf7), 27);			MIX(&(buf6), &(buf5), 14);			MIX(&(buf0), &(buf3), 42);
		MIX(&(buf4), &(buf1), 17);			MIX(&(buf6), &(buf3), 49);			MIX(&(buf0), &(buf5), 36);			MIX(&(buf2), &(buf7), 39);
		MIX(&(buf6), &(buf1), 44);			MIX(&(buf0), &(buf7), 9);			MIX(&(buf2), &(buf5), 54);			MIX(&(buf4), &(buf3), 56);
		//KEYINJECT 17
		buf0 += locKey8;
		buf1 += locKey0;
		buf2 += locKey1;
		buf3 += locKey2;
		buf4 += locKey3;
		buf5 += locKey4 + locTweak2;
		buf6 += locKey5 + locTweak0;
		buf7 += locKey6 + 17;
		//Rounds 68 through 71
		MIX(&(buf0), &(buf1), 39);			MIX(&(buf2), &(buf3), 30);			MIX(&(buf4), &(buf5), 34);			MIX(&(buf6), &(buf7), 24);
		MIX(&(buf2), &(buf1), 13);			MIX(&(buf4), &(buf7), 50);			MIX(&(buf6), &(buf5), 10);			MIX(&(buf0), &(buf3), 17);
		MIX(&(buf4), &(buf1), 25);			MIX(&(buf6), &(buf3), 29);			MIX(&(buf0), &(buf5), 39);			MIX(&(buf2), &(buf7), 43);
		MIX(&(buf6), &(buf1), 8);			MIX(&(buf0), &(buf7), 35);			MIX(&(buf2), &(buf5), 56);			MIX(&(buf4), &(buf3), 22);
		//KEYINJECT 18
		buf0 += locKey0;
		buf1 += locKey1;
		buf2 += locKey2;
		buf3 += locKey3;
		buf4 += locKey4;
		buf5 += locKey5 + locTweak0;
		buf6 += locKey6 + locTweak1;
		buf7 += locKey7 + 18;
		//==END 512====================================================================================
		// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 

		// Assignments to the bufX variables after storing them in result[X] are to zero the memory by essentially
		// XORing them with themselves.  This (hopefully) prevents the compiler from optimizing the zeroing
		// of the buffer variables out of the compiled code.  This zeroing is optional but prevents leaks.
		
		if (feed)
		{
			result[0] = buf0 ^ input[0];
			buf0 ^= result[0] ^ input[0];
			result[1] = buf1 ^ input[1];
			buf1 ^= result[1] ^ input[1];
			result[2] = buf2 ^ input[2];
			buf2 ^= result[2] ^ input[2];
			result[3] = buf3 ^ input[3];
			buf3 ^= result[3] ^ input[3];
			result[4] = buf4 ^ input[4];
			buf4 ^= result[4] ^ input[4];
			result[5] = buf5 ^ input[5];
			buf5 ^= result[5] ^ input[5];
			result[6] = buf6 ^ input[6];
			buf6 ^= result[6] ^ input[6];
			result[7] = buf7 ^ input[7];
			buf7 ^= result[7] ^ input[7];
		}
		else
		{
			result[0] = buf0;
			buf0 ^= result[0];
			result[1] = buf1;
			buf1 ^= result[1];
			result[2] = buf2;
			buf2 ^= result[2];
			result[3] = buf3;
			buf3 ^= result[3];
			result[4] = buf4;
			buf4 ^= result[4];
			result[5] = buf5;
			buf5 ^= result[5];
			result[6] = buf6;
			buf6 ^= result[6];
			result[7] = buf7;
			buf7 ^= result[7];
		}

		//return result;
	}

	void Skein::ThreeFishCore::InvProcess512(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(8);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];
		UInt64 buf4 = input[4];		UInt64 buf5 = input[5];		UInt64 buf6 = input[6];		UInt64 buf7 = input[7];
				
		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = key[4];	UInt64 locKey5 = key[5];	UInt64 locKey6 = key[6];	UInt64 locKey7 = key[7];
		UInt64 locKey8 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey8 ^= key[i];	}
		
		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);

		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==512========================================================================================
		//KEYINJECT 18
		buf0 -= locKey0;
		buf1 -= locKey1;
		buf2 -= locKey2;
		buf3 -= locKey3;
		buf4 -= locKey4;
		buf5 -= (locKey5 + locTweak0);
		buf6 -= (locKey6 + locTweak1);
		buf7 -= (locKey7 + 18);
		//Rounds 71 through 68
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 17
		buf0 -= locKey8;
		buf1 -= locKey0;
		buf2 -= locKey1;
		buf3 -= locKey2;
		buf4 -= locKey3;
		buf5 -= (locKey4 + locTweak2);
		buf6 -= (locKey5 + locTweak0);
		buf7 -= (locKey6 + 17);
		//Rounds 67 through 64
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 16
		buf0 -= locKey7;
		buf1 -= locKey8;
		buf2 -= locKey0;
		buf3 -= locKey1;
		buf4 -= locKey2;
		buf5 -= (locKey3 + locTweak1);
		buf6 -= (locKey4 + locTweak2);
		buf7 -= (locKey5 + 16);
		//Rounds 63 through 60
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 15
		buf0 -= locKey6;
		buf1 -= locKey7;
		buf2 -= locKey8;
		buf3 -= locKey0;
		buf4 -= locKey1;
		buf5 -= (locKey2 + locTweak0);
		buf6 -= (locKey3 + locTweak1);
		buf7 -= (locKey4 + 15);
		//Rounds 59 through 56
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 14
		buf0 -= locKey5;
		buf1 -= locKey6;
		buf2 -= locKey7;
		buf3 -= locKey8;
		buf4 -= locKey0;
		buf5 -= (locKey1 + locTweak2);
		buf6 -= (locKey2 + locTweak0);
		buf7 -= (locKey3 + 14);
		//Rounds 55 through 52
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 13
		buf0 -= locKey4;
		buf1 -= locKey5;
		buf2 -= locKey6;
		buf3 -= locKey7;
		buf4 -= locKey8;
		buf5 -= (locKey0 + locTweak1);
		buf6 -= (locKey1 + locTweak2);
		buf7 -= (locKey2 + 13);
		//Rounds 51 through 48
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 12
		buf0 -= locKey3;
		buf1 -= locKey4;
		buf2 -= locKey5;
		buf3 -= locKey6;
		buf4 -= locKey7;
		buf5 -= (locKey8 + locTweak0);
		buf6 -= (locKey0 + locTweak1);
		buf7 -= (locKey1 + 12);
		//Rounds 47 through 44
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 11
		buf0 -= locKey2;
		buf1 -= locKey3;
		buf2 -= locKey4;
		buf3 -= locKey5;
		buf4 -= locKey6;
		buf5 -= (locKey7 + locTweak2);
		buf6 -= (locKey8 + locTweak0);
		buf7 -= (locKey0 + 11);
		//Rounds 43 through 40
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 10
		buf0 -= locKey1;
		buf1 -= locKey2;
		buf2 -= locKey3;
		buf3 -= locKey4;
		buf4 -= locKey5;
		buf5 -= (locKey6 + locTweak1);
		buf6 -= (locKey7 + locTweak2);
		buf7 -= (locKey8 + 10);
		//Rounds 39 through 36
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 9
		buf0 -= locKey0;
		buf1 -= locKey1;
		buf2 -= locKey2;
		buf3 -= locKey3;
		buf4 -= locKey4;
		buf5 -= (locKey5 + locTweak0);
		buf6 -= (locKey6 + locTweak1);
		buf7 -= (locKey7 + 9);
		//Rounds 35 through 32
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 8
		buf0 -= locKey8;
		buf1 -= locKey0;
		buf2 -= locKey1;
		buf3 -= locKey2;
		buf4 -= locKey3;
		buf5 -= (locKey4 + locTweak2);
		buf6 -= (locKey5 + locTweak0);
		buf7 -= (locKey6 + 8);
		//Rounds 31 through 28
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 7
		buf0 -= locKey7;
		buf1 -= locKey8;
		buf2 -= locKey0;
		buf3 -= locKey1;
		buf4 -= locKey2;
		buf5 -= (locKey3 + locTweak1);
		buf6 -= (locKey4 + locTweak2);
		buf7 -= (locKey5 + 7);
		//Rounds 27 through 24
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 6
		buf0 -= locKey6;
		buf1 -= locKey7;
		buf2 -= locKey8;
		buf3 -= locKey0;
		buf4 -= locKey1;
		buf5 -= (locKey2 + locTweak0);
		buf6 -= (locKey3 + locTweak1);
		buf7 -= (locKey4 + 6);
		//Rounds 23 through 20
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 5
		buf0 -= locKey5;
		buf1 -= locKey6;
		buf2 -= locKey7;
		buf3 -= locKey8;
		buf4 -= locKey0;
		buf5 -= (locKey1 + locTweak2);
		buf6 -= (locKey2 + locTweak0);
		buf7 -= (locKey3 + 5);
		//Rounds 19 through 16
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 4
		buf0 -= locKey4;
		buf1 -= locKey5;
		buf2 -= locKey6;
		buf3 -= locKey7;
		buf4 -= locKey8;
		buf5 -= (locKey0 + locTweak1);
		buf6 -= (locKey1 + locTweak2);
		buf7 -= (locKey2 + 4);
		//Rounds 15 through 12
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 3
		buf0 -= locKey3;
		buf1 -= locKey4;
		buf2 -= locKey5;
		buf3 -= locKey6;
		buf4 -= locKey7;
		buf5 -= (locKey8 + locTweak0);
		buf6 -= (locKey0 + locTweak1);
		buf7 -= (locKey1 + 3);
		//Rounds 11 through 8
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 2
		buf0 -= locKey2;
		buf1 -= locKey3;
		buf2 -= locKey4;
		buf3 -= locKey5;
		buf4 -= locKey6;
		buf5 -= (locKey7 + locTweak2);
		buf6 -= (locKey8 + locTweak0);
		buf7 -= (locKey0 + 2);
		//Rounds 7 through 4
		INVMIX(&(buf6), &(buf1), 8);			INVMIX(&(buf0), &(buf7), 35);			INVMIX(&(buf2), &(buf5), 56);			INVMIX(&(buf4), &(buf3), 22);
		INVMIX(&(buf4), &(buf1), 25);			INVMIX(&(buf6), &(buf3), 29);			INVMIX(&(buf0), &(buf5), 39);			INVMIX(&(buf2), &(buf7), 43);
		INVMIX(&(buf2), &(buf1), 13);			INVMIX(&(buf4), &(buf7), 50);			INVMIX(&(buf6), &(buf5), 10);			INVMIX(&(buf0), &(buf3), 17);
		INVMIX(&(buf0), &(buf1), 39);			INVMIX(&(buf2), &(buf3), 30);			INVMIX(&(buf4), &(buf5), 34);			INVMIX(&(buf6), &(buf7), 24);
		//KEYINJECT 1
		buf0 -= locKey1;
		buf1 -= locKey2;
		buf2 -= locKey3;
		buf3 -= locKey4;
		buf4 -= locKey5;
		buf5 -= (locKey6 + locTweak1);
		buf6 -= (locKey7 + locTweak2);
		buf7 -= (locKey8 + 1);
		//Rounds 3 through 0
		INVMIX(&(buf6), &(buf1), 44);			INVMIX(&(buf0), &(buf7), 9);			INVMIX(&(buf2), &(buf5), 54);			INVMIX(&(buf4), &(buf3), 56);
		INVMIX(&(buf4), &(buf1), 17);			INVMIX(&(buf6), &(buf3), 49);			INVMIX(&(buf0), &(buf5), 36);			INVMIX(&(buf2), &(buf7), 39);
		INVMIX(&(buf2), &(buf1), 33);			INVMIX(&(buf4), &(buf7), 27);			INVMIX(&(buf6), &(buf5), 14);			INVMIX(&(buf0), &(buf3), 42);
		INVMIX(&(buf0), &(buf1), 46);			INVMIX(&(buf2), &(buf3), 36);			INVMIX(&(buf4), &(buf5), 19);			INVMIX(&(buf6), &(buf7), 37);
		//KEYINJECT 0
		buf0 -= locKey0;
		buf1 -= locKey1;
		buf2 -= locKey2;
		buf3 -= locKey3;
		buf4 -= locKey4;
		buf5 -= (locKey5 + locTweak0);
		buf6 -= (locKey6 + locTweak1);
		buf7 -= (locKey7 + 0);
		//==END 512====================================================================================
		// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 

		result[0] = buf0;
		buf0 ^= result[0];
		result[1] = buf1;
		buf1 ^= result[1];
		result[2] = buf2;
		buf2 ^= result[2];
		result[3] = buf3;
		buf3 ^= result[3];
		result[4] = buf4;
		buf4 ^= result[4];
		result[5] = buf5;
		buf5 ^= result[5];
		result[6] = buf6;
		buf6 ^= result[6];
		result[7] = buf7;
		buf7 ^= result[7];

		//return result;
	}
}
