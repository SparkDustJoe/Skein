#pragma once
#include "System.Security.Cryptography.SkeinHashAlgorithm.cpp"
using namespace System;

namespace System {
	namespace Security {
		namespace Cryptography
		{
			public ref class Skein256Managed sealed : public SkeinHashAlgorithm
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 4; } };
			public:
				Skein256Managed() { Initialize(); }
				~Skein256Managed() { Clear(); }
			};

			public ref class Skein512Managed sealed : public SkeinHashAlgorithm
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 8; } };
			public:
				Skein512Managed() { Initialize(); }
				~Skein512Managed() { Clear(); }
			};

			public ref class Skein1024Managed sealed : public SkeinHashAlgorithm
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 16; } };
			public:
				Skein1024Managed() { Initialize(); }
				~Skein1024Managed() { Clear(); }
			};
		}
	}
}