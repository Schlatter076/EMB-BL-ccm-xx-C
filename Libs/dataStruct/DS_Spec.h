/*******************************************************************************
  * File    :  DS_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-9
  * Brief   :  
*******************************************************************************/
#ifndef __DS_SPEC_H_KENSKY_2012_9_9
#define __DS_SPEC_H_KENSKY_2012_9_9

/**** Includes ****************************************************************/
#include 	<errno.h>
#include 	<stddef.h>

#ifdef  __cplusplus
//******************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Defines *****************************************************************/
#define ksOffsetof(T, member)  ((size_t)(&((T *)0)->member))
/**
 * container_of - cast a member of a structure out to the containing structure
 * @pMbr			: the pointer to the member.
 * @cntnrType	: the type of the container struct this is embedded in.
 * @mbr				: the name of the member within the struct.
 *
 */
#ifndef container_of
#if ((defined __GNUC__) && (0)) // todo ??
#define container_of(pMbr, cntnrType, mbr) 											\
		({ 																													\
			const typeof(((cntnrType *)0)->mbr)*__mptr = (pMbr); 			\
			(cntnrType *)((char *)__mptr - offsetof(cntnrType, mbr)); \
		})
#else
#define container_of(pMbr, cntnrType, mbr) 									    \
			((cntnrType*)((size_t)pMbr - ksOffsetof(cntnrType, mbr)))
#endif // __GNUC__
#endif // container_of

/**** DS Module Switch ********************************************************/
#define     	_DS_MODULE_is_ON        				(0x00u)
#define     	_DS_MODULE_is_OFF       				(0x01u)

/**** Return Messages *********************************************************/
#define     	_DS_SUCCESSFUL          				(0x00l)
#define     	_DS_is_EMPTY            				(0x01l)
#define     	_DS_is_not_EMPTY        				(0x02l)
#define     	_DS_is_FULL             				(0x03l)
#define     	_DS_is_not_FULL         				(0x04l)
#define     	_DS_ERROR               				(-0x01)
#define     	_DS_FAIL_MALLOC         				(-0x02)
#define     	_DS_FAIL_RDHEAD         				(-0x03)
#define     	_DS_FAIL_PARA_ERR       				(-0x04)
#define     	_DS_FAIL_MISMATCH       				(-0x05)
#define     	_DS_FAIL_WR             				(-0x06)

#define       _DS_IS_FREE                     (0x00)
#define       _DS_LOCKED                      (!_DS_IS_FREE)

#define     	M_MINORBITS         						(0x08U)
#define     	M_MINORMASK         						((1U << MINORBITS) - 1)

#define     	M_MAJOR(dev)        						((unsigned char) ((dev) >> MINORBITS))
#define     	M_MINOR(dev)        						((unsigned char) ((dev) & MINORMASK))
#define     	M_MKDEV(ma, mi)     						(((ma) << MINORBITS) | (mi))

#define 			M_BV(n) 												(1<<(n))
#define 			M_FALSE													(0)
#define				M_TRUE													(!M_FALSE)
#define				M_REG_GET_VAL(reg, mask, os)		(((reg)&(mask))>>(os))

#define       M_DEV_NULL                      ((void *)0)
#define       M_DEV_EOK                       (0x00U)         /**< There is no error */


#define       M_DEV_TIMEOUT                   (0x0000f000ul)  /**< timedout period */

#define				M_is_POW_OF_2(val) 							((val) & ((val) - 1))

// used for ESP8266
#ifdef ICACHE_FLASH
#define ICACHE_FLASH_ATTR         __attribute__((section(".irom0.text")))
#define ICACHE_RODATA_ATTR        __attribute__((section(".irom.text")))
#else
#define ICACHE_FLASH_ATTR
#define ICACHE_RODATA_ATTR
#endif /* ICACHE_FLASH */

/**** Global Data Type ********************************************************/
typedef enum
{
	dsDisable = 0,
	dsEnable	= !dsDisable,
} dsState_e;

/**** Global Data Types *******************************************************/
typedef union
{
  unsigned char       *pU08;
  unsigned short      *pU16;
  unsigned int        *pU32;
  unsigned long long  *pU64;
} generic_data_p;

typedef enum
{
  data_is_U08 = 0x00000010,
  data_is_U16 = 0x00000100,
  data_is_U32 = 0x00001000,
  data_is_U64 = 0x00010000,
} data_type_e;

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus


#endif // __DS_SPEC_H_KENSKY_2012_9_9-9
