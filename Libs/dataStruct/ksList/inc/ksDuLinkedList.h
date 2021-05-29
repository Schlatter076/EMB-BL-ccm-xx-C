////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksDuLinkedList.h"
/// * Author  : kensky
/// * Version :
/// * Date    : Mar 11, 2014
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __KSDULINKEDLIST_H_KENSKY_2015_04_16_001
#define __KSDULINKEDLIST_H_KENSKY_2015_04_16_001

//******************************************************************************
#ifdef  __cplusplus
//******************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "../../ksLIFO/inc/ksStack.h"
#ifndef __linux
#include  <ksPeriph.h>
#else
#define __KS_ENTER_CRITICAL(sr)
#define __KS_EXIT_CRITICAL(sr)
#endif

/**** Global Data Types *******************************************************/
typedef struct duListNode
{
	struct duListNode *next;
	struct duListNode *prev;
} ksDuListNode_t;

// the structure will be attached to an actual data
typedef   ksDuListNode_t    ksDuListHead_t;

typedef struct duList
{ // the structure is used to manage a list
  ksDuListHead_t  head;     // the first element of the list
  ksStack_t       *stack;   // stack to manage the nodes
  ksDlistSize_t   lSize;    // list size
  ksDlistSize_t   used;     // how many elements have been filled into the hash map
  dsU08           locked;   // reserved for synchronization
} ksDuList_t;

/**** Defines *****************************************************************/
#define KS_DLIST_HEAD_INIT(name) 	{ .next = &(name), .prev = &(name) }
#define KS_DLIST_HEAD(name) 			ksDuListNode_t name = KS_DLIST_HEAD_INIT(name)

/***** Function Definitions ***************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksDlistNodeMalloc
/// @param      : p_arg
///               @arg  pList
/// @return     : the node that has been malloced, or else, just return NULL
/// @brief      : the node will be managed by a stack to reduce the workload of
///               memory management.
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
ksDuListNode_t * ksDlistNodeMalloc(ksDuList_t *pList);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistInitHead
/// @param      : p_arg
///               @arg  list
/// @return     : no return value.
/// @brief      : initialize the head of a dList
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistInitHead(ksDuListHead_t *head)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  head->next = head;
  head->prev = head;
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : __ksDlistAdd
/// @param      : toBeAdded
/// @param      : before
/// @param      : after
/// @return     : no return value.
/// @brief      : toBeAdded is inserted between the before and the after
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : this one will only be used here
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void __ksDlistAdd(ksDuListNode_t *toBeAdded,
																  ksDuListNode_t *before,
																  ksDuListNode_t *after)
{
  after->prev     = toBeAdded;
	toBeAdded->next = after;
	toBeAdded->prev = before;
	before->next    = toBeAdded;
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistAddAfter
/// @param      : toBeAdded :: new node to be adde
/// @param      : theNode   :: toBeAdded is inserted after the theNode
/// @return     : no return value.
/// @brief      : insert the new node after the specified node
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : critical
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistAddAfter(ksDuListNode_t *toBeAdded, ksDuListNode_t *theNode)
{
	__ksDlistAdd(toBeAdded, theNode, theNode->next);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistAddBefore
/// @param      : toBeAdded :: new node to be added
/// @param      : theNode   :: toBeAdded is inserted before the theNode
/// @return     : no return value.
/// @brief      : Insert a new node before the specified head(node).
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : This is useful for implementing queues.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistAddBefore(ksDuListNode_t *toBeAdded, ksDuListNode_t *theNode)
{
	__ksDlistAdd(toBeAdded, theNode->prev, theNode);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksDlistAdd
/// @param      : p_arg
///               @arg  lst   : the lost
///               @arg  node  : the node to be added
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-6-26
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void ksDlistAdd(ksDuList_t *lst, ksDuListNode_t *node)
{
  _ksDlistAddBefore(node, &lst->head);
  ++lst->used; // this value is very important
}
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : __ksDlistDel
/// @param      : before
/// @param      : after
/// @return     : no return value.
/// @brief      : delete a node between the before and the after
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : This is only for internal list manipulation where we know the
///               prev/next entries already!
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
 __STATIC_INLINE void __ksDlistDel(ksDuListNode_t *before, ksDuListNode_t *after)
{
  after->prev   = before;
	before->next  = after;
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistDel
/// @param      : node : the node to be removed
/// @return     : no return value.
/// @brief      : deletes node from list.
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : list_empty() on node does not return true after this, the node
///               is in an undefined state.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
 __STATIC_INLINE void _ksDlistDelNode(ksDuListNode_t *node)
{
  __ksDlistDel(node->prev, node->next);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistDel
/// @param      : p_arg
///               @arg  node : the node to be removed
/// @return     : no return value.
/// @brief      : deletes node from list. and ...
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE void _ksDlistDel(ksDuListNode_t *node)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  _ksDlistDelNode(node);
	node->next = NULL;
	node->prev = NULL;
	__KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksDlistDel
/// @param      : pList : the duList
/// @param      : node  : the node to be removed
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-6-26
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE void ksDlistDel(ksDuList_t *pList, ksDuListNode_t *node)
{
  _ksDlistDel(node);
  --pList->used;
}

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
int ksDlistNodeFree (ksDuList_t *pList, ksDuListNode_t *node);

#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
int ksDlistFlush    (ksDuList_t *pList, ksDuListNode_t *node);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistDelInit
/// @param      : node : the node to be removed
/// @return     : no return value.
/// @brief      : deletes node from list and reinitialize it.
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistDelInit(ksDuListNode_t *node)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  _ksDlistDelNode(node);
  _ksDlistInitHead(node);
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistReplace
/// @param      : p_arg
///               @arg  old :: the element to be replaced
///               @arg  new :: the new element to insert
/// @return     : no return value.
/// @brief      : replace old node by new one
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : If @old was empty, it will be overwritten.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistReplace(ksDuListNode_t *old, ksDuListNode_t *next)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  next->next       = old->next;
  next->next->prev = next;
  next->prev       = old->prev;
  next->prev->next = next;
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistReplaceInit
/// @param      : p_arg
///               @arg  old :: the element to be replaced
///               @arg  new :: the new element to insert
/// @return     : no return value.
/// @brief      : replace old node by new one and initialize the old node
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistReplaceInit(ksDuListNode_t *old, ksDuListNode_t *next)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  _ksDlistReplace(old, next);
  _ksDlistInitHead(old);
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistMoveBefore
/// @param      : p_arg
///               @arg  node    :: the entry to move
///               @arg  moveTo  :: the head that will precede our entry
/// @return     : no return value.
/// @brief      : delete from one list and add as another's head
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistMoveBefore(ksDuListNode_t *node, ksDuListNode_t *moveTo)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  _ksDlistDelNode(node);
  _ksDlistAddBefore(node, moveTo);
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistMoveAfter
/// @param      : p_arg
///               @arg  node   :: the node to be moved
///               @arg  moveTo :: the head that will follow our entry
/// @return     : no return value.
/// @brief      : delete from one list and add as another's tail
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistMoveAfter(ksDuListNode_t *node, ksDuListNode_t *moveTo)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  _ksDlistDelNode(node);
  _ksDlistAddAfter(node, moveTo);
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistIsLast
/// @param      : p_arg
///               @arg  node  : the node to be tested
///               @arg  head  : the list contain the elements
/// @return     : 0 || !0
/// @brief      : tests whether @node is the last entry in list @list
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int _ksDlistIsLast(const ksDuListNode_t *node, const ksDuList_t *list)
{
  return (node->next == &list->head);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistIsFirst
/// @param      : node  : the node to be tested
/// @param      : head  : the list contain the elements
/// @return     : 0 || !0
/// @brief      : tests whether @node is the last entry in list @list
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int _ksDlistIsFirst(const ksDuListNode_t *node, const ksDuList_t *list)
{
  return (node->prev == &list->head);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistIsEmpty
/// @param      : list  :: the list to test.
/// @return     : description of return value.
/// @brief      : tests whether a list is empty
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
#ifdef __EN_RAM_EXECUTION
__ramfunc
#endif
__STATIC_INLINE int _ksDlistIsEmpty(const ksDuListHead_t *head)
{
  return (head->next == head);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksDlistIsEmptyCareful
/// @param      : list : the list to test
/// @return     : 0 || !0
/// @brief      : tests whether a list is empty and not being modified
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : tests whether a list is empty _and_ checks that no other CPU
///               might be in the process of modifying either member (next or
///               prev)
///               _NOTE_: using ksDlistIsEmptyCareful() without synchronization
///               can only be safe if the only activity that can happen
///               to the list entry is list_del_init(). Eg. it cannot be used
///               if another CPU could re-list_add() it.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int ksDlistIsEmptyCareful(const ksDuListNode_t *list)
{
  ksDuListNode_t *next = list->next;
  return (next == list) && (next == list->prev);
}

////////////////////////////////////////////////////////////////////////////////
/// @fn     : _ksDlistIsFull
/// @param  : list  :: the list to test.
/// @return : description of return value.
/// @brief  : tests whether a list is full
/// @author : kensky
/// @date   : 2015-4-17
/// @pre    : add precondition here if needed.
/// @note   : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int _ksDlistIsFull(const ksDuList_t *list)
{
  return (list->used>=list->lSize);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistRotateLeft
/// @param      : p_arg
///               @arg  node : the node of the list
/// @return     : no return value.
/// @brief      : rotate the list to the left
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistRotateLeft(ksDuListNode_t *node)
{
#ifndef __linux
  volatile size_t dsSr;
#endif

  __KS_ENTER_CRITICAL(dsSr);
  if (!_ksDlistIsEmpty(node))
  {
    ksDuListNode_t *firstAfter = node->next;
    _ksDlistMoveAfter(firstAfter, node);
  }
  __KS_EXIT_CRITICAL(dsSr);
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistIsSingular
/// @param      : p_arg
///               @arg  list : the list to test.
/// @return     : 0 || !0
/// @brief      : tests whether a list has just one entry.
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE int _ksDlistIsSingular(const ksDuListNode_t *list)
{
  return (!_ksDlistIsEmpty(list) && (list->next == list->prev));
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : __ksDlistCutToPosition
/// @param      : p_arg
///               @arg  newList  : a new list to add all removed entries
///               @arg  oldList  : the old list which has the pos entry
///               @arg  pos      : an entry within oldList
/// @return     : no return value.
/// @brief      : cut and generate a new list from the old list, from the next
///               node of the old list to the pos node of the old list, by which
///               we can get two different lists
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : This is only for internal list manipulation
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void __ksDlistCutToPosition(ksDuListNode_t *newList,
                                          ksDuListNode_t *oldList,
                                          ksDuListNode_t *pos)
{
  ksDuListNode_t *nextOfPos = pos->next;

  newList->next       = oldList->next;
  newList->next->prev = newList; // the oldList next node will be attached after the newList

  newList->prev       = pos;
  pos->next           = newList; // the newList will be attached after the pos

  oldList->next       = nextOfPos;
  nextOfPos->prev     = oldList;
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistCutToPosition
/// @param      : p_arg
///               @arg  newList  : a new list to add all removed entries
///               @arg  oldList  : the old list which has the pos entry
///               @arg  pos      : an entry within oldList, could be the head
///                                itself and if so we won't cut the list
/// @return     : no return value.
/// @brief      : cut and generate a new list from the old list, from the next
///               node of the old list to the pos node of the old list, by which
///               we can get two different lists
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : This helper moves the initial part of oldList, up to and
///               including pos, from oldList to newList. You should pass on
///               pos an element you know is on oldList. newList should be an
///               empty list or a list you do not care about losing its data.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistCutToPosition(ksDuListNode_t *newList,
                                         ksDuListNode_t *oldList,
                                         ksDuListNode_t *pos)
{
  if (_ksDlistIsEmpty(oldList))
  {
    return;
  }

  if (_ksDlistIsSingular(oldList) && (oldList->next != pos && oldList != pos))
  {
    return;
  }

  if (pos == oldList)
  {
    _ksDlistInitHead(newList);
  }
  else
  {
    __ksDlistCutToPosition(newList, oldList, pos);
  }
}

__STATIC_INLINE void __ksDlistSplice(const ksDuListNode_t *newList,
                                   ksDuListNode_t       *oldPrev,
                                   ksDuListNode_t       *oldNext)
{
  ksDuListNode_t *first = newList->next;
  ksDuListNode_t *last  = newList->prev;

  first->prev   = oldPrev;
  oldPrev->next = first;

  last->next    = oldNext;
  oldNext->prev = last;
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistSpliceAfter
/// @param      : p_arg
///               @arg  newList : the new list to be added.
///               @arg  theNode : the new list will be added after the node
/// @return     : no return value.
/// @brief      : join two lists, this is designed for stacks
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistSpliceAfter(const
                                       ksDuListNode_t *newList,
                                       ksDuListNode_t *theNode)
{
  if (!_ksDlistIsEmpty(newList))
  {
    __ksDlistSplice(newList, theNode, theNode->next);
  }
}

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksDlistSpliceBefore
/// @param      : p_arg
///               @arg  newList : the new list to be added.
///               @arg  theNode : the new list will be added before the node
/// @return     : no return value.
/// @brief      : join two lists, this is designed for stacks
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
__STATIC_INLINE void _ksDlistSpliceBefore(ksDuListNode_t *newList,
                                        ksDuListNode_t *theNode)
{
  if (!_ksDlistIsEmpty(newList))
  {
    __ksDlistSplice(newList, theNode->prev, theNode);
  }
}

/**
 * _ksDlistSpliceAfterInit - join two lists and reinitialize the emptied list.
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * The list at @list is reinitialized
 */
__STATIC_INLINE void _ksDlistSpliceAfterInit(ksDuListNode_t *newList,
                                           ksDuListNode_t *theNode)
{
  if (!_ksDlistIsEmpty(newList))
  {
    __ksDlistSplice(newList, theNode, theNode->next);
    _ksDlistInitHead(newList);
  }
}

/**
 * _ksDlistSpliceBeforeInit - join two lists and reinitialize the emptied list
 * @list: the new list to add.
 * @head: the place to add it in the first list.
 *
 * Each of the lists is a queue.
 * The list at @list is reinitialized
 */
__STATIC_INLINE void _ksDlistSpliceBeforeInit(ksDuListNode_t *newList,
                                              ksDuListNode_t *theNode)
{
  if (!_ksDlistIsEmpty(newList))
  {
    __ksDlistSplice(newList, theNode->prev, theNode);
    _ksDlistInitHead(newList);
  }
}

/**
 * __KS_DLIST_ENTRY - get the struct for this entry
 * @ptr:  the &struct list_head pointer.
 * @type: the type of the struct this is embedded in.
 * @member: the name of the list_struct within the struct.
 */
#define __KS_DLIST_ENTRY(ptr, type, member)   container_of(ptr, type, member)

/**
 * __KS_DLIST_FIRST_ENTRY - get the first/next element from a list
 * @ptr:  the list head to take the element from.
 * @type: the type of the struct this is embedded in.
 * @member: the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define __KS_DLIST_FIRST_ENTRY(ptr, type, member) \
    __KS_DLIST_ENTRY((ptr)->next, type, member)

/**
 * __ksDlistNextEntry - get the next element in list
 * @pos:  the type * to cursor
 * @member: the name of the list_struct within the struct.
 */
#define __KS_DLIST_NEXT_ENTRY(pos, member) \
    __KS_DLIST_ENTRY((pos)->member.next, typeof(*(pos)), member)

/**
 * list_last_entry - get the last/previous element from a list
 * @ptr:  the list head to take the element from.
 * @type: the type of the struct this is embedded in.
 * @member: the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define __KS_DLIST_LAST_ENTRY(ptr, type, member) \
    __KS_DLIST_ENTRY((ptr)->prev, type, member)

/**
 * __KS_DLIST_PREV_ENTRY - get the previous element in list
 * @pos:  the type * to cursor
 * @member: the name of the list_struct within the struct.
 */
#define __KS_DLIST_PREV_ENTRY(pos, member) \
    __KS_DLIST_ENTRY((pos)->member.prev, typeof(*(pos)), member)

/**
 * list_first_entry_or_null - get the first element from a list
 * @ptr:  the list head to take the element from.
 * @type: the type of the struct this is embedded in.
 * @member: the name of the list_struct within the struct.
 *
 * Note that if the list is empty, it returns NULL.
 */
#define __KS_DLIST_FIRST_ENTRY_OR_NULL(ptr, type, member) \
    (!_ksDlistIsEmpty(ptr) ? __KS_DLIST_FIRST_ENTRY(ptr, type, member) : NULL)

/**** FOR_EACH ****************************************************************/
/**
 * list_for_each  - iterate over a list
 * @pos:  the &struct list_head to use as a loop cursor.
 * @head: the head for your list.
 * the direction is to next element
 */
#define __KS_DLIST_FOREACH(pos, head) \
    for (pos  = (head)->next;         \
         pos != (head);               \
         pos  = pos->next)

/**
 * __ksDlistForEachPrev - iterate over a list backwards
 * @pos:  the &struct list_head to use as a loop cursor.
 * @head: the head for your list.
 * the direction is to previous element
 */
#define __KS_DLIST_FOREACH_PREV(pos, head)  \
    for (pos  = (head)->prev;               \
         pos != (head);                     \
         pos  = pos->prev)

/**
 * __ksDlistForEachSafe - iterate over a list safe against removal of list entry
 * @pos : the &struct list_head to use as a loop cursor.
 * @tmp : another &struct list_head to use as temporary storage
 * @head: the head for your list.
 * the direction is to next element
 */
#define __KS_DLIST_FOREACH_SAFE(pos, tmp, head) \
    for (pos  = (head)->next, tmp = pos->next;  \
         pos != (head);                         \
         pos  = tmp, tmp = pos->next) // todo : erroneous, this one is not tested

/**
 * __KS_DLIST_FOREACH_PREV_SAFE - iterate over a list backwards safe against
 *                                removal of list entry
 * @pos : the &struct list_head to use as a loop cursor.
 * @tmp : another &struct list_head to use as temporary storage
 * @head: the head for your list.
 * the direction is to previous element
 */
#define __KS_DLIST_FOREACH_PREV_SAFE(pos, tmp, head)\
    for (pos  = (head)->prev, tmp = pos->prev;      \
         pos != (head);                             \
         pos  = tmp,          tmp = pos->prev)

#define __KS_DLIST_FOREACH_BACK_SAFE(pos, tmp, head)\
        __KS_DLIST_FOREACH_PREV_SAFE(pos, tmp, head)

/**
 * __KS_DLIST_FOREACH_ENTRY  - iterate over list of given type
 * @pos:  the type * to use as a loop cursor.
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 * todo ???
 */
#define __KS_DLIST_FOREACH_ENTRY(pos, head, member)                \
    for (pos = __KS_DLIST_FIRST_ENTRY(head, typeof(*pos), member); \
         &pos->member != (head);                                   \
         pos = __KS_DLIST_NEXT_ENTRY(pos, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_REVERSE - iterate backwards over list of given type.
 * @pos:  the type * to use as a loop cursor.
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 */
#define __KS_DLIST_FOREACH_ENTRY_REVERSE(pos, head, member)       \
    for (pos = __KS_DLIST_LAST_ENTRY(head, typeof(*pos), member); \
         &pos->member != (head);                                  \
         pos = __KS_DLIST_PREV_ENTRY(pos, member))

/**
 * __ksDlist_PrepareEntry - prepare a pos entry for use in
 *                          __ksDlistForEachEntryContinue()
 * @pos:  the type * to use as a start point
 * @head: the head of the list
 * @member: the name of the list_struct within the struct.
 *
 * Prepares a pos entry for use as a start point in list_for_each_entry_continue().
 */
#define __KS_DLIST_PREPARE_ENTRY(pos, head, member)               \
    ((pos) ? : __KS_DLIST_ENTRY(head, typeof(*pos), member))

/**
 * __ksDlistForEachEntryContinue - continue iteration over list of given type
 * @pos:  the type * to use as a loop cursor.
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Continue to iterate over list of given type, continuing after
 * the current position.
 */
#define __KS_DLIST_FOREACH_ENTRY_CONTINUE(pos, head, member)\
    for (pos = __KS_DLIST_NEXT_ENTRY(pos, member);          \
         &pos->member != (head);                            \
         pos = __KS_DLIST_NEXT_ENTRY(pos, member))

/**
 * __ksDlistForEachEntryContinueReverse - iterate backwards from the given point
 * @pos:  the type * to use as a loop cursor.
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Start to iterate over list of given type backwards, continuing after
 * the current position.
 */
#define __KS_DLIS_TFOREACH_ENTRY_CONTINUE_REVERSE(pos, head, member)\
    for (pos = __KS_DLIST_PREV_ENTRY(pos, member);                  \
         &pos->member != (head);                                    \
         pos = __KS_DLIST_PREV_ENTRY(pos, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_FROM - iterate over list of given type from the current
 *                                 point
 * @pos:  the type * to use as a loop cursor.
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Iterate over list of given type, continuing from current position.
 */
#define __KS_DLIST_FOREACH_ENTRY_FROM(pos, head, member)  \
    for (;                                                \
         &pos->member != (head);                          \
         pos = __KS_DLIST_NEXT_ENTRY(pos, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_SAFE - iterate over list of given type safe against
 *                                 removal of list entry
 * @pos:  the type * to use as a loop cursor.
 * @n:    another type * to use as temporary storage
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 */
#define __KS_DLIST_FOREACH_ENTRY_SAFE(pos, n, head, member)         \
    for (pos = __KS_DLIST_FIRST_ENTRY(head, typeof(*pos), member),  \
         n = __KS_DLIST_NEXT_ENTRY(pos, member);                    \
         &pos->member != (head);                                    \
         pos = n, n = __KS_DLIST_NEXT_ENTRY(n, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_SAFE_CONTINUE - continue list iteration safe against
 *                                          removal
 * @pos:  the type * to use as a loop cursor.
 * @n:    another type * to use as temporary storage
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Iterate over list of given type, continuing after current point,
 * safe against removal of list entry.
 */
#define __KS_DLIST_FOREACH_ENTRY_SAFE_CONTINUE(pos, n, head, member)\
    for (pos = __KS_DLIST_NEXT_ENTRY(pos, member),                  \
         n = __ksDlistNextEntry(pos, member);                       \
         &pos->member != (head);                                    \
         pos = n, n = __KS_DLIST_NEXT_ENTRY(n, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_SAFE_FROM - iterate over list from current point
 *                                      safe against removal
 * @pos:  the type * to use as a loop cursor.
 * @n:    another type * to use as temporary storage
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Iterate over list of given type from current point, safe against
 * removal of list entry.
 */
#define __KS_DLIST_FOREACH_ENTRY_SAFE_FROM(pos, n, head, member)\
    for (n = __KS_DLIST_NEXT_ENTRY(pos, member);                \
         &pos->member != (head);                                \
         pos = n, n = __KS_DLIST_NEXT_ENTRY(n, member))

/**
 * __KS_DLIST_FOREACH_ENTRY_SAFE_FROM_SAFE_REVERSE - iterate backwards over list safe
 *                                            against removal
 * @pos:  the type * to use as a loop cursor.
 * @n:    another type * to use as temporary storage
 * @head: the head for your list.
 * @member: the name of the list_struct within the struct.
 *
 * Iterate backwards over list of given type, safe against removal
 * of list entry.
 */
#define __KS_DLIST_FOREACH_ENTRY_SAFE_FROM_SAFE_REVERSE(pos, n, head, member) \
    for (pos = __KS_DLIST_NEXT_ENTRY(head, typeof(*pos), member),             \
         n = __KS_DLIST_PREV_ENTRY(pos, member);                              \
         &pos->member != (head);                                              \
         pos = n, n = __KS_DLIST_PREV_ENTRY(n, member))

/**
 * __KS_DLIST_SAFE_RESET_NEXT - reset a stale list_for_each_entry_safe loop
 * @pos:  the loop cursor used in the list_for_each_entry_safe loop
 * @n:    temporary storage used in list_for_each_entry_safe
 * @member: the name of the list_struct within the struct.
 *
 * list_safe_reset_next is not safe to use in general if the list may be
 * modified concurrently (eg. the lock is dropped in the loop body). An
 * exception to this is if the cursor element (pos) is pinned in the list,
 * and list_safe_reset_next is called after re-taking the lock and before
 * completing the current iteration of the loop body.
 */
#define __KS_DLIST_SAFE_RESET_NEXT(pos, n, member)  n = __KS_DLIST_NEXT_ENTRY(pos, member)

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksDuListInit
/// @param      : p_arg
///               @arg  pList   : the duList to be initialized
///               @arg  pStack  : the stack used to manage the list nodes
///               @arg  pNodeBuf: array to store the nodes, controlled by pStack
///               @arg  pStkBuf : array to operate the pointer of nodes
///               @arg  lSize   : list size :: how many elements in total
/// @return     : description of return value.
/// @brief      : Brief description of the function.
/// @author     : kensky
/// @date       : 2014-3-12
/// @pre        : add precondition here if needed.
/// @note       : add some important notes here if needed.
////////////////////////////////////////////////////////////////////////////////
int ksDuListInit(ksDuList_t     *pList,
                 ksStack_t      *pStack,
                 void           *pNodeBuf,
                 const dsAddr_t **pStkBuf,
                 size_t         eSize,
                 ksDlistSize_t  lSize);

#ifdef  __cplusplus
//******************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//******************************************************************************
}
#endif // __cplusplus

#endif // __KSDULINKEDLIST_H_KENSKY_2015_04_16_001
