/*******************************************************************************
 * File    :  tracer_usart.c
 * Author  :  kensky
 * Version :
 * Date    :  2020-4-02
 * Brief   :
 *******************************************************************************/

/**** Includes ****************************************************************/
#include	"../inc/tracer_usart.h"
#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

#if ((__USART_TRACER == _TRACER_ON))
/**** LOCAL VARIABLES *********************************************************/
#if (defined(__KS_DMA_IT_TC_OS))
#if (__uTRACER_CNT >= 1)

static ksDMA_t uTracerTxDMA[__uTRACER_CNT] =
{
  {
    .dmaBaseAddr    = 0,  // auto-complete
#if   ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_1)

#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_4,
    .periBaseAddr   = (ksAddr_t)&(USART1->TDR),
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_4,
    .periBaseAddr   = (ksAddr_t)&(USART1->DR),
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .group          = DMA_GRP_0,
    .channel        = DMA_Chan_2, // user can modify this parameter by
    .periBaseAddr   = (ksAddr_t)&(USART0->TXDATA),
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .group          = DMA_GRP_NotUsed, // no group is needed
    .channel        = __uTRACER_TX_DMA_CHANNEL,   // user can modify this parameter by
    .periBaseAddr   = NULL,            // auto-complete,
#else
    #error "not supportted!"
#endif // __MCU_TYPE

#elif ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_2)
#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_7,
    .periBaseAddr   = (ksAddr_t)&(USART2->TDR),
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_7,
    .periBaseAddr   = (ksAddr_t)&(USART2->DR),
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .group          = DMA_GRP_0,
    .channel        = DMA_Chan_4,
    .periBaseAddr   = (ksAddr_t)&(USART1->TXDATA),
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .group          = DMA_GRP_NotUsed,
    .channel        = DMA_Chan_4,
    .periBaseAddr   = (ksAddr_t)&(LPUART1->TXDATA),
#else
    #error "not supportted!"
#endif
#else
#endif // __uTRACER_BUS_1

    .periId         = 0,  // auto-complete
    .memBaseAddr    = (ksAddr_t)&uTracer[0].txBuf.buf,
    .dir            = DMA_peri_is_des,
    .memSize        = __TRACER_DMABUF_SIZE, // initial value
    .periAddrInc    = DMA_AddrNoneInc,
    .memAddrInc     = DMA_AddrAutoInc,
    .periTransSize  = DMA_1_Byte,
    .memTransSize   = DMA_1_Byte,
    .bufMode        = DMA_Buf_Normal,
    .prio           = DMA_PRIO_1,
    .transMode      = DMA_peri_Mem,
#if   ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
    // nothing to be defined
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
    .itFlag         = DMA_IT_TC | DMA_IT_TE,
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#else
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#endif // __MCU_TYPE
    .status         = ksDisbale,
#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
    .dmaEn          = USART_DMAEn_Tx,
#if   ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_1)
    .dmaReq         = USART1_DMAReq_Tx,
#elif ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_2)
    .dmaReq         = USART2_DMAReq_Tx,
#endif
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .dmaEn          = dmadrvPeripheralSignal_USART0_TXBL,
    .dmaReq         = 0x00, // null
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
    // nothing to be defined
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#else
    .dmaEn          = 0x00, // USART_DMAReq_Tx,
    .dmaReq         = 0x00, // null
#endif // __MCU_TYPE

    .isr =
    {
      .id       = 0, // auto complete
      .handler  = NULL,
#if   ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
      .flag         = DMA_IT_TC | DMA_IT_TE,
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
      .flag         = DMA_IF_ERR, // todo
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
      .flag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
      .flag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#else
      .flag         = DMA_IT_TC | DMA_IT_TE,
#endif
      .preprio  = __uTRACER_TX_PREPRIO_1,
      .subprio  = __uTRACER_TX_SUBPRIO_1,
    },
  },
};
#endif // (__uTRACER_CNT >= 1)

#if (__uTRACER_CNT >= 1)
static ksDMA_t uTracerRxDMA[__uTRACER_CNT] =
{
  {
    .dmaBaseAddr    = 0, // autocomplete
#if   ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == is_usart1)
#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_5,
    .periBaseAddr   = (ksAddr_t)&(USART1->RDR),
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_5,
    .periBaseAddr   = (ksAddr_t)&(USART1->DR),
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .group          = DMA_GRP_0,
    .channel        = DMA_Chan_3,
    .periBaseAddr   = (ksAddr_t)&(USART0->RXDATA),
#elif (__MCU_TYPE == _MCU_IS_NRF52832)
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .group          = DMA_GRP_NotUsed,
    .channel        = __uTRACER_RX_DMA_CHANNEL,
    .periBaseAddr   = 0x00, // auto complete
#else
    #error "not supportted!"
#endif // __MCU_TYPE

#elif ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_2)
#if  (__MCU_TYPE == _MCU_IS_STM32L0x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_6,
    .periBaseAddr   = (ksAddr_t)&(USART2->RDR),
#elif (__MCU_TYPE == _MCU_IS_STM32F10x)
    .group          = DMA_GRP_1,
    .channel        = DMA_Chan_6,
    .periBaseAddr   = (ksAddr_t)&(USART2->DR),
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .group          = DMA_GRP_0,
    .channel        = DMA_Chan_4,
    .periBaseAddr   = (ksAddr_t)&(USART1->TXDATA),
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .group          = DMA_GRP_NotUsed,
    .channel        = DMA_Chan_3,
    .periBaseAddr   = (ksAddr_t)&(LPUART1->DATA),
#else
#endif
#else
#endif

    .periId         = 0,// autocomplete
    .memBaseAddr    = (ksAddr_t)&uTracer[0].rxBuf,
    .dir            = DMA_peri_is_src,
    .memSize        = __TRACER_DMABUF_SIZE,
    .periAddrInc    = DMA_AddrNoneInc,
    .memAddrInc     = DMA_AddrAutoInc,
    .periTransSize  = DMA_1_Byte,
    .memTransSize   = DMA_1_Byte,
    .bufMode        = DMA_Buf_Normal, // DMA_Buf_Circular,
    .prio           = DMA_PRIO_1,
    .transMode      = DMA_peri_Mem,

#if   ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
    .itFlag         = DMA_IT_TC | DMA_IT_HT | DMA_IT_TE,
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
    .itFlag         = DMA_IF_ERR, // todo
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
    .itFlag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#else
    .itFlag         = DMA_IT_TC | DMA_IT_HT | DMA_IT_TE,
#endif
    // ksU32 dmaIT = DMA1_FLAG_GL1<<((lv_pTxDMA->channel-DMA_Chan_1)*4);
    .status         = ksEnable,
#if   (__MCU_TYPE == _MCU_IS_STM32L0x)
        .dmaEn      = USART_DMAEn_Rx,
#if   ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == is_usart1)
        .dmaReq     = USART1_DMAReq_Rx,
#elif ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == is_usart2)
        .dmaReq     = USART2_DMAReq_Rx,
#endif // __uTRACER_BUS_1

#elif ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
        .dmaEn      = 0x00, // meaningless
        .dmaReq     = 0x00, // null
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
        .dmaEn      = 0x00, // meaningless
        .dmaReq     = 0x00, // null
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
#if   ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_1)
        .dmaEn      = dmadrvPeripheralSignal_USART0_RXDATAV, // SPI_I2S_DMAReq_Tx,
#elif ((__uTRACER_BUS_1 & _KS_USART_CHN_MASK) == _USART_CHN_2)
        .dmaEn      = dmadrvPeripheralSignal_USART1_RXDATAV, // SPI_I2S_DMAReq_Tx,
#endif // __uTRACER_BUS_1
        .dmaReq     = 0x00, // null
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        .dmaEn      = 0x00,
        .dmaReq     = 0x00, // null
#else
        .dmaEn      = USART_DMAReq_Rx,
        .dmaReq     = 0x00, // null
#endif // __MCU_TYPE

    .isr            =
    {
      .id       = 0, // auto complete
      .handler  = NULL,
#if   ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
#elif (__MCU_TYPE == _MCU_IS_STM32L0x)
      .flag         = DMA_IT_TC | DMA_IT_TE,
#elif ((__MCU_TYPE == _MCU_IS_EFM32TGxxx) || (__MCU_TYPE == _MCU_IS_EFM32ZGxxx))
      .flag         = DMA_IF_ERR, // todo
#elif (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
      .flag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#elif (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
      .flag         = 0x00, // DMA_IT_TC | DMA_IT_TE,
#else
      .flag         = DMA_IT_TC | DMA_IT_TE,
#endif
      .preprio  = __uTRACER_RX_PREPRIO_1,
      .subprio  = __uTRACER_RX_SUBPRIO_1,
    },
  },
};
#endif // (__uTRACER_CNT >= 1)
#endif // defined __KS_DMA_IT_TC_OS

/**** Global Variables ********************************************************/
#if (__uTRACER_CNT >= 1)
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
static ksFsklPort_t sv_uartIoPort[__uTRACER_CNT][_KS_USART_IO_RXD + 0x01] =
{
  {
    {.pFPort = NULL, .pPort = NULL,},
    {.pFPort = NULL, .pPort = NULL,},
    {.pFPort = NULL, .pPort = NULL,},
  }

#if (__uTRACER_CNT >= 2)
  {
    {.pFPort = NULL, .pPort = NULL,},
    {.pFPort = NULL, .pPort = NULL,},
    {.pFPort = NULL, .pPort = NULL,},
  }
#endif
};
#endif // _MCU_IS_FSKLxxZ4

static ksUSART_t sv_usart[__uTRACER_CNT] =
{
  {
    .bus        = (ksUSART_bus_e)__uTRACER_BUS_1,
    .periphID   = 0,
    .addrBase   = 0,
    .RX_isr     =
    { _ksISR_CHN_NULL, (void*)0, __uTRACER_RCVISR_FLAG_1, __uTRACER_RX_PREPRIO_1, __uTRACER_RX_SUBPRIO_1,}, // ykUSART_ISR_t
    .TC_isr     =
    { _ksISR_CHN_NULL, (void*)0, __uTRACER_TXISR_FLAG_1, 0, 0,}, // ykUSART_ISR_t
    {               // GPIO[9]
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        .isr        = { 0,0},
        .PORTn      = __uTRACER_TX_PORT_N_1,
        .Pin        =
        { __uTRACER_TX_PIN_N_1,
          __uTRACER_TX_MODE_1,
          __uTRACER_IO_SPEED_N_1,
#ifdef __uTRACER_TX_AFIO_1
          __uTRACER_TX_AFIO_1,
#endif
        },
        .status     = IO_is_High,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        .pSpecial   = &sv_uartIoPort[0x00][_KS_USART_IO_TXD],
#else
        .pSpecial   = NULL,
#endif
      },

      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        .isr        = { 0,0},
        .PORTn      = __uTRACER_SCK_PORT_N_1,
        .Pin        =
        { __uTRACER_SCK_PIN_N_1,
          __uTRACER_SCK_MODE_1,
          __uTRACER_IO_SPEED_N_1},
        .status     = IO_is_High,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        // .pSpecial   = IO_is_High,
#endif
      },

      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        .isr        = { 0,0},
        .PORTn      = __uTRACER_RX_PORT_N_1,
        .Pin        =
        { __uTRACER_RX_PIN_N_1,
#if     ((__MCU_TYPE == _MCU_IS_STM32L1x) || (__MCU_TYPE == _MCU_IS_STM32L0x))
          (io_Mode_APP),
#elif   (__MCU_TYPE == _MCU_IS_EFR32BG1Pxxx)
          (io_Mode_FIN),
#elif   (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        (io_Mode_FIN),
#else
       __uTRACER_RX_MODE_1,
#endif
       __uTRACER_IO_SPEED_N_1,
#ifdef __uTRACER_RX_AFIO_1
       __uTRACER_RX_AFIO_1,
#endif
        },
        .status     = IO_is_High,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        .pSpecial   = &sv_uartIoPort[0x00][_KS_USART_IO_RXD],
#endif
      },

      { // NSS
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        .isr        = { 0,0},
        .PORTn      = io_Port_No,
        .Pin        = { io_Pin_No,  io_Mode_No, io_NoSpeed},
        .status     = IO_is_High,
#if (__MCU_TYPE == _MCU_IS_FSKLxxZ4)
        // .pSpecial   = IO_is_High,
#endif
      },

      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_RTS_PORT_N_1,
        { __uTRACER_RTS_PIN_N_1,
          __uTRACER_RTS_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_CTS_PORT_N_1,
        {
          __uTRACER_CTS_PIN_N_1,
          __uTRACER_CTS_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_DTR_PORT_N_1,
        {
          __uTRACER_DTR_PIN_N_1,
          __uTRACER_DTR_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_DSR_PORT_N_1,
        {
          __uTRACER_DSR_PIN_N_1,
          __uTRACER_DSR_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_DCD_PORT_N_1,
        {
          __uTRACER_DCD_PIN_N_1,
          __uTRACER_DCD_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },

      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        { 0,0},
        __uTRACER_RI_PORT_N_1,
        {
          __uTRACER_RI_PIN_N_1,
          __uTRACER_RI_MODE_1,
          __uTRACER_IO_SPEED_N_1},
      },
    },

    .params =
    { // ksUsartParams_t
      __uTRACER_BDR_1,            // BaudRate
#if   ((__MCU_TYPE == _MCU_IS_NRF51822) || (__MCU_TYPE == _MCU_IS_NRF52832))
      _KS_USART_WordLength_9b,    // WordLength
#else
      _KS_USART_WordLength_8b,    // WordLength
#endif
      _KS_USART_StopBits_1,       // StopBits
      _KS_USART_Parity_No,        // Parity
      _KS_USART_TxRx_MODE,        // Mode
      _KS_USART_FlowControl_SOFT, // FlowCntl
    },

    .Clk =
    {
      _KS_USART_Clk_Disable,      // USART_Clock
      _KS_USART_CPOL_Low,         // USART_CPOL
      _KS_USART_CPHA_1Edge,       // USART_CPHA
      _KS_USART_LastBit_Disable,  // USART_LastBit
    },

    .clkFreq = 0x00,

#if (__uTRACER_ISR_MODE_1 == _TRACER_ISR_NODMA)
    .rxDMA = NULL,
    .txDMA = NULL,
#else
#if   (__MCU_TYPE == _MCU_IS_NRF52832)
    .rxDMA = NULL,  // not real DMA
    .txDMA = NULL,  // not real DMA
#elif (__MCU_TYPE == _MCU_IS_NRF51822)
    .rxDMA = NULL,
    .txDMA = NULL,
#else
    .rxDMA = &uTracerRxDMA[0],
    .txDMA = &uTracerTxDMA[0],
#endif
#endif

  },

#if (__uTRACER_CNT >= 2)
  {   // ksUSART_bus_e
    .bus        = __uTRACER_BUS_2,
    .periphID   = 0,
    .addrBase   = 0,
    { _ksISR_CHN_NULL, (void*)0, __uTRACER_RCVISR_FLAG_2, __uTRACER_RX_PREPRIO_2, __uTRACER_RX_SUBPRIO_2,}, // ykUSART_ISR_t
    { _ksISR_CHN_NULL, (void*)0, __uTRACER_TXISR_FLAG_2, 0, 0,}, // ykUSART_ISR_t
    {               // GPIO[9]
      {
        .storage    = ksRAM,
        .periphID   = 0,
        .addrBase   = 0,
        .isr        = { 0,0},
        .PORTn      = __uTRACER_TX_PORT_N_2,
        .Pin        =
        { __uTRACER_TX_PIN_N_2,
          __uTRACER_TX_MODE_2,
          __uTRACER_IO_SPEED_N_2},
        .status     = IO_is_High,
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_RX_PORT_N_2,
        { __uTRACER_RX_PIN_N_2,
          __uTRACER_RX_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_SCK_PORT_N_2,
        { __uTRACER_SCK_PIN_N_2,
          __uTRACER_SCK_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_RTS_PORT_N_2,
        { __uTRACER_RTS_PIN_N_2,
          __uTRACER_RTS_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_CTS_PORT_N_2,
        { __uTRACER_CTS_PIN_N_2,
          __uTRACER_CTS_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_DTR_PORT_N_2,
        { __uTRACER_DTR_PIN_N_2,
          __uTRACER_DTR_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_DSR_PORT_N_2,
        { __uTRACER_DSR_PIN_N_2,
          __uTRACER_DSR_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_DCD_PORT_N_2,
        { __uTRACER_DCD_PIN_N_2,
          __uTRACER_DCD_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },

      {
        0, 0,
        { 0,0},
        __uTRACER_RI_PORT_N_2,
        { __uTRACER_RI_PIN_N_2,
          __uTRACER_RI_MODE_2,
          __uTRACER_IO_SPEED_N_2},
      },
    },

    { // ksUsartParams_t
      __uTRACER_BDR_2,// BaudRate
      _YK_USART_WordLength_8b,// WordLength
      _YK_USART_StopBits_1,// StopBits
      _YK_USART_Parity_No,// Parity
      _YK_USART_TxRx_MODE,// Mode
      _YK_USART_FlowControl_SOFT,// FlowCntl
    },

    { // ksUsartClock_t
      _YK_USART_Clk_Disable,// USART_Clock
      _YK_USART_CPOL_Low,// USART_CPOL
      _YK_USART_CPHA_1Edge,// USART_CPHA
      _YK_USART_LastBit_Disable,// USART_LastBit
    },
#if (__TRACER_ISR_MODE_2 == _TRACER_ISR_NODMA)
    .rxDMA = NULL,
    .txDMA = NULL,
#else
    .rxDMA = &tracerRxDMA[0],
    .txDMA = &tracerTxDMA[0],
#endif
  },
#endif
};
#endif // (__uTRACER_CNT >= 1)

#if (__uTRACER_CNT >= 1)
ksTracer_t uTracer[__uTRACER_CNT] =
{
  {
    .storage  = ksRAM,
    .index    = __UTRACER_IDX_1,
    .status   = _tracer_uninit,
    .type     = _tracer_usart,
    .pPeriph  = &sv_usart[0],
    .Q        = NULL,
  },

#if (__uTRACER_CNT >= 2)
  {
    .storage  = ksRAM,
    .index    = 2,
    .status   = _tracer_uninit,
    .type     = _USART_TRACER,
    .pPeriph  = &sv_usart[1],
    { 0,}, // ptr to the Queue
  },
#endif // (__uTRACER_CNT >= 2)
};
#endif // (__uTRACER_CNT >= 1)

/***** Function Definitions ***************************************************/
/*******************************************************************************
 *  Func_Name: Tracer_USART_Receive_Data
 *  Paras    : Tracer_N  :
 *             pData     :
 *  Returns  : None
 *  Brief    : this routine will be called by an ISR
 *  Build on :
 *  Note     : in the tracer, we will only use _TRACER_Console to receive data
 *             from other terminals. by default, the tracer console always uses
 *             tracer0
 *******************************************************************************/
void Tracer_USART_Receive_Data(ksTracer_t *tracer, ksU08 *pData)
{
  *pData = ksUsartGetByte((ksUSART_t*)tracer->pPeriph);
}

#endif // (__TRACER_TYPE == _USART_TRACER)

#endif // (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
