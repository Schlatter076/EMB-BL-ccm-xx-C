////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "GPIO_NRF52832.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-19
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF52832_INC_GPIO_NRF52832_H_KENSKY_2016__
#define __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF52832_INC_GPIO_NRF52832_H_KENSKY_2016__

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
#include    "../../Common/inc/GPIO_Common.h"

#if (defined __MCU_TYPE)       && \
    (defined _MCU_IS_NRF52832) && \
    (__MCU_TYPE == _MCU_IS_NRF52832)

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** TYPEDEFS ****************************************************************/
typedef   NRF_GPIO_Type    ksGpioPort_t;

/**** Defines *****************************************************************/
#define __NRF52832_IO(IO)                   (((ksGpioPort_t *)(IO)->addrBase))

#define __GPIO_PIN_N(PinNum)                ((uint32_t)(1<<(PinNum)))
#define __ODR_OFFSET                        (0x04u)
#define __IDR_OFFSET                        (0x10u)

// one pin at a time
#define __SET_PIN_HIGH(Port,PinNum)         st((Port)->OUTSET = __GPIO_PIN_N(PinNum);)
#define __SET_PIN_LOW(Port, PinNum)         st((Port)->OUTCLR = __GPIO_PIN_N(PinNum);)
#define __PIN_is_LOW(Port,  PinNum)         (!(((Port)->IN) & __GPIO_PIN_N(PinNum)))  // Port_Pin = 0
#define __PIN_is_HIGH(Port, PinNum)         (!(__PIN_is_LOW((Port),(PinNum))))        // Port_Pin = 1

#define __set_NRF_IO_HIGH(IO)               st(__SET_PIN_HIGH(__NRF52832_IO(IO),((IO)->Pin.pinNum));)
#define __set_NRF_IO_LOW(IO)                st(__SET_PIN_LOW(__NRF52832_IO(IO), ((IO)->Pin.pinNum));)
#define __NRF_IO_is_LOW(IO)                 __PIN_is_LOW(__NRF52832_IO(IO),     ((IO)->Pin.pinNum))
#define __NRF_IO_is_HIGH(IO)                __PIN_is_HIGH(__NRF52832_IO(IO),    ((IO)->Pin.pinNum))

/***** Function Prototypes ****************************************************/
ksGpioPort_t *nrf52832GpioGetType           (ksGPIO_t *IO);
ksU32         nrf52832GpioGetPeriphID       (ksGPIO_t *IO);
int           nrf52832GpioDeInit            (ksGPIO_t *IO);
void          nrf52832GpioInit              (ksGPIO_t *IO);
int           nrf52832GpioReadInputDataBit  (ksGPIO_t *IO);
int           nrf52832GpioReadInputData     (ksGPIO_t *IO);
int           nrf52832GpioReadOutputDataBit (ksGPIO_t *IO, uint8_t PinNun);
int           nrf52832GpioReadOutputData    (ksGPIO_t *IO);
void          nrf52832GpioWrite             (ksGPIO_t *IO, uint16_t PortVal);
int           nrf52832GpioSaveIoSetting     (ksGPIO_t *IO, ksGPIO_CTRLReg_t *IO_setting);
int           nrf52832GpioRestoreIoSetting  (ksGPIO_t *IO, ksGPIO_CTRLReg_t *IO_setting);

#endif // (defined __MCU_TYPE)       && \
          (defined _MCU_IS_NRF52832) && \
          (__MCU_TYPE == _MCU_IS_NRF52832)

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF52832_INC_GPIO_NRF52832_H_KENSKY_2016__
