/*******************************************************************************
  * File    :  ksPeriphSpec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2019-9-19
  * Brief   :  
*******************************************************************************/
#ifndef __RL_PERIPH_SPEC_H_KENSKY_2019_9_19
#define __RL_PERIPH_SPEC_H_KENSKY_2019_9_19

/**** Includes ****************************************************************/
#include <projCfg.h>

#ifndef __MCU_TYPE
#error "please specify the MCU type in first place"
#endif

/**** Defines *****************************************************************/
#ifndef __UUID
#define     _uuidCheck()  // override the global uuid checking routine
#endif

#define     __MINORBITS                               8
#define     __MINORMASK                               ((1U << MINORBITS) - 1)

#define     __MAJOR(dev)                              ((unsigned char) ((dev) >> MINORBITS))
#define     __MINOR(dev)                              ((unsigned char) ((dev) & MINORMASK))
#define     __MKDEV(ma, mi)                           (((ma) << MINORBITS) | (mi))

#define     __DEV_NULL                                ((void *)0)
#define     __DEV_ACK                                 (1)     /**< There is no error */
#define     __DEV_EOK                                 (0)     /**< There is no error */
#define     __DEV_ERROR                               (-1)    /**< A generic error happens */
#define     __DEV_ETIMEOUT                            (-2)    /**< Timed out */
#define     __DEV_EFULL                               (-3)    /**< The resource is full */
#define     __DEV_EEMPTY                              (-4)    /**< The resource is empty */
#define     __DEV_ENOMEM                              (-5)    /**< No memory */
#define     __DEV_ENOSYS                              (-6)    /**< No system */
#define     __DEV_EBUSY                               (-7)    /**< Busy, not ready */
#define     __DEV_EIO                                 (-8)    /**< IO error */
#define     __DEV_UNDERFLOW                           (-9)    /**< underflow error */
#define     __DEV_OVERFLOW                            (-10)   /**< overflow error */
#define     __DEV_ERR_PARAS                           (-11)   /**< Prameters error */
#define     __DEV_UNSUPPORTED                         (-12)   /**< unsupportted error */
#define     __DEV_UNACCESSABLE                        (-13)   /**< not accessible error */
#define     __DEV_ELEN                                (-14)   /**< something need to be implemented */
#define     __DEV_ENULL                               (-15)   /**< something need to be implemented */
#define     __DEV_ENODEV                              (-16)   /**< something need to be implemented */
#define     __DEV_TODO                                (-127)  /**< something need to be implemented */
#define     __DEV_TIMEOUT                             (0x0000F000ul)   /**< timedout period */

#define     _REG_GET_VAL(reg, mask, os)               (((reg)&(mask))>>(os))

#define     _KS_BV(n)                                 (1<<(n)) /* bit value */

#ifndef FALSE
#define     FALSE                                     (0)
#endif

#ifndef TRUE
#define     TRUE                                      (!FALSE)
#endif

#define     _KS_SET_BIT(REG, BIT)                     ((REG) |= (BIT))
#define     _KS_CLEAR_BIT(REG, BIT)                   ((REG) &= ~(BIT))
#define     _KS_READ_BIT(REG, BIT)                    ((REG) & (BIT))
#define     _KS_CLEAR_REG(REG)                        ((REG) = (0x0))
#define     _KS_WRITE_REG(REG, VAL)                   ((REG) = (VAL))
#define     _KS_READ_REG(REG)                         ((REG))
#define     _KS_MODIFY_REG(REG, CLEARMASK, SETMASK)   WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/*
 *  This macro is for use by other macros to form a fully valid C statement.
 *  Without this, the if/else conditionals could show unexpected behavior.
 *
 *  For example, use...
 *    #define SET_REGS()  st( ioreg1 = 0; ioreg2 = 0; )
 *  instead of ...
 *    #define SET_REGS()  { ioreg1 = 0; ioreg2 = 0; }
 *  or
 *    #define  SET_REGS()    ioreg1 = 0; ioreg2 = 0;
 *  The last macro would not behave as expected in the if/else construct.
 *  The second to last macro will cause a compiler error in certain uses
 *  of if/else construct
 *
 *  It is not necessary, or recommended, to use this macro where there is
 *  already a valid C statement.  For example, the following is redundant...
 *    #define CALL_FUNC()   st(  func();  )
 *  This should simply be...
 *    #define CALL_FUNC()   func()
 *
 * (The while condition below evaluates false without generating a
 *  constant-controlling-loop type of warning on most compilers.)
 */

/**** LOCAL DATA TYPES ********************************************************/
#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)
#include "./FC_ARCH/inc/archSTM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM8)
#elif (__MCU_TYPE == _MCU_IS_MSP430)
#elif (__MCU_TYPE == _MCU_IS_AVR)
#elif (__MCU_TYPE == _MCU_IS_C51)
#elif (__MCU_TYPE == _MCU_IS_PIC16)
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "./FC_ARCH/inc/archSTM32l1x.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#include "./FC_ARCH/inc/archSTM32F0x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "./FC_ARCH/inc/archSTM32L0xx.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "./FC_ARCH/inc/archEFM32xGyyy.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32ZGxxx)
#include "./FC_ARCH/inc/archEFM32xGyyy.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "./FC_ARCH/inc/archEFM32xGyyy.h"
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include <FC_ARCH/inc/archCM0.h>
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include <FC_ARCH/inc/archCM4.h>
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#include <FC_ARCH/inc/archESP8266.h>  // ESP8266 is 32bits, we can use arm3 ARCH
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#include <FC_ARCH/inc/archCM3.h>      // CC1310 is cortex M3
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#include <FC_ARCH/inc/archCM4.h>      // EFR32BG1Pxxx is cortex M4
#elif (__MCU_TYPE == STM32F429_439xx)
#include <FC_ARCH/inc/archCM4.h>      // EFR32BG1Pxxx is cortex M4
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include <FC_ARCH/inc/archCM0plus.h>  // MKL17zxxVFM4 is cortex M0+
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#include <FC_ARCH/inc/archCM0plus.h>  // HSDC32L1xx is cortex M0+
#endif

/*! @name Min/max macros */
/* @{ */

/**
  * @brief  This macro returns the maximum value between two inputs,
  *                    the evaluation is done with the ">" operator
  * @param  a  First input
  * @param  b  Second input
  * @retval Max(a,b)
  */
#if !defined(MIN)
#define MIN(a, b)             (((a) < (b)) ? (a) : (b))
#endif

/**
  * @brief  This macro returns the maximum value between two inputs,
  *                    the evaluation is done with the ">" operator
  * @param  a  First input
  * @param  b  Second input
  * @retval Max(a,b)
  */
#if !defined(MAX)
#define MAX(a, b)             (((a) > (b)) ? (a) : (b))
#endif
/* @} */

/*! @brief Computes the number of elements in an array. */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr)       (sizeof(arr) / sizeof((arr)[0]))
#endif

/*! @name UINT16_MAX/UINT32_MAX value */
/* @{ */
#if !defined(UINT16_MAX)
#define UINT16_MAX ((uint16_t)-1)
#endif

#if !defined(UINT32_MAX)
#define UINT32_MAX ((uint32_t)-1)
#endif
/* @} */

/*! @name Timer utilities */
/* @{ */
/*! Macro to convert a microsecond period to raw count value */
#define USEC_TO_COUNT(us, clockFreqInHz)        (uint64_t)(((uint64_t)(us) * (clockFreqInHz)) / 1000000U)
/*! Macro to convert a raw count value to microsecond */
#define COUNT_TO_USEC(count, clockFreqInHz)     (uint64_t)((uint64_t)count * 1000000U / clockFreqInHz)

/*! Macro to convert a millisecond period to raw count value */
#define MSEC_TO_COUNT(ms, clockFreqInHz)        (uint64_t)((uint64_t)ms * clockFreqInHz / 1000U)
/*! Macro to convert a raw count value to millisecond */
#define COUNT_TO_MSEC(count, clockFreqInHz)     (uint64_t)((uint64_t)count * 1000U / clockFreqInHz)
/* @} */


typedef union
{
  ksU08     ui08[sizeof(ksU32)/sizeof(ksU08)];
  ksS08     si08[sizeof(ksS32)/sizeof(ksS08)];
  ksU16     ui16[sizeof(ksU32)/sizeof(ksU16)];
  ksS16     si16[sizeof(ksS32)/sizeof(ksS16)];
  ksU32     ui32[sizeof(ksU32)/sizeof(ksU16)];
  ksS32     si32[sizeof(ksS32)/sizeof(ksS32)];
  ksU32     all;
} int_u, ksInt_u, ksUint_u;

typedef enum
{
  ksDisbale   = 0,
  ksEnable    = !ksDisbale
} ksState_e;

#define   _KS_RW_STORAGE      (0x00)
#define   _KS_RO_STORAGE      (0x01)
typedef enum
{
  ksRAM   = _KS_RW_STORAGE,
  ksFlash = _KS_RO_STORAGE,
} ksStroage_e;

typedef enum
{ // for synchronization
  ksFree    = 0x00,
  ksLocked  = 0x01,
} ksLockState_e;

//typedef enum
//{
//  mcu_big_endian    = 0,
//  mcu_litle_endian  = 1,
//  mcu_unkonw_endian = 2,
//} mcu_endian_e;

typedef  void       (*fnGenericCallBack)(void);
typedef  void       (*pResetHandler)(void);
typedef  void       (*pFunction)(void);

#if 0
/**
 *  The object type can be one of the follows with specific
 *  macros enabled:
 *  - Thread
 *  - Semaphore
 *  - Mutex
 *  - Event
 *  - MailBox
 *  - MessageQueue
 *  - MemHeap
 *  - MemPool
 *  - Device
 *  - Timer
 *  - Module
 *  - Unknown
 *  - Static
 */
enum rt_object_class_type
{
    RT_Object_Class_Thread = 0,                         /**< The object is a thread.                */
#ifdef RT_USING_SEMAPHORE
    RT_Object_Class_Semaphore,                          /**< The object is a semaphore.             */
#endif
#ifdef RT_USING_MUTEX
    RT_Object_Class_Mutex,                              /**< The object is a mutex.                 */
#endif
#ifdef RT_USING_EVENT
    RT_Object_Class_Event,                              /**< The object is a event.                 */
#endif
#ifdef RT_USING_MAILBOX
    RT_Object_Class_MailBox,                            /**< The object is a mail box.              */
#endif
#ifdef RT_USING_MESSAGEQUEUE
    RT_Object_Class_MessageQueue,                       /**< The object is a message queue.         */
#endif
#ifdef RT_USING_MEMHEAP
    RT_Object_Class_MemHeap,                            /**< The object is a memory heap            */
#endif
#ifdef RT_USING_MEMPOOL
    RT_Object_Class_MemPool,                            /**< The object is a memory pool.           */
#endif
#ifdef RT_USING_DEVICE
    RT_Object_Class_Device,                             /**< The object is a device                 */
#endif
    RT_Object_Class_Timer,                              /**< The object is a timer.                 */
#ifdef RT_USING_MODULE
    RT_Object_Class_Module,                             /**< The object is a module.                */
#endif
    RT_Object_Class_Unknown,                            /**< The object is unknown.                 */
    RT_Object_Class_Static = 0x80                       /**< The object is a static object.         */
};



/* RT-Thread basic data type definitions */
typedef signed   char                   rt_int8_t;      /**<  8bit integer type */
typedef signed   short                  rt_int16_t;     /**< 16bit integer type */
typedef signed   long                   rt_int32_t;     /**< 32bit integer type */
typedef unsigned char                   rt_uint8_t;     /**<  8bit unsigned integer type */
typedef unsigned short                  rt_uint16_t;    /**< 16bit unsigned integer type */
typedef unsigned long                   rt_uint32_t;    /**< 32bit unsigned integer type */
typedef int                             rt_bool_t;      /**< boolean type */

/* 32bit CPU */
typedef long                            rt_base_t;      /**< Nbit CPU related date type */
typedef unsigned long                   rt_ubase_t;     /**< Nbit unsigned CPU related data type */

typedef rt_base_t                       rt_err_t;       /**< Type for error number      */
typedef rt_uint32_t                     rt_time_t;      /**< Type for time stamp        */
typedef rt_uint32_t                     rt_tick_t;      /**< Type for tick count        */
typedef rt_base_t                       rt_flag_t;      /**< Type for flags             */
typedef rt_ubase_t                      rt_size_t;      /**< Type for size number       */
typedef rt_ubase_t                      rt_dev_t;       /**< Type for device            */
typedef rt_base_t                       rt_off_t;       /**< Type for offset            */


//typedef     uint16_t    ykDev_t;
//
//
//
//typedef struct
//{
//  unsigned char   major_num;
//  unsigned char   minor_num;
//} ykDevNum_t;

enum yk_dev_class_t
{
    RT_Device_Class_Char = 0,   /**< character device */
    RT_Device_Class_Block,      /**< block device */
    RT_Device_Class_NetIf,      /**< net interface */
    RT_Device_Class_MTD,        /**< memory device */
    RT_Device_Class_CAN,        /**< CAN device */
    RT_Device_Class_RTC,        /**< RTC device */
    RT_Device_Class_Sound,      /**< Sound device */
    RT_Device_Class_Graphic,    /**< Graphic device */
    RT_Device_Class_I2CBUS,     /**< I2C bus device */
    RT_Device_Class_USBDevice,  /**< USB slave device */
    RT_Device_Class_USBHost,    /**< USB host bus */
    RT_Device_Class_SPIBUS,     /**< SPI bus device */
    RT_Device_Class_SPIDevice,  /**< SPI device */
    RT_Device_Class_SDIO,       /**< SDIO bus device */
    RT_Device_Class_PM,         /**< PM pseudo device */
    RT_Device_Class_Unknown     /**< unknown device */
};


struct rt_list_node
{
    struct rt_list_node                 *next;          /* point to next node. */
    struct rt_list_node                 *prev;          /* point to prev node. */
};
typedef struct rt_list_node rt_list_t;                  /* Type for lists.     */

struct ykObject
{
  char      name[8/*RT_NAME_MAX*/]; /**< name of kernel object      */
  uint8_t   type;                   /**< type of kernel object      */
  uint8_t   flag;                   /**< flag of kernel object      */

#ifdef RT_USING_MODULE
    void        *module_id;                             /**< id of application module   */
#endif
    rt_list_t   list;                                   /**< list node of kernel object */
};
typedef struct ykObject *ykObject_t;                  /* Type for kernel objects.     */


typedef struct ykDev *ykDev_t;
struct ykDev
{
  struct    ykObject        parent;             /**< inherit from rt_object */
  enum      yk_dev_class_t  type;               /**< device type */
  uint16_t                  flag, open_flag;    /**< device flag and device open flag */
  uint8_t                   device_id;          /* 0 - 255 */
  /* device call back */
  int32_t (*rx_indicate)(ykDev_t dev, rt_size_t size);
  int32_t (*tx_complete)(ykDev_t dev, void      *buffer);
    /* common device interface */
  int32_t   (*init)   (ykDev_t dev);
  int32_t   (*open)   (ykDev_t dev, rt_uint16_t oflag);
  int32_t   (*close)  (ykDev_t dev);
  rt_size_t (*read)   (ykDev_t dev, rt_off_t pos, void *buffer, rt_size_t size);
  rt_size_t (*write)  (ykDev_t dev, rt_off_t pos, const void *buffer, rt_size_t size);
  int32_t   (*control)(ykDev_t dev, rt_uint8_t cmd, void *args);
#if defined __USING_DEVICE_SUSPEND
  int32_t   (*suspend)(ykDev_t dev);
  int32_t   (*resumed)(ykDev_t dev);
#endif
    void *user_data;                            /**< device private data */
};


typedef uint32_t        __kernel_dev_t;
typedef __kernel_dev_t  dev_t;

#endif // 0

#endif // __RL_PERIPH_SPEC_H_KENSKY_2019_9_19
