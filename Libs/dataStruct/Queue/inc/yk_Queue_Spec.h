/*******************************************************************************
  * File    :  yk_Queue_Spec.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-10
  * Brief   :  
*******************************************************************************/
#ifndef __YK_QUEUE_SPEC_H_KENSKY_2012_9_10
#define __YK_QUEUE_SPEC_H_KENSKY_2012_9_10

/**** Includes ****************************************************************/
#include    "../../DS_Spec.h"

/**** Defines *****************************************************************/

/**** Global Data Types *******************************************************/
/*******************************************************************************
*  Type_Name : pQsend
*  Elements  : chn      : some routine may have this argument to specify which
*                         channel is used to send the data
*              pData    : the data pointer
*              len      : howmany data should be transmitted
*              datatype : the type of the data
*  Brief     : function pointer for data send routine
*******************************************************************************/
typedef unsigned int (*pQsend)(unsigned char  chn,
                               void           *pData,
                               unsigned int   len,
                               data_type_e    datatype);


#endif // __YK_QUEUE_SPEC_H_KENSKY_2012_9_10
