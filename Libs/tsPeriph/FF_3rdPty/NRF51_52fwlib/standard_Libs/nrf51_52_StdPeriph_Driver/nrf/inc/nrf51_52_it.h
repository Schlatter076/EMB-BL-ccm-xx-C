/*******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.h 
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
*******************************************************************************/

/***** Define to prevent recursive inclusion **********************************/
#ifndef __NRF51_52_IT_H
#define __NRF51_52_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/***** Includes ***************************************************************/
#include "../../config/nrf.h"

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))

/***** Exported types *********************************************************/

/***** Exported constants *****************************************************/

/***** Exported macro *********************************************************/

/***** Exported functions *****************************************************/
void NMI_Handler            (void);
void HardFault_Handler      (void);
void SVC_Handler            (void);
void PendSV_Handler         (void);
void SysTick_Handler        (void);

#ifdef __cplusplus
}
#endif

#endif // (defined __MCU_TYPE)        && \
          (defined _MCU_IS_NRF51822) && \
          (__MCU_TYPE == _MCU_IS_NRF51822)

#endif /* __NRF51_52_IT_H */
