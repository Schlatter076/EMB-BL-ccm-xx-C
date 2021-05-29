/*******************************************************************************
  * File    :  llist.h
  * Author  :  kensky
  * Version :   
  * Date    :  2020-9-9
  * Brief   :  (a1,a2,......,ai-1,ai,ai+1,.....,an)
*******************************************************************************/
#ifndef __LLIST_H_KENSKY_2012_9_9
#define __LLIST_H_KENSKY_2012_9_9

/**** Includes ****************************************************************/
#include <stdbool.h>

/**** LOCAL DATA TYPES ********************************************************/
typedef         int         Item; // change int for other data type in stack
typedef struct  list_type  *LList; // Incomplete Data Structure


LList   Create_List (void);
void    Destroy_List(LList lst);
void    Clear_List(LList lst);
bool    List_is_Empty(LList lst);
bool    List_is_Full(LList lst);
int32_t get_List_Length(LList lst);
//get_Element_in_List
//locate_Element_in_List
//insert_Element_in_List
//delete_Element_in_List
//tranver_List
//get_next_Element_in_List
//get_prior_Element_in_List
int32_t merge_List(LList la, LList lb, LList lc);

#endif // __LLIST_H_KENSKY_2012_9_9
