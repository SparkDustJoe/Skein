// this is included by ThreeFishCore.h
#pragma once
#include "ThreeFishCore.h"
#define MIX(X, Y, N) { *X += *Y; *Y = _rotl64(*Y, N); *Y ^= *X; };
#define INVMIX(X, Y, N) { *Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y; };
namespace Skein
{
	void Skein::ThreeFishCore::Process1024(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, bool feed, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(16);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];
		UInt64 buf4 = input[4];		UInt64 buf5 = input[5];		UInt64 buf6 = input[6];		UInt64 buf7 = input[7];
		UInt64 buf8 = input[8];		UInt64 buf9 = input[9];		UInt64 buf10 = input[10];	UInt64 buf11 = input[11];
		UInt64 buf12 = input[12];	UInt64 buf13 = input[13];	UInt64 buf14 = input[14];	UInt64 buf15 = input[15];
				
		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = key[4];	UInt64 locKey5 = key[5];	UInt64 locKey6 = key[6];	UInt64 locKey7 = key[7];
		UInt64 locKey8 = key[8];	UInt64 locKey9 = key[9];	UInt64 locKey10 = key[10];	UInt64 locKey11 = key[11];
		UInt64 locKey12 = key[12];	UInt64 locKey13 = key[13];	UInt64 locKey14 = key[14];	UInt64 locKey15 = key[15];
		UInt64 locKey16 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey16 ^= key[i];	}
		
		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);
		
		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==1024========================================================================================
		//KEYINJECT 0
		buf0 += locKey0;
		buf1 += locKey1;
		buf2 += locKey2;
		buf3 += locKey3;
		buf4 += locKey4;
		buf5 += locKey5;
		buf6 += locKey6;
		buf7 += locKey7;
		buf8 += locKey8;
		buf9 += locKey9;
		buf10 += locKey10;
		buf11 += locKey11;
		buf12 += locKey12;
		buf13 += locKey13 + locTweak0;
		buf14 += locKey14 + locTweak1;
		buf15 += locKey15 + 0;
		//Rounds 0 through 3
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 1
		buf0 += locKey1;
		buf1 += locKey2;
		buf2 += locKey3;
		buf3 += locKey4;
		buf4 += locKey5;
		buf5 += locKey6;
		buf6 += locKey7;
		buf7 += locKey8;
		buf8 += locKey9;
		buf9 += locKey10;
		buf10 += locKey11;
		buf11 += locKey12;
		buf12 += locKey13;
		buf13 += locKey14 + locTweak1;
		buf14 += locKey15 + locTweak2;
		buf15 += locKey16 + 1;
		//Rounds 4 through 7
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 2
		buf0 += locKey2;
		buf1 += locKey3;
		buf2 += locKey4;
		buf3 += locKey5;
		buf4 += locKey6;
		buf5 += locKey7;
		buf6 += locKey8;
		buf7 += locKey9;
		buf8 += locKey10;
		buf9 += locKey11;
		buf10 += locKey12;
		buf11 += locKey13;
		buf12 += locKey14;
		buf13 += locKey15 + locTweak2;
		buf14 += locKey16 + locTweak0;
		buf15 += locKey0 + 2;
		//Rounds 8 through 11
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 3
		buf0 += locKey3;
		buf1 += locKey4;
		buf2 += locKey5;
		buf3 += locKey6;
		buf4 += locKey7;
		buf5 += locKey8;
		buf6 += locKey9;
		buf7 += locKey10;
		buf8 += locKey11;
		buf9 += locKey12;
		buf10 += locKey13;
		buf11 += locKey14;
		buf12 += locKey15;
		buf13 += locKey16 + locTweak0;
		buf14 += locKey0 + locTweak1;
		buf15 += locKey1 + 3;
		//Rounds 12 through 15
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 4
		buf0 += locKey4;
		buf1 += locKey5;
		buf2 += locKey6;
		buf3 += locKey7;
		buf4 += locKey8;
		buf5 += locKey9;
		buf6 += locKey10;
		buf7 += locKey11;
		buf8 += locKey12;
		buf9 += locKey13;
		buf10 += locKey14;
		buf11 += locKey15;
		buf12 += locKey16;
		buf13 += locKey0 + locTweak1;
		buf14 += locKey1 + locTweak2;
		buf15 += locKey2 + 4;
		//Rounds 16 through 19
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 5
		buf0 += locKey5;
		buf1 += locKey6;
		buf2 += locKey7;
		buf3 += locKey8;
		buf4 += locKey9;
		buf5 += locKey10;
		buf6 += locKey11;
		buf7 += locKey12;
		buf8 += locKey13;
		buf9 += locKey14;
		buf10 += locKey15;
		buf11 += locKey16;
		buf12 += locKey0;
		buf13 += locKey1 + locTweak2;
		buf14 += locKey2 + locTweak0;
		buf15 += locKey3 + 5;
		//Rounds 20 through 23
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 6
		buf0 += locKey6;
		buf1 += locKey7;
		buf2 += locKey8;
		buf3 += locKey9;
		buf4 += locKey10;
		buf5 += locKey11;
		buf6 += locKey12;
		buf7 += locKey13;
		buf8 += locKey14;
		buf9 += locKey15;
		buf10 += locKey16;
		buf11 += locKey0;
		buf12 += locKey1;
		buf13 += locKey2 + locTweak0;
		buf14 += locKey3 + locTweak1;
		buf15 += locKey4 + 6;
		//Rounds 24 through 27
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 7
		buf0 += locKey7;
		buf1 += locKey8;
		buf2 += locKey9;
		buf3 += locKey10;
		buf4 += locKey11;
		buf5 += locKey12;
		buf6 += locKey13;
		buf7 += locKey14;
		buf8 += locKey15;
		buf9 += locKey16;
		buf10 += locKey0;
		buf11 += locKey1;
		buf12 += locKey2;
		buf13 += locKey3 + locTweak1;
		buf14 += locKey4 + locTweak2;
		buf15 += locKey5 + 7;
		//Rounds 28 through 31
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 8
		buf0 += locKey8;
		buf1 += locKey9;
		buf2 += locKey10;
		buf3 += locKey11;
		buf4 += locKey12;
		buf5 += locKey13;
		buf6 += locKey14;
		buf7 += locKey15;
		buf8 += locKey16;
		buf9 += locKey0;
		buf10 += locKey1;
		buf11 += locKey2;
		buf12 += locKey3;
		buf13 += locKey4 + locTweak2;
		buf14 += locKey5 + locTweak0;
		buf15 += locKey6 + 8;
		//Rounds 32 through 35
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 9
		buf0 += locKey9;
		buf1 += locKey10;
		buf2 += locKey11;
		buf3 += locKey12;
		buf4 += locKey13;
		buf5 += locKey14;
		buf6 += locKey15;
		buf7 += locKey16;
		buf8 += locKey0;
		buf9 += locKey1;
		buf10 += locKey2;
		buf11 += locKey3;
		buf12 += locKey4;
		buf13 += locKey5 + locTweak0;
		buf14 += locKey6 + locTweak1;
		buf15 += locKey7 + 9;
		//Rounds 36 through 39
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 10
		buf0 += locKey10;
		buf1 += locKey11;
		buf2 += locKey12;
		buf3 += locKey13;
		buf4 += locKey14;
		buf5 += locKey15;
		buf6 += locKey16;
		buf7 += locKey0;
		buf8 += locKey1;
		buf9 += locKey2;
		buf10 += locKey3;
		buf11 += locKey4;
		buf12 += locKey5;
		buf13 += locKey6 + locTweak1;
		buf14 += locKey7 + locTweak2;
		buf15 += locKey8 + 10;
		//Rounds 40 through 43
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 11
		buf0 += locKey11;
		buf1 += locKey12;
		buf2 += locKey13;
		buf3 += locKey14;
		buf4 += locKey15;
		buf5 += locKey16;
		buf6 += locKey0;
		buf7 += locKey1;
		buf8 += locKey2;
		buf9 += locKey3;
		buf10 += locKey4;
		buf11 += locKey5;
		buf12 += locKey6;
		buf13 += locKey7 + locTweak2;
		buf14 += locKey8 + locTweak0;
		buf15 += locKey9 + 11;
		//Rounds 44 through 47
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 12
		buf0 += locKey12;
		buf1 += locKey13;
		buf2 += locKey14;
		buf3 += locKey15;
		buf4 += locKey16;
		buf5 += locKey0;
		buf6 += locKey1;
		buf7 += locKey2;
		buf8 += locKey3;
		buf9 += locKey4;
		buf10 += locKey5;
		buf11 += locKey6;
		buf12 += locKey7;
		buf13 += locKey8 + locTweak0;
		buf14 += locKey9 + locTweak1;
		buf15 += locKey10 + 12;
		//Rounds 48 through 51
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 13
		buf0 += locKey13;
		buf1 += locKey14;
		buf2 += locKey15;
		buf3 += locKey16;
		buf4 += locKey0;
		buf5 += locKey1;
		buf6 += locKey2;
		buf7 += locKey3;
		buf8 += locKey4;
		buf9 += locKey5;
		buf10 += locKey6;
		buf11 += locKey7;
		buf12 += locKey8;
		buf13 += locKey9 + locTweak1;
		buf14 += locKey10 + locTweak2;
		buf15 += locKey11 + 13;
		//Rounds 52 through 55
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 14
		buf0 += locKey14;
		buf1 += locKey15;
		buf2 += locKey16;
		buf3 += locKey0;
		buf4 += locKey1;
		buf5 += locKey2;
		buf6 += locKey3;
		buf7 += locKey4;
		buf8 += locKey5;
		buf9 += locKey6;
		buf10 += locKey7;
		buf11 += locKey8;
		buf12 += locKey9;
		buf13 += locKey10 + locTweak2;
		buf14 += locKey11 + locTweak0;
		buf15 += locKey12 + 14;
		//Rounds 56 through 59
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 15
		buf0 += locKey15;
		buf1 += locKey16;
		buf2 += locKey0;
		buf3 += locKey1;
		buf4 += locKey2;
		buf5 += locKey3;
		buf6 += locKey4;
		buf7 += locKey5;
		buf8 += locKey6;
		buf9 += locKey7;
		buf10 += locKey8;
		buf11 += locKey9;
		buf12 += locKey10;
		buf13 += locKey11 + locTweak0;
		buf14 += locKey12 + locTweak1;
		buf15 += locKey13 + 15;
		//Rounds 60 through 63
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 16
		buf0 += locKey16;
		buf1 += locKey0;
		buf2 += locKey1;
		buf3 += locKey2;
		buf4 += locKey3;
		buf5 += locKey4;
		buf6 += locKey5;
		buf7 += locKey6;
		buf8 += locKey7;
		buf9 += locKey8;
		buf10 += locKey9;
		buf11 += locKey10;
		buf12 += locKey11;
		buf13 += locKey12 + locTweak1;
		buf14 += locKey13 + locTweak2;
		buf15 += locKey14 + 16;
		//Rounds 64 through 67
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 17
		buf0 += locKey0;
		buf1 += locKey1;
		buf2 += locKey2;
		buf3 += locKey3;
		buf4 += locKey4;
		buf5 += locKey5;
		buf6 += locKey6;
		buf7 += locKey7;
		buf8 += locKey8;
		buf9 += locKey9;
		buf10 += locKey10;
		buf11 += locKey11;
		buf12 += locKey12;
		buf13 += locKey13 + locTweak2;
		buf14 += locKey14 + locTweak0;
		buf15 += locKey15 + 17;
		//Rounds 68 through 71
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 18
		buf0 += locKey1;
		buf1 += locKey2;
		buf2 += locKey3;
		buf3 += locKey4;
		buf4 += locKey5;
		buf5 += locKey6;
		buf6 += locKey7;
		buf7 += locKey8;
		buf8 += locKey9;
		buf9 += locKey10;
		buf10 += locKey11;
		buf11 += locKey12;
		buf12 += locKey13;
		buf13 += locKey14 + locTweak0;
		buf14 += locKey15 + locTweak1;
		buf15 += locKey16 + 18;
		//Rounds 72 through 75
		MIX(&buf0, &buf1, 24);	MIX(&buf2, &buf3, 13);	MIX(&buf4, &buf5, 8);	MIX(&buf6, &buf7, 47);
		MIX(&buf8, &buf9, 8);	MIX(&buf10, &buf11, 17);	MIX(&buf12, &buf13, 22);	MIX(&buf14, &buf15, 37);
		//===
		MIX(&buf0, &buf9, 38);	MIX(&buf2, &buf13, 19);	MIX(&buf6, &buf11, 10);	MIX(&buf4, &buf15, 55);
		MIX(&buf10, &buf7, 49);	MIX(&buf12, &buf3, 18);	MIX(&buf14, &buf5, 23);	MIX(&buf8, &buf1, 52);
		//===
		MIX(&buf0, &buf7, 33);	MIX(&buf2, &buf5, 4);	MIX(&buf4, &buf3, 51);	MIX(&buf6, &buf1, 13);
		MIX(&buf12, &buf15, 34);	MIX(&buf14, &buf13, 41);	MIX(&buf8, &buf11, 59);	MIX(&buf10, &buf9, 17);
		//===
		MIX(&buf0, &buf15, 5);	MIX(&buf2, &buf11, 20);	MIX(&buf6, &buf13, 48);	MIX(&buf4, &buf9, 41);
		MIX(&buf14, &buf1, 47);	MIX(&buf8, &buf5, 28);	MIX(&buf10, &buf3, 16);	MIX(&buf12, &buf7, 25);
		//===
		//KEYINJECT 19
		buf0 += locKey2;
		buf1 += locKey3;
		buf2 += locKey4;
		buf3 += locKey5;
		buf4 += locKey6;
		buf5 += locKey7;
		buf6 += locKey8;
		buf7 += locKey9;
		buf8 += locKey10;
		buf9 += locKey11;
		buf10 += locKey12;
		buf11 += locKey13;
		buf12 += locKey14;
		buf13 += locKey15 + locTweak1;
		buf14 += locKey16 + locTweak2;
		buf15 += locKey0 + 19;
		//Rounds 76 through 79
		MIX(&buf0, &buf1, 41);	MIX(&buf2, &buf3, 9);	MIX(&buf4, &buf5, 37);	MIX(&buf6, &buf7, 31);
		MIX(&buf8, &buf9, 12);	MIX(&buf10, &buf11, 47);	MIX(&buf12, &buf13, 44);	MIX(&buf14, &buf15, 30);
		//===
		MIX(&buf0, &buf9, 16);	MIX(&buf2, &buf13, 34);	MIX(&buf6, &buf11, 56);	MIX(&buf4, &buf15, 51);
		MIX(&buf10, &buf7, 4);	MIX(&buf12, &buf3, 53);	MIX(&buf14, &buf5, 42);	MIX(&buf8, &buf1, 41);
		//===
		MIX(&buf0, &buf7, 31);	MIX(&buf2, &buf5, 44);	MIX(&buf4, &buf3, 47);	MIX(&buf6, &buf1, 46);
		MIX(&buf12, &buf15, 19);	MIX(&buf14, &buf13, 42);	MIX(&buf8, &buf11, 44);	MIX(&buf10, &buf9, 25);
		//===
		MIX(&buf0, &buf15, 9);	MIX(&buf2, &buf11, 48);	MIX(&buf6, &buf13, 35);	MIX(&buf4, &buf9, 52);
		MIX(&buf14, &buf1, 23);	MIX(&buf8, &buf5, 31);	MIX(&buf10, &buf3, 37);	MIX(&buf12, &buf7, 20);
		//===
		//KEYINJECT 20
		buf0 += locKey3;
		buf1 += locKey4;
		buf2 += locKey5;
		buf3 += locKey6;
		buf4 += locKey7;
		buf5 += locKey8;
		buf6 += locKey9;
		buf7 += locKey10;
		buf8 += locKey11;
		buf9 += locKey12;
		buf10 += locKey13;
		buf11 += locKey14;
		buf12 += locKey15;
		buf13 += locKey16 + locTweak2;
		buf14 += locKey0 + locTweak0;
		buf15 += locKey1 + 20;
		//==END 1024====================================================================================
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
			result[8] = buf8 ^ input[8];
			buf8 ^= result[8] ^ input[8];
			result[9] = buf9 ^ input[9];
			buf9 ^= result[9] ^ input[9];
			result[10] = buf10 ^ input[10];
			buf10 ^= result[10] ^ input[10];
			result[11] = buf11 ^ input[11];
			buf11 ^= result[11] ^ input[11];
			result[12] = buf12 ^ input[12];
			buf12 ^= result[12] ^ input[12];
			result[13] = buf13 ^ input[13];
			buf13 ^= result[13] ^ input[13];
			result[14] = buf14 ^ input[14];
			buf14 ^= result[14] ^ input[14];
			result[15] = buf15 ^ input[15];
			buf15 ^= result[15] ^ input[15];
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
			result[8] = buf8;
			buf8 ^= result[8];
			result[9] = buf9;
			buf9 ^= result[9];
			result[10] = buf10;
			buf10 ^= result[10];
			result[11] = buf11;
			buf11 ^= result[11];
			result[12] = buf12;
			buf12 ^= result[12];
			result[13] = buf13;
			buf13 ^= result[13];
			result[14] = buf14;
			buf14 ^= result[14];
			result[15] = buf15;
			buf15 ^= result[15];
		}

		//return result;
	}

	void Skein::ThreeFishCore::InvProcess1024(array<UInt64>^ input, array<UInt64>^ key, array<UInt64>^ tweak, array<UInt64>^ result)
	{
		//array<UInt64>^ result = gcnew array<UInt64>(16);
		UInt64 buf0 = input[0]; 	UInt64 buf1 = input[1];		UInt64 buf2 = input[2];		UInt64 buf3 = input[3];
		UInt64 buf4 = input[4];		UInt64 buf5 = input[5];		UInt64 buf6 = input[6];		UInt64 buf7 = input[7];
		UInt64 buf8 = input[8];		UInt64 buf9 = input[9];		UInt64 buf10 = input[10];	UInt64 buf11 = input[11];
		UInt64 buf12 = input[12];	UInt64 buf13 = input[13];	UInt64 buf14 = input[14];	UInt64 buf15 = input[15];
				
		UInt64 locKey0 = key[0];	UInt64 locKey1 = key[1];	UInt64 locKey2 = key[2];	UInt64 locKey3 = key[3];
		UInt64 locKey4 = key[4];	UInt64 locKey5 = key[5];	UInt64 locKey6 = key[6];	UInt64 locKey7 = key[7];
		UInt64 locKey8 = key[8];	UInt64 locKey9 = key[9];	UInt64 locKey10 = key[10];	UInt64 locKey11 = key[11];
		UInt64 locKey12 = key[12];	UInt64 locKey13 = key[13];	UInt64 locKey14 = key[14];	UInt64 locKey15 = key[15];
		UInt64 locKey16 = ThreeFishCore::ThreeFishParity;
		for (int i = 0; i < key->Length; i++)
		{	locKey16 ^= key[i];	}
		
		UInt64 locTweak0 = tweak[0];
		UInt64 locTweak1 = tweak[1];
		UInt64 locTweak2 = (tweak[0] ^ tweak[1]);

		// *** GENERATED CODE:  SEE BuildThreeFishCPP PROJECT *** 
		//==1024========================================================================================
		//KEYINJECT 20
		buf0 -= locKey3;
		buf1 -= locKey4;
		buf2 -= locKey5;
		buf3 -= locKey6;
		buf4 -= locKey7;
		buf5 -= locKey8;
		buf6 -= locKey9;
		buf7 -= locKey10;
		buf8 -= locKey11;
		buf9 -= locKey12;
		buf10 -= locKey13;
		buf11 -= locKey14;
		buf12 -= locKey15;
		buf13 -= (locKey16 + locTweak2);
		buf14 -= (locKey0 + locTweak0);
		buf15 -= (locKey1 + 20);
		//Rounds 79 through 76
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 19
		buf0 -= locKey2;
		buf1 -= locKey3;
		buf2 -= locKey4;
		buf3 -= locKey5;
		buf4 -= locKey6;
		buf5 -= locKey7;
		buf6 -= locKey8;
		buf7 -= locKey9;
		buf8 -= locKey10;
		buf9 -= locKey11;
		buf10 -= locKey12;
		buf11 -= locKey13;
		buf12 -= locKey14;
		buf13 -= (locKey15 + locTweak1);
		buf14 -= (locKey16 + locTweak2);
		buf15 -= (locKey0 + 19);
		//Rounds 75 through 72
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 18
		buf0 -= locKey1;
		buf1 -= locKey2;
		buf2 -= locKey3;
		buf3 -= locKey4;
		buf4 -= locKey5;
		buf5 -= locKey6;
		buf6 -= locKey7;
		buf7 -= locKey8;
		buf8 -= locKey9;
		buf9 -= locKey10;
		buf10 -= locKey11;
		buf11 -= locKey12;
		buf12 -= locKey13;
		buf13 -= (locKey14 + locTweak0);
		buf14 -= (locKey15 + locTweak1);
		buf15 -= (locKey16 + 18);
		//Rounds 71 through 68
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 17
		buf0 -= locKey0;
		buf1 -= locKey1;
		buf2 -= locKey2;
		buf3 -= locKey3;
		buf4 -= locKey4;
		buf5 -= locKey5;
		buf6 -= locKey6;
		buf7 -= locKey7;
		buf8 -= locKey8;
		buf9 -= locKey9;
		buf10 -= locKey10;
		buf11 -= locKey11;
		buf12 -= locKey12;
		buf13 -= (locKey13 + locTweak2);
		buf14 -= (locKey14 + locTweak0);
		buf15 -= (locKey15 + 17);
		//Rounds 67 through 64
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 16
		buf0 -= locKey16;
		buf1 -= locKey0;
		buf2 -= locKey1;
		buf3 -= locKey2;
		buf4 -= locKey3;
		buf5 -= locKey4;
		buf6 -= locKey5;
		buf7 -= locKey6;
		buf8 -= locKey7;
		buf9 -= locKey8;
		buf10 -= locKey9;
		buf11 -= locKey10;
		buf12 -= locKey11;
		buf13 -= (locKey12 + locTweak1);
		buf14 -= (locKey13 + locTweak2);
		buf15 -= (locKey14 + 16);
		//Rounds 63 through 60
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 15
		buf0 -= locKey15;
		buf1 -= locKey16;
		buf2 -= locKey0;
		buf3 -= locKey1;
		buf4 -= locKey2;
		buf5 -= locKey3;
		buf6 -= locKey4;
		buf7 -= locKey5;
		buf8 -= locKey6;
		buf9 -= locKey7;
		buf10 -= locKey8;
		buf11 -= locKey9;
		buf12 -= locKey10;
		buf13 -= (locKey11 + locTweak0);
		buf14 -= (locKey12 + locTweak1);
		buf15 -= (locKey13 + 15);
		//Rounds 59 through 56
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 14
		buf0 -= locKey14;
		buf1 -= locKey15;
		buf2 -= locKey16;
		buf3 -= locKey0;
		buf4 -= locKey1;
		buf5 -= locKey2;
		buf6 -= locKey3;
		buf7 -= locKey4;
		buf8 -= locKey5;
		buf9 -= locKey6;
		buf10 -= locKey7;
		buf11 -= locKey8;
		buf12 -= locKey9;
		buf13 -= (locKey10 + locTweak2);
		buf14 -= (locKey11 + locTweak0);
		buf15 -= (locKey12 + 14);
		//Rounds 55 through 52
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 13
		buf0 -= locKey13;
		buf1 -= locKey14;
		buf2 -= locKey15;
		buf3 -= locKey16;
		buf4 -= locKey0;
		buf5 -= locKey1;
		buf6 -= locKey2;
		buf7 -= locKey3;
		buf8 -= locKey4;
		buf9 -= locKey5;
		buf10 -= locKey6;
		buf11 -= locKey7;
		buf12 -= locKey8;
		buf13 -= (locKey9 + locTweak1);
		buf14 -= (locKey10 + locTweak2);
		buf15 -= (locKey11 + 13);
		//Rounds 51 through 48
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 12
		buf0 -= locKey12;
		buf1 -= locKey13;
		buf2 -= locKey14;
		buf3 -= locKey15;
		buf4 -= locKey16;
		buf5 -= locKey0;
		buf6 -= locKey1;
		buf7 -= locKey2;
		buf8 -= locKey3;
		buf9 -= locKey4;
		buf10 -= locKey5;
		buf11 -= locKey6;
		buf12 -= locKey7;
		buf13 -= (locKey8 + locTweak0);
		buf14 -= (locKey9 + locTweak1);
		buf15 -= (locKey10 + 12);
		//Rounds 47 through 44
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 11
		buf0 -= locKey11;
		buf1 -= locKey12;
		buf2 -= locKey13;
		buf3 -= locKey14;
		buf4 -= locKey15;
		buf5 -= locKey16;
		buf6 -= locKey0;
		buf7 -= locKey1;
		buf8 -= locKey2;
		buf9 -= locKey3;
		buf10 -= locKey4;
		buf11 -= locKey5;
		buf12 -= locKey6;
		buf13 -= (locKey7 + locTweak2);
		buf14 -= (locKey8 + locTweak0);
		buf15 -= (locKey9 + 11);
		//Rounds 43 through 40
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 10
		buf0 -= locKey10;
		buf1 -= locKey11;
		buf2 -= locKey12;
		buf3 -= locKey13;
		buf4 -= locKey14;
		buf5 -= locKey15;
		buf6 -= locKey16;
		buf7 -= locKey0;
		buf8 -= locKey1;
		buf9 -= locKey2;
		buf10 -= locKey3;
		buf11 -= locKey4;
		buf12 -= locKey5;
		buf13 -= (locKey6 + locTweak1);
		buf14 -= (locKey7 + locTweak2);
		buf15 -= (locKey8 + 10);
		//Rounds 39 through 36
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 9
		buf0 -= locKey9;
		buf1 -= locKey10;
		buf2 -= locKey11;
		buf3 -= locKey12;
		buf4 -= locKey13;
		buf5 -= locKey14;
		buf6 -= locKey15;
		buf7 -= locKey16;
		buf8 -= locKey0;
		buf9 -= locKey1;
		buf10 -= locKey2;
		buf11 -= locKey3;
		buf12 -= locKey4;
		buf13 -= (locKey5 + locTweak0);
		buf14 -= (locKey6 + locTweak1);
		buf15 -= (locKey7 + 9);
		//Rounds 35 through 32
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 8
		buf0 -= locKey8;
		buf1 -= locKey9;
		buf2 -= locKey10;
		buf3 -= locKey11;
		buf4 -= locKey12;
		buf5 -= locKey13;
		buf6 -= locKey14;
		buf7 -= locKey15;
		buf8 -= locKey16;
		buf9 -= locKey0;
		buf10 -= locKey1;
		buf11 -= locKey2;
		buf12 -= locKey3;
		buf13 -= (locKey4 + locTweak2);
		buf14 -= (locKey5 + locTweak0);
		buf15 -= (locKey6 + 8);
		//Rounds 31 through 28
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 7
		buf0 -= locKey7;
		buf1 -= locKey8;
		buf2 -= locKey9;
		buf3 -= locKey10;
		buf4 -= locKey11;
		buf5 -= locKey12;
		buf6 -= locKey13;
		buf7 -= locKey14;
		buf8 -= locKey15;
		buf9 -= locKey16;
		buf10 -= locKey0;
		buf11 -= locKey1;
		buf12 -= locKey2;
		buf13 -= (locKey3 + locTweak1);
		buf14 -= (locKey4 + locTweak2);
		buf15 -= (locKey5 + 7);
		//Rounds 27 through 24
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 6
		buf0 -= locKey6;
		buf1 -= locKey7;
		buf2 -= locKey8;
		buf3 -= locKey9;
		buf4 -= locKey10;
		buf5 -= locKey11;
		buf6 -= locKey12;
		buf7 -= locKey13;
		buf8 -= locKey14;
		buf9 -= locKey15;
		buf10 -= locKey16;
		buf11 -= locKey0;
		buf12 -= locKey1;
		buf13 -= (locKey2 + locTweak0);
		buf14 -= (locKey3 + locTweak1);
		buf15 -= (locKey4 + 6);
		//Rounds 23 through 20
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 5
		buf0 -= locKey5;
		buf1 -= locKey6;
		buf2 -= locKey7;
		buf3 -= locKey8;
		buf4 -= locKey9;
		buf5 -= locKey10;
		buf6 -= locKey11;
		buf7 -= locKey12;
		buf8 -= locKey13;
		buf9 -= locKey14;
		buf10 -= locKey15;
		buf11 -= locKey16;
		buf12 -= locKey0;
		buf13 -= (locKey1 + locTweak2);
		buf14 -= (locKey2 + locTweak0);
		buf15 -= (locKey3 + 5);
		//Rounds 19 through 16
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 4
		buf0 -= locKey4;
		buf1 -= locKey5;
		buf2 -= locKey6;
		buf3 -= locKey7;
		buf4 -= locKey8;
		buf5 -= locKey9;
		buf6 -= locKey10;
		buf7 -= locKey11;
		buf8 -= locKey12;
		buf9 -= locKey13;
		buf10 -= locKey14;
		buf11 -= locKey15;
		buf12 -= locKey16;
		buf13 -= (locKey0 + locTweak1);
		buf14 -= (locKey1 + locTweak2);
		buf15 -= (locKey2 + 4);
		//Rounds 15 through 12
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 3
		buf0 -= locKey3;
		buf1 -= locKey4;
		buf2 -= locKey5;
		buf3 -= locKey6;
		buf4 -= locKey7;
		buf5 -= locKey8;
		buf6 -= locKey9;
		buf7 -= locKey10;
		buf8 -= locKey11;
		buf9 -= locKey12;
		buf10 -= locKey13;
		buf11 -= locKey14;
		buf12 -= locKey15;
		buf13 -= (locKey16 + locTweak0);
		buf14 -= (locKey0 + locTweak1);
		buf15 -= (locKey1 + 3);
		//Rounds 11 through 8
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 2
		buf0 -= locKey2;
		buf1 -= locKey3;
		buf2 -= locKey4;
		buf3 -= locKey5;
		buf4 -= locKey6;
		buf5 -= locKey7;
		buf6 -= locKey8;
		buf7 -= locKey9;
		buf8 -= locKey10;
		buf9 -= locKey11;
		buf10 -= locKey12;
		buf11 -= locKey13;
		buf12 -= locKey14;
		buf13 -= (locKey15 + locTweak2);
		buf14 -= (locKey16 + locTweak0);
		buf15 -= (locKey0 + 2);
		//Rounds 7 through 4
		INVMIX(&buf0, &buf15, 9);	INVMIX(&buf2, &buf11, 48);	INVMIX(&buf6, &buf13, 35);	INVMIX(&buf4, &buf9, 52);
		INVMIX(&buf14, &buf1, 23);	INVMIX(&buf8, &buf5, 31);	INVMIX(&buf10, &buf3, 37);	INVMIX(&buf12, &buf7, 20);
		//===
		INVMIX(&buf0, &buf7, 31);	INVMIX(&buf2, &buf5, 44);	INVMIX(&buf4, &buf3, 47);	INVMIX(&buf6, &buf1, 46);
		INVMIX(&buf12, &buf15, 19);	INVMIX(&buf14, &buf13, 42);	INVMIX(&buf8, &buf11, 44);	INVMIX(&buf10, &buf9, 25);
		//===
		INVMIX(&buf0, &buf9, 16);	INVMIX(&buf2, &buf13, 34);	INVMIX(&buf6, &buf11, 56);	INVMIX(&buf4, &buf15, 51);
		INVMIX(&buf10, &buf7, 4);	INVMIX(&buf12, &buf3, 53);	INVMIX(&buf14, &buf5, 42);	INVMIX(&buf8, &buf1, 41);
		//===
		INVMIX(&buf0, &buf1, 41);	INVMIX(&buf2, &buf3, 9);	INVMIX(&buf4, &buf5, 37);	INVMIX(&buf6, &buf7, 31);
		INVMIX(&buf8, &buf9, 12);	INVMIX(&buf10, &buf11, 47);	INVMIX(&buf12, &buf13, 44);	INVMIX(&buf14, &buf15, 30);
		//===
		//KEYINJECT 1
		buf0 -= locKey1;
		buf1 -= locKey2;
		buf2 -= locKey3;
		buf3 -= locKey4;
		buf4 -= locKey5;
		buf5 -= locKey6;
		buf6 -= locKey7;
		buf7 -= locKey8;
		buf8 -= locKey9;
		buf9 -= locKey10;
		buf10 -= locKey11;
		buf11 -= locKey12;
		buf12 -= locKey13;
		buf13 -= (locKey14 + locTweak1);
		buf14 -= (locKey15 + locTweak2);
		buf15 -= (locKey16 + 1);
		//Rounds 3 through 0
		INVMIX(&buf0, &buf15, 5);	INVMIX(&buf2, &buf11, 20);	INVMIX(&buf6, &buf13, 48);	INVMIX(&buf4, &buf9, 41);
		INVMIX(&buf14, &buf1, 47);	INVMIX(&buf8, &buf5, 28);	INVMIX(&buf10, &buf3, 16);	INVMIX(&buf12, &buf7, 25);
		//===
		INVMIX(&buf0, &buf7, 33);	INVMIX(&buf2, &buf5, 4);	INVMIX(&buf4, &buf3, 51);	INVMIX(&buf6, &buf1, 13);
		INVMIX(&buf12, &buf15, 34);	INVMIX(&buf14, &buf13, 41);	INVMIX(&buf8, &buf11, 59);	INVMIX(&buf10, &buf9, 17);
		//===
		INVMIX(&buf0, &buf9, 38);	INVMIX(&buf2, &buf13, 19);	INVMIX(&buf6, &buf11, 10);	INVMIX(&buf4, &buf15, 55);
		INVMIX(&buf10, &buf7, 49);	INVMIX(&buf12, &buf3, 18);	INVMIX(&buf14, &buf5, 23);	INVMIX(&buf8, &buf1, 52);
		//===
		INVMIX(&buf0, &buf1, 24);	INVMIX(&buf2, &buf3, 13);	INVMIX(&buf4, &buf5, 8);	INVMIX(&buf6, &buf7, 47);
		INVMIX(&buf8, &buf9, 8);	INVMIX(&buf10, &buf11, 17);	INVMIX(&buf12, &buf13, 22);	INVMIX(&buf14, &buf15, 37);
		//===
		//KEYINJECT 0
		buf0 -= locKey0;
		buf1 -= locKey1;
		buf2 -= locKey2;
		buf3 -= locKey3;
		buf4 -= locKey4;
		buf5 -= locKey5;
		buf6 -= locKey6;
		buf7 -= locKey7;
		buf8 -= locKey8;
		buf9 -= locKey9;
		buf10 -= locKey10;
		buf11 -= locKey11;
		buf12 -= locKey12;
		buf13 -= (locKey13 + locTweak0);
		buf14 -= (locKey14 + locTweak1);
		buf15 -= (locKey15 + 0);
		//==END 1024====================================================================================
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
		result[8] = buf8;
		buf8 ^= result[8];
		result[9] = buf9;
		buf9 ^= result[9];
		result[10] = buf10;
		buf10 ^= result[10];
		result[11] = buf11;
		buf11 ^= result[11];
		result[12] = buf12;
		buf12 ^= result[12];
		result[13] = buf13;
		buf13 ^= result[13];
		result[14] = buf14;
		buf14 ^= result[14];
		result[15] = buf15;
		buf15 ^= result[15];
		
		//return result;
	}
}
