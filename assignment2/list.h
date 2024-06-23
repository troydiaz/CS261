/*
 * This file contains the definition of the interface for a linked list.  You
 * can find descriptions of the linked list functions, including their
 * parameters and their return values, in list.c.
 */

#ifndef __LIST_H
#define __LIST_H

/*
 * Structure used to represent a singly-linked list.  You may not change the
 * fact that only a forward declaration of the list structure is included
 * here.  In other words, you can't define the fields of the struct here.
 */
struct list;

/*
 * Linked list interface function prototypes.  Refer to list.c for
 * documentation about each of these functions.
 */
/********************************************************************* 
** Function: list_create
** Description: Allocate memory to linked list.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns a pointer to empty linked list.
*********************************************************************/
struct list* list_create();

/********************************************************************* 
** Function: list_free
** Description: Freeing memory from linked list.
** Parameters: struct list* list
** Pre-Conditions: pointer to linked list
** Post-Conditions: Frees memory of nodes then frees the list itself.
*********************************************************************/
void list_free(struct list* list);

/********************************************************************* 
** Function: list_insert
** Description: Inserts a new node at start of list.
** Parameters: struct list* list, void* val
** Pre-Conditions: pointer to list and value of val
** Post-Conditions: Inserts a new node with value at the head of list.
*********************************************************************/
void list_insert(struct list* list, void* val);

/********************************************************************* 
** Function: list_remove
** Description: Removes node at specified value.
** Parameters: struct list* list, void* val, int (*cmp)(void* a, void* b)
** Pre-Conditions: pointer to list, value of val, cmp function which returns 
if value is equiv to value in linked list
** Post-Conditions: Removes node at spec value and frees the memory.
*********************************************************************/
void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b));

/********************************************************************* 
** Function: list_position
** Description: Gets value of linked list given the value.
** Parameters: struct list* list, void* val, int (*cmp)(void* a, void* b)
** Pre-Conditions: pointer to list, value of val, cmp function which returns 
if value is equiv to value in linked list
** Post-Conditions: Returns position of value in linked list.
*********************************************************************/
int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b));

/********************************************************************* 
** Function: list_reverse
** Description: Reverses the linked list values and pointers.
** Parameters: struct list* list
** Pre-Conditions: pointer to list
** Post-Conditions: Reverses the list order.
*********************************************************************/
void list_reverse(struct list* list);

/********************************************************************* 
** Function: list_empty
** Description: Returns if list is empty or not
** Parameters: struct list* list
** Pre-Conditions: pointer to list
** Post-Conditions: Returns if list is empty or not
*********************************************************************/
int list_empty(struct list* list);

/********************************************************************* 
** Function: list_front
** Description: Returns front value of list
** Parameters: struct list* list
** Pre-Conditions: pointer to list
** Post-Conditions: Returns front value of list
*********************************************************************/
void* list_front(struct list* list);

/********************************************************************* 
** Function: list_remove_front
** Description: Removes value at front of list
** Parameters: struct list* list
** Pre-Conditions: pointer to list
** Post-Conditions: Removes value at front of list
*********************************************************************/
void list_remove_front(struct list* list);

/********************************************************************* 
** Function: get_list_size
** Description: Gets list size
** Parameters: struct list* list
** Pre-Conditions: pointer to list 
** Post-Conditions: Returns list size
*********************************************************************/
int get_list_size(struct list* list);

#endif
