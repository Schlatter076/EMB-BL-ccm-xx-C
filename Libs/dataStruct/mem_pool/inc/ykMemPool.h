/*******************************************************************************
  * File    :  yk_memPool.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-10
  * Brief   :  
*******************************************************************************/
#ifndef __YK_MEMPOOL_H_KENSKY_2012_9_10
#define __YK_MEMPOOL_H_KENSKY_2012_9_10

/**** Includes ****************************************************************/
#include "./ykMemPoolCfg.h"

#ifdef __cplusplus
  extern"C"{
#endif

#ifndef NULL
  #ifdef __cplusplus
    #define NULL    0
  #else
    #define NULL    ((void*)0)
  #endif
#endif

/**** Defines *****************************************************************/
/*******************************************************************************
*  Macro_Name : __DEFINE_MEMPOOL_by_TYPE
*  Paras      : element_type：the element type of a mem_pool
*  Brief      : define a mem pool based on the type of its elements
*  Notes      : mem pool is not created yet!
*******************************************************************************/
#define __DEFINE_MEMPOOL_by_TYPE(element_type)   __DEFINE_MEMPOOL_by_UNIT(sizeof(element_type))

/*******************************************************************************
*  Macro_Name : __DEFINE_MEMPOOL
*  Paras      : unit_size：the size of the element in a mem pool
*  Brief      : define a mem pool based on the size of its elements
*  Notes      : mem pool is not created yet!
*******************************************************************************/
#define __DEFINE_MEMPOOL_by_UNIT(unit_size) \
    __DEFINE_MEMPOOL_by_ALIGN((unit_size), (__MEM_POOL_DEFAULT_ALIGN_SIZE))

/*******************************************************************************
*  Macro_Name : __DEFINE_MEMPOOL_ALIGN
*  Paras      : unit_size：the size of the element in a mem pool
*               align_size  ：align size
*  Brief      :
*  Notes      : mem pool is not created yet!
*******************************************************************************/
#define __DEFINE_MEMPOOL_by_ALIGN(unit_size, align_size) \
    __DEFINE_MEMPOOL_FULL((unit_size), (align_size), (__MEM_POOL_DEFAULT_POOL_SIZE))

/*******************************************************************************
*  Macro_Name : __DEFINE_MEMPOOL_FULL
*  Paras      : unit_size   ：mem unit size
*               align_size  ：alignment size
*               pool_size   ：the pool size is the whole size of a mem pool,
*                             which has a unit of byte. the routine will adjust
*                             the size according to the alignment in order to
*                             put in aligned mem units.
*  Brief      : 上述内存池的定义允许重复定义。但是unit_size和align_size必须是
*               常量并且必须align_size>0。否则编译器将会报告错误（类似不能初始化常
*               量、除数是0）。尽量不要在循环中定义内存池，因为这将降低程序的执行效率。
*  Notes      : mem pool is not created yet!
*******************************************************************************/
#define __DEFINE_MEMPOOL_FULL(unit_size, align_size, pool_size) \
{\
    static unsigned long const \
      elm_size = (unit_size),\
      alg_size = (align_size) /*,pl_size=pool_size*/; /*This define can't be deleted*/\
    \
    static unsigned long const \
      x        = 0/align_size;/*This define can't be deleted*/\
    \
    static mem_pool_type ALLOC_ELEMENT;\
    \
    define_mempool_fun_CDC05EA9_8F5A_4e17_864C_34A872EEEBC1\
        (&ALLOC_ELEMENT, elm_size, alg_size, pool_size+x-x);\
}

/*******************************************************************************
*  Macro_Name : POOLMALLOC
*  Paras	  : unit_size
*  Brief      : 从内存池分配一个分配单元, 分配失败返回NULL. 应该对应DEFINE_MEMPOOL
*               定义的内存池（或者使用DEFINE_MEMPOOL_ALIGN、DEFINE_MEMPOOL_FULL定
*               义，但是align_size为默认对齐）unit_size：应该是已经定义过的
*               （使用默认对齐），否则返回NULL
* Note        : if successful, the mem pool is created
*******************************************************************************/
#define POOLMALLOC(unit_size) \
    poolmalloc_align((unit_size), (__MEM_POOL_DEFAULT_ALIGN_SIZE))

/*******************************************************************************
*  Macro_Name : POOLFREE
*  Paras	  : pBuf        : 分配内存时返回的指针，当pBuf为NULL时，直接返回。（不会出错）
*               unit_size: 必须和分配时指定的分配单元字节大小相同
*  Brief      : 释放一个分配单元到内存池, 应该和POOLMALLOC成对使用（只能释放使用默认
*               对齐分配的分配单元）
*******************************************************************************/
#define POOLFREE(pBuf, unit_size) \
    poolfree_align((pBuf), (unit_size), __MEM_POOL_DEFAULT_ALIGN_SIZE)

/*******************************************************************************
*  Macro_Name : POOLMALLOC_TYPE
*  Paras	  :
*  Brief      : 从内存池分配一个分配单元, 分配失败返回NULL. 应该对应DEFINE_MEMPOOL
*               定义的内存池, 或者使用DEFINE_MEMPOOL_ALIGN、DEFINE_MEMPOOL_FULL定
*               义，但是align_size为默认对齐）unit_size：应该是已经定义过的（使
*               用默认对齐），否则返回NULL
*******************************************************************************/
#define POOLMALLOC_TYPE(type)       ((type*)POOLMALLOC(sizeof(type)))

/*******************************************************************************
*  Macro_Name : POOLFREE_TYPE
*  Paras	  : pBuf    : 分配内存时返回的指针（必须具有正确的类型，依靠它得到释放
*                         单元的大小.
*  Brief      : 应该和POOLMALLOC_TYPE成对使用. （只能释放使用默认对齐分配的分配单元）
                sizeof(pBuf)必须和分配时指定的分配单元字节大小相同）,当pBuf为NULL
                                          时，直接返回。（不会出错）
*******************************************************************************/
#define POOLFREE_TYPE(pBuf) \
    poolfree_align(pBuf, sizeof(*pBuf), __MEM_POOL_DEFAULT_ALIGN_SIZE)

/*******************************************************************************
*  Func_Name: poolmalloc_align
*  Paras    : unit_size  :
*             align_size    :
*  Returns  : 分配失败返回NULL
*  Brief    : 从内存池分配一个分配单元
*  Build on :
*  Note     : 对应DEFINE_MEMPOOL、DEFINE_MEMPOOL_ALIGN或者DEFINE_MEMPOOL_FULL定义
*             过的内存池。应该定义过unit_size和align_size对应的内存池，
*             否则返回NULL
*******************************************************************************/
void* poolmalloc_align(unsigned long unit_size, unsigned long align_size);

/*******************************************************************************
*  Func_Name: poolfree_align
*  Paras    : pBuf          : 分配内存时返回的指针，当pBuf为NULL时，直接返回。
*                             （不会出错）
*             unit_size  :
*             align_size    :
*  Returns  :
*  Brief    : 释放一个分配单元到内存池
*  Build on :
*  Note     : 应该和poolmalloc_align成对使用, unit_size和align_size：必须和分
*             配时指定的数值相同
*******************************************************************************/
void poolfree_align(void*pBuf,unsigned long unit_size,unsigned long align_size);

#if(__MEM_POOL_OPTIMAL_SIMPLE_USE == _NOTSET_ORIGINAL_BLKSIZE)
/*当__MEM_POOL_OPTIMAL_SIMPLE_USE为1时才有这个宏
pBuf：分配内存时返回的指针，当pBuf为NULL时，直接返回。（不会出错）
当__MEM_POOL_OPTIMAL_SIMPLE_USE为1时，也可以使用poolfree_align或者POOLFREE释放，
但是应该保证unit_size和align_size正确或者全部为0。
当同时__MEM_POOL_DEBUG为1时，必须保证unit_size和align_size正确或者全部为0。*/
#define POOLFREE_SIMPLE(pBuf)   poolfree_align(pBuf,0,0)
#endif

typedef void*POOL_HANDLE;

/*得到内存池的句柄,没有内存池返回NULL*/
/*******************************************************************************
*  Func_Name:
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
POOL_HANDLE poolgethandle(unsigned long unit_size,unsigned long align_size);
/*得到某个内存池的使用信息
handle[in]内存池的句柄
ptotal_pool_size[in/out]如果不是NULL，*ptotal_pool_size返回内存池分配的内存空间（handle==NULL，返回0）
返回值
  内存池已经分配的元素个数（handle==NULL，返回0）*/

/*******************************************************************************
*  Func_Name:
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
unsigned long poolgetinfo(POOL_HANDLE handle,unsigned long*ptotal_pool_size);

/*******************************************************************************
*  Func_Name: poolsetlimit
*  Paras    : handle: 内存池的句柄
*             limit : 内存池分配空间限制,负数表示不限制(默认没有限制)
*  Returns  :
*  Brief    : 设置内存池总尺寸限制
*  Build on :
*  Note     :
*******************************************************************************/
void poolsetlimit(POOL_HANDLE handle, long limit);

/*得到内存池总尺寸限制
handle[in]内存池的句柄(handle==NULL，返回负数)
返回值
  内存池分配空间限制,负数表示不限制(默认返回负数)*/
//long poolgetlimit(POOL_HANDLE handle);


/*以下宏定义用于调试使用，建议尽量使用宏定义而不使用poolgethandle和poolgetinfo函数
因为宏可以适应调试状态和非调试状态*/
#define POOLGETINFODIRECT(unit_size,ptotal_pool_size) \
    POOLGETINFO(POOLGETHANDLE(unit_size),ptotal_pool_size)

#define POOLGETINFODIRECT_ALIGN(unit_size,align_size,ptotal_pool_size) \
    POOLGETINFO(POOLGETHANDLE_ALIGN(unit_size,align_size),ptotal_pool_size)

#define POOLGETHANDLE(unit_size) \
    POOLGETHANDLE_ALIGN(unit_size,__MEM_POOL_DEFAULT_ALIGN_SIZE)

#if(__MEM_POOL_DEBUG == _MEMPOOL_DBG_ON)
#define POOLGETHANDLE_ALIGN(unit_size,align_size) \
    poolgethandle(unit_size,align_size)
#define POOLGETINFO(handle,ptotal_pool_size) \
    poolgetinfo(handle,ptotal_pool_size)
#else
#define POOLGETHANDLE_ALIGN(unit_size,align_size) 0
#define POOLGETINFO(handle,ptotal_pool_size) \
    (ptotal_pool_size?*(unsigned long*)ptotal_pool_size=0:0,0)
#endif

/*以下内容用户不应该了解实现细节，应该看成不透明的*/
typedef union
{
    void            *pv;    //void
    char            *pc;    //char
    unsigned char   *puc;   // unsigned char
    char            ch[sizeof(void*)];
    unsigned char   uc[sizeof(void*)];
} mempool_addr_union;

typedef struct mem_unit_node // node
{
  unsigned long         size;       // element size
  unsigned long         alignsize;  // alignment size
  struct mem_unit_node  *pNext;
} mem_pool_unit_type;               // allocation unit

typedef struct mem_pool_node
{
    struct mem_pool_node    *pNext;         // list
    mempool_addr_union      Free;           //
    mem_pool_unit_type      allocunit;      // allocation unit
    unsigned long           size;           // element size + sizeof(ALLOC_LIST*) adjusted by alignment
    unsigned long           alignsize;      // alignment size
    unsigned long           poolsize;       // pool size
    unsigned long           totalpoolsize;  //
    unsigned long           elementnum;
    long                    totalpoolsizelimit;
    unsigned char volatile  bRunning;       // running status???
} mem_pool_type;

typedef mem_pool_type       ALLOC_LIST;
typedef mempool_addr_union  ADDR;
typedef mem_pool_unit_type  ALLOC_UNIT;

//typedef struct  stack_type  *Stack; // Incomplete Data Structure

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : memPool_Define
/// @param      : p_arg     description of param
///               @arg  arg_1
///               @arg  arg_2
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2013-4-25
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
/// @deprecated : add deprecated reason.
////////////////////////////////////////////////////////////////////////////////
void memPool_Define(ALLOC_LIST      *pElmt,     unsigned long unit_size,
                     unsigned long  align_size, unsigned long pool_size);

/*******************************************************************************
*  Func_Name:
*  Paras    :
*  Returns  :
*  Brief    :
*  Build on :
*  Note     :
*******************************************************************************/
void define_mempool_fun_CDC05EA9_8F5A_4e17_864C_34A872EEEBC1
    (mem_pool_type*,
     unsigned long, unsigned long, unsigned long);

#ifdef __cplusplus
}
#endif

#endif // __YK_MEMPOOL_H_KENSKY_2012_9_10

/**** Examples ****************************************************************/
/*******************************************************************************
#include "yk_memPool.h"

//Complile error
static void mem_fun(unsigned long i){
    //DEFINE_MEMPOOL(i);
    //DEFINE_MEMPOOL_ALIGN(sizeof(long),i);
}

void mem_test()
{
    void*pbuf=NULL,*pbuf2=NULL;
    unsigned long i=sizeof(int),size;
    mem_fun(i);
    DEFINE_MEMPOOL_FULL(sizeof(long),sizeof(long),8);
    DEFINE_MEMPOOL_ALIGN(20,1);
    DEFINE_MEMPOOL_FULL(sizeof(short),sizeof(long),12);
    DEFINE_MEMPOOL_ALIGN(20,2);
    for(i=sizeof(long);i<sizeof(long)*3;i+=sizeof(long))
    {
        DEFINE_MEMPOOL_FULL(sizeof(long),sizeof(long),i);
    }
    pbuf=POOLMALLOC(6);
    pbuf=POOLMALLOC(1);
    pbuf=POOLMALLOC(2);
    pbuf2=POOLMALLOC(4);
    pbuf=POOLMALLOC(4);
    pbuf=POOLMALLOC(4);
    POOLFREE(pbuf2,4);
    pbuf=POOLMALLOC(3);
    pbuf=poolmalloc_align(20,2);
    DEFINE_MEMPOOL_ALIGN(20,4);
    pbuf=poolmalloc_align(20,1);
    pbuf=poolmalloc_align(20,4);
    i=POOLGETINFODIRECT_ALIGN(20,1,&size);
    i=POOLGETINFODIRECT_ALIGN(20,2,&size);
    i=POOLGETINFODIRECT_ALIGN(20,4,&size);
    i=POOLGETINFODIRECT_ALIGN(sizeof(long),sizeof(long),&size);
}
*******************************************************************************/

