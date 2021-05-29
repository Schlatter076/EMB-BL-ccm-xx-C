////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksBase.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Feb 6, 2014
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSBASE_H_KENSKY_2014
#define __KSBASE_H_KENSKY_2014

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
#include "../../DS_cfg.h"

/**** Defines *****************************************************************/
#define 		M_KS_MIN(x,y) 		({ 											\
																	typeof(x) _x = (x); \
																	typeof(y) _y = (y); \
																	(void) (&_x == &_y);\
																	_x < _y ? _x : _y;	\
															})

#define 		M_KS_MAX(x,y) 		({ 											\
        													typeof(x) _x = (x); \
        													typeof(y) _y = (y); \
        													(void) (&_x == &_y);\
        													_x > _y ? _x : _y; 	\
        											})

/***** Function Prototypes ****************************************************/
#if 1
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksFls
/// @param      : x :  the word to search
/// @return     : description of return value.
/// @brief      : This is defined the same way as ffs.
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
////////////////////////////////////////////////////////////////////////////////
#ifdef  __ICCARM__
__STATIC_INLINE int ksFls(int x)
{
	int r = 0;
#ifdef __ICCARM__

#if 0
	asm("bsrl %1,%0\n\t"
			"jnz 1f\n\t"
			"movl $-1,%0\n"
			"1:" : "=r" (r) : "rm" (x));
#endif // 1

#else
	__asm__("bsrl %1,%0\n\t"
			    "jnz 1f\n\t"
			    "movl $-1,%0\n"
			    "1:" : "=r" (r) : "rm" (x));
#endif
	return r+1;
}
#else
#if defined __GNUC__
__STATIC_INLINE int ICACHE_FLASH_ATTR ksFls(int x)
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksFls
/// @param      : p_arg
///               @arg  x :  the word to search
/// @return     : description of return value.
/// @brief      : This is defined the same way as ffs.
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.fls(0) = 0, fls(1) = 1,
///								fls(0x80000000) = 32.
////////////////////////////////////////////////////////////////////////////////
#else
static __always_inline int ksFls(int x)
#endif // __GNUC__
{
	int r = 32;

	if (!x)
		return 0;

	if (!(x & 0xffff0000u))
	{
		x <<= 16;
		r -= 16;
	}

	if (!(x & 0xff000000u))
	{
		x <<= 8;
		r -= 8;
	}

	if (!(x & 0xf0000000u))
	{
		x <<= 4;
		r -= 4;
	}

	if (!(x & 0xc0000000u))
	{
		x <<= 2;
		r -= 2;
	}

	if (!(x & 0x80000000u))
	{
		x <<= 1;
		r -= 1;
	}
	return r;
}
#endif // ICCARM
#endif // fls

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksFls64
/// @param      : p_arg
///               @arg  x :  the word to search
/// @return     : description of return value.
/// @brief      : This is defined the same way as ffs.
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.fls(0) = 0, fls(1) = 1,
///								fls(0x80000000) = 32.
////////////////////////////////////////////////////////////////////////////////
#ifdef  __ICCARM__
__STATIC_INLINE int ksFls64(dsU64 x)
#elif defined __GNUC__
__STATIC_INLINE int ICACHE_FLASH_ATTR ksFls64(dsU64 x)
#else
static __always_inline int ksFls64(dsU64 x)
#endif
{
	dsU32 h = x >> 32;
	if (h)
	{
		return ksFls(h) + 32;
	}
	else
	{
	  return ksFls(x);
	}
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksFlsLong
/// @param      : p_arg
///               @arg  l :  the word to search
/// @return     : description of return value.
/// @brief      : This is defined the same way as ffs.
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.fls(0) = 0, fls(1) = 1,
///								fls(0x80000000) = 32.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE unsigned ICACHE_FLASH_ATTR ksFlsLong(unsigned long l)
{
  if (sizeof(l) == 4)
  {
  	return ksFls(l);
  }
  else
  {
    return ksFls64(l);
  }
}

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus

#endif // __KSBASE_H_KENSKY_2014
