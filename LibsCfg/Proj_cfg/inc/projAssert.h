////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "projAssert.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __PROJASSERT_H_KENSKY_2014__
#define __PROJASSERT_H_KENSKY_2014__

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

/**** Defines *****************************************************************/
#ifdef  __USE_YK_ASSERT

#define __ASSERT_NULL                     "nil"
#define __ASSERT_LIMIT                    "lmt"
#define __ASSERT_PARA                     "arg"
#define __ASSERT_NOT_HAPPEN               "not"
#define __ASSERT_VALUE                    "val"
#define __ASSERT_LOCK                     "lock"
#define __ASSERT_TIMEOUT                  "tmout"
#define __ASSERT_FAULT                    "err"
#define __ASSERT_TODO                     "todo"
#define __ERROR__MSG                      "err_ret"

#ifdef __UUID

#define  _uuidCheck()                     \
  extern volatile ksUUID128_u *gp_uuid;   \
  while((!gp_uuid));                      \
  while((gp_uuid->id64[0] != __UUID0));   \
  while((gp_uuid->id64[1] != __UUID1));

#else // the __UUID is not defined

#define  _uuidCheck()

#endif // __UUID

/*******************************************************************************
* check whether this expression is beyond the limit defined by routine!
*******************************************************************************/
#define __KS_STATIC_ASSERT(expr)            void bspDummyPrototype(char dummy[1/((expr)!=0)])

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed.
  *   If expr is true, it returns no value.
  * @retval None
  */
#if (defined USE_FULL_FILENAME)
#define __KS_RUNTIME_ASSERT(expr, msg)      st(((expr) ? (void)0 : ksAssertFailed((unsigned char *)__FILE__, __LINE__, (msg)));)
#define __KS_FORCE_ASSERT(msg)              st(ksAssertFailed((unsigned char *)__FILE__, __LINE__, (msg));)
#define __KS_ERROR_CHECK(errRet)            st(((0x00 == errRet) ? (void)0 : ksAssertFailed((unsigned char *)__FILE__, __LINE__, (__ERROR__MSG)));)
#else
#define __KS_RUNTIME_ASSERT(expr, msg)      st(((expr) ? (void)0 : ksAssertFailed((unsigned char *)__func__, 0x00, (msg)));)
#define __KS_FORCE_ASSERT(msg)              st(ksAssertFailed((unsigned char *)__func__, 0x00, (msg));)
#define __KS_ERROR_CHECK(errRet)            st((0x00 == errRet) ? (void)0 : ksAssertFailed((unsigned char *)__func__, 0x00, (__ERROR__MSG));)
#endif

/* Exported functions ------------------------------------------------------- */
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
void ksAssertFailed     (unsigned char * file, unsigned int line, const char *msg);
void bspDummyPrototype  (char dummy[1]);

#else

#define __ASSERT_NULL
#define __ASSERT_LIMIT
#define __ASSERT_PARA
#define __ASSERT_NOT_HAPPEN
#define __ASSERT_VALUE
#define __ASSERT_LOCK
#define __ASSERT_TIMEOUT
#define __ASSERT_FAULT
#define __ASSERT_TODO

#define __KS_FORCE_ASSERT(msg)              // ((void)0)
#define __KS_STATIC_ASSERT(expr)            // void bspDummyPrototype(char dummy[1/((expr)!=0)])
#define __KS_RUNTIME_ASSERT(expr, msg)      // ((void)0)

#endif /* __USE_YK_ASSERT */

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __PROJASSERT_H_KENSKY_2014__
