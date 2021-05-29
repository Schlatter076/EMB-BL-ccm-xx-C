////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksHash.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSHASHMAP_H_KENSKY_2014
#define __KSHASHMAP_H_KENSKY_2014

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
#include "../../ksLIFO/inc/ksStack.h"
#include "../fnv/inc/fnv.h"
#include "../../ksList/inc/ksHashList.h"

/**** Global Data Types *******************************************************/
typedef struct
{
  hListNode_t node;
  void        *pData;
} ksHmapNode_t;

typedef dsU64   (*genHval_fn)(const unsigned char *pKey,
                              unsigned int        keyLen,
                              unsigned char       width);

typedef dsS32   (*locateCb_fn)(const ksHmapNode_t   *pElmt,
                               const unsigned char  *pKey,
                               unsigned int         keyLen);

/*******************************************************************************
 * there will be 3 basic data structure to support the hashmap
 * 1. : array of the hListHead : it is linked with the array of the actual data
 * 															 both of which are sequentially accessed within
 * 															 the hQty.
 * 			@hQty : head quantity
 * 2.	: stack of the ksHmapNode_t, you also have to prepare an array for it
 * 			@nQty	: mSize - hQty
 * 3. : array of the actual data
 * 			@dQty	: mSize
*******************************************************************************/
typedef struct
{
  hListHead_t   *hBase;     // base points to the address of the hListHead
	ksStack_t			*stack;     // we will use a stack to maintain the ksHmapNode
  void   				*dBase;     // base points to the address of the actual data
  ksHashSize_t	hQty;		    // head quantity, how many heads are there?
  ksHashSize_t  eSize;      // element size :: size of actual data elemenetK
  ksHashSize_t  mSize;      // the hashMap size, how many elements can be hold all together?
  ksHashSize_t  used;       // how many elements have been filled into the hash map
  dsU08         locked;     // reserved for synchronization
  genHval_fn    genHashFn;  // the function to generate the hash value
} ksHashMap_t;

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksHmapInit
/// @param      : p_arg
///               @arg  pHmap     : the data structure of a hashmap
///               @arg  pStack    : the statck used by the hashmap
///               @arg  pHeadBuf  : headArray :: hList
///               @arg  pStackBase: nodeArray :: stack manipulated
///               @arg  pDataBuf  : dataArray :: realData
///               @arg  mSize     : max size of the map
///               @arg  hQty      : the size of the head of the map
///               @arg  eSize     : the size of the element in the map
/// @return     : errno or 0 for success
/// @brief      : initialize the hash map, you must initialize a stack and a
///               hList together. there will be 3 arrays, which are head array,
///               data array and node array. the node array will be managed by
///               the stack. The node array and the data array are linked with
///               index.
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       : the data are stored in a array, the front part of that is
///               manipulated by the the listHead, the position of both is
///               matched with each other. however, the hind part of the buf is
///               managed by the stack. So, there will be no pData in the head,
///               we will use the index to access the data in the buffer
////////////////////////////////////////////////////////////////////////////////
int ksHmapInit(ksHashMap_t        *pHmap,
               ksStack_t          *pStack,
               hListHead_t        *pHeadBuf,
               const ksHmapNode_t *pNodeBuf,
               const void         *pDataBuf,
               ksHashSize_t       mSize,
               ksHashSize_t       hQty,
               ksHashSize_t       eSize,
               genHval_fn         hvalCb);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksHmapLocate
/// @param      : p_arg
///               @arg  pHmap     :: the hMap
///               @arg  pKey      :: the key
///               @arg  keyLen    :: the length of the key
///               @arg  locateCb  :: how to locate the element
/// @return     : the pointer to the element holding the key
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       : make sure the key is stored inside the data, and the address
///               of the key should be the same as pData
////////////////////////////////////////////////////////////////////////////////
ksHmapNode_t* ksHmapLocate(const ksHashMap_t  *pHmap,
                           const void         *pKey,
                           dsU32              keyLen,
                           locateCb_fn        locateCb);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksHmapUpdate
/// @param      : p_arg
///               @arg  pHmap     : the hash map
///               @arg  pKey      : key
///               @arg  keyLen    : length of the key
///               @arg  pVal      : value to put
///               @arg  locateCb  :: how to locate the element
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : Jun 14, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
dsS32 ksHmapUpdate(ksHashMap_t *pHmap,
                   const void  *pKey,
                   dsU32       keyLen,
                   const void  *pVal,
                   locateCb_fn locateCb);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksHmapPut
/// @param      : p_arg
///               @arg  pHmap   : the hash map
///               @arg  pKey    : key
///               @arg  keyLen  : length of the key
///               @arg  pVal    : value to put
/// @return     : description of return value.
/// @brief      : insert an element into the hash map by its key, you have to
///               provide the value
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksHmapPut(ksHashMap_t *pHmap,
              const void  *pKey,
              dsU32       keyLen,
              const void  *pVal);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksHmapRemove
/// @param      : p_arg
///               @arg  pHmap     :: the hashmap
///               @arg  pKey      :: the key
///               @arg  keyLen    :: the length of the key
///               @arg  locateCb  :: how to locate the element
/// @return     : 0 for success, -1 for failure otherwise
/// @brief      : remove an emelemt in the hash map by its key
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       :
////////////////////////////////////////////////////////////////////////////////
int ksHmapRemove(ksHashMap_t   *pHmap,
                 const void     *pKey,
                 size_t         keyLen,
                 locateCb_fn   locateCb);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __KSHASH_H_KENSKY_2014
