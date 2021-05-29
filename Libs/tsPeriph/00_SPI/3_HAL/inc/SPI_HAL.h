/*******************************************************************************
  * File    :  SPI_HAL.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-23
  * Brief   :  
*******************************************************************************/
#ifndef __SPI_HAL_H_KENSKY_2020_9_23
#define __SPI_HAL_H_KENSKY_2020_9_23

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/SPI_DDL.h"
#include "../../2_DDL/inc/SPI_DDL_TranceiveByte.h"
#include "./SPI_RegHandle.h"

/**** Defines *****************************************************************/

/***** Function Prototypes ****************************************************/
/*******************************************************************************
*  Func_Name: ksSpiInit
*  Paras    : SPI
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
ksRet_t ksSpiInit(ksSPI_t *pSPI);

/*******************************************************************************
*  Func_Name: ksSpiTxRxU08
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
ksU08 ksSpiTxRxU08(const ksSPI_t *pSPI, ksU08 Byte);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksSpiTxU08
/// @param      : p_arg     description of param
///               @arg  SPI
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksSpiTxU08(const ksSPI_t *pSPI, ksU08 Byte);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ykSPI_Rx_U08
/// @param      : p_arg     description of param
///               @arg  SPI
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU08 ykSPI_Rx_U08(const ksSPI_t *pSPI);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ykSpiGetIsrId
/// @param      : p_arg
///               @arg  SPI - ??
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-9-4
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void ykSpiGetIsrId(ksSPI_t *pSPI);

void ksSpiTxRxBuffer(const
                       ksSPI_t *pSPI,
                       const
                       ksU08   *pTxBuf,
                       ksU08   *pRxBuf,
                       ksU32   size);

void ykSPI_Rx_Buffer  (const
                       ksSPI_t *pSPI,
                       ksU08   *pRxBuf,
                       ksU32   size);

void ksSpiTxBuffer  (const
                       ksSPI_t *pSPI,
                       const
                       void   *pTxBuf,
                       ksU32   txSize);

ksRet_t ykSpiSwitch   (ksSPI_t *pSPI, ksSPI_State_e state);

#endif // __SPI_HAL_H_KENSKY_2020_9_23
