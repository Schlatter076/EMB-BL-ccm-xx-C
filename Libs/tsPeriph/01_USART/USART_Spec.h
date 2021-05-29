/*******************************************************************************
  * file    : "USART_Spec.h"
  * author  : ken_yang
  * version : 0.2
  * date    : 2020-9-1
  * brief   :
*******************************************************************************/
#ifndef     __USART_SPEC_H_20120901YK
#define     __USART_SPEC_H_20120901YK

/**** Includes ****************************************************************/
#include <04_GPIO/GPIO_Spec.h>
#include <11_DMA/DMA_Spec.h>

/**** Defines *****************************************************************/
#define     _KS_USART_CHN_1                 (0x01ul)  // hard uasrt interface 1
#define     _KS_USART_CHN_2                 (0x02ul)  // hard uasrt interface 2
#define     _KS_USART_CHN_3                 (0x03ul)  // hard uasrt interface 3
#define     _KS_USART_CHN_4                 (0x04ul)  // hard uasrt interface 4
#define     _KS_USART_CHN_5                 (0x05ul)  // hard uasrt interface 5
#define     _KS_USART_CHN_6                 (0x06ul)  // hard uasrt interface 6
#define     _KS_USART_CHN_7                 (0x07ul)  // hard uasrt interface 7
#define     _KS_USART_CHN_8                 (0x08ul)  // hard uasrt interface 8
#define     _KS_USART_CHN_9                 (0x09ul)  // hard uasrt interface 9
#define     _KS_LPUSART_CHN_1               (0x11ul)  // lp-uart interface 1
#define     _KS_LPUSART_CHN_2               (0x12ul)  // lp-uart interface 2
#define     _KS_LPUSART_CHN_3               (0x13ul)  // lp-uart interface 3
#define     _KS_LPUSART_CHN_4               (0x14ul)  // lp-uart interface 4
#define     _KS_LPUSART_CHN_5               (0x15ul)  // lp-uart interface 5
#define     _KS_LPUSART_CHN_6               (0x16ul)  // lp-uart interface 6
#define     _KS_LPUSART_CHN_7               (0x17ul)  // lp-uart interface 7
#define     _KS_LPUSART_CHN_8               (0x18ul)  // lp-uart interface 8
#define     _KS_LPUSART_CHN_9               (0x19ul)  // lp-uart interface 9

#define     _KS_USART_CHN_MASK              (0x0Ful)  //
#define     _KS_LPUSART_MASK                (0x10ul)  //

/**** USART GPIO Abstraction **************************************************/
// the sequence definition is to be compatible with i2c and spi
#define     _KS_USART_IO_TXD                (0x00ul)
#define     _KS_USART_IO_MOSI               (0x00ul)
#define     _KS_USART_IO_CK                 (0x01ul)
#define     _KS_USART_IO_SCK                (0x01ul)
#define     _KS_USART_IO_RXD                (0x02ul)
#define     _KS_USART_IO_MISO               (0x02ul)
#define     _KS_USART_IO_CS                 (0x03ul) // not used!!
#define     _KS_USART_IO_NSS                (0x03ul) // not used!!
#define     _KS_USART_IO_RTS                (0x04ul)
#define     _KS_USART_IO_CTS                (0x05ul)
#define     _KS_USART_IO_DTR                (0x06ul)
#define     _KS_USART_IO_DSR                (0x07ul)
#define     _KS_USART_IO_DCD                (0x08ul)
#define     _KS_USART_IO_RI                 (0x09ul)
#define     _KS_USART_IO_NUM                (_KS_USART_IO_RI + 0x01u)

#define     _KS_USART_IO_UNSPECIFIED        (0xFFu)

/**** USART_BaudRate **********************************************************/
#define     _KS_USART_BaudRate_is_115200    (0x00u)

/**** USART Data Direction ****************************************************/
#define     _KS_USART_LITTLE_ENDIAN         (0x00u)
#define     _KS_USART_BIG_ENDIAN            (0x01u)
#define     _KS_IS_USART_ENDIAN(ENDIAN)     (((ENDIAN) == _KS_USART_LITTLE_ENDIAN) || \
                                             ((ENDIAN) == _KS_USART_BIG_ENDIAN))

/**** Usart WordLength ********************************************************/
#define     _KS_USART_WordLength_5b         (0x00u)  //supported by ATMEGA8
#define     _KS_USART_WordLength_6b         (0x01u)  //supported by ATMEGA8
#define     _KS_USART_WordLength_7b         (0x02u)  //supported by ATMEGA8
#define     _KS_USART_WordLength_8b         (0x03u)  //supported by ATMEGA8, stm32f10x
#define     _KS_USART_WordLength_9b         (0x04u)  //supported by ATMEGA8, stm32f10x
#define     _KS_IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == _KS_USART_WordLength_5b) || \
                                              ((LENGTH) == _KS_USART_WordLength_6b))|| \
                                              ((LENGTH) == _KS_USART_WordLength_7b))|| \
                                              ((LENGTH) == _KS_USART_WordLength_8b))|| \
                                              ((LENGTH) == _KS_USART_WordLength_9b))

/**** Usart_StopBits **********************************************************/
#define     _KS_USART_StopBits_0_5          (0x00u)
#define     _KS_USART_StopBits_1            (0x01u)
#define     _KS_USART_StopBits_1_5          (0x02u)
#define     _KS_USART_StopBits_2            (0x03u)
#define     _KS_IS_USART_STOPBITS(STOPBITS) (((STOPBITS) == _KS_USART_StopBits_1) || \
                                             ((STOPBITS) == _KS_USART_StopBits_0_5) || \
                                             ((STOPBITS) == _KS_USART_StopBits_2) || \
                                             ((STOPBITS) == _KS_USART_StopBits_1_5))

/**** Usart_Parity ************************************************************/
#define     _KS_USART_Parity_No             (0x00u)
#define     _KS_USART_Parity_Even           (0x01u)
#define     _KS_USART_Parity_Odd            (0x02u)
#define     _KS_IS_USART_PARITY(PARITY)     (((PARITY) == _KS_USART_Parity_No) || \
                                             ((PARITY) == _KS_USART_Parity_Even) || \
                                             ((PARITY) == _KS_USART_Parity_Odd))

/**** Usart_Mode **************************************************************/
#define     _KS_USART_SMARTCARD_MODE        (0x10u) // Smartcard Protocol
#define     _KS_USART_SWR_MODE              (0x20u) // Single Wire Half-Duplex
#define     _KS_USART_IrDA_MODE             (0x30u) // infrared Data Association
#define     _KS_USART_LIN_MODE              (0x40u) // Local Interconnection Mode
#define     _KS_USART_ASYNC_MODE            (0x50u) // Asynchronous Mode
#define     _KS_USART_SYNC_MODE             (0x60u) // Synchronous Mode
#define     _KS_USART_RX_MODE               (0x01u) // RXD
#define     _KS_USART_TX_MODE               (0x02u) // TXD
#define     _KS_USART_TxRx_MODE             (0x03u) // RX + TX
#define     _KS_IS_USART_MODE(MODE)         (((MODE) == _KS_USART_SMARTCARD_MODE)   || \
                                             ((MODE) == _KS_USART_SWR_MODE)         || \
                                             ((MODE) == _KS_USART_IrDA_MODE))       || \
                                             ((MODE) == _KS_USART_LIN_MODE))        || \
                                             ((MODE) == _KS_USART_ASYNC_MODE))      || \
                                             ((MODE) == _KS_USART_SYNC_MODE))

/**** USART Clock *************************************************************/
#define     _KS_USART_Clk_Disable           (0x00u)
#define     _KS_USART_Clk_Enable            (0x01u)
#define     _KS_IS_USART_CLOCK(CLOCK)       (((CLOCK) == _KS_USART_Clk_Disable) || \
                                             ((CLOCK) == _KS_USART_Clk_Enable))

#define     _KS_USART_CPOL_Low              (0x00u)
#define     _KS_USART_CPOL_High             (0x01u)
#define     _KS_IS_USART_CPOL(CPOL)         (((CPOL) == _KS_USART_CPOL_Low) || \
                                             ((CPOL) == _KS_USART_CPOL_High))

#define     _KS_USART_CPHA_1Edge            (0x00u)
#define     _KS_USART_CPHA_2Edge            (0x01u)
#define     _KS_IS_USART_CPHA(CPHA)         (((CPHA) == _KS_USART_CPHA_1Edge) || \
                                             ((CPHA) == _KS_USART_CPHA_2Edge))

#define     _KS_USART_LastBit_Disable       (0x00u)
#define     _KS_USART_LastBit_Enable        (0x01u)
#define     _KS_IS_USART_LASTBIT(LASTBIT)   (((LASTBIT) == _KS_USART_LastBit_Disable) || \
                                             ((LASTBIT) == _KS_USART_LastBit_Enable))

/**** Usart_FlowControl ********************************************************
Hardware Flow Control:
   RTS/CTS flow control and DTR/DSR flow control:
   RTS/CTS : （请求发送/清除发送）流控制时，应将通讯两端的RTS、CTS线对应相连，数据终端设备（如计算机）使用RTS来起始调制解调器或其它数据通讯设备的数据流，而数据通讯设备（如调制解调器）则用CTS来起动和暂停来自计算机的数据流。这种硬件握手方式的过程为：我们在编程时根据接收端缓冲区大小设置一个高位标志（可为缓冲区大小的75％）和一个低位标志（可为缓冲区大小的25％），当缓冲区内数据量达到高位时，我们在接收端将CTS线置低电平（送逻辑 0），当发送端的程序检测到CTS为低后，就停止发送数据，直到接收端缓冲区的数据量低于低位而将CTS置高电平。RTS则用来标明接收设备有没有准备好接收数据。
    常用的流控制还有还有
   DTR/DSR :
Software Flow Control:
   XON/XOFF:
       常用方法是：当接收端的输入缓冲区内数据量超过设定的高位时，就向数据发送端发出XOFF
       字符（十进制的19或Control-S，设备编程说明书应该有详细阐述），发送端收到 XOFF字符后
       就立即停止发送数据；当接收端的输入缓冲区内数据量低于设定的低位时，就向数据发送端发
       出XON字符（十进制的17或Control- Q），发送端收到XON字符后就立即开始发送数据。一般
       可以从设备配套源程序中找到发送的是什么字符。
    应该注意，若传输的是二进制数据，标志字符也有可能在数据流中出现而引起误操作，这是软件
    流控制的缺陷，而硬件流控制不会有这个问题。
*******************************************************************************/
#define _KS_USART_FlowControl_SOFT      (0x00u)// Software Flow Control
#define _KS_USART_FlowControl_RTS       (0x01u)
#define _KS_USART_FlowControl_CTS       (0x02u)
#define _KS_USART_FlowControl_RTS_CTS   (0x03u)
#define _KS_USART_FlowControl_DTR       (0x03u)
#define _KS_USART_FlowControl_DSR       (0x03u)
#define _KS_USART_FlowControl_DTR_DSR   (0x03u)
#define IS_USART_FLOW_CONTROL(CONTROL)  (((CONTROL) == USART_HardwareFlowControl_None) || \
                                         ((CONTROL) == USART_HardwareFlowControl_RTS) || \
                                         ((CONTROL) == USART_HardwareFlowControl_CTS) || \
                                         ((CONTROL) == USART_HardwareFlowControl_RTS_CTS)) || \
                                         ((CONTROL) == _KS_USART_FlowControl_DTR)) || \
                                         ((CONTROL) == _KS_USART_FlowControl_DSR)) || \
                                         ((CONTROL) == _KS_USART_FlowControl_DTR_DSR))

/**** Use DMA? ****************************************************************/
#define     _USART_DMA_is_ON            (0x00)
#define     _USART_DMA_is_OFF           (0x01)

/**** return message **********************************************************/
#define     _USART_Txd_ONGOING          ((int32_t)(01))
#define     _USART_Txd_OVER             ((int32_t)(02))

/**** USART TimeOut ***********************************************************/
#define     _USART_CHIP_WAIT_TICK       (0x4ffffu)

/**** Global Data Types *******************************************************/
typedef enum
{
  disableUsart   = 0,
  enableUsart    = !disableUsart
} ksUSART_State_e;

typedef enum
{
  is_usart1     = _KS_USART_CHN_1,
  is_usart2     = _KS_USART_CHN_2,
  is_usart3     = _KS_USART_CHN_3,
  is_usart4     = _KS_USART_CHN_4,
  is_usart5     = _KS_USART_CHN_5,
  is_usart6     = _KS_USART_CHN_6,
  is_usart7     = _KS_USART_CHN_7,
  is_usart8     = _KS_USART_CHN_8,
  is_usart9     = _KS_USART_CHN_9,
  is_lpusart1   = _KS_LPUSART_CHN_1,
  is_lpusart2   = _KS_LPUSART_CHN_2,
  is_lpusart3   = _KS_LPUSART_CHN_3,
  is_lpusart4   = _KS_LPUSART_CHN_4,
  is_lpusart5   = _KS_LPUSART_CHN_5,
  is_lpusart6   = _KS_LPUSART_CHN_6,
  is_lpusart7   = _KS_LPUSART_CHN_7,
  is_lpusart8   = _KS_LPUSART_CHN_8,
  is_lpusart9   = _KS_LPUSART_CHN_9,
  null_ubus     = 0xFF,
} ksUSART_bus_e;

/*******************************************************************************
  * Typedef         : ykUSART_CLK_TypeDef
  * USART_Clock     : Specifies whether the USART clock is enabled or disabled.
  * USART_CPOL      : Specifies the steady state value of the serial clock.
  * USART_CPHA      : Specifies the clock transition on which the bit capture
  *                   is made.
  * USART_LastBit   : Specifies whether the clock pulse corresponding to the last
  *                   transmitted data bit (MSB) has to be output on the SCLK
  *                   pin in synchronous mode.
*******************************************************************************/
typedef struct
{
  ksU16 USART_Clock;
  ksU16 USART_CPOL;
  ksU16 USART_CPHA;
  ksU16 USART_LastBit;
} ksUsartClock_t;

/*******************************************************************************
  * Typedef     : ksUsartParams_t
  * Mode        : whether the Receive or Transmit mode is enabled or disabled.
  * BaudRate    : USART communication baud rate.
  * WordLength  : the number of data bits transmitted or received in a frame.
  * StopBits    : the number of stop bits transmitted.
  * Parity      : the parity mode.
  * FlowCntl    : whether the hardware flow control mode is enabled or disabled.
*******************************************************************************/
typedef struct
{
  ksU32 BaudRate;
  ksU32 WordLength;
  ksU32 StopBits;
  ksU32 Parity;
  ksU32 Mode;
  ksU32 FlowCntl;
} ksUsartParams_t;

typedef struct
{
  ksUSART_bus_e         bus;
  ksU32                 periphID;
  ksAddr_t              addrBase;
  ksISR_t               RX_isr; // something received!
  ksISR_t               TC_isr; // transmission completed!
  ksGPIO_t              gpio[_KS_USART_IO_NUM];// 9 for TXD, RXD, RTS, CK, CTS, DTR, DSR, DCD, RI
  ksUsartParams_t       params;
  ksUsartClock_t        Clk;
  ksU32                 clkFreq;
  ksDMA_t               *rxDMA;
  ksDMA_t               *txDMA;
} ksUSART_t;

#if 0
#define USART_DMAReq_Tx                      ((uint16_t)0x0080)
#define USART_DMAReq_Rx                      ((uint16_t)0x0040)
#define IS_USART_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFF3F) == 0x00) && ((DMAREQ) != (uint16_t)0x00))

/** @defgroup USART_WakeUp_methods
  * @{
  */

#define USART_WakeUp_IdleLine                ((uint16_t)0x0000)
#define USART_WakeUp_AddressMark             ((uint16_t)0x0800)
#define IS_USART_WAKEUP(WAKEUP) (((WAKEUP) == USART_WakeUp_IdleLine) || \
                                 ((WAKEUP) == USART_WakeUp_AddressMark))

/** @defgroup USART_LIN_Break_Detection_Length
  * @{
  */

#define USART_LINBreakDetectLength_10b      ((uint16_t)0x0000)
#define USART_LINBreakDetectLength_11b      ((uint16_t)0x0020)
#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                               (((LENGTH) == USART_LINBreakDetectLength_10b) || \
                                ((LENGTH) == USART_LINBreakDetectLength_11b))

/** @defgroup USART_IrDA_Low_Power
  * @{
  */

#define USART_IrDAMode_LowPower              ((uint16_t)0x0004)
#define USART_IrDAMode_Normal                ((uint16_t)0x0000)
#define IS_USART_IRDA_MODE(MODE) (((MODE) == USART_IrDAMode_LowPower) || \
                                  ((MODE) == USART_IrDAMode_Normal))

/** @defgroup USART_Flags
  * @{
  */

#define USART_FLAG_CTS                       ((uint16_t)0x0200)
#define USART_FLAG_LBD                       ((uint16_t)0x0100)
#define USART_FLAG_TXE                       ((uint16_t)0x0080)
#define USART_FLAG_TC                        ((uint16_t)0x0040)
#define USART_FLAG_RXNE                      ((uint16_t)0x0020)
#define USART_FLAG_IDLE                      ((uint16_t)0x0010)
#define USART_FLAG_ORE                       ((uint16_t)0x0008)
#define USART_FLAG_NE                        ((uint16_t)0x0004)
#define USART_FLAG_FE                        ((uint16_t)0x0002)
#define USART_FLAG_PE                        ((uint16_t)0x0001)
#define IS_USART_FLAG(FLAG) (((FLAG) == USART_FLAG_PE) || ((FLAG) == USART_FLAG_TXE) || \
                             ((FLAG) == USART_FLAG_TC) || ((FLAG) == USART_FLAG_RXNE) || \
                             ((FLAG) == USART_FLAG_IDLE) || ((FLAG) == USART_FLAG_LBD) || \
                             ((FLAG) == USART_FLAG_CTS) || ((FLAG) == USART_FLAG_ORE) || \
                             ((FLAG) == USART_FLAG_NE) || ((FLAG) == USART_FLAG_FE))

#define IS_USART_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFC9F) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_USART_PERIPH_FLAG(PERIPH, USART_FLAG) ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) &&\
                                                  ((*(uint32_t*)&(PERIPH)) != UART5_BASE)) \
                                                  || ((USART_FLAG) != USART_FLAG_CTS))
#define IS_USART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x0044AA21))
#define IS_USART_ADDRESS(ADDRESS) ((ADDRESS) <= 0xF)
#define IS_USART_DATA(DATA) ((DATA) <= 0x1FF)


/** @defgroup USART_Exported_Macros
  * @{
  */


/** @defgroup USART_Exported_Functions
  * @{
  */

//void USART_DeInit(USART_TypeDef* USARTx);
//void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
//void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
//void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
//void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
//void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
//void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
//void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
//void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
//void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
//void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
//uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
//void USART_SendBreak(USART_TypeDef* USARTx);
//void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
//void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
//void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
//void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
//void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
//FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
//void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
//ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
//void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);

#endif // 0
#endif      // __USART_SPEC_H_20120901YK
