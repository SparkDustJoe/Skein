#pragma once
#include "System.Security.Cryptography.HMACSkein.cpp"
using namespace System;

namespace System {
	namespace Security {
		namespace Cryptography
		{
			public ref class HMACSkein256Managed sealed : public HMACSkein
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 4; } };
			public:
				HMACSkein256Managed() { Initialize(); }
				~HMACSkein256Managed() { Clear(); }
			};

			public ref class HMACSkein512Managed sealed : public HMACSkein
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 8; } };
			public:
				HMACSkein512Managed() { Initialize(); }
				~HMACSkein512Managed() { Clear(); }
			};

			public ref class HMACSkein1024Managed sealed : public HMACSkein
			{
			protected:
				property Byte QWORDWIDTH {virtual Byte get() sealed override { return 16; } };
			public:
				HMACSkein1024Managed() { Initialize(); }
				~HMACSkein1024Managed() { Clear(); }
			};
		}
	}
}