/*
 * This file contains the definition of the interface for a dynamic array.
 * You can find descriptions of the dynamic array functions, including their
 * parameters and their return values, in dynarray.c.
 */

#ifndef __DYNARRAY_H
#define __DYNARRAY_H

/*
 * Structure used to represent a dynamic array.  You may not change the fact
 * that only a forward declaration of the dynamic array structure is included
 * here.  In other words, you can't define the fields of the struct here.
 */
struct dynarray;

/*
 * Dynamic array interface function prototypes.  Refer to dynarray.c for
 * documentation about each of these functions.
 */
/********************************************************************* 
** Function: dynarray_create
** Description: Allocate memory to dynamic array.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Created array is empty and has a capacity of 2.
*********************************************************************/
struct dynarray* dynarray_create();

/********************************************************************* 
** Function: dynarray_free
** Description: Free memory of dynamic array.
** Parameters: struct dynarray* da
** Pre-Conditions: the memory of da, the dynamic array
** Post-Conditions: Dynamic array elements are freed, then the dynamic array
itself is freed.
*********************************************************************/
void dynarray_free(struct dynarray* da);

/********************************************************************* 
** Function: dynarray_size
** Description: Returns the size of dynamic array.
** Parameters: struct dynarray* da
** Pre-Conditions: the memory of da
** Post-Conditions: Returns the size or number of elements in da.
*********************************************************************/
int dynarray_size(struct dynarray* da);

/********************************************************************* 
** Function: dynarray_insert
** Description: Inserts element at end of dynamic array.
** Parameters: struct dynarray* da, void* val
** Pre-Conditions: the memory of da, and value of val
** Post-Conditions: Increments dynamic array size by one and last element
is now val.
*********************************************************************/
void dynarray_insert(struct dynarray* da, void* val);

/********************************************************************* 
** Function: dynarray_remove
** Description: Removes element at specified value.
** Parameters: struct dynarray* da, int idx
** Pre-Conditions: the memory of da, and the value of idx index
** Post-Conditions: Decrements dynamic size by one and specified value
is removed from dynamic array.
*********************************************************************/
void dynarray_remove(struct dynarray* da, int idx);

/********************************************************************* 
** Function: dynarray_get
** Description: Gets the value of dynamic array at specified index.
** Parameters: struct dynarray* da, int idx
** Pre-Conditions: the memory of da, the value of idx index
** Post-Conditions: Returns value of element at index idx in dynamic array.
*********************************************************************/
void* dynarray_get(struct dynarray* da, int idx);

/********************************************************************* 
** Function: dynarray_set
** Description: sets the value of dynamic array at specified index
** Parameters: struct dynarray* da, int idx, void* val
** Pre-Conditions: the memory of da, the value of idx index, the value of val
** Post-Conditions: Updates element at specified index to val.
*********************************************************************/
void dynarray_set(struct dynarray* da, int idx, void* val);

/********************************************************************* 
** Function: get_size
** Description: Returns dynarray size
** Parameters: struct dynarray* da
** Pre-Conditions: none
** Post-Conditions: Returns dynarray size
*********************************************************************/
int get_size(struct dynarray* da);

/********************************************************************* 
** Function: get_capacity
** Description: Returns dynarray capacity
** Parameters: struct dynarray* da
** Pre-Conditions: none
** Post-Conditions: Returns dynarray capacity
*********************************************************************/
int get_capacity(struct dynarray* da);

/********************************************************************* 
** Function: get_start
** Description: Returns index of start value
** Parameters: struct dynarray* da
** Pre-Conditions: none
** Post-Conditions: Returns index of start value
*********************************************************************/
int get_start(struct dynarray* da);

/********************************************************************* 
** Function: get_start_value
** Description: Returns value of start 
** Parameters: struct dynarray* da
** Pre-Conditions: none
** Post-Conditions: Returns value of start 
*********************************************************************/
int get_start_value(struct dynarray* da);

/********************************************************************* 
** Function: set_size
** Description: Sets the size of array
** Parameters: struct dynarray* da, int new_size
** Pre-Conditions: none
** Post-Conditions: Sets the size of array
*********************************************************************/
int set_size(struct dynarray* da, int new_size);

/********************************************************************* 
** Function: set_capacity
** Description: Sets the capacity of array
** Parameters: struct dynarray* da, int new_capacity
** Pre-Conditions: none
** Post-Conditions: Sets the capacity of array
*********************************************************************/
int set_capacity(struct dynarray* da, int new_capacity);

/********************************************************************* 
** Function: set_start
** Description: Sets the value of start
** Parameters: struct dynarray* da, int new_start
** Pre-Conditions: none
** Post-Conditions: Sets the value of start
*********************************************************************/
int set_start(struct dynarray* da, int new_start);

void dynarray_print(struct dynarray* da, void (*p) (void* a));

#endif
