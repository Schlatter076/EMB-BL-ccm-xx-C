////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Proj_cfg.c"
/// * Author  : kensky
/// * Version :
/// * Date    : 2013-4-13
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////

/**** Includes ****************************************************************/
#include <projCfg.h>

#if ((defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON))
#include  <Tracer.h>
#endif
#include <stdio.h>
#include <string.h>

#if (__KS_PERIPH_MODULE == _MODULE_ON)
#include <ksPeriph.h>
#endif // (__KS_PERIPH_MODULE == _MODULE_ON)

#ifndef __MCU_ADDR_SPACE
#error "please define the __MCU_ADDR_SPACE in the first place!"
#endif

volatile ksU08        mcuEndian     = mcu_unkonwn_endian;
volatile ksU08        *gp_StkTop;
volatile ksU08        *gp_StkHip;
volatile ksU08        *gp_free; // pointer to next available free ram area
#if (__KS_PERIPH_MODULE == _MODULE_ON)
volatile ksUUID128_u  *gp_uuid;
#endif // (__KS_PERIPH_MODULE == _MODULE_ON)
volatile int          *gp_rstCnt  = NULL;
volatile int          *gp_1stFlag = NULL; // the application is first launched

__KS_STATIC_ASSERT(mcu_big_endian     == 0x00);
__KS_STATIC_ASSERT(mcu_litle_endian   == 0x01);
__KS_STATIC_ASSERT(mcu_unkonwn_endian == 0xff);

#ifdef __CC_ARM
extern int Image$$RW_IRAM1$$ZI$$Limit;
#elif (defined __ICCARM__)
#pragma segment   = "CSTACK"
#else
extern int __bss_end;
#endif

#ifndef ICACHE_FLASH_ATTR
#define ICACHE_FLASH_ATTR
#endif

#ifndef _uuidCheck
#define _uuidCheck()
#endif

/***** Function Definitions ***************************************************/
void projDebug ()
{

}

////////////////////////////////////////////////////////////////////////////////
/// @fn     : projInit
/// @param  : p_arg :: none
/// @return : description of return value.
/// @brief  : initializing procedure of the project, get the stack top and hip
/// @author : kensky
/// @date   : 2015-2-27
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void  ICACHE_FLASH_ATTR projInit (void)
{
#if ((__MCU_TYPE != _MCU_IS_ESP8266) && (__MCU_TYPE != _MCU_IS_AMD64))
  // volatile makes the variable is allocated on the top of the stack
  volatile int  sp    = 0x1234; // the address of sp is the current value of the SP
  int           stackSize  = 0x00; // this one is allocated in the register

#ifdef __ICCARM__
  gp_StkTop  = (ksVU08*)__sfb("CSTACK");
  gp_StkHip  = (ksVU08*)__sfe("CSTACK");
#else
  // dfferent strcuture from IAR
  gp_StkTop  = (ksVU08*)&__StackLimit;
  gp_StkHip  = (ksVU08*)&__StackTop;
#endif
  stackSize = (int)&sp - (int)gp_StkTop - 64; // it is safe
  memset((ksU08*)gp_StkTop, __CSTACK_FILL_NUM, stackSize);

#if (0)
#ifdef __ADDR_FREE_MEM
  gp_1stFlag  = (int*)(((ksAddr_t)__ADDR_FREE_MEM + 0x08)/4*4); // after gp_stkHip, aligned by 4, offset is 8
#else
  gp_1stFlag  = (int*)(((ksAddr_t)gp_StkHip + 0x08)/4*4); // after gp_stkHip, aligned by 4, offset is 8
#endif
  gp_rstCnt   = ++gp_1stFlag;  // reset counter is after gp_1stFlag, offset is 0x04 (bytes)
  gp_uuid     = (ksUUID128_u *)((ksAddr_t)gp_rstCnt + sizeof(int));
  gp_free     = (ksU08 *)((ksAddr_t)gp_uuid + sizeof(ksUUID128_u));

#if (__KS_PERIPH_MODULE == _MODULE_ON)
  while(!gp_uuid); // should never happen
  // _rvMcuDDLGetUUID((ksUUID128_u*)gp_uuid); // ??
#endif // (__KS_PERIPH_MODULE == _MODULE_ON)

  if (*gp_1stFlag != 0)
  { // always not zero, but please check
    *gp_1stFlag = 0;
    *gp_rstCnt  = 0;

    // initLoopQueue(gp_CycQ, (unitElement_t*)((uint32_t)gp_CycQ+sizeof(loopQueue)+0x08));
    // memset((unitElement_t*)((uint32_t)gp_CycQ+sizeof(loopQueue)+0x08),
    //        0x01,
    //        sizeof(unitElement_t)*gp_CycQ->qSize);
  }
  else
  {
    *gp_rstCnt += 1;
  }
#endif

#if ((defined __MCU_ENDIAN) && (1))
  mcuEndian = ksIsBigEndian();
  __KS_RUNTIME_ASSERT(__MCU_ENDIAN == (endian_is_little == mcuEndian), __ASSERT_NOT_HAPPEN);
#endif

  _uuidCheck();
#endif // (__MCU_TYPE != _MCU_IS_ESP8266)
}

__WEAK void ICACHE_FLASH_ATTR bspDummyPrototype(char dummy[1])
{
  asm("nop"); // do nothing
}

#ifdef  USE_FULL_ASSERT

#if  ((!defined USE_DEFAULT_YK_ASSERT) && (defined __USE_YK_ASSERT))

////////////////////////////////////////////////////////////////////////////////
/// @fn     : ksAssertFailed
/// @param  : p_arg
///           @arg  file  :: which file ?
///           @arg  line  :: which line ?
///           @arg  msg   :: assert message
/// @return : description of return value.
/// @brief  : Brief description of the function.
/// @author : kensky
/// @date   : 2015-4-7
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void ICACHE_FLASH_ATTR ksAssertFailed(ksU08 *file, unsigned int line, const char *msg)
{
#if ((defined __TRACER_MODULE)        && \
     (__TRACER_MODULE == _MODULE_ON)  && \
     (__uTRACER_CNT >= 0x01)          && \
     (0))
  if (_USART_TRACER == uTracer[__TRACER_OUT].type)
  {
    if (_tracer_inited == uTracer[__TRACER_OUT].status)
    {
      __uTRACER_PRINTF(__TRACER_OUT, "\n\rError on [%s]\r\n", file);
      if (msg)
      {
        __uTRACER_PRINTF(__TRACER_OUT, "msg : [%s]\r\n", msg);
      }
    }
    else
    {
#if 0
      printf(__TRACER_OUT,
             "\n\rError on [%s]_line_%d\r\n",
             file,
             line);
      if (msg)
      {
        printf(__TRACER_OUT, "msg : [%s]\r\n", msg);
      }
#endif
    }
  }
#endif

#if (__MCU_TYPE == _MCU_IS_AMD64)

  printf("something wrong at \r\nfile : %s\r\nline :%d\r\nwith message of %s", file, line, msg);

  while(1);
#elif (__MCU_TYPE != _MCU_IS_ESP8266)
#if ((1) || (__RELEASE_MODE == _MODULE_ON))

  ksDelayUsByLoop(1000*1000); // 1 seconds
  __ksGLOBAL_IRQ_OFF();
  ksNvicSwReset();
#else
   __ksGLOBAL_IRQ_OFF();
  while (1) ;
#endif
#else
  while(1); // todo, there should be some debugging information
#endif
}
#endif // ((!defined USE_DEFAULT_YK_ASSERT) && (defined __USE_YK_ASSERT))

/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert error line source number
* Output         : None
* Return         : None
*******************************************************************************/
__WEAK void assert_failed(ksU08* file, int line)
{
  ksAssertFailed(file, line, "stdLibAssert!");
}

#endif // USE_FULL_ASSERT
