/*******************************************************************************
  * File    :  Timer_DDL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __TIMER_DDL_H_KENSKY_2020_9_17
#define __TIMER_DDL_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/Timer_PHY.h"

#if 	(__MCU_TYPE == _MCU_IS_STM32F10x)

/**** Defines *****************************************************************/
#define     __Disable_TIMn(t)           __DIS_STM32_TIMn((t))
#define     __Enable_TIMn(t)            __EN_STM32_TIMn((t))
#define     __Set_TIMn_Cnt(t, v)        __Set_STM32_TIMn_Cnt((t), (v))
#define     __Clr_TIMn_Cnt(t)           __Clr_STM32_TIMn_Cnt((t))
#define     __Clr_TIMn_Pending(t, P)    __Clr_STM32_TIMn_Pending((t), (P))
#define     __Clr_TIMn_Flag(t, F)       __Clr_STM32_TIMn_Flag((t), (F))
#define     __Disable_TIMn_Irq(t, I)    __DIS_STM32_TIMn_Irq((t), (I))
#define     __Enable_TIMn_Irq(t, I)     __EN_STM32_TIMn_Irq((t), (I))
#define     __TIMn_Pending_is_Clr(t, P) __STM32_TIMn_Pending_is_Clr((t), (P))
#define     __TIMn_Pending_is_Set(t, P) __STM32_TIMn_Pending_is_Set((t), (P))
#define     __TIMn_Flag_is_Clr(t, F)    __STM32_TIMn_Flag_is_Clr((t), (F))
#define     __TIMn_Flag_is_Set(t, F)    __STM32_TIMn_Flag_is_Set((t), (F))
#define     __Clr_TIMn(t, R, C)         __Clr_STM32_TIMn((t), R, (C))
#define     __Set_TIMn(t, R, C)         __Set_STM32_TIMn((t), R, (C))
#define     __Get_TIMn(t, R, C)         __Get_STM32_TIMn((t), R, (C))
#define     __Assign_TIMn(t, R, C)      __Assign_STM32_TIMn((t), R, (C))
#define     __TIMn_is_Clr(t, R, C)      __STM32_TIMn_is_Clr((t), R, (C))
#define     __TIMn_is_Set(t, R, C)      __STM32_TIMn_is_Set((t), R, (C))
#define     __TIMn_Irq_is_On(t, I)      __STM32_TIMn_Irq_is_On((t), (I))
#define     __TIMn_get_CNT(t)           __STM32_TIMn_get_CNT((t))

#define     __KS_GET_TIMn_ARR(t, C)     __Get_TIMn((t), ARR, (C))
#define     __KS_SET_TIMn_ARR(t, C)     __Assign_TIMn((t), ARR, (C))

#elif (__MCU_TYPE == _MCU_IS_STM32L1x)
/**** Defines *****************************************************************/
#define     __Disable_TIMn(t)           __DIS_STM32_TIMn((t))
#define     __Enable_TIMn(t)            __EN_STM32_TIMn((t))
#define     __Set_TIMn_Cnt(t, v)        __Set_STM32_TIMn_Cnt((t), (v))
#define     __Clr_TIMn_Cnt(t)           __Clr_STM32_TIMn_Cnt((t))
#define     __Clr_TIMn_Pending(t, P)    __Clr_STM32_TIMn_Pending((t), (P))
#define     __Clr_TIMn_Flag(t, F)       __Clr_STM32_TIMn_Flag((t), (F))
#define     __Disable_TIMn_Irq(t, I)    __DIS_STM32_TIMn_Irq((t), (I))
#define     __Enable_TIMn_Irq(t, I)     __EN_STM32_TIMn_Irq((t), (I))
#define     __TIMn_Pending_is_Clr(t, P) __STM32_TIMn_Pending_is_Clr((t), (P))
#define     __TIMn_Pending_is_Set(t, P) __STM32_TIMn_Pending_is_Set((t), (P))
#define     __TIMn_Flag_is_Clr(t, F)    __STM32_TIMn_Flag_is_Clr((t), (F))
#define     __TIMn_Flag_is_Set(t, F)    __STM32_TIMn_Flag_is_Set((t), (F))
#define     __Clr_TIMn(t, R, C)         __Clr_STM32_TIMn((t), R, (C))
#define     __Set_TIMn(t, R, C)         __Set_STM32_TIMn((t), R, (C))
#define     __Get_TIMn(t, R, C)         __Get_STM32_TIMn((t), R, (C))
#define     __Assign_TIMn(t, R, C)      __Assign_STM32_TIMn((t), R, (C))
#define     __TIMn_is_Clr(t, R, C)      __STM32_TIMn_is_Clr((t), R, (C))
#define     __TIMn_is_Set(t, R, C)      __STM32_TIMn_is_Set((t), R, (C))
#define     __TIMn_Irq_is_On(t, I)      __STM32_TIMn_Irq_is_On((t), (I))
#define     __TIMn_get_CNT(t)           __STM32_TIMn_get_CNT((t))

#define     __KS_GET_TIMn_ARR(t, C)     __Get_TIMn((t), ARR, (C))
#define     __KS_SET_TIMn_ARR(t, C)     __Assign_TIMn((t), ARR, (C))

#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)

#elif (__MCU_TYPE == _MCU_IS_STN32F0xx)
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
#define     __Disable_TIMn(t)           __DIS_STM32_TIMn((t))
#define     __Enable_TIMn(t)            __EN_STM32_TIMn((t))
#define     __Set_TIMn_Cnt(t, v)        __Set_STM32_TIMn_Cnt((t), (v))
#define     __Clr_TIMn_Cnt(t)           __Clr_STM32_TIMn_Cnt((t))
#define     __Clr_TIMn_Pending(t, P)    __Clr_STM32_TIMn_Pending((t), (P))
#define     __Clr_TIMn_Flag(t, F)       __Clr_STM32_TIMn_Flag((t), (F))
#define     __Disable_TIMn_Irq(t, I)    __DIS_STM32_TIMn_Irq((t), (I))
#define     __Enable_TIMn_Irq(t, I)     __EN_STM32_TIMn_Irq((t), (I))
#define     __TIMn_Pending_is_Clr(t, P) __STM32_TIMn_Pending_is_Clr((t), (P))
#define     __TIMn_Pending_is_Set(t, P) __STM32_TIMn_Pending_is_Set((t), (P))
#define     __TIMn_Flag_is_Clr(t, F)    __STM32_TIMn_Flag_is_Clr((t), (F))
#define     __TIMn_Flag_is_Set(t, F)    __STM32_TIMn_Flag_is_Set((t), (F))
#define     __Clr_TIMn(t, R, C)         __Clr_STM32_TIMn((t), R, (C))
#define     __Set_TIMn(t, R, C)         __Set_STM32_TIMn((t), R, (C))
#define     __Get_TIMn(t, R, C)         __Get_STM32_TIMn((t), R, (C))
#define     __Assign_TIMn(t, R, C)      __Assign_STM32_TIMn((t), R, (C))
#define     __TIMn_is_Clr(t, R, C)      __STM32_TIMn_is_Clr((t), R, (C))
#define     __TIMn_is_Set(t, R, C)      __STM32_TIMn_is_Set((t), R, (C))
#define     __TIMn_Irq_is_On(t, I)      __STM32_TIMn_Irq_is_On((t), (I))
#define     __TIMn_get_CNT(t)           __STM32_TIMn_get_CNT((t))

#define     __KS_GET_TIMn_ARR(t, C)     __Get_TIMn((t), ARR, (C))
#define     __KS_SET_TIMn_ARR(t, C)     __Assign_TIMn((t), ARR, (C))

#elif (__MCU_TYPE == _MCU_IS_EFM32TGxxx)
#define     __Disable_TIMn(t)           __EFM32_TIMx_DIS((t))
#define     __Enable_TIMn(t)            __EFM32_TIMx_EN((t))
#define     __Set_TIMn_Cnt(t, v)        __EFM32_TIMx_CntSet((t), (v))
#define     __Clr_TIMn_Cnt(t)           __EFM32_TIMx_CntClr((t))
#define     __Clr_TIMn_Pending(t, P)    __EFM32_TIMx_ClrPending((t), (P))
#define     __Clr_TIMn_Flag(t, F)       __EFM32_TIMx_ClrFlag((t), (F))
#define     __Disable_TIMn_Irq(t, I)    __EFM32_TIMx_IrqOFF((t), (I))
#define     __Enable_TIMn_Irq(t, I)     __EFM32_TIMx_IrqON((t), (I))
#define     __TIMn_Pending_is_Clr(t, P) __EFM32_TIMx_IS_CLR((t), IF, (P))
#define     __TIMn_Pending_is_Set(t, P) __EFM32_TIMx_IS_SET((t), IF, (P))
#define     __TIMn_Flag_is_Clr(t, F)    __TIMn_Pending_is_Clr((t), (F))
#define     __TIMn_Flag_is_Set(t, F)    __TIMn_Pending_is_Set((t), (F))
#define     __Clr_TIMn(t, R, C)         __EFM32_TIMx_EQU((t), R, (C))
#define     __Set_TIMn(t, R, C)         __EFM32_TIMx_SET((t), R, (C))
#define     __Get_TIMn(t, R, C)         __EFM32_TIMx_GET((t), R, (C))
#define     __Assign_TIMn(t, R, C)      __EFM32_TIMx_Assign((t), R, (C))
#define     __TIMn_is_Clr(t, R, C)      __EFM32_TIMx_IS_CLR((t), R, (C))
#define     __TIMn_is_Set(t, R, C)      __EFM32_TIMx_IS_SET((t), R, (C))
#define     __TIMn_Irq_is_On(t, I)      __TIMn_is_Set((t), IEN, (I))
#define     __TIMn_get_CNT(t)           __EFM32_TIMx_CntGet((t))

#define     __KS_GET_TIMn_ARR(t, C)     __Get_TIMn((t), TOP, (C))
#define     __KS_SET_TIMn_ARR(t, C)     __Assign_TIMn((t), TOP, (C))

#elif (__MCU_TYPE == _MCU_IS_EFM32Gxxx)
#elif (__MCU_TYPE == _MCU_IS_ESP8266)
#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || ((__MCU_TYPE == _MCU_IS_NRF52832)))

#define __Disable_TIMn(t)               TIMx_DIS((t))
#define __Enable_TIMn(t)                TIMx_EN((t))
#define __Clr_TIMn_Cnt(t)               TIMx_CntClr((t))
#define __Clr_TIMn_Pending(t, P)        TIMx_ClrPending((t), (P))
#define __Clr_TIMn_Flag(t, F)           TIMx_ClrFlag((t), (F))
#define __Disable_TIMn_Irq(t, I)        TIMx_IrqOFF((t), (I))
#define __Enable_TIMn_Irq(t, I)         TIMx_IrqON((t), (I))
#define __TIMn_Pending_is_Clr(t, P)     TIMx_IS_CLR((t), IF, (P))
#define __TIMn_Pending_is_Set(t, P)     TIMx_IS_Pending((t), (P))
#define __TIMn_Flag_is_Clr(t, F)        TIMx_IS_CLR((t), (F))
#define __TIMn_Flag_is_Set(t, F)        TIMx_IS_Pending((t), (F))
#define __TIMn_get_CNT(t)               TIMx_CntGet((t))

#define __TIMn_Irq_is_On(t, I)          TIMx_IRQ_IS_ON((t), (I))

#define __KS_GET_TIMn_ARR(t, buf)       TIMx_GET_ARR((t), (buf))
#define __KS_SET_TIMn_ARR(t, arr)       TIMx_SET_ARR((t), (arr))

#elif (__MCU_TYPE == _MCU_IS_TI_CC13XX)
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)

#define     __Disable_TIMn(t)           __EFR32_TIMx_DIS((t))
#define     __Enable_TIMn(t)            __EFR32_TIMx_EN((t))
#define     __Set_TIMn_Cnt(t, v)        __EFR32_TIMx_CntSet((t), (v))
#define     __Clr_TIMn_Cnt(t)           __EFR32_TIMx_CntClr((t))
#define     __Clr_TIMn_Pending(t, P)    __EFR32_TIMx_ClrPending((t), (P))
#define     __Clr_TIMn_Flag(t, F)       __EFR32_TIMx_ClrFlag((t), (F))
#define     __Disable_TIMn_Irq(t, I)    __EFR32_TIMx_IrqOFF((t), (I))
#define     __Enable_TIMn_Irq(t, I)     __EFR32_TIMx_IrqON((t), (I))
#define     __TIMn_Pending_is_Clr(t, P) __EFR32_TIMx_IS_CLR((t), IF, (P))
#define     __TIMn_Pending_is_Set(t, P) __EFR32_TIMx_IS_SET((t), IF, (P))
#define     __TIMn_Flag_is_Clr(t, F)    __TIMn_Pending_is_Clr((t), (F))
#define     __TIMn_Flag_is_Set(t, F)    __TIMn_Pending_is_Set((t), (F))
#define     __Clr_TIMn(t, R, C)         __EFR32_TIMx_EQU((t), R, (C))
#define     __Set_TIMn(t, R, C)         __EFR32_TIMx_SET((t), R, (C))
#define     __Get_TIMn(t, R, C)         __EFR32_TIMx_GET((t), R, (C))
#define     __Assign_TIMn(t, R, C)      __EFR32_TIMx_Assign((t), R, (C))
#define     __TIMn_is_Clr(t, R, C)      __EFR32_TIMx_IS_CLR((t), R, (C))
#define     __TIMn_is_Set(t, R, C)      __EFR32_TIMx_IS_SET((t), R, (C))
#define     __TIMn_Irq_is_On(t, I)      __TIMn_is_Set((t), IEN, (I))
#define     __TIMn_get_CNT(t)           __EFR32_TIMx_CntGet((t))

#define     __KS_GET_TIMn_ARR(t, C)     __Get_TIMn((t), TOP, (C))
#define     __KS_SET_TIMn_ARR(t, C)     __Assign_TIMn((t), TOP, (C))

#elif (__MCU_TYPE == _MCU_IS_STM32F4xx)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
#elif (__MCU_TYPE == _MCU_IS_HSDC32L110)
#else
#error unsupportted!
#endif

/***** Function Prototypes ****************************************************/

#endif // __TIMER_DDL_H_KENSKY_2020_9_17
