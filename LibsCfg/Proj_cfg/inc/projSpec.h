/*******************************************************************************
  * File    : "proj_spec.h"
  * Author  : kensky
  * Version : v0.0
  * Date    : 2020-8-9
  * Brief   :
*******************************************************************************/
#ifndef __PROJ_SPEC_H_20120809YK
#define __PROJ_SPEC_H_20120809YK

/**** Global Variables ********************************************************/
extern volatile unsigned char   mcuEndian;
extern volatile unsigned char   *gp_StkTop;
extern volatile unsigned char   *gp_StkHip;
extern volatile unsigned char   *gp_free;

/**** Defines *****************************************************************/
/**** MCU Types ***************************************************************/
#define     _MCU_IS_AVR                               (0x00000010uL)
#define     _MCU_IS_C51                               (0x00000020uL)
#define     _MCU_IS_MSP430                            (0x00000040uL)
#define     _MCU_IS_PIC16                             (0x00000080uL)
#define     _MCU_IS_EFM32ZGxxx                        (0x00000100uL)
#define     _MCU_IS_EFM32TGxxx                        (0x00000101uL)
#define     _MCU_IS_EFM32Gxxx                         (0x00000102uL)
#define     _MCU_IS_EFR32BG1Pxxx                      (0x00000200uL)
#define     _MCU_IS_EFR32FG1Pxxx                      (0x00000201uL)
#define     _MCU_IS_EFR32FG1Vxxx                      (0x00000202uL)
#define     _MCU_IS_EFR32MG1Pxxx                      (0x00000204uL)
#define     _MCU_IS_FSKLxxZ4                          (0x00000400uL)
#define     _MCU_IS_FSKL2yZxx                         (0x00000401uL)
#define     _MCU_IS_NRF24LE1                          (0x00000800uL)
#define     _MCU_IS_NRF51822                          (0x00000810uL)
#define     _MCU_IS_NRF52810                          (0x00000820uL)
#define     _MCU_IS_NRF52811                          (0x00000821uL)
#define     _MCU_IS_NRF52832                          (0x00000822uL)
#define     _MCU_IS_NRF52833                          (0x00000823uL)
#define     _MCU_IS_NRF52840                          (0x00000824uL)
#define     _MCU_IS_TI_CC13XX                         (0x00001000uL)
#define     _MCU_IS_TI_CC2640                         (0x00002000uL)
#define     _MCU_IS_STM8                              (0x00004000uL)
#define     _MCU_IS_STN32F0xx                         (0x00008000uL)
#define     _MCU_IS_STM32F10x                         (0x00008001uL)
#define     _MCU_IS_STM32F2xx                         (0x00008002uL)
#define     _MCU_IS_STM32F4xx                         (0x00008004uL)
#define     _MCU_IS_STM32L0x                          (0x00008008uL)
#define     _MCU_IS_STM32L1x                          (0x00008010uL)
#define     _MCU_IS_HSDC32L110                        (0x00010000uL)

#define     _MCU_IS_ESP8266                           (0xFFFFFFFDuL)
#define     _MCU_IS_AMD64                             (0xFFFFFFFFuL)

/**** MCU bits ****************************************************************/
#define     _MCU_IS_08_BITS                           (0x00uL)
#define     _MCU_IS_16_BITS                           (0x01uL)
#define     _MCU_IS_32_BITS                           (0x02uL)
#define     _MCU_IS_64_BITS                           (0x03uL)

/**** Low Power Strategy ******************************************************/
#define     _MCU_LPWR_SLEEP                           (0x00uL)
#define     _MCU_LPWR_STOP                            (0x01uL)
#define     _MCU_LPWR_STANDBY                         (0x02uL)

/**** MCU endian **************************************************************/
#define     _MCU_is_BIG_ENDIAN                        (0x00uL)
#define     _MCU_is_LITTLE_ENDIAN                     (0x01uL)
#define     _MCU_is_UNKNOWN_ENDIAN                    (0xFFuL)

/***** Switch Macros **********************************************************/
#define     _GLOBAL_CONFIGURED                        (0x01u)
#define     _LOCAL_CONFIGURED                         (!(_GLOBAL_CONFIGURED))

#define     _MODULE_ON                                (1)
#define     _MODULE_OFF                               (!(_MODULE_ON))

/**** IRQ Priority Macros *****************************************************/
#define     _HAL_IRQ_PrioGRP0                         (0x00u) // this is not modifiable!! "0"
#define     _HAL_IRQ_PrioGRP1                         (0x01u) // this is not modifiable!! "1"
#define     _HAL_IRQ_PrioGRP2                         (0x02u) // this is not modifiable!! "2"
#define     _HAL_IRQ_PrioGRP3                         (0x03u) // this is not modifiable!! "3"
#define     _HAL_IRQ_PrioGRP4                         (0x04u) // this is not modifiable!! "4"

#define     _HAL_IRQ_PrePrio0                         (0x00u)
#define     _HAL_IRQ_PrePrio1                         (0x01u)
#define     _HAL_IRQ_PrePrio2                         (0x02u)
#define     _HAL_IRQ_PrePrio3                         (0x03u)
#define     _HAL_IRQ_PrePrio4                         (0x04u)
#define     _HAL_IRQ_PrePrio5                         (0x05u)
#define     _HAL_IRQ_PrePrio6                         (0x06u)
#define     _HAL_IRQ_PrePrio7                         (0x07u)
#define     _HAL_IRQ_PrePrio8                         (0x08u)
#define     _HAL_IRQ_PrePrio9                         (0x09u)

#define     _HAL_IRQ_SubPrio0                         (0x00u)
#define     _HAL_IRQ_SubPrio1                         (0x01u)
#define     _HAL_IRQ_SubPrio2                         (0x02u)
#define     _HAL_IRQ_SubPrio3                         (0x03u)
#define     _HAL_IRQ_SubPrio4                         (0x04u)
#define     _HAL_IRQ_SubPrio5                         (0x05u)
#define     _HAL_IRQ_SubPrio6                         (0x06u)
#define     _HAL_IRQ_SubPrio7                         (0x07u)
#define     _HAL_IRQ_SubPrio8                         (0x08u)
#define     _HAL_IRQ_SubPrio9                         (0x09u)

#define     st(x)                                     do {x} while(0)

#define     __CSTACK_FILL_NUM                         (0x24)
#define     __CSTACK_FILL_SZ                          (0x10)

#define     __SET_BIT(REG, BIT)                       ((REG) |= (BIT))
#define     __CLEAR_BIT(REG, BIT)                     ((REG) &= ~(BIT))
#define     __READ_BIT(REG, BIT)                      ((REG) & (BIT))
#define     __CLEAR_REG(REG)                          ((REG) = (0x0))
#define     __WRITE_REG(REG, VAL)                     ((REG) = (VAL))
#define     __READ_REG(REG)                           ((REG))
#define     __MODIFY_REG(REG, CLEARMASK, SETMASK)     __WRITE_REG((REG), (((__READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define     __KS_INVALID                              (void *)(0xFFFFFFFFul)
#define     __LIB_STRING_NO_ERR                       (0x00)
#define     __LIB_STRING_CMP_OK                       (0x00)

/**** Global Data Types *******************************************************/
typedef enum
{
  mcu_big_endian      = _MCU_is_BIG_ENDIAN,
  mcu_litle_endian    = _MCU_is_LITTLE_ENDIAN,
  mcu_unkonwn_endian  = _MCU_is_UNKNOWN_ENDIAN,
} mcu_endian_e;

/***** Function Prototypes ****************************************************/
void projDebug  (void);
void projInit   (void);
#endif // __PROJ_SPEC_H_20120809YK
