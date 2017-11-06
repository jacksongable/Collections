/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Adds an element to the end of the list and returns 1 on success
int ll_add(void *element);

//Deletes the node at 'position'. Returns 1 on success and 0 on failure.
int ll_delete(int position);

/*
 * Returns a pointer to the element at the specified position in the
 * linked list, or NULL if an error occurs
 */
void *ll_get(int position);

//Returns the size of the list
int ll_size();

#endif