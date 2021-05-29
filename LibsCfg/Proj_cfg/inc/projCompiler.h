/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : compiler.h
* Author             : AMS - HEA&RF BU
* Version            : V1.0.0
* Date               : 19-July-2012
* Description        : Compiler-dependent macros.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
#ifndef   __PROJ_COMPILER_H
#define   __PROJ_COMPILER_H


/**
 * @cond (NODOX)
 */
/*lint -save -e27 -e10 -e19 */
#if   defined (__LINT__)
#define STACK_BASE      0x1F000 // Arbitrary value.
#define STACK_TOP       0x20000 // Arbitrary value.

#elif defined ( __CC_ARM )
extern char STACK$$Base;
extern char STACK$$Length;
#define STACK_BASE      &STACK$$Base
#define STACK_TOP       ((void*)((uint32_t)STACK_BASE + (uint32_t)&STACK$$Length))

#elif defined ( __ICCARM__ )
extern char CSTACK$$Base;
extern char CSTACK$$Length;
#define STACK_BASE      &CSTACK$$Base
#define STACK_TOP       ((void*)((uint32_t)STACK_BASE + (uint32_t)&CSTACK$$Length))

#elif defined ( __GNUC__ )
extern unsigned long    __StackTop;
extern unsigned long    __StackLimit;

#ifndef STACK_BASE
#define STACK_BASE      &__StackLimit
#endif

#ifndef STACK_TOP
#define STACK_TOP       &__StackTop
#endif

#endif // STACK


#if   defined ( __CC_ARM )    // MDK

#define __ASM               __asm        /*!< asm keyword for ARM Compiler          */
#define __INLINE            __inline     /*!< inline keyword for ARM Compiler       */
#define __STATIC_INLINE     static __inline

#elif defined ( __ICCARM__ ) 	// IAR

#define __ASM               asm           /*!< asm keyword for IAR Compiler          */
#define __INLINE            inline        /*!< inline keyword for IAR Compiler. Only available in High optimization mode! */
#define __STATIC_INLINE     static inline
#define PACKED
#ifndef __WEAK
//#define __WEAK              _Pragma("object_attribute = __weak ")
#endif

#elif defined ( __GNUC__ )    // GNU

#define __ASM               __asm        /*!< asm keyword for GNU Compiler          */
#define __INLINE            inline       /*!< inline keyword for GNU Compiler       */
#define __STATIC_INLINE     static inline

#ifndef __packed
 #define __packed
#endif

#ifndef __PACKED
#define PACKED              __attribute__((packed))
#endif

#ifndef __WEAK
//#define __WEAK              __attribute__((weak))
#endif

#elif defined ( __TASKING__ )
#define __ASM               __asm        /*!< asm keyword for TASKING Compiler      */
#define __INLINE            inline       /*!< inline keyword for TASKING Compiler   */
#define __STATIC_INLINE     static inline

#else

#define PACKED
#define __packed
#endif

#if (__MCU_TYPE == _MCU_IS_ESP8266)
#ifdef __cplusplusl
  #define   __I         volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I         volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O         volatile             /*!< Defines 'write only' permissions                */
#define     __IO        volatile             /*!< Defines 'read / write' permissions              */
#endif // (__MCU_TYPE == _MCU_IS_ESP8266)

#endif // __PROJ_COMPILER_H
