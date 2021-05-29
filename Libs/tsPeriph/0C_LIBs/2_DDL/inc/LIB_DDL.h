/*******************************************************************************
  * File    :  LIB_DDL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-10-8
  * Brief   :  
*******************************************************************************/
#ifndef __LIB_DDL_H_KENSKY_2012_10_8
#define __LIB_DDL_H_KENSKY_2012_10_8

/**** Includes ****************************************************************/
#include "../../1_PHY/Common/inc/LIB_Common.h"

#if (__MCU_TYPE != _MCU_IS_ESP8266)
/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksLibDdlGetRandomNum
*  Paras    : min   :
*             max   :
*  Returns  : a random integer number
*  Brief    : the routine will return a random integer which is between min and
*             max.
*  Build on :
*  Note     :
*******************************************************************************/
ksU32 ksLibDdlGetRandomNum(ksU32    min,
                           ksU32    max,
                           ksADC_t  *pAD);

#endif // (__MCU_TYPE != _MCU_IS_ESP8266)

#endif // __LIB_DDL_H_KENSKY_2012_10_8
