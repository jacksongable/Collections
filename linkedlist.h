/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#ifndef LINKEDLIST_H

#define LINKEDLIST_OK 200
#define LINKEDLIST_OUT_OF_BOUNDS_EX (-1)

#define LINKEDLIST_H

typedef struct linkedlist linkedlist;

linkedlist *alloc_ll();

int ll_add(linkedlist *list, void *element);
int ll_delete(linkedlist *list, int position);
void *ll_get(linkedlist *list, int position);

unsigned int ll_size(linkedlist *list);

#endif