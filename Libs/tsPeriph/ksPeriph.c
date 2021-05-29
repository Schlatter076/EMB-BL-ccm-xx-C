/*******************************************************************************
  * File    :  ksPeriph.c
  * Author  :  kensky
  * Version :
  * Date    :  2020-9-19
  * Brief   :
*******************************************************************************/

/**** Includes ****************************************************************/
#include <ksPeriph.h>

/***** Function Definitions ***************************************************/
#if ((defined USE_DEFAULT_YK_ASSERT) && (defined __USE_YK_ASSERT))
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed.
  *   If expr is true, it returns no value.
  * @retval None
  */
#if (defined __TRACER_MODULE) && \
    (__TRACER_MODULE == _MODULE_ON)
#include <Tracer.h>
#endif

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void ksAssertFailed(unsigned char *file, unsigned int line, const char *msg)
{
#if (defined __TRACER_MODULE) && (__TRACER_MODULE == _MODULE_ON)
#if (__uTRACER_CNT >= (__TRACER_OUT+1))
  if (_USART_TRACER == uTracer[__TRACER_OUT].type)
  {
    if ((uTracer[__TRACER_OUT].txBuf.status != _tracer_Locked) &&
        (_tracer_inited == uTracer[__TRACER_OUT].status))
    {
      __uTRACER_PRINTF(__TRACER_OUT,
                       _TRACER_SHOW,
                       "\n\rError detected on [%s]_line_%d\r\n",
                       file,
                       line);
      if (msg)
      {
        __uTRACER_PRINTF(__TRACER_OUT, _TRACER_SHOW, "msg : [%s]\r\n", msg);
      }
    }
    else
    {
#if 0
      printf(__TRACER_OUT, "\n\rWrong parameter value detected on\r\n");
      printf(__TRACER_OUT, "[%s]_line_%d\r\n", file, line);
      if (msg)
      {
        printf(__TRACER_OUT, "msg : [%s]\r\n", msg);
      }
#endif
    }
  }
#endif // (__uTRACER_CNT >= (__TRACER_OUT+1))
#endif

#if ((1) || (__RELEASE_MODE == _MODULE_ON))
  ksDelayUsByLoop(1000*1000); // 1 seconds
  ksNvicSwReset();
#else
  while (1) ;
#endif
}

#endif // #if (defined __USE_YK_ASSERT)
