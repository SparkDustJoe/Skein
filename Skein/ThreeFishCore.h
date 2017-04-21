// ThreeFishCore.h
#pragma once
#include <stdlib.h>
using namespace System;
#define THREEFISH_CORE_H

namespace Skein
{
	public ref class ThreeFishCore
	{
		internal:
			static const UInt64 ThreeFishParity = 0x1BD11BDAA9FC1A22;
			//static UInt64 UniqueK(array<UInt64>^ UInt64);
		//static void MIX(UInt64*, UInt64*, int);
		//static void INVMIX(UInt64*, UInt64*, int);
		public:
			static void Process256(array<UInt64>^, array<UInt64>^, array<UInt64>^, bool feed, array<UInt64>^ );
			static void InvProcess256(array<UInt64>^, array<UInt64>^, array<UInt64>^, array<UInt64>^ );
			static void Process512(array<UInt64>^, array<UInt64>^, array<UInt64>^, bool feed, array<UInt64>^ );
			static void InvProcess512(array<UInt64>^, array<UInt64>^, array<UInt64>^, array<UInt64>^ );
			static void Process1024(array<UInt64>^, array<UInt64>^, array<UInt64>^, bool feed, array<UInt64>^ );
			static void InvProcess1024(array<UInt64>^, array<UInt64>^, array<UInt64>^, array<UInt64>^ );
		
	};
//#ifndef _UNIQUE_K
//#define _UNIQUE_K
//	UInt64 ThreeFishCore::UniqueK(array<UInt64>^ input)
//	{
//		UInt64 result = ThreeFishCore::ThreeFishParity;
//		for(int i = 0; i < input->Length; i++)
//		{
//			result ^= input[i];
//		}
//		return result;
//	};
//#endif // !_UNIQUE_K

	//do not __forceinline the following MIX functions, that takes WAY too long to compile, produces bloated binaries, 
	// and provides no speed benefits whatsoever
	//*Y = (UInt64)(*Y << N) + (UInt64)(*Y >> (64 - N)); //ROTATE LEFT
	//*Y = (UInt64)(*Y >> N) + (UInt64)(*Y << (64 - N)); //ROTATE RIGHT

	//void SkeinLib::ThreeFishCore::MIX(UInt64 *X, UInt64 *Y, int N)
	//{
	//	*X += *Y; *Y= _rotl64(*Y, N); *Y ^= *X;
	//}

	   //auto MIX = [&](UInt64 *X, UInt64 *Y, int N){ *X += *Y; *Y = (UInt64)(*Y << N) + (UInt64)(*Y >> (64 - N)); *Y ^= *X; };
	//auto INVMIX = [&](UInt64 *X, UInt64 *Y, int N){ *Y ^= *X; *Y = (UInt64)(*Y >> N) + (UInt64)(*Y << (64 - N)); *X -= *Y; };

	 //auto MIX = [&](UInt64 *X, UInt64 *Y, int N) { *X += *Y; *Y = _rotl64(*Y, N); *Y ^= *X; };
	 //auto INVMIX = [&](UInt64 *X, UInt64 *Y, int N) { *Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y; };

	//void SkeinLib::ThreeFishCore::INVMIX(UInt64 *X, UInt64 *Y, int N)
	//{
	//	*Y ^= *X; *Y = _rotr64(*Y, N); *X -= *Y;
	//}

}
