// this is included by ThreeFishCore.h
#pragma once
#include "ThreeFishCore.h"
#define MIX(X, Y, N) { *X += *Y; *Y = _rotl64(*Y, N); *Y ^= *X; };
#define INVMIX(X, Y, N) { *Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y; };
namespace Skein
{
	void Skein::ThreeFishCore::Process256(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, bool feed, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(4);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];

		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey4 ^= key[i];	}

		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);
		
		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==256========================================================================================
		//KEYINJECT 0
		buf0 += locKey0;
		buf1 += locKey1 + locTweak0;
		buf2 += locKey2 + locTweak1;
		buf3 += locKey3 + 0;
		//Rounds 0 through 3
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 1
		buf0 += locKey1;
		buf1 += locKey2 + locTweak1;
		buf2 += locKey3 + locTweak2;
		buf3 += locKey4 + 1;
		//Rounds 4 through 7
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 2
		buf0 += locKey2;
		buf1 += locKey3 + locTweak2;
		buf2 += locKey4 + locTweak0;
		buf3 += locKey0 + 2;
		//Rounds 8 through 11
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 3
		buf0 += locKey3;
		buf1 += locKey4 + locTweak0;
		buf2 += locKey0 + locTweak1;
		buf3 += locKey1 + 3;
		//Rounds 12 through 15
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 4
		buf0 += locKey4;
		buf1 += locKey0 + locTweak1;
		buf2 += locKey1 + locTweak2;
		buf3 += locKey2 + 4;
		//Rounds 16 through 19
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 5
		buf0 += locKey0;
		buf1 += locKey1 + locTweak2;
		buf2 += locKey2 + locTweak0;
		buf3 += locKey3 + 5;
		//Rounds 20 through 23
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 6
		buf0 += locKey1;
		buf1 += locKey2 + locTweak0;
		buf2 += locKey3 + locTweak1;
		buf3 += locKey4 + 6;
		//Rounds 24 through 27
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 7
		buf0 += locKey2;
		buf1 += locKey3 + locTweak1;
		buf2 += locKey4 + locTweak2;
		buf3 += locKey0 + 7;
		//Rounds 28 through 31
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 8
		buf0 += locKey3;
		buf1 += locKey4 + locTweak2;
		buf2 += locKey0 + locTweak0;
		buf3 += locKey1 + 8;
		//Rounds 32 through 35
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 9
		buf0 += locKey4;
		buf1 += locKey0 + locTweak0;
		buf2 += locKey1 + locTweak1;
		buf3 += locKey2 + 9;
		//Rounds 36 through 39
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 10
		buf0 += locKey0;
		buf1 += locKey1 + locTweak1;
		buf2 += locKey2 + locTweak2;
		buf3 += locKey3 + 10;
		//Rounds 40 through 43
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 11
		buf0 += locKey1;
		buf1 += locKey2 + locTweak2;
		buf2 += locKey3 + locTweak0;
		buf3 += locKey4 + 11;
		//Rounds 44 through 47
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 12
		buf0 += locKey2;
		buf1 += locKey3 + locTweak0;
		buf2 += locKey4 + locTweak1;
		buf3 += locKey0 + 12;
		//Rounds 48 through 51
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 13
		buf0 += locKey3;
		buf1 += locKey4 + locTweak1;
		buf2 += locKey0 + locTweak2;
		buf3 += locKey1 + 13;
		//Rounds 52 through 55
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 14
		buf0 += locKey4;
		buf1 += locKey0 + locTweak2;
		buf2 += locKey1 + locTweak0;
		buf3 += locKey2 + 14;
		//Rounds 56 through 59
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 15
		buf0 += locKey0;
		buf1 += locKey1 + locTweak0;
		buf2 += locKey2 + locTweak1;
		buf3 += locKey3 + 15;
		//Rounds 60 through 63
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 16
		buf0 += locKey1;
		buf1 += locKey2 + locTweak1;
		buf2 += locKey3 + locTweak2;
		buf3 += locKey4 + 16;
		//Rounds 64 through 67
		MIX(&(buf0), &(buf1), 14);			MIX(&(buf2), &(buf3), 16);
		MIX(&(buf0), &(buf3), 52);			MIX(&(buf2), &(buf1), 57);
		MIX(&(buf0), &(buf1), 23);			MIX(&(buf2), &(buf3), 40);
		MIX(&(buf0), &(buf3), 5);			MIX(&(buf2), &(buf1), 37);
		//KEYINJECT 17
		buf0 += locKey2;
		buf1 += locKey3 + locTweak2;
		buf2 += locKey4 + locTweak0;
		buf3 += locKey0 + 17;
		//Rounds 68 through 71
		MIX(&(buf0), &(buf1), 25);			MIX(&(buf2), &(buf3), 33);
		MIX(&(buf0), &(buf3), 46);			MIX(&(buf2), &(buf1), 12);
		MIX(&(buf0), &(buf1), 58);			MIX(&(buf2), &(buf3), 22);
		MIX(&(buf0), &(buf3), 32);			MIX(&(buf2), &(buf1), 32);
		//KEYINJECT 18
		buf0 += locKey3;
		buf1 += locKey4 + locTweak0;
		buf2 += locKey0 + locTweak1;
		buf3 += locKey1 + 18;
		//==END 256====================================================================================
		// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 

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
		}
		//return result;
	}

	void Skein::ThreeFishCore::InvProcess256(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(4);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];

		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey4 ^= key[i];	}

		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);
		
		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==256========================================================================================
		//KEYINJECT 18
		buf0 -= locKey3;
		buf1 -= (locKey4 + locTweak0);
		buf2 -= (locKey0 + locTweak1);
		buf3 -= (locKey1 + 18);
		//Rounds 72 through 75
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 17
		buf0 -= locKey2;
		buf1 -= (locKey3 + locTweak2);
		buf2 -= (locKey4 + locTweak0);
		buf3 -= (locKey0 + 17);
		//Rounds 68 through 71
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 16
		buf0 -= locKey1;
		buf1 -= (locKey2 + locTweak1);
		buf2 -= (locKey3 + locTweak2);
		buf3 -= (locKey4 + 16);
		//Rounds 64 through 67
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 15
		buf0 -= locKey0;
		buf1 -= (locKey1 + locTweak0);
		buf2 -= (locKey2 + locTweak1);
		buf3 -= (locKey3 + 15);
		//Rounds 60 through 63
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 14
		buf0 -= locKey4;
		buf1 -= (locKey0 + locTweak2);
		buf2 -= (locKey1 + locTweak0);
		buf3 -= (locKey2 + 14);
		//Rounds 56 through 59
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 13
		buf0 -= locKey3;
		buf1 -= (locKey4 + locTweak1);
		buf2 -= (locKey0 + locTweak2);
		buf3 -= (locKey1 + 13);
		//Rounds 52 through 55
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 12
		buf0 -= locKey2;
		buf1 -= (locKey3 + locTweak0);
		buf2 -= (locKey4 + locTweak1);
		buf3 -= (locKey0 + 12);
		//Rounds 48 through 51
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 11
		buf0 -= locKey1;
		buf1 -= (locKey2 + locTweak2);
		buf2 -= (locKey3 + locTweak0);
		buf3 -= (locKey4 + 11);
		//Rounds 44 through 47
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 10
		buf0 -= locKey0;
		buf1 -= (locKey1 + locTweak1);
		buf2 -= (locKey2 + locTweak2);
		buf3 -= (locKey3 + 10);
		//Rounds 40 through 43
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 9
		buf0 -= locKey4;
		buf1 -= (locKey0 + locTweak0);
		buf2 -= (locKey1 + locTweak1);
		buf3 -= (locKey2 + 9);
		//Rounds 36 through 39
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 8
		buf0 -= locKey3;
		buf1 -= (locKey4 + locTweak2);
		buf2 -= (locKey0 + locTweak0);
		buf3 -= (locKey1 + 8);
		//Rounds 32 through 35
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 7
		buf0 -= locKey2;
		buf1 -= (locKey3 + locTweak1);
		buf2 -= (locKey4 + locTweak2);
		buf3 -= (locKey0 + 7);
		//Rounds 28 through 31
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 6
		buf0 -= locKey1;
		buf1 -= (locKey2 + locTweak0);
		buf2 -= (locKey3 + locTweak1);
		buf3 -= (locKey4 + 6);
		//Rounds 24 through 27
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 5
		buf0 -= locKey0;
		buf1 -= (locKey1 + locTweak2);
		buf2 -= (locKey2 + locTweak0);
		buf3 -= (locKey3 + 5);
		//Rounds 20 through 23
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 4
		buf0 -= locKey4;
		buf1 -= (locKey0 + locTweak1);
		buf2 -= (locKey1 + locTweak2);
		buf3 -= (locKey2 + 4);
		//Rounds 16 through 19
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 3
		buf0 -= locKey3;
		buf1 -= (locKey4 + locTweak0);
		buf2 -= (locKey0 + locTweak1);
		buf3 -= (locKey1 + 3);
		//Rounds 12 through 15
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 2
		buf0 -= locKey2;
		buf1 -= (locKey3 + locTweak2);
		buf2 -= (locKey4 + locTweak0);
		buf3 -= (locKey0 + 2);
		//Rounds 8 through 11
		INVMIX(&(buf0), &(buf3), 32);			INVMIX(&(buf2), &(buf1), 32);
		INVMIX(&(buf0), &(buf1), 58);			INVMIX(&(buf2), &(buf3), 22);
		INVMIX(&(buf0), &(buf3), 46);			INVMIX(&(buf2), &(buf1), 12);
		INVMIX(&(buf0), &(buf1), 25);			INVMIX(&(buf2), &(buf3), 33);
		//KEYINJECT 1
		buf0 -= locKey1;
		buf1 -= (locKey2 + locTweak1);
		buf2 -= (locKey3 + locTweak2);
		buf3 -= (locKey4 + 1);
		//Rounds 4 through 7
		INVMIX(&(buf0), &(buf3), 5);			INVMIX(&(buf2), &(buf1), 37);
		INVMIX(&(buf0), &(buf1), 23);			INVMIX(&(buf2), &(buf3), 40);
		INVMIX(&(buf0), &(buf3), 52);			INVMIX(&(buf2), &(buf1), 57);
		INVMIX(&(buf0), &(buf1), 14);			INVMIX(&(buf2), &(buf3), 16);
		//KEYINJECT 0
		buf0 -= locKey0;
		buf1 -= (locKey1 + locTweak0);
		buf2 -= (locKey2 + locTweak1);
		buf3 -= (locKey3 + 0);
		//==END 256====================================================================================
		// *** END OF GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
	
		result[0] = buf0;
		buf0 ^= result[0];
		result[1] = buf1;
		buf1 ^= result[1];
		result[2] = buf2;
		buf2 ^= result[2];
		result[3] = buf3;
		buf3 ^= result[3];

		//return result;
	}
}