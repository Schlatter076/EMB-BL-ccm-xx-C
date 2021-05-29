////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksHashList.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSHASHLIST_H_KENSKY_2014
#define __KSHASHLIST_H_KENSKY_2014

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
#if (defined __linux__) || \
    (defined linux)     || \
    (defined __unix__)  || \
    (defined unix)
#endif // platform

/**** Global Data Types *******************************************************/

/*******************************************************************************
该哈希链表很适合作为哈希表的冲突链, 在哈希表中,当数据产生冲突(关键字重复)时,就把这些相互冲突的数
据存放在一个冲突链中;而结构体hListNode_t就是用来描述哈希表的冲突链的,称为冲突表或散列表;当数据
产生冲突时,就使用结构体hListNode_t来组织链表存放冲突数据;

hListHead_t和hListNode_t都是单向链表,而且也不是循环的;因为表头结构hListHead_t中只有一个
first字段指向散列表hListNode_t的第一个节点,散列表结构hListNode_t也只有一个next字段指向下
一个冲突数据节点,pPrev不是指向前一个节点的指针,而是指向前一个节点的next字段的指针,如果前一个
节点是表头,则是指向first字段的指针,如果前一个节点是普通节点,则是指向前一个节点的next字段的指针;

1、与一般的链表相比，hash list的表头与表节点的数据结构是不同的，其表头只有一个first指针，而没
   有prev指针，这是为什么呢？

        首先我们需要知道hash的概念，对于hash表，其目的是为了方便快速的查找，如果hash表的
        长度较小的话（即hash数组的大小较小），则冲突的可能性则比较大，这样也就失去了散列
        表的意义。因此尽可能的维护一直大的hash表，但又要尽可能小的使用内存空间，这就需要
        改造hash表的数据结构了。普通链表元素都包含2个指针next、prev，而每一个指针则占用
   4个字节，如果我们能够将链表相关的数据结构所包含的指针减少到一个的话，则hash表的
        大小就会增加1倍。比如我们使用普通的链表结构list_head定义一个hash表

   struct list_head hash[255];该hash表的大小为255，占用内存为255*8bytes。如果使
       用hlist_head，则相同内存大小，我们可以定义的hash表的大小为500。由此可见，相同内
       存下，与普通list_head相比，表头仅包含一个指针可以使hash表增倍

2、hlist_node中，为什么pprev是指针的指针，而不是一级指针呢？

       这样做就解决了数据结构不一致的问题，hlist_node巧妙的将pprev指向上一个节点的next
       指针的地址，由于hlist_head和hlist_node指向的下一个节点的指针类型相同，就解决了
       通用性,关键是要注意head 与 node是不同的数据类型，因此，如果采用list的prev指针，那
       么指向头部的指针会出问题，变成了一个node指针指向head类型的数据，因此采用了pPrev
*******************************************************************************/

/*******************************************************************************
 * Double linked lists with a single pointer list head.
 * Mostly useful for hash tables where the two pointer list head is
 * too wasteful.
 * You lose the ability to access the tail in O(1).
*******************************************************************************/
typedef struct hListNode
{
  struct hListNode  *next;
  struct hListNode  **pPrev;  // point to the previous next (prevNextPtr)
} hListNode_t, ksHlistNode_t;

typedef struct hlistHead
{
  hListNode_t   *first;       // only has the next
} hListHead_t, ksHlistHead_t;

/**** Defines *****************************************************************/
#define     KS_HLIST_HEAD_INIT         {.next = NULL}
#define     KS_HLIST_HEAD(name)        hListHead_t name = KS_HLIST_HEAD_INIT
#define     INIT_KS_HLIST_HEAD(ptr)    ((ptr->first) = NULL)

/***** Function Prototypes ****************************************************/
/*
 * initialize the head
 */
__STATIC_INLINE void hListInitHead(hListHead_t *pHead)
{
  INIT_KS_HLIST_HEAD(pHead);
}

/*
 * initialize the node
 */
__STATIC_INLINE void hListInitNode(hListNode_t *pNode)
{
  pNode->next   = NULL; // in linux, the 0 cannot be accessed
  pNode->pPrev  = NULL; // in linux, the 0 cannot be accessed
}

__STATIC_INLINE  int hListIsEmpty(const hListHead_t *pHead)
{ // attention the first one will not store data
  return !(pHead->first);
}

__STATIC_INLINE int hListUnHashed(const hListNode_t *pNode)
{
  return !pNode->pPrev;
}

__STATIC_INLINE void __hListDel(hListNode_t *pNode)
{
  hListNode_t  *next    = pNode->next;
  hListNode_t  **pPrev  = pNode->pPrev;

  *pPrev = next;
  if (next)
  {
    next->pPrev = pPrev;
  }
}

__STATIC_INLINE void hListDel(hListNode_t *pNode)
{
  __hListDel(pNode);

#if (defined __linux__) || \
    (defined linux)     || \
    (defined __unix__)  || \
    (defined unix)
  pNode->next  = NULL /*LIST_POISON1*/; // should not be accessed
  pNode->pPrev = NULL /*LIST_POISON2*/; // should not be accessed
#else
  pNode->next  = NULL; // should not be accessed
  pNode->pPrev = NULL; // should not be accessed
#endif // platform

}

__STATIC_INLINE void hListDelInit(hListNode_t *node)
{
  if (!hListUnHashed(node))
  {
    __hListDel(node);
    hListInitNode(node); // set to NULL
  }
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : hListAddHead
/// @param      : p_arg
///               @arg  pAdded
///               @arg  head
/// @return     : none
/// @brief      : add the pAdded after the head
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       :
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void hListAddHead(hListNode_t *pAdded, hListHead_t *head)
{
	pAdded->next = head->first; // make the added node's next point to the next
	if (!hListIsEmpty(head))
	{
		head->first->pPrev = &pAdded->next;
	}
	head->first   = pAdded;
	pAdded->pPrev = &head->first;
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : hListAddBefore
/// @param      : p_arg
///               @arg  pAdded :: node to be added
///               @arg  node 	 :: the added node will be inserted before the node
/// @return     : none
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void hListAddBefore(hListNode_t *pAdded, hListNode_t *node)
{
	pAdded->pPrev 		= node->pPrev; 		// copy node pPrev
	pAdded->next  		= node;						// point the next of added node to the node
	node->pPrev 			= &pAdded->next; 	// node's pPrev points to added node
	*(pAdded->pPrev) 	= pAdded;					// modify the prev node's next
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : hListAddAfter
/// @param      : p_arg
///               @arg  node
///               @arg  pAdded
/// @return     : none
/// @brief      : add the pAdded after the node
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       :
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void hListAddAfter(hListNode_t *node, hListNode_t *pAdded)
{
	pAdded->next 	= node->next; 	// copy original node's next
	node->next 		= pAdded; 			// point the original node's next to the added node
	pAdded->pPrev = &node->next;  // point the pPrev to thenode's next

	if (pAdded->next)
	{
		pAdded->next->pPrev = &pAdded->next; // modify the next node's next
	}
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : hListMoveList
/// @param      : p_arg
///               @arg  pOld
///               @arg  pNew
/// @return     : description of return value.
/// @brief      : Move a list from one list head to another. Fixup the pPrev
///								reference of the first entry if it exists.
/// @author     : kensky
/// @date       : Mar 8, 2014
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void hListMoveList(hListHead_t *pOld, hListHead_t *pNew)
{
	pNew->first = pOld->first;
	if (!hListIsEmpty(pNew))
	{
		pNew->first->pPrev = &pNew->first;
	}
	pOld->first = NULL;
}

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

/**
 * container_of - cast a member of a structure out to the containing structure
 * @pMbr			: the pointer to the member.
 * @cntnrType	: the type of the container struct this is embedded in.
 * @mbr				: the name of the member within the struct.
 *
 */
#ifndef container_of
#ifdef __GNUC__
#define container_of(pMbr, cntnrType, mbr) 											\
		({ 																													\
			const typeof(((cntnrType *)0)->mbr)*__mptr = (pMbr); 			\
			(cntnrType *)((char *)__mptr - offsetof(cntnrType, mbr)); \
		})
#else
#define container_of(pMbr, cntnrType, mbr) 									\
		({ 																											\
			const void* __mptr = (void*)pMbr;\
			(cntnrType*)(size_t(__mptr) - offset(cntnrType, mbr))	\
		})
#endif // __GNUC__
#endif // container_of

#define __HLIST_ENTRY(ptr, type, member) 									\
		container_of(ptr, type, member)

#ifdef __GNUC__
#define	__HLIST_ENTRY_SAFE(ptr, type, member)							\
		({ typeof(ptr) ____ptr = (ptr); 											\
	   	 ____ptr ? 																					\
	   	 	 __HLIST_ENTRY(____ptr, type, member) : NULL; 		\
		})
#else
#define	__HLIST_ENTRY_SAFE(ptr, type, member)							\
		({ (void*) ____ptr = (void*)(ptr); 										\
	   	 ____ptr ? 																					\
	   	 	 __HLIST_ENTRY(____ptr, type, member) : NULL; 		\
		})
#endif

#define __HLIST_FOR_EACH(pos, head)												\
		for (pos = (head)->first; pos ; pos = pos->next)

#define __HLIST_FOR_EACH_SAFE(pos, n, head)								\
		for (pos = (head)->first; 				  									\
				 pos && ((n = pos->next)||1);     								\
				 pos = n)

/**
 * __HILST_FOR_EACH_ENTRY	- iterate over list of given type
 * @pos		:	the type * to use as a loop cursor.
 * @type	:	the type of the pos
 * @head	:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#ifdef __GNUC__
#define	__HILST_FOR_EACH_ENTRY(pos, type, head, member) \
		for (pos = __HLIST_ENTRY_SAFE((head)->first, 				\
																	typeof(*(pos)),				\
																	member);							\
				 pos; 																					\
				 pos = __HLIST_ENTRY_SAFE((pos)->member.next,		\
				 	 	 	 	 	 	 	 	 	 	 	 	  typeof(*(pos)), 			\
				 	 	 	 	 	 	 	 	 	 	 	 	  member))

#else
#define	__HILST_FOR_EACH_ENTRY(pos, type, head, member) \
		for (pos = __HLIST_ENTRY_SAFE((head)->first, 				\
																	type,									\
																	member);							\
				 pos; 																					\
				 pos = __HLIST_ENTRY_SAFE((pos)->member.next,		\
				 	 	 	 	 	 	 	 	 	 	 	 	  type, 								\
				 	 	 	 	 	 	 	 	 	 	 	 	  member))
#endif // __GNUC__

/**
 * __HLIST_FOR_EACH_ENTRY_CONTINUE - iterate over a hlist continuing after
 * 																	 current point
 * @pos		:	the type * to use as a loop cursor.
 * @type	:	the type of the pos
 * @member:	the name of the hlist_node within the struct.
 */
#ifdef __GNUC__
#define	__HLIST_FOR_EACH_ENTRY_CONTINUE(pos, type, member) 	\
		for (pos = __HLIST_ENTRY_SAFE((pos)->member.next, 			\
																	typeof(*(pos)), 					\
																	member);									\
	     	 pos; 																							\
	     	 pos = __HLIST_ENTRY_SAFE((pos)->member.next, 			\
	     			 	 	 	 	 	 	 	 	 	 	 	typeof(*(pos)), 					\
	     			 	 	 	 	 	 	 	 	 	 	 	member))
#else
#define	__HLIST_FOR_EACH_ENTRY_CONTINUE(pos, type, member) 	\
		for (pos = __HLIST_ENTRY_SAFE((pos)->member.next, 			\
																	type, 										\
																	member);									\
	     	 pos; 																							\
	     	 pos = __HLIST_ENTRY_SAFE((pos)->member.next, 			\
	     			 	 	 	 	 	 	 	 	 	 	 	type, 										\
	     			 	 	 	 	 	 	 	 	 	 	 	member))
#endif // __GNUC__

/**
 * __HLIST_FOR_EACH_ENTRY_FROM - iterate over a hlist continuing from current
 * 															 point
 * @pos		:	the type * to use as a loop cursor.
 * @member:	the name of the hlist_node within the struct.
 */
#ifdef __GNUC__
#define	__HLIST_FOR_EACH_ENTRY_FROM(pos, type, member) 	\
		for (;																							\
				 pos;																						\
	     	 pos = __HLIST_ENTRY_SAFE((pos)->member.next,		\
	     	 	 	 	 	 	 	 	 	 	 	 	 	 	typeof(*(pos)),				\
	     	 	 	 	 	 	 	 	 	 	 	 	 	 	member))
#else
#define	__HLIST_FOR_EACH_ENTRY_FROM(pos, type, member) 	\
		for (;																							\
				 pos;																						\
	     	 pos = __HLIST_ENTRY_SAFE((pos)->member.next,		\
	     	 	 	 	 	 	 	 	 	 	 	 	 	 	type,									\
	     	 	 	 	 	 	 	 	 	 	 	 	 	 	member))
#endif // __GNUC__

/**
 * __HLIST_FOR_EACH_ENTRY_SAFE - iterate over list of given type safe against
 *  														 removal of list entry
 * @pos		:	the type * to use as a loop cursor.
 * @n			: another &struct hlist_node to use as temporary storage
 * @head	:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#ifdef __GNUC__
#define	__HLIST_FOR_EACH_ENTRY_SAFE(pos, n, head, member)	\
		for (pos = __HLIST_ENTRY_SAFE((head)->next, typeof(*pos), member);\
	     	 pos && ({ n = pos->member.next; 1; });						\
	     	 pos = __HLIST_ENTRY_SAFE(n, typeof(*pos), member))
#else
#endif // __GNUC__

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __KSHASHLIST_H_KENSKY_2014
