/*******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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

/***** Includes ***************************************************************/
#include "../inc/nrf51_52_it.h"

#if ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))

#ifndef USE_EXTERNAL_PROJECT_IT_H

/***** Private typedef ********************************************************/
/***** Private define *********************************************************/
/***** Private macro **********************************************************/
/***** Private variables ******************************************************/
/***** Private function prototypes ********************************************/
/***** Private functions ******************************************************/

/***** Cortex-M3 Processor Exceptions Handlers ********************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void __attribute__ ((section(".after_vectors"),weak))
NMI_Handler (void)
{
  while(1);
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void __attribute__ ((section(".after_vectors"),weak,naked))
HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
 * @fn MemoryManagement_Handler
 */
void __attribute__ ((section(".after_vectors"),weak,naked))
MemoryManagement_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void __attribute__ ((section(".after_vectors"),weak,naked))
SVC_Handler(void)
{
  while(1);
}

/**
 * @fn DebugMon_Handler
 */
void __attribute__ ((section(".after_vectors"),weak,naked))
DebugMon_Handler(void)
{
  while(1);
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void __attribute__ ((section(".after_vectors"),weak,naked))
PendSV_Handler(void)
{
  while(1);
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void __attribute__ ((section(".after_vectors"),weak,naked))
SysTick_Handler(void)
{
  while(1);
}

/**
 * @fn UsageFault_Handler
 */
void __attribute__ ((section(".after_vectors"),weak,naked))
UsageFault_Handler (void)
{
  while(1);
}

/**
 * @fn BusFault_Handler
 */
void __attribute__ ((section(".after_vectors"),weak,naked))
BusFault_Handler (void)
{
  while(1);
}
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

#endif // (defined __MCU_TYPE)        && \
          (defined _MCU_IS_NRF51822) && \
          (__MCU_TYPE == _MCU_IS_NRF51822)

#endif //  USE_EXTERNAL_IRQ_DECLARATION
