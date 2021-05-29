////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "DMA_Spec.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __DMA_SPEC_H_KENSKY_2019_6_23
#define __DMA_SPEC_H_KENSKY_2019_6_23

/**** Includes ****************************************************************/
#include <0A_ISR/ISR_Spec.h>

/**** Global Data Types *******************************************************/
typedef enum
{
  DMA_peri_is_des   = 0,
  DMA_mem_to_peri   = 0,
  DMA_peri_is_src   = 1,
  DMA_peri_to_mem   = 1,
  DMA_mem_to_mem    = 2,
} ksDMADir_e;

typedef enum
{
  DMA_AddrNoneInc   = 0, // fixed
  DMA_AddrAutoInc   = 1, // auto incremented for one byte
  DMA_AddrAutoInc1  = 1, // auto incremented for one byte
  DMA_AddrAutoInc2  = 2, // auto incremented for two byte
  DMA_AddrAutoInc4  = 4, // auto incremented for four byte
} ksDMAIncMode_e;

typedef enum
{
  DMA_1_Byte        =  0,
  DMA_2_Byte        =  1,
  DMA_4_Byte        =  2,
} ksDMATxRxSize_e;

typedef enum
{
  DMA_Mem_Mem       = 0,
  DMA_peri_Mem      = 1,
} ksDMATxRxMode_e;

typedef enum
{
  DMA_Direct_Mode   = 0x00,
  DMA_Fifo_Disable  = 0x00,
  DMA_Fifo_Mode     = 0x01,
  DMA_Fifo_Enable   = 0x01,
} ksDmaFifoMode_e;

typedef enum
{
  DMA_Fifo_Thresh_1_4 = 0x00,   // 1/4
  DMA_Fifo_Thresh_1_2 = 0x01,   // 1/2
  DMA_Fifo_Thresh_2_4 = 0x02,   // 3/4
  DMA_Fifo_Thresh_4_4 = 0x03,   // full
} ksDmaFifoThresh_e;

typedef enum
{
  DMA_MemBurst_01     = 0x00,   // increment of 1
  DMA_PeriBurst_01    = 0x00,   // increment of 1
  DMA_MemBurst_04     = 0x01,   // increment of 4
  DMA_PeriBurst_04    = 0x01,   // increment of 1
  DMA_MemBurst_08     = 0x02,   // increment of 8
  DMA_PeriBurst_08    = 0x02,   // increment of 1
  DMA_MemBurst_16     = 0x03,   // increment of 16
  DMA_PeriBurst_16    = 0x03,   // increment of 1
} ksDmaMemBurst_e, ksDmaPeriBurst_e;  // the definition must be the same

typedef enum
{
  DMA_GRP_NotUsed   = 0, // RESERVED, to be compatible with all MCUs, this group is not used.
  DMA_GRP_0         = 0,
  DMA_GRP_1         = 1,
  DMA_GRP_2         = 2,
  DMA_GRP_3         = 3,
} ksDMAGrp_e;

typedef enum
{
  DMA_Chan_NotUsed  = 0, // RESRVED, it seems there is no chn0
  DMA_Chan_0        = 0,
  DMA_Chan_1        = 1,
  DMA_Chan_2        = 2,
  DMA_Chan_3        = 3,
  DMA_Chan_4        = 4,
  DMA_Chan_5        = 5,
  DMA_Chan_6        = 6,
  DMA_Chan_7        = 7,
  DMA_Chan_8        = 8,
} ksDMAChan_e;

typedef enum
{
  DMA_Stream_0      = 0x00, // RESERVED, some mcu doesn't have stream or channel 0x00
  DMA_Stream_1      = 0x01,
  DMA_Stream_2      = 0x02,
  DMA_Stream_3      = 0x03,
  DMA_Stream_4      = 0x04,
  DMA_Stream_5      = 0x05,
  DMA_Stream_6      = 0x06,
  DMA_Stream_7      = 0x07,
  DMA_Stream_8      = 0x08,
} ksDMAStream_e;

typedef enum
{
  DMA_Buf_Normal    = 0,
  DMA_Buf_Circular  = 1,
} ksDMABufMode_e;

typedef enum
{
  DMA_PRIO_0        = 0, // HIGHEST
  DMA_PRIO_VeryHigh = 0, // HIGHEST
  DMA_PRIO_1        = 1, // High
  DMA_PRIO_High     = 1, // High
  DMA_PRIO_2        = 2, // Medium
  DMA_PRIO_Medium   = 2, // Medium
  DMA_PRIO_3        = 3, // LOW
  DMA_PRIO_Low      = 3, // LOW
  DMA_PRIO_4        = 4, // LOWER
  DMA_PRIO_Lower    = 4, // LOWER
} ksDMAprio_e;

typedef struct
{
  ksU32             dmaSrShift;
  ksDMAGrp_e        group;
  ksDMAStream_e     stream;         // for stm32f4xx, f0xx, l0xx
  ksDMAChan_e       channel;
  ksU32             dmaBaseAddr;
  ksU32             periId;
  union
  {
    ksU32           periBaseAddr;   // Specifies the peripheral base address for DMAy Channelx.
    ksU32           srcBaseAddr;    // by default, the source is a peripheral
  };
  union
  {
    volatile ksAddr_t  memBaseAddr; // Specifies the memory base address for DMAy Channelx.
    volatile ksAddr_t  dstBaseAddr; // by default, the source is a peripheral
  };
  ksDMADir_e        dir;            // direction
  ksU32             memSize;        // the memory size
  union
  {
    ksDMAIncMode_e  periAddrInc;    // if the addr of peripheral will be incremented? : 0 | 1
    ksDMAIncMode_e  srcAddrInc;     // by default, the source is a peripheral
  };
  union
  {
    ksDMAIncMode_e  memAddrInc;     // if the addr of peripheral will be incremented? : 0 | 1
    ksDMAIncMode_e  desAddrInc;     // by default, the source is a peripheral
  };
  ksDMATxRxSize_e   periTransSize;  // periph transferring data size: byte word or 1/2word
  ksDMATxRxSize_e   memTransSize;   // memory transferring data size: byte word or 1/2word
  ksDMABufMode_e    bufMode;        // circular or normal
  ksDMAprio_e       prio;           // priority
  ksDMATxRxMode_e   transMode;      // mem2mem, peri2mem or mem2peri
  ksU32             itFlag;
  ksState_e         status;
  ksU32             dmaEn;          // switch the peripheral's DMA
  ksU32             dmaReq;         // remapping value of some DMAs
  ksISR_t           isr;

/**** new in stm32f4xx ****/
  ksDmaFifoMode_e   dmaFifoMode;
  ksDmaFifoThresh_e fifoThreshold;
  ksDmaMemBurst_e   dmaMemBurst;    // inc for 1, 4, 8 and 16
  ksDmaPeriBurst_e  dmaPeriBurst;
} ksDMA_t;
#endif // __DMA_SPEC_H_KENSKY_2019_6_23
