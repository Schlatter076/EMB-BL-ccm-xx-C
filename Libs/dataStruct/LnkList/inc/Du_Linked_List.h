////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Du_Linked_List.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   : 用于链表操作（双向循环链表）。
/// *           因为双向循环链表的内存开销没有比单向链表巨大增长，
/// *           故可以在只需要单向（无论是否循环）时使用双向循环链表。
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __DU_LINKED_LIST_H_KENSKY_2012_12_15
#define __DU_LINKED_LIST_H_KENSKY_2012_12_15

/**** Includes ****************************************************************/
#include "../../DS_cfg.h"

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifdef __cplusplus
extern"C"{
#endif

//该结构用于管理双向循环链表。
//在需要使用双向循环链表的结构中定义一个Bi_Cycle_List类型成员。
//建议定义成第一个成员
typedef struct _Bi_Cycle_List
{
    struct _Bi_Cycle_List*pBefore,*pAfter;
} Bi_Cycle_List;

void*BiCyList_AddrToItemType(Bi_Cycle_List*ptr,long delta);
Bi_Cycle_List*BiCyList_AddrFromItemType(void*ptr,long delta);

#define BiCyList_ADDR_DELTA(type,member) ((long)&((type*)NULL)->member)

//从一个Bi_Cycle_List指针转换成type类型指针（NULL还是转换成NULL，只改变类型）
#define BiCyList_ENTRY(ptr,type,member) \
    ((type*)BiCyList_AddrToItemType(ptr,BiCyList_ADDR_DELTA(type,member)))

//初始化一个链表，pOriginal指向一个哑元节点，内存空间由用户分配
void BiCyList_CreateInstance(Bi_Cycle_List*pOriginal);
//释放一个空链表，返回RET_SUCCESS_SUCCESS表示成功（链表为空）
//返回RET_ERROR_GENERAL表示失败（链表不为空）。此时需要删除所有链表元素，然后再次调用
//BiCyList_DeleteInstance
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
long BiCyList_DeleteInstance(Bi_Cycle_List*pOriginal);

//交换两个链表
//pOriginalFirst:指向第一个哑元节点
//pOriginalSecond:指向第二个哑元节点
//当pOriginalFirst==pOriginalSecond时，程序可以正常执行（什么都不做）
void BiCyList_Exchange(Bi_Cycle_List*pOriginalFirst,Bi_Cycle_List*pOriginalSecond);

//交换一个链表中的两个元素
//返回：
//  RET_SUCCESS_SUCCESS表示成功
//  RET_ERROR_GENERAL表示失败，pOriginal==pFirst||pOriginal==pSecond
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pFirst：要交换的一个元素
//pSecond：要交换的另一个元素
//当pFirst==pSecond时，程序可以正常执行（什么都不做）
long BiCyList_ExchangeItem(Bi_Cycle_List*pOriginal,
    Bi_Cycle_List*pFirst,Bi_Cycle_List*pSecond);

//在当前位置插入一个元素（原来该位置及其之后的元素向后移动）
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pPosition当前位置。如果pOriginal==pPosition||NULL==pPosition，插入到链表的最后面。
//pNew新元素的地址（新元素的内存空间由用户分配），该函数只是将它插入到链表中
//如果pNew为NULL，什么都不做。
//注意，pNew必须在链表之外（就是说同一个地址不能多次加入链表），一般来说是新分配的空间。
//返回：pNew
Bi_Cycle_List*BiCyList_Insert(Bi_Cycle_List*pOriginal,Bi_Cycle_List*pPosition,
    Bi_Cycle_List*pNew);
//删除当前位置的元素
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pPosition当前位置。如果pOriginal==pPosition||NULL==pPosition，什么都不做，返回NULL
//返回：删除之前pPosition的后面一个元素的指针。如果没有后一个元素了，返回NULL。
Bi_Cycle_List*BiCyList_Delete(Bi_Cycle_List*pOriginal,Bi_Cycle_List*pPosition);
//得到前面一个元素的地址
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pPosition当前位置
//bCycled如果不是0，链表的第一个元素的前面一个元素是最后一个元素（循环方式）
//bCycled如果是0，链表的第一个元素的前面一个元素不存在（返回NULL，非循环方式）
//无论bCycled是什么值，
//如果pOriginal==pPosition||NULL==pPosition，返回最后一个元素的地址（空链表返回NULL）
//返回：前面一个元素的地址
Bi_Cycle_List*BiCyList_Before(Bi_Cycle_List*pOriginal,Bi_Cycle_List*pPosition,int bCycled);
//得到后面一个元素的地址
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pPosition当前位置
//bCycled如果不是0，链表的最后一个元素的后面一个元素是第一个元素（循环方式）
//bCycled如果是0，链表的最后一个元素的后面一个元素不存在（返回NULL，非循环方式）
//无论bCycled是什么值，
//如果pOriginal==pPosition||NULL==pPosition，返回第一个元素的地址（空链表返回NULL）
//返回：后面一个元素的地址
Bi_Cycle_List   *BiCyList_After(Bi_Cycle_List*pOriginal,Bi_Cycle_List*pPosition,int bCycled);

//交换一个链表中的两个元素
//返回：
//  RET_SUCCESS_SUCCESS表示成功
//  RET_ERROR_GENERAL表示失败，pOriginal==pFirst||pOriginal==pSecond
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pFirst：要交换的一个元素
//pSecond：要交换的另一个元素
//当pFirst==pSecond时，程序可以正常执行（什么都不做）
#define BiCyList_EXCHANGE_ITEM(pOriginal,pFirst,pSecond,type,member) \
    BiCyList_ExchangeItem(pOriginal,\
    BiCyList_AddrFromItemType(pFirst,BiCyList_ADDR_DELTA(type,member)),\
    BiCyList_AddrFromItemType(pSecond,BiCyList_ADDR_DELTA(type,member)))

//在当前位置插入一个元素（原来该位置及其之后的元素向后移动）
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pItem当前位置（type类型的指针）。
//如果pOriginal==pItem->member||NULL==pItem，插入到链表的最后面。
//pNewItem新元素的地址（新元素的内存空间由用户分配），该函数只是将它插入到链表中
//如果pNewItem为NULL，什么都不做。
//注意，pNewItem必须在链表之外（就是说同一个地址不能多次加入链表），一般来说是新分配的空间。
//type:pItem和pNewItem的类型
//member:type类型中链表管理结构（Bi_Cycle_List）的成员名称
//返回：pNewItem
#define BiCyList_INSERT_ITEM(pOriginal,pItem,pNewItem,type,member) \
    BiCyList_ENTRY(BiCyList_Insert(pOriginal,\
    BiCyList_AddrFromItemType(pItem,BiCyList_ADDR_DELTA(type,member)),\
    BiCyList_AddrFromItemType(pNewItem,BiCyList_ADDR_DELTA(type,member))),\
    type,member)

//删除当前位置的元素
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pItem当前位置（type类型的指针）。
//如果pOriginal==pItem->member||NULL==pItem，什么都不做，返回NULL
//返回：删除之前pItem的后面一个元素的指针。如果没有后一个元素了，返回NULL。
#define BiCyList_DELETE_ITEM(pOriginal,pItem,type,member) \
    BiCyList_ENTRY(BiCyList_Delete(pOriginal,\
    BiCyList_AddrFromItemType(pItem,BiCyList_ADDR_DELTA(type,member))),\
    type,member)

//得到前面一个元素的地址
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pItem当前位置（type类型的指针）。
//bCycled如果不是0，链表的第一个元素的前面一个元素是最后一个元素（循环方式）
//bCycled如果是0，链表的第一个元素的前面一个元素不存在（返回NULL，非循环方式）
//无论bCycled是什么值，
//如果pOriginal==pItem->member||NULL==pItem，返回最后一个元素的地址（空链表返回NULL）
//返回：前面一个元素的地址
#define BiCyList_BEFORE_ITEM(pOriginal,pItem,bCycled,type,member) \
    BiCyList_ENTRY(BiCyList_Before(pOriginal,\
    BiCyList_AddrFromItemType(pItem,BiCyList_ADDR_DELTA(type,member)),\
    bCycled),type,member)

//得到后面一个元素的地址
//pOriginal和BiCyList_CreateInstance调用时使用相同的值
//pItem当前位置（type类型的指针）。
//bCycled如果不是0，链表的最后一个元素的后面一个元素是第一个元素（循环方式）
//bCycled如果是0，链表的最后一个元素的后面一个元素不存在（返回NULL，非循环方式）
//无论bCycled是什么值，
//如果pOriginal==pItem->member||NULL==pItem，返回第一个元素的地址（空链表返回NULL）
//返回：后面一个元素的地址
#define BiCyList_AFTER_ITEM(pOriginal,pItem,bCycled,type,member) \
    BiCyList_ENTRY(BiCyList_After(pOriginal,\
    BiCyList_AddrFromItemType(pItem,BiCyList_ADDR_DELTA(type,member)),\
    bCycled),type,member)

#ifdef __cplusplus
}
#endif

#endif // __DU_LINKED_LIST_H_KENSKY_2012_12_15
/*
简单使用说明：
该模块用于双向循环链表操作。
定义了一个结构Bi_Cycle_List，用于存放前一个元素和后一个元素的指针。
需要在使用双向循环链表的结构（或者是联合、类）中定义一个Bi_Cycle_List类型的变量，
建议定义成第一个成员变量。
该模块提供了两套方案用于双向循环链表操作。
BiCyList_CreateInstance和BiCyList_DeleteInstance用于初始化和删除链表，
是两套方案共用的。BiCyList_Exchange用于交换两个链表，也是两套方案共用的。
需要注意，该模块不负责分配和释放内存，所有内存分配释放由用户自行处理。
后续操作都用到了一个指针（BiCyList_CreateInstance的参数），该指针就是一个句柄。
必须保证在BiCyList_CreateInstance调用之前不使用该句柄（除了BiCyList_CreateInstance），
必须保证在BiCyList_DeleteInstance调用之后不再使用该句柄（除了BiCyList_CreateInstance）。
两套方案都提供了插入元素、删除元素、查询前一个元素、查询后一个元素的操作。
第二套方案（使用宏实现）使用方便一点。样例程序如下：
#include "u_bidirection_cycle_list.h"
int main()
{
    long lRet;
    typedef struct{
        int value;
        Bi_Cycle_List pointer;//最好定义成第一个成员。
    }TESTLIST;
    TESTLIST x[2],*pTmp,*pFirst,*pLast;
    Bi_Cycle_List Original;
    x[0].value=0;
    x[1].value=1;
    BiCyList_CreateInstance(&Original);
    BiCyList_INSERT_ITEM(&Original,NULL,x+1,TESTLIST,pointer);
    BiCyList_INSERT_ITEM(&Original,x+1,&x[0],TESTLIST,pointer);
    pFirst=BiCyList_AFTER_ITEM(&Original,NULL,0,TESTLIST,pointer);
    pLast=BiCyList_BEFORE_ITEM(&Original,NULL,0,TESTLIST,pointer);
    pTmp=BiCyList_BEFORE_ITEM(&Original,pFirst,0,TESTLIST,pointer);
    pTmp=BiCyList_BEFORE_ITEM(&Original,pFirst,1,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&Original,pLast,0,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&Original,pLast,1,TESTLIST,pointer);
    for(;pFirst;)
    {
        pFirst=BiCyList_DELETE_ITEM(&Original,pFirst,TESTLIST,pointer);
    }
    lRet=BiCyList_DeleteInstance(&Original);
    BiCyList_CreateInstance(&x[1].pointer);
    pTmp=BiCyList_BEFORE_ITEM(&x[1].pointer,&x[1],0,TESTLIST,pointer);
    pTmp=BiCyList_BEFORE_ITEM(&x[1].pointer,&x[1],1,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&x[1].pointer,&x[1],0,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&x[1].pointer,&x[1],1,TESTLIST,pointer);
    BiCyList_INSERT_ITEM(&x[1].pointer,&x[1],x+0,TESTLIST,pointer);
    pTmp=BiCyList_BEFORE_ITEM(&x[1].pointer,x+1,0,TESTLIST,pointer);
    pTmp=BiCyList_BEFORE_ITEM(&x[1].pointer,x+1,1,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&x[1].pointer,x+1,0,TESTLIST,pointer);
    pTmp=BiCyList_AFTER_ITEM(&x[1].pointer,x+1,1,TESTLIST,pointer);
    lRet=BiCyList_DeleteInstance(&x[1].pointer);//此处会失败
    BiCyList_DELETE_ITEM(&x[1].pointer,BiCyList_AFTER_ITEM
        (&x[1].pointer,x+1,0,TESTLIST,pointer),TESTLIST,pointer);
    BiCyList_INSERT_ITEM(&x[1].pointer,BiCyList_AFTER_ITEM
        (&x[1].pointer,NULL,0,TESTLIST,pointer),x,TESTLIST,pointer);
    BiCyList_DELETE_ITEM(&x[1].pointer,BiCyList_AFTER_ITEM
        (&x[1].pointer,NULL,0,TESTLIST,pointer),TESTLIST,pointer);
    lRet=BiCyList_DeleteInstance(&x[1].pointer);
    return 0;
}
*/
