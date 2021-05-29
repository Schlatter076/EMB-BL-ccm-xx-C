/*******************************************************************************
  * File    :  SPI_PHY.h
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-23
  * Brief   :
*******************************************************************************/
#ifndef __SPI_PHY_H_KENSKY_2020_9_23
#define __SPI_PHY_H_KENSKY_2020_9_23

/**** Includes ****************************************************************/
#include <00_SPI/4_CFG/SPI_cfg.h>

#if   (defined __MCU_TYPE) && (__MCU_TYPE == _MCU_IS_STM32F10x)
#include "../../STM32_F10x/inc/SPI_STM32F10x.h"
#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
#include "../../STM32L1xx/inc/SPI_STM32L1x.h"
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#include "../../FSKLxxZyyy/inc/spiFSKLxxZyyy.h"
#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#include "../../STM32L0xx/inc/stm32L0xSpi.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#include "../../EFM32TGxx/inc/efm32TGxxSpi.h"
#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#include "../../EFM32TGxx/inc/efm32TGxxSpi.h"
#elif (__MCU_TYPE == _MCU_IS_ESP8266)

#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#include "../../NRF52832/inc/nrf52832Spi.h"
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
#include "../../NRF51822/inc/nrf51822Spi.h"
#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#include "../../EFR32yGxx/inc/efr32yGxxSpi.h"
#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

/**** Defines *****************************************************************/
#define __Activate_SPI(S)       __KS_IO_SET_LOW(&(S)->gpio[_KS_SPI_NSS])
#define __Deactivate_SPI(S)     __KS_IO_SET_HIGH(&(S)->gpio[_KS_SPI_NSS])

/***** Function Prototypes ****************************************************/
void  ksSpiInitStruct       (ksSPI_para_t *pParams,
                             ksU16        Direction,
                             ksU16        Mode,
                             ksU16        DataSize,
                             ksU16        CPOL,
                             ksU16        CPHA,
                             ksU16        NSS,
                             ksU16        Prescaler,
                             ksU16        Endian,
                             ksU16        CRCPolynomial);

ksU08 sSPITxRxU08           (const ksSPI_t *pSPI, ksU08 Byte);
void  sSPITxU08             (const ksSPI_t *pSPI, ksU08 Byte);
void  sSPITxRxBuffer        (const
                             ksSPI_t *pSPI,
                             const
                             ksU08   *pTxBytes,
                             ksU08   *pRxBytes,
                             ksU32   size);
void  sSPITxBuffer          (const
                             ksSPI_t *pSPI,
                             const
                             ksU08   *pTxBytes,
                             ksU32   size);
#endif // __SPI_PHY_H_KENSKY_2020_9_23
