#pragma once
#include "SkeinEx.cpp"
#define SKEIN_X_EX
namespace Skein
{
	/// <summary>
	/// Skein hash algorithm with a 256 bit internal state size.
	/// </summary>
	public ref class Skein256Ex : public Skein::SkeinEx
	{

	protected:
		/// <summary>
		/// The internal state size of Skein256
		/// </summary>
		property Byte QWORDWIDTH {Byte get() sealed override { return 4; } }
			
	public:
		/// <summary>
		/// The default, uninitialized constructor.  The Initialize method must be called before the object can be used.
		/// </summary>
		Skein256Ex() { Initialize(DEFAULTHASHBITLENGTH, nullptr, nullptr, 0, 0, 0); }

		/// <summary>
		/// Initializes Skein with an output length (in BITS) and an (optional) key.
		/// </summary>
		/// <param name="hashBitLen">The length of the output hash (in BITS).</param>
		/// <param name="key">The (optional) key (for HMAC).</param>
		Skein256Ex(UInt64 hashBitLen, array<Byte>^ key) { Initialize(hashBitLen, key, nullptr, 0, 0, 0); }

		/// <summary>
		/// 
		/// </summary>
		~Skein256Ex()
		{
			Clear();
		}
	};

	/// <summary>
	/// Skein hash algorithm with a 512 bit internal state size.
	/// </summary>
	public ref class Skein512Ex : public Skein::SkeinEx
	{

	protected:
		/// <summary>
		/// The internal state size of Skein512
		/// </summary>
		property Byte QWORDWIDTH {Byte get() sealed override { return 8; } }

	public:
		/// <summary>
		/// The default, uninitialized constructor.  The Initialize method must be called before the object can be used.
		/// </summary>
		Skein512Ex() { Initialize(DEFAULTHASHBITLENGTH, nullptr, nullptr, 0, 0, 0); }

		/// <summary>
		/// Initializes Skein with an output length (in BITS) and an (optional) key.
		/// </summary>
		/// <param name="hashBitLen">The length of the output hash (in BITS).</param>
		/// <param name="key">The (optional) key (for HMAC).</param>
		Skein512Ex(UInt64 hashBitLen, array<Byte>^ key) { Initialize(hashBitLen, key, nullptr, 0, 0, 0); }

		/// <summary>
		/// 
		/// </summary>
		~Skein512Ex()
		{
			Clear();
		}
	};

	/// <summary>
	/// Skein hash algorithm with a 1024 bit internal state size.
	/// </summary>
	public ref class Skein1024Ex : public Skein::SkeinEx
	{

	protected:
		/// <summary>
		/// The internal state size of Skein1024
		/// </summary>
		property Byte QWORDWIDTH {Byte get() sealed override { return 16; } }

	public:
		/// <summary>
		/// The default, uninitialized constructor.  The Initialize method must be called before the object can be used.
		/// </summary>
		Skein1024Ex() { Initialize(DEFAULTHASHBITLENGTH, nullptr, nullptr, 0, 0, 0); }

		/// <summary>
		/// Initializes Skein with an output length (in BITS) and an (optional) key.
		/// </summary>
		/// <param name="hashBitLen">The length of the output hash (in BITS).</param>
		/// <param name="key">The (optional) key (for HMAC).</param>
		Skein1024Ex(UInt64 hashBitLen, array<Byte>^ key) { Initialize(hashBitLen, key, nullptr, 0, 0, 0); }

		/// <summary>
		/// 
		/// </summary>
		~Skein1024Ex()
		{
			Clear();
		}
	};
}