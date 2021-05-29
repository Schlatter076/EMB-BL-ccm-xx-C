////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksLog2.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Feb 6, 2014
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSLOG2_H_kensky_2014
#define __KSLOG2_H_kensky_2014

//******************************************************************************
#ifdef  __cplusplus
//******************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "./ksBase.h"

#if (!defined(__ICCARM__) && (1))
/**** Defines *****************************************************************/
/*
 * deal with unrepresentable constant logarithms
 */
#ifdef __ICCARM__
extern ATTRIBUTE((const, noreturn)) int 	____kslog2_NaN(void);
#else
//extern __attribute__((const, noreturn)) int 	____kslog2_NaN(void);
extern __attribute__((const)) int 	____kslog2_NaN(void);
#endif
/*
 * non-constant log of base 2 calculators
 * - the arch may override these in asm/bitops.h if they can be implemented
 *   more efficiently than using fls() and fls64()
 * - the arch is not required to handle n==0 if implementing the fallback
 */
#ifndef CONFIG_ARCH_HAS_ILOG2_U32
__STATIC_INLINE __attribute__((const)) 		int 	__kslog2_u32(dsU32 n)
{
	return ksFls(n) - 1;
}
#endif

#ifndef CONFIG_ARCH_HAS_ILOG2_U64
__STATIC_INLINE __attribute__((const)) 		int 	__kslog2_u64(dsU64 n)
{
	return ksFls64(n) - 1;
}

/*
 *  Determine whether some value is a power of two, where zero is
 * *not* considered a power of two.
 */
__STATIC_INLINE __attribute__((const)) 		int 	ksIsPowOf2(dsU32 n)
{
	return (n != 0 && ((n & (n - 1)) == 0));
}

/*
 * round up to nearest power of two
 */
__STATIC_INLINE __attribute__((const)) 		dsU32 __ks_roundup_pow_of_two(dsU32 n)
{
	return 1UL << ksFlsLong(n - 1);
}

/*
 * round down to nearest power of two
 */
__STATIC_INLINE __attribute__((const)) 		dsU32 __ks_rounddown_pow_of_two(dsU32 n)
{
	return 1UL << (ksFlsLong(n) - 1);
}

/*
 * get the modulus of left from right, make sure the right is power of 2
 */
__STATIC_INLINE __attribute__((const))		dsU32 ksGetModulusFromPow2(dsU32 lft, dsU32 rht)
{
	return lft & (rht-1); // lft % rht;
}
/**
 * ilog2 - log of base 2 of 32-bit or a 64-bit unsigned value
 * @n - parameter
 *
 * constant-capable log of base 2 calculation
 * - this can be used to initialise global variables from constant data, hence
 *   the massive ternary operator construction
 *
 * selects the appropriately-sized optimised version depending on sizeof(n)
 */
#define kslog2(n)								\
(																\
	__builtin_constant_p(n) ? 		\
	(															\
		(n) < 1 ? ____kslog2_NaN() :\
		(n) & (1ULL << 63) ? 63 :		\
		(n) & (1ULL << 62) ? 62 :		\
		(n) & (1ULL << 61) ? 61 :		\
		(n) & (1ULL << 60) ? 60 :		\
		(n) & (1ULL << 59) ? 59 :		\
		(n) & (1ULL << 58) ? 58 :		\
		(n) & (1ULL << 57) ? 57 :		\
		(n) & (1ULL << 56) ? 56 :		\
		(n) & (1ULL << 55) ? 55 :		\
		(n) & (1ULL << 54) ? 54 :		\
		(n) & (1ULL << 53) ? 53 :		\
		(n) & (1ULL << 52) ? 52 :		\
		(n) & (1ULL << 51) ? 51 :		\
		(n) & (1ULL << 50) ? 50 :		\
		(n) & (1ULL << 49) ? 49 :		\
		(n) & (1ULL << 48) ? 48 :		\
		(n) & (1ULL << 47) ? 47 :		\
		(n) & (1ULL << 46) ? 46 :		\
		(n) & (1ULL << 45) ? 45 :		\
		(n) & (1ULL << 44) ? 44 :		\
		(n) & (1ULL << 43) ? 43 :		\
		(n) & (1ULL << 42) ? 42 :		\
		(n) & (1ULL << 41) ? 41 :		\
		(n) & (1ULL << 40) ? 40 :		\
		(n) & (1ULL << 39) ? 39 :		\
		(n) & (1ULL << 38) ? 38 :		\
		(n) & (1ULL << 37) ? 37 :		\
		(n) & (1ULL << 36) ? 36 :		\
		(n) & (1ULL << 35) ? 35 :		\
		(n) & (1ULL << 34) ? 34 :		\
		(n) & (1ULL << 33) ? 33 :		\
		(n) & (1ULL << 32) ? 32 :	  \
		(n) & (1ULL << 31) ? 31 :	  \
		(n) & (1ULL << 30) ? 30 :	  \
		(n) & (1ULL << 29) ? 29 :	  \
		(n) & (1ULL << 28) ? 28 :	  \
		(n) & (1ULL << 27) ? 27 :	  \
		(n) & (1ULL << 26) ? 26 :	  \
		(n) & (1ULL << 25) ? 25 :	  \
		(n) & (1ULL << 24) ? 24 :	  \
		(n) & (1ULL << 23) ? 23 :	  \
		(n) & (1ULL << 22) ? 22 :	  \
		(n) & (1ULL << 21) ? 21 :	  \
		(n) & (1ULL << 20) ? 20 :	  \
		(n) & (1ULL << 19) ? 19 :	  \
		(n) & (1ULL << 18) ? 18 :	  \
		(n) & (1ULL << 17) ? 17 :	  \
		(n) & (1ULL << 16) ? 16 :	  \
		(n) & (1ULL << 15) ? 15 :	  \
		(n) & (1ULL << 14) ? 14 :	  \
		(n) & (1ULL << 13) ? 13 :	  \
		(n) & (1ULL << 12) ? 12 :	  \
		(n) & (1ULL << 11) ? 11 :	  \
		(n) & (1ULL << 10) ? 10 :	  \
		(n) & (1ULL <<  9) ?  9 :	  \
		(n) & (1ULL <<  8) ?  8 :	  \
		(n) & (1ULL <<  7) ?  7 :	  \
		(n) & (1ULL <<  6) ?  6 :	  \
		(n) & (1ULL <<  5) ?  5 :	  \
		(n) & (1ULL <<  4) ?  4 :	  \
		(n) & (1ULL <<  3) ?  3 :	  \
		(n) & (1ULL <<  2) ?  2 :	  \
		(n) & (1ULL <<  1) ?  1 :	  \
		(n) & (1ULL <<  0) ?  0 :	  \
		____kslog2_NaN() 						\
	) :														\
	(sizeof(n) <= 4) ?						\
			__kslog2_u32(n) :					\
			__kslog2_u64(n) 					\
 )

/**
 * roundup_pow_of_two - round the given value up to nearest power of two
 * @n - parameter
 *
 * round the given value up to the nearest power of 2
 * - the result is undefined when n == 0
 * - this can be used to initialise global variables from constant data
 */
#define ks_roundup_pow_of_two(n) 		\
( 																	\
	__builtin_constant_p(n) ? 				\
	(																	\
		(n == 1) ? 											\
			1 : (1UL << (kslog2((n)-1)+1))\
	) : __ks_roundup_pow_of_two(n) 		\
)

/**
 * rounddown_pow_of_two - round the given value down to nearest power of two
 * @n - parameter
 *
 * round the given value down to the nearest power of two
 * - the result is undefined when n == 0
 * - this can be used to initialise global variables from constant data
 */
#define ks_rounddown_pow_of_two(n) 	\
(																		\
	__builtin_constant_p(n) ?					\
		(1UL << kslog2(n)) : 						\
		__ks_rounddown_pow_of_two(n) 		\
)

/**
 * order_base_2 - calculate the (rounded up) base 2 order of the argument
 * @n: parameter
 *
 * The first few values calculated by this routine:
 *  ob2(0) = 0
 *  ob2(1) = 0
 *  ob2(2) = 1
 *  ob2(3) = 2
 *  ob2(4) = 2
 *  ob2(5) = 3
 *  ... and so on.
 */
#define 	order_base_2(n) 					kslog2(roundup_pow_of_two(n))

#endif

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus

#endif // __ICCARM__
#endif // __KSLOG2_H_kensky_2014
