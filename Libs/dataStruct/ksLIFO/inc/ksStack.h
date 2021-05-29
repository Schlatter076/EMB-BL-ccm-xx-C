////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksStack.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSSTACK_H_KENSKY_2014
#define __KSSTACK_H_KENSKY_2014

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
#include "../../DS_cfg.h"

/**** Defines *****************************************************************/
#define			M__KSSTACK_EMPTY					(-1)

/**** LOCAL DATA TYPES ********************************************************/
typedef  enum
{
  ksStackDynamic  = 0,  // the stack is dynamically allocated
  ksStackStatic   = 1,  // the stack is statically allocated
} ksStackType_e;

// the stack should be only initialized based on an static array
typedef  struct
{ // make the data private and invisible
  void          *base;  // the base addr of the stack
  ksStackSize_t eSize;  // element size
  ksStackSize_t sSize;  // stack size : how many elements
  ksStackSize_t top;    // the top of the stack, can be -1(empty)
  ksStackSize_t used;   // how many elements have been used
  dsU08         locked; // synchronizing lock
} ksStack_t;

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackInit
/// @param      : p_arg
///               @arg  pStack
///               @arg  base
///               @arg  eSize
///               @arg  sSize
/// @return     : error number
/// @brief      : initialize a stack
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : the memory allocation should be finisehed outside this routine
////////////////////////////////////////////////////////////////////////////////
int ksStackInit (ksStack_t      *pStack,
                 const void     *base,
                 ksStackSize_t  eSize,
                 ksStackSize_t  sSize);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackDestroy
/// @param      : p_arg
///               @arg  pStack
/// @return     : error number
/// @brief      : when the stack is no longer used, free the mem
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksStackDestroy (const ksStack_t *pStack);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackClear
/// @param      : p_arg
///               @arg  pStack
/// @return     : description of return value.
/// @brief      : set the top of the stack to the base, and free unused mem
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksStackClear     (ksStack_t *pStack);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackIsEmpty
/// @param      : p_arg
///               @arg  pStack
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int _ksStackIsEmpty (const ksStack_t *pStack)
{
  return (-1 == pStack->top);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackIsFull
/// @param      : pStack :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE int _ksStackIsFull (const ksStack_t *pStack)
{
  return (pStack->sSize == pStack->top+1);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackMoveToNext
/// @param      : pStack :
/// @return     : EFAULT || ENODATA || SUCCESS
/// @brief      : move the tail indexer by one, which means one data is being
///               extracted from the queue, and the memory is freed
/// @author     : kensky
/// @date       : Feb 6, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksStackMoveToNext(ksStack_t *pStack);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackPush
/// @param      : pStack :
/// @param      : pElem  :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
int ksStackPush (ksStack_t  *pStack,
                 const void *pElem);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackGetTop
/// @Param      : pStack :
/// @return     : description of return value.
/// @brief      : return the pointer of the top element
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void* ksStackGetTop (const ksStack_t *pStack);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackPop
/// @param      : pStack :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
void* ksStackPop (ksStack_t *pStack);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksStackGetLen
/// @param      : pStack :
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-3
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE ksStackSize_t ksStackGetLen (const ksStack_t *pStack)
{
	 return pStack->used;
}

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __KSSTACK_H_KENSKY_2014
