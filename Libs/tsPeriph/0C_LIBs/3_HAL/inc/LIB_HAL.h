/*******************************************************************************
  * File    :  LIB_HAL.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-10-8
  * Brief   :
*******************************************************************************/
#ifndef __LIB_HAL_H_KENSKY_2020_10_8
#define __LIB_HAL_H_KENSKY_2020_10_8

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/LIB_DDL.h"

/**** Defines *****************************************************************/
#define __LIB_GET_HI(valU16)                  (((valU16) & 0xFF00) >> 8)
#define __LIB_GET_LO(valU16)                  ((valU16) & 0x00FF)

#define __LIB_TO_STR(raw)                     #raw
#define __LIB_CONCAT_RAW(raw0, raw1)          (__LIB_TO_STR(raw0) __LIB_TO_STR(raw1))
#define __LIB_CONCAT_STR(str0, str1)          (str0 str1)

/**** TYPEDEFS ****************************************************************/
typedef enum
{ // the definition is coming from Qiankang. do not modify!
  endian_is_undefed = 0xFFU,
  endian_is_little  = 0x7FU,
  endian_is_big     = 0x80U,
} ksEndian_e;
#define __IS_KS_ENDIAN(endian)      (((endian) == endian_is_little) || \
                                    ((endian)  == endian_is_big))

/***** Function Prototypes ****************************************************/
#if (__MCU_ENDIAN == _MCU_is_LITTLE_ENDIAN)
/**
 * Convert an ksU16 from host- to network byte order.
 *
 * @param n ksU16 in host byte order
 * @return n in network byte order
 */
__STATIC_INLINE ksU16 ks_htons(ksU16 n)
{
  return ((((n) & 0x00FFuL) << 8) | (((n) & 0xFF00uL) >> 8));
}

/**
 * Convert an ksU16 from network- to host byte order.
 *
 * @param n ksU16 in network byte order
 * @return n in host byte order
 */
__STATIC_INLINE ksU16 ks_ntohs(ksU16 n)
{
  return ks_htons(n);
}

/**
 * Convert an ksU32 from host- to network byte order.
 *
 * @param n ksU32 in host byte order
 * @return n in network byte order
 */
__STATIC_INLINE ksU32 ks_htonl(ksU32 n)
{
  return ((n & 0xff) << 24)       |
          ((n & 0xff00) << 8)     |
          ((n & 0xff0000UL) >> 8) |
          ((n & 0xff000000UL) >> 24);
}

/**
 * Convert an ksU32 from network- to host byte order.
 *
 * @param n ksU32 in network byte order
 * @return n in host byte order
 */
__STATIC_INLINE ksU32 ks_ntohl(ksU32 n)
{
  return ks_htonl(n);
}

#define   __KS_CONVERT_VAR_NTOH_S(s)    (s = ks_ntohs(s));
#define   __KS_CONVERT_VAR_NTOH_L(l)    (l = ks_ntohl(l));
#define   __KS_CONVERT_VAR_HTON_S(s)    (s = ks_htons(s));
#define   __KS_CONVERT_VAR_HTON_L(l)    (l = ks_htonl(l));

#else
/**
 * Convert an ksU16 from host- to network byte order.
 *
 * @param n ksU16 in host byte order
 * @return n in network byte order
 */
__STATIC_INLINE ksU16 ks_htons(ksU16 n)
{
  return n;
}

/**
 * Convert an ksU16 from network- to host byte order.
 *
 * @param n ksU16 in network byte order
 * @return n in host byte order
 */
__STATIC_INLINE ksU16 ks_ntohs(ksU16 n)
{
  return ks_htons(n);
}

/**
 * Convert an ksU32 from host- to network byte order.
 *
 * @param n ksU32 in host byte order
 * @return n in network byte order
 */
__STATIC_INLINE ksU32 ks_htonl(ksU32 n)
{
  return n;
}

/**
 * Convert an ksU32 from network- to host byte order.
 *
 * @param n ksU32 in network byte order
 * @return n in host byte order
 */
__STATIC_INLINE ksU32 ks_ntohl(ksU32 n)
{
  return ks_htonl(n);
}
#endif

#if (__MCU_TYPE != _MCU_IS_ESP8266)
/*******************************************************************************
*  Func_Name: ksLibGetRandomNum
*  Paras    : min   :
*             max   :
*             ADC   :
*  Returns  : a random integer number
*  Brief    : the routine will return a random integer which is between min and
*             max.
*  Build on :
*  Note     :
*******************************************************************************/
ksU32 ksLibGetRandomNum(ksU32 min, ksU32 max, ksADC_t *pAD);
#endif // (__MCU_TYPE != _MCU_IS_ESP8266)

/**
 * ksLibBinaryInRangeU32 :
 *        find an element by key provided, it the search is sucessful, return index,
 *        or else, return -1;
 * @param pArray
 * @param dataSize
 * @param arrayLen
 * @param key
 * @return -1 : failure, >= 0 : the index
 */
ksS32 ksLibBinaryInRangeU32 (const ksS32 * const pArray, ksUintFast_t arraySize, ksS32 key);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibGetEndian
/// @param      : p_arg     none
/// @return     : mcu_endian_e : mcu_big_endian | mcu_litle_endian
/// @brief      : get the endian of a MCU during runtime
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
mcu_endian_e ksLibGetEndian(void);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibGetDataMem2ByteStream
/// @param      : p_arg
///               @arg  byteStream
///               @arg  mem
///               @arg  len
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-6-25
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.

////////////////////////////////////////////////////////////////////////////////
int ksLibGetDataMem2ByteStream(ksU08 *byteStream, ksU08 *mem, ksU16 len);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksIsBigEndian
/// @param      : p_arg
///               @arg  none
/// @return     : description of return value.
/// @brief      : check if the endian of the MCU is big or little.
/// @author     : kensky
/// @date       : 2013-8-19
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
ksEndian_e ksIsBigEndian();

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ykEndianSwap
/// @param      : p_arg
///               @arg  none
/// @return     : description of return value.
/// @brief      : check if the endian of the MCU is big or little., user must
///               guarantee
/// @author     : kensky
/// @date       : 2013-8-19
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
int ykEndianSwap(ksU08* pSrc, ksU08* pDes, ksU32 len);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibIsWhiteSpace
/// @param      : p_arg
///               @arg  ch
/// @return     : description of return value.
/// @brief      : check if the char is white space
/// @author     : kensky
/// @date       : 2014-4-13
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksLibIsWhiteSpace(ksChar ch);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibTrimRight
/// @param      : p_arg
///               @arg  str
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-4-13
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksLibTrimRight(ksChar* str);

////////////////////////////////////////////////////////////////////////////////
/// @fn     : ksLibGetPow2
/// @param  : p_arg
///           @arg  Num
/// @return : description of return value.
/// @brief  : 0,1 : 0; 2,3 : 1; 4,5,6,7 : 2
/// @author : kensky
/// @date   : 2015-1-12
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU32 ksLibGetPow2(ksU32 Num);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibDigit2Char
/// @param      : digit
/// @param      : pChar
/// @return     : the converted digit in ASCII
/// @brief      : convert a nibble to char in ASCII
/// @author     : kensky
/// @date       : 2013-8-19
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void ksLibDigit2Char(ksU08 digit, ksChar *pChar)
{
  digit &= 0x0F; // only 0-f
  *pChar = digit + (digit <= 0x09)? '0' : 'a';
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibChar2Digit
/// @param      : p_arg
///               @arg  chr
/// @return     : int : if it is ok, return the num, or else return error val
/// @brief      : Convert nibble to hexadecimal from ASCII
/// @author     : kensky
/// @date       : 2013-9-28
/// @pre        : add precondition here if needed.
/// @note       : always hexadecimal, but it does not matter
////////////////////////////////////////////////////////////////////////////////
int ksLibChar2Digit(const ksChar chr);

void ksLibBuf2Str(ksU08 *pBuf, void *pStr, ksU16 len, char* startMark, char* endMark, char* spacing);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksLibNum2Str
/// @param      : p_arg
///               @arg  cNum    : integer number to convert
///               @arg  cString : output string
///               @arg  NumBase : number base
/// @return     : number of ASCII parameters
/// @brief      : Convert integer to ASCII in NumBase
/// @author     : kensky
/// @date       : 2014-4-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU16 ksLibNum2Str    (ksS64 cNum,
                       ksChar *pStr,
                       ksU08 NumBase);

ksS64 ksLibStr2Num    (const
                       ksChar *pStr,
                       ksU08  strLen,
                       ksU08  NumBase);

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void  ksDelayUsByLoop (ksU32 us);

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void  ksDelayMsByLoop (ksU32 ms);

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void  ksSetSysFreq    (ksU64 freq);

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
ksU64 ksGetSysFreq    (void);


#endif // __LIB_HAL_H_KENSKY_2020_10_8
