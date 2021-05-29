/*******************************************************************************
  * File    :  SPI_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-14
  * Brief   :  
*******************************************************************************/
#ifndef __SPI_SPEC_H_KENSKY_2012_9_14
#define __SPI_SPEC_H_KENSKY_2012_9_14

/**** Includes ****************************************************************/
#include <04_GPIO/GPIO_Spec.h>
#include <11_DMA/DMA_Spec.h>
#include <09_Timer/Timer_Spec.h>

/**** Defines *****************************************************************/
#define     _KS_SSPI                   (0x00ul) // soft spi interface (all)
#define     _KS_HSPI1                  (0x01ul) // hard spi interface 1
#define     _KS_HSPI2                  (0x02ul) // hard spi interface 2
#define     _KS_HSPI3                  (0x03ul) // hard spi interface 3
#define     _KS_HSPI4                  (0x04ul) // hard spi interface 4
#define     _KS_HSPI5                  (0x05ul) // hard spi interface 5
#define     _KS_HSPI6                  (0x06ul) // hard spi interface 6

/**** SPI Direction ***********************************************************/
#define     _KS_SPI_FullDuplex         (0x00ul)
#define     _KS_SPI_2Lines_RxOnly      (0x01ul)
#define     _KS_SPI_1Line_Rx           (0x02ul)
#define     _KS_SPI_1Line_Tx           (0x03ul)

/**** SPI Mode ****************************************************************/
#define     _KS_MASTER_SPI             (0x01ul)
#define     _KS_SLAVE_SPI              (0x02ul)

/**** SPI Data Size ***********************************************************/
#define     _KS_SPI_16b                (0x10ul)
#define     _KS_SPI_08b                (0x08ul)

/**** SPI Clock Polarity ******************************************************/
#define     _KS_SPI_CPOL_Low           (0x00ul) // idle-low, active-high
#define     _KS_SPI_CPOL_High          (0x01ul) // idle-high,active-low

/**** SPI Clock Phase *********************************************************/
#define     _KS_SPI_CPHA_1Edge         (0x00ul) // 1st edge sampling, Leading
#define     _KS_SPI_CPHA_2Edge         (0x01ul) // 2nd edge sampling, Trailing

/**** SPI Slave Select Management *********************************************/
#define     _KS_SPI_NSS_Soft           (0x00ul)
#define     _KS_SPI_NSS_Hard           (0x01ul)
#define     _KS_SPI_NSS_HardIn         (0x01ul)
#define     _KS_SPI_NSS_HardOut        (0x02ul)

/**** SPI BaudRate Prescaler **************************************************/
#define     _KS_SPI_BR_Prescaler_1     (0x00ul)
#define     _KS_SPI_BR_Prescaler_2     (0x01ul)
#define     _KS_SPI_BR_Prescaler_4     (0x02ul)
#define     _KS_SPI_BR_Prescaler_8     (0x03ul)
#define     _KS_SPI_BR_Prescaler_16    (0x04ul)
#define     _KS_SPI_BR_Prescaler_32    (0x05ul)
#define     _KS_SPI_BR_Prescaler_64    (0x06ul)
#define     _KS_SPI_BR_Prescaler_128   (0x07ul)
#define     _KS_SPI_BR_Prescaler_256   (0x08ul)

/**** SPI Endian  *************************************************************/
#define     _KS_SPI_MSB_First          (0x00ul)
#define     _KS_SPI_LSB_First          (0x01ul)

/**** SPI Pin Sequence ********************************************************/
// the sequence definition is to be compatible with usart and i2c
#define     _KS_SPI_MOSI               (0x00ul)
#define     _KS_SPI_TXD                (0x00ul)
#define     _KS_SPI_SCK                (0x01ul)
#define     _KS_SPI_MISO               (0x02ul)
#define     _KS_SPI_RXD                (0x02ul)
#define     _KS_SPI_NSS                (0x03ul)
#define     _KS_SPI_CS                 (0x03ul)
#define     _KS_SPI_IO_NUM             (_KS_SPI_NSS + 0x01)

/**** SPI Return Messages *****************************************************/
#define     _KS_SPI_SUCCESSFUL         ((ksS32)(0x00))
#define     _KS_SPI_MISMATCH           ((ksS32)(-1))

/**** Global Data Types *******************************************************/

/**** Global Data Types *******************************************************/
typedef enum
{
  ksSpiMater = _KS_MASTER_SPI,
  ksSpiSlave = _KS_SLAVE_SPI,
} ksSpiMode_e;

/*******************************************************************************
  * Typedef     : ykUSART_CLK_TypeDef
  * Mode        : whether the Receive or Transmit mode is enabled or disabled.
  * BaudRate    : USART communication baud rate.
  * WordLength  : the number of data bits transmitted or received in a frame.
  * StopBits    : the number of stop bits transmitted.
  * Parity      : the parity mode.
  * FlowCntl    : whether the hardware flow control mode is enabled or disabled.
*******************************************************************************/
typedef struct
{
  ksU16   Direction;
  ksU16   Mode;      // Master or Slave
  ksU16   DataSize;  // 8 bits or 16 bits
  ksU16   CPOL;
  ksU16   CPHA;
  ksU16   NSS;
  ksU16   Prescaler;
  ksU16   Endian;    // MSB or LSB
  ksU16   TiProtoEn; // TI Protocol compliant
  ksU16   crcEn;     // enable CRC
  ksU16   CRCPolynomial;
} ksSPI_para_t;

typedef enum
{
  sSPI      = _KS_SSPI,    // 0 for SSPI, 1..3 for hSPI1..3 separately
  hSPI_1    = _KS_HSPI1,
  hSPI_2    = _KS_HSPI2,
  hSPI_3    = _KS_HSPI3,
  hSPI_4    = _KS_HSPI4,
  hSPI_5    = _KS_HSPI5,
  hSPI_6    = _KS_HSPI6,
  null_sbus = 0xff,   // to be compatible with usart
} ksSPI_bus_e;

typedef enum
{
  ksSPI_Disable   = 0,
  ksSPI_Enable    = !ksSPI_Disable
} ksSPI_State_e;

typedef struct
{
  ksStroage_e     storage;
  ksLockState_e   isLocked;   // if it is used
  ksSPI_bus_e     bus;
  ksU32           periphID;
  ksAddr_t        addrBase;  // use the address base as the peripheral interface
  ksISR_t         RX_isr;    // something received!
  ksISR_t         TC_isr;    // transmission completed!
  ksGPIO_t        gpio[_KS_SPI_IO_NUM];
  ksSPI_para_t    para;
  ksDMA_t         *rxDMA;
  ksDMA_t         *txDMA;
  ksTIM_t         *rxDMAtimer;
  ksSPI_State_e   isEnabled;
} ksSPI_t;

#endif // __SPI_SPEC_H_KENSKY_2012_9_14
