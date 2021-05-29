////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "GPIO_NRF51822.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2016-1-19
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF51822_INC_GPIO_NRF51822_H_KENSKY_2016__
#define __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF51822_INC_GPIO_NRF51822_H_KENSKY_2016__

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
    (defined _MCU_IS_NRF51822) && \
    (__MCU_TYPE == _MCU_IS_NRF51822)

/**** Includes ****************************************************************/
#include "../../../../FF_3rdPty/NRF51_52fwlib/nrf51_52_expansion.h"

/**** TYPEDEFS ****************************************************************/
typedef   NRF_GPIO_Type    ksGpioPort_t;

/**** Defines *****************************************************************/
#define __NRF51822_IO(IO)                   (((ksGpioPort_t *)(IO)->addrBase))

#define __GPIO_PIN_N(PinNum)                ((ksU32)(1<<(PinNum)))
#define __ODR_OFFSET                        (0x04u)
#define __IDR_OFFSET                        (0x10u)

// one pin at a time
#define __SET_PIN_HIGH(Port,PinNum)         st((Port)->OUTSET = __GPIO_PIN_N(PinNum);)
#define __SET_PIN_LOW(Port, PinNum)         st((Port)->OUTCLR = __GPIO_PIN_N(PinNum);)

#define __SET_PIN_OUTPUT(Port, PinNum)      st((Port)->DIRSET = __GPIO_PIN_N(PinNum);)
#define __SET_PIN_INPUT(Port, PinNum)       st((Port)->DIRCLR = __GPIO_PIN_N(PinNum);)

#define __PIN_is_LOW(Port,  PinNum)         (!(((Port)->IN) & __GPIO_PIN_N(PinNum)))  // Port_Pin = 0
#define __PIN_is_HIGH(Port, PinNum)         (!(__PIN_is_LOW((Port),(PinNum))))        // Port_Pin = 1

#define __set_NRF_IO_HIGH(IO)               st(__SET_PIN_HIGH(__NRF51822_IO(IO),((IO)->Pin.pinNum));)
#define __set_NRF_IO_LOW(IO)                st(__SET_PIN_LOW(__NRF51822_IO(IO), ((IO)->Pin.pinNum));)

#define __set_NRF_IO_OUTPUT(IO)             st(__SET_PIN_OUTPUT(__NRF51822_IO(IO),((IO)->Pin.pinNum));)
#define __set_NRF_IO_INPUT(IO)              st(__SET_PIN_INPUT(__NRF51822_IO(IO),((IO)->Pin.pinNum));)

#define __NRF_IO_is_LOW(IO)                 __PIN_is_LOW(__NRF51822_IO(IO),     ((IO)->Pin.pinNum))
#define __NRF_IO_is_HIGH(IO)                __PIN_is_HIGH(__NRF51822_IO(IO),    ((IO)->Pin.pinNum))

#define __NRF_IO_MODE_APP                   (0x03ul)
#define __NRF_IO_MODE_OPP                   (__NRF_IO_MODE_APP)
#define __NRF_IO_MODE_AIN                   (0x00ul)
#define __NRF_IO_MODE_FIN                   (__NRF_IO_MODE_AIN)
#define __NRF_IO_MODE_IPD                   (0x08ul)
#define __NRF_IO_MODE_IPU                   (0x0Cul)

/***** Function Prototypes ****************************************************/
ksGpioPort_t* nrf51822GpioGetType           (ksGPIO_t *IO);
ksU32         nrf51822GpioGetPeriphID       (ksGPIO_t *IO);
int           nrf51822GpioDeInit            (ksGPIO_t *IO);
void          nrf51822GpioInit              (ksGPIO_t *IO);
int           nrf51822GpioReadInputDataBit  (ksGPIO_t *IO);
int           nrf51822GpioReadInputData     (ksGPIO_t *IO);
int           nrf51822GpioReadOutputDataBit (ksGPIO_t *IO, uint8_t PinNun);
int           nrf51822GpioReadOutputData    (ksGPIO_t *IO);
void          nrf51822GpioWrite             (ksGPIO_t *IO, uint16_t PortVal);
int           nrf51822GpioSaveIoSetting     (ksGPIO_t *IO, ksGPIO_CTRLReg_t *IO_setting);
int           nrf51822GpioRestoreIoSetting  (ksGPIO_t *IO, ksGPIO_CTRLReg_t *IO_setting);

#endif // (defined __MCU_TYPE)       && \
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

#endif // __LIBS_KSPERIPH_04_GPIO_1_PHY_NRF51822_INC_GPIO_NRF51822_H_KENSKY_2016__
