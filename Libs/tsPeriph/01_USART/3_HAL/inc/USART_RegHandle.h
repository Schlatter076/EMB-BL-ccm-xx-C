////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "USART_RegHandle.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2014-11-26
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_RVPERIPH_01_USART_3_HAL_INC_USART_REGHANDLE_H_KENSKY_2014__
#define __LIBS_RVPERIPH_01_USART_3_HAL_INC_USART_REGHANDLE_H_KENSKY_2014__

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
#include "../../2_DDL/inc/USART_DDL.h"

/***** Function Prototype *****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @fn         : ksUsartClrITFlag
/// @param      : pUsart  :
/// @param      : isrFlag :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-11-26
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksUsartClrITFlag (ksUSART_t *pUsart, ksU32 isrFlag);

////////////////////////////////////////////////////////////////////////////////
/// @fn         : ykUsartGetITfalg
/// @param      : pUsart  :
/// @param      : isrFlag :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-11-27
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksU08 ykUsartGetITfalg (ksUSART_t *pUsart, ksU32 isrFlag);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_RVPERIPH_01_USART_3_HAL_INC_USART_REGHANDLE_H_kensky_2014__
