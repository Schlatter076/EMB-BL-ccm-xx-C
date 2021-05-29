////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "NVIC_NRF51822.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-8
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_08_NVIC_1_PHY_NRF51822_INC_NVIC_NRF51822_H_KENSKY_2016__
#define __LIBS_KSPERIPH_08_NVIC_1_PHY_NRF51822_INC_NVIC_NRF51822_H_KENSKY_2016__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "../../../4_CFG/NVIC_cfg.h"

#if (defined __MCU_TYPE)       && \
    (defined _MCU_IS_NRF51822) && \
    (__MCU_TYPE == _MCU_IS_NRF51822)

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** Defines *****************************************************************/
#define   NVIC_PriorityGroup_0            ((ksU32)(0)) // meaningless
#define   IS_NVIC_PRIORITY_GROUP(grp)     ((grp) == NVIC_PriorityGroup_0)

/**
  * @brief  NVIC Init Structure definition
  */
typedef struct
{
  ksS08      IRQn;          /*!< Specifies the IRQn to be enabled or disabled.
                                 This parameter can be a value of @ref IRQn_Type
                                 (For the complete NRF51822 Devices IRQ Channels list,
                                 please refer to stm32l0xx.h file) */
  ksU08      preemptPrio;   /*!< Specifies the priority level for the IRQn in NVIC_IRQChannel. 0 .. 3.  */
  ksU08      subPrio;       /*!dummy value for cortex M0 and M0+.  */
  funState_e IRQnCmd;       /*!< Specifies if the IRQn defined in NVIC_IRQChannel
                                 will be enabled or disabled.
                                 This parameter can be set either to ENABLE or DISABLE */
} NVIC_InitTypeDef, ksNvicInit_t;

/***** Function Prototypes ****************************************************/
/*******************************************************************************
 brief    :  NRF51822_NVIC_get_Status.
 get the NVIC status of a IRQn
 param    :  IRQn        : irq number
 retrieval :  bool status
 -- 0 (false): setted
 -- 1 (true):   not set
 Note     : None
 *******************************************************************************/
__STATIC_INLINE ksNvicStatus_e NRF51822_NVIC_Get_Status(ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  return (ksNvicStatus_e)!!(NVIC->ISER[0] & ((uint32_t) 1 << (IRQn&0x1F)));
}

////////////////////////////////////////////////////////////////////////////////
/// @fn     : NRF51822_NVIC_Set_Status
/// @param  : IRQn : ira channel number
/// @return : description of return value.
/// @brief  : Brief description of the function.
/// @author : kensky
/// @date   : 2016-1-8
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void NRF51822_NVIC_Set_Pending (ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  NVIC->ISPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

////////////////////////////////////////////////////////////////////////////////
/// @fn     : NRF51822_NVIC_Clear_Pending
/// @param  : IRQn : ira channel number
/// @return : description of return value.
/// @brief  : Brief description of the function.
/// @author : kensky
/// @date   : 2016-1-8
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void NRF51822_NVIC_Clear_Pending (IRQn_Type IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  NVIC->ICPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: NRF51822_NVIC_Enable
/// * Paras    : IRQn   :irq number
/// * Returns  : -1     : failure
/// *          :  0     : success
/// * Brief    :
/// * Author   : kensky
/// * Build on : 2020-12-7
/// * Note     : None
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE void NRF51822_NVIC_Enable(ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  NVIC->ISER[0] = (uint32_t) 1 << (IRQn & 0x1F);
}

////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: NRF51822_NVIC_Disable
/// * Paras    : IRQn   :irq number
/// * Returns  : -1     : failure
/// *          :  0     : success
/// * Brief    :
/// * Author   : kensky
/// * Build on : 2020-12-7
/// * Note     : None
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE void NRF51822_NVIC_Disable(ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  NVIC->ICER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

__STATIC_INLINE void nrf51822NvicClear (ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= (IRQn_Type)0, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= (IRQn_Type)25, __ASSERT_LIMIT);

  NVIC->ICPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

////////////////////////////////////////////////////////////////////////////////
/// @fn     : NRF51822_NVIC_Is_Enable
/// * Paras : IRQn   :irq number
/// @return : description of return value.
/// @brief  : check if the IRQn is enabled
/// @author : kensky
/// @date   : 2016-1-8
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE ksNvicStatus_e NRF51822_NVIC_Is_Enabled(ksIsrChn IRQn)
{
  __KS_RUNTIME_ASSERT(IRQn >= POWER_CLOCK_IRQn, __ASSERT_LIMIT);
  __KS_RUNTIME_ASSERT(IRQn <= SWI5_IRQn, __ASSERT_LIMIT);

  return (ksNvicStatus_e)!!(NVIC->ISER[0]&((uint32_t)1<<(IRQn&0x1f)));
}

int8_t  NRF51822_NVIC_GPIO_Config (ksU08            Pin_Num,
                                   ksU08            PrePriority,
                                   ksU08            SubPriority);
void    NRF51822_NVIC_Init        (ksIsrChn        IRQn,
                                   ksU08            PrePriority,
                                   ksU08            SubPriority,
                                   ksNvicStatus_e  NVIC_State);

// the following interfaces are from bad wilton
int     NRF51822_fault_init         (ksU08 fault_channel, ksU08 priority);
void    NRF51822_SoftReset          (void);

#endif // (defined __MCU_TYPE)        && \
          (defined _MCU_IS_NRF51822) && \
          (__MCU_TYPE == _MCU_IS_NRF51822)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_08_NVIC_1_PHY_NRF51822_INC_NVIC_NRF51822_H_KENSKY_2016__
