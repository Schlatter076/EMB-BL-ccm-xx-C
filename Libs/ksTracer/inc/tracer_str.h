/*******************************************************************************
  * File    :  tracer_str.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-20
  * Brief   :  
*******************************************************************************/
#ifndef __TRACER_STR_H_KENSKY_2012_9_20
#define __TRACER_STR_H_KENSKY_2012_9_20

/**** Includes ****************************************************************/
#include "../tracer_cfg.h"
#include <stdint.h>

#if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)

/*******************************************************************************
* Function Name  : int dbg_hex2str
                     ( char *str, int size_str, uint8_t *hex, int len_hex )
* Description    : hex2str
* Input          : 1. *str:
                   2. size_str:
                   3. *hex:
                   4. len_hex:
* Output         : ???????????
* Return         : len_hex
*******************************************************************************/
int dbg_hex2str(char*str, int size_str, uint8_t*hex, int len_hex);

#endif // #if (defined __TRACER_MODULE)  &&  (__TRACER_MODULE == _MODULE_ON)
#endif // __TRACER_STR_H_KENSKY_2012_9_20
