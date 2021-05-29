/*******************************************************************************
  * File    :  Timer_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-17
  * Brief   :  
*******************************************************************************/
#ifndef __TIMER_SPEC_H_KENSKY_2020_9_17
#define __TIMER_SPEC_H_KENSKY_2020_9_17

/**** Includes ****************************************************************/
#include <0A_ISR/ISR_Spec.h>

/**** Defines *****************************************************************/
/**** Timer error messages ****************************************************/
#define     _TIM_SUCCESSFUL     (0x00)
#define     _TIM_ERR_GENERIC    (-0x01)
#define     _TIM_MISMATCH       (-0x02)

#define     _TIM_STATE_OFF      (0x00U)
#define     _TIM_STATE_ON       (0X01U)

/**** Global Data Types *******************************************************/
typedef enum
{
  is_DIV01  = 0,
  is_DIV02  = 1,
  is_DIV04  = 2,
  is_DIV08  = 3,
  is_DIV16  = 4,
  is_DIVxx  = 0xff,
} ksTIM_ClkDiv_e;

typedef enum
{
  is_UP     = 0, // Counter up
  is_DOWN   = 1, // Counter down
  is_CA1    = 2, // Center Align 1, up & down mode : flag set when down
  is_CA2    = 3, // Center Align 2, up & down mode : flag set when up
  is_CA3    = 4, // Center Align 3, up & down mode : flag set when up or down
  UnSure    = 0xff,
} ksTIM_Mode_e;

typedef struct
{
  ksU32           Prescaler;
  ksTIM_Mode_e    Mode;
  ksU32           Period;     // for ARR or TOP
  ksTIM_ClkDiv_e  ClkDiv;
  ksU32           RepetitionCounter;
  ksU08           count2x;    // 0 : off, other : on, counter increments/decrements by 2
  ksU08           isOneShot;  // contiguous or one shot??
} ksTIM_para_t;

// the following TIMER NUMBER will also used by the lptimer
#define   __KS_TIMER_000       (0x00)
#define   __KS_TIMER_001       (0x01)
#define   __KS_TIMER_002       (0x02)
#define   __KS_TIMER_003       (0x03)
#define   __KS_TIMER_004       (0x04)
#define   __KS_TIMER_005       (0x05)
#define   __KS_TIMER_006       (0x06)
#define   __KS_TIMER_007       (0x07)
#define   __KS_TIMER_008       (0x08)
#define   __KS_TIMER_009       (0x09)
#define   __KS_TIMER_010       (0x0a)
#define   __KS_TIMER_011       (0x0b)
#define   __KS_TIMER_012       (0x0c)
#define   __KS_TIMER_013       (0x0d)
#define   __KS_TIMER_014       (0x0e)
#define   __KS_TIMER_015       (0x0f)
#define   __KS_TIMER_016       (0x10)
#define   __KS_TIMER_017       (0x11)
#define   __KS_TIMER_018       (0x12)
#define   __KS_TIMER_019       (0x13)
#define   __KS_TIMER_020       (0x14)
#define   __KS_TIMER_021       (0x15)
#define   __KS_TIMER_022       (0x16)
#define   __KS_TIMER_LPW       (0xE0) // low-power timer
#define   __KS_TIMER_RTC       (0xF0)
#define   __KS_TIMER_RTC0      (0xF0)
#define   __KS_TIMER_RTC1      (0xF1)
#define   __KS_TIMER_RTC2      (0xF2)

typedef enum
{
  is_tim00    = 0, // reserved.we think tim01 is TIM1
  is_tim01    = __KS_TIMER_001,
  is_tim02    = __KS_TIMER_002,
  is_tim03    = __KS_TIMER_003,
  is_tim04    = __KS_TIMER_004,
  is_tim05    = __KS_TIMER_005,
  is_tim06    = __KS_TIMER_006,
  is_tim07    = __KS_TIMER_007,
  is_tim08    = __KS_TIMER_008,
  is_tim09    = __KS_TIMER_009,
  is_tim10    = __KS_TIMER_010,
  is_tim11    = __KS_TIMER_011,
  is_tim12    = __KS_TIMER_012,
  is_tim13    = __KS_TIMER_013,
  is_tim14    = __KS_TIMER_014,
  is_tim15    = __KS_TIMER_015,
  is_tim16    = __KS_TIMER_016,
  is_tim17    = __KS_TIMER_017,
  is_tim18    = __KS_TIMER_018,
  is_tim19    = __KS_TIMER_019,
  is_tim20    = __KS_TIMER_020,
  is_tim21    = __KS_TIMER_021,
  is_tim22    = __KS_TIMER_022,
  is_timLp    = __KS_TIMER_LPW,
  is_timRTC   = __KS_TIMER_RTC,  // use RTC as the timer, by default, RTC0 is RTC
  is_timRTC0  = __KS_TIMER_RTC0, // use RTC as the timer
  is_timRTC1  = __KS_TIMER_RTC1, // use RTC as the timer
  is_timRTC2  = __KS_TIMER_RTC2, // use RTC as the timer
} ksTIM_bus_e;

typedef enum
{
  TIM_Disbale   = 0,
  TIM_Enable    = !TIM_Disbale
} ksTIM_State_e;

typedef enum
{
  is_08_bits = 0x08, // 8
  is_16_bits = 0x10, // 16
  is_24_bits = 0x18, // 24
  is_32_bits = 0x20, // 32
  is_64_bits = 0x40, // 64
  unset_bits = 0xff,
} ksTIM_width_e;

typedef enum
{
  timer_state_halted  = _TIM_STATE_OFF,
  timer_state_running = _TIM_STATE_ON,
  timer_state_unknown = 0xFF,
} ksTIM_status_e;

typedef struct
{
  ksTIM_bus_e     bus;
  ksU32           periphID;
  ksAddr_t        addrBase;  // this addr is used to transform to specific TIMn registers
  ksU32           freq;      // Hz
  ksTIM_width_e   width;
  ksISR_t         UP_isr;    // update isr!
  ksISR_t         GE_isr;    // generic isr
  ksTIM_para_t    params;
  ksTIM_status_e  status;
  ksLockState_e   locked;    // for synchronization
} ksTIM_t;

#endif // __TIMER_SPEC_H_KENSKY_2020_9_17
