/*******************************************************************************
  * File    : "tracer_spec.h"
  * Author  : kensky
  * Version :
  * Date    : 2019-9-19
  * Brief   :
*******************************************************************************/
#ifndef __TRACER_SPEC_H_2019_9_19
#define __TRACER_SPEC_H_2019_9_19

/**** Includes ****************************************************************/

/**** Defines *****************************************************************/
/**** module switch ***********************************************************/
#define     _TRACER_ON              (0x01u)
#define     _TRACER_OFF             (0x00u)

#define     _TRACER_NOSHOW          (0x00u)
#define     _TRACER_SHOW            (0x01u)
/**** tracer type *************************************************************/
#define     _UNSPECIFIED_TRACER     (0x00u) // set Trace output as Screen
#define     _USART_TRACER           (0x01u) // set Trace output as USART
#define     _SPI_TRACER             (0x02u) // set Trace output as SPI

/**** tracer error messages ***************************************************/
#define     _TRACER_VOID            ((void *)0)

#define     _TRACER_EOK             (0) /**< There is no error */
#define     _TRACER_ERROR           (-1) /**< A generic error happens */
#define     _TRACER_ETIMEOUT        (-2) /**< Timed out */
#define     _TRACER_EFULL           (-3) /**< The resource is full */
#define     _TRACER_EEMPTY          (-4) /**< The resource is empty */
#define     _TRACER_ENOMEM          (-5) /**< No memory */
#define     _TRACER_ENOSYS          (-6) /**< No system */
#define     _TRACER_EBUSY           (-7) /**< Busy */
#define     _TRACER_EIO             (-8) /**< IO error */
#define     _TRACER_NULL            (-9) /**< trace is null*/
#define     _TRACER_EXIST           (-10) /**< trace is already initiated */
#define     _TRACER_ENOLOAD         (-11) /**< No load to be transmitted */

#define     _TRACER_TIMEOUT         (0xfffffff0ull)

#define     _TRACER_0               (0)
#define     _TRACER_1               (1)
#define     _TRACER_2               (2)

#define     _TRACER_ISR_DMA         (0)
#define     _TRACER_ISR_NODMA       (1)

#define     _TRACER_UNLOCKED        (0) // make sure the value is 0
#define     _TRACER_LOCKED          (!_TRACER_UNLOCKED)

#endif //__TRACER_SPEC_H_2019_9_19
