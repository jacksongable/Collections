/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <stdlib.h>
#include "linkedlist.h"

struct node {
    void *element;
    struct node *next;
};

struct linkedlist {
    unsigned int size;
    struct node *head;
};

/*
 * Allocates a new linked list on the heap, and returns a pointer to the list
 */
linkedlist *alloc_ll() {
    linkedlist *list = malloc(sizeof(linkedlist));
    list->size = 0;
    list->head = NULL;
    return list;
}

/*
 * For internal use. Traverses the list to 'position', and returns a pointer to that node.
 */
struct node *_node_at(linkedlist *list, int position) {
    struct node *the_node = list->head;
    if (position == 0)
        return the_node;
    for (int n = 0; n < position; n++)
        the_node = the_node->next;
    return the_node;
}

/*
 * Adds an element to the end of the linked list. Returns LINKEDLIST_OK on success.
 */
int ll_add(linkedlist *list, void *element) {
    int position = ++(list->size) - 1; //Increment size and move cursor to last node in list
    struct node *new_node = malloc(sizeof(struct node));
    new_node->element = element;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    }
    else
        _node_at(list, position - 1)->next = new_node;

    return LINKEDLIST_OK; //Success
}

/*
 * Deletes the element at the specified position from the list. Retunrs LINKEDLIST_OK on
 * success, or LINKEDLIST_OUT_OF_BOUNDS_EX if an illegal position is supplied.
 */
int ll_delete(linkedlist *list, int position) {
    if (position < 0 || position >= list->size)
        return LINKEDLIST_OUT_OF_BOUNDS_EX; //Index out of bounds

    struct node *to_delete = _node_at(list, position);

    if (position == 0) // Deleting head node
        list->head = list->head->next;

    if (position != list->size - 1) { //Deleting a node in the middle of the list
        //"Glue" together the nodes before and after the to-be-deleted node
        _node_at(list, position - 1)->next = _node_at(list, position + 1);
    }

    else //Deleting the last node
        _node_at(list, position - 1)->next = NULL;

    //Free up dat RAM
    free(to_delete);
    list->size--;
    return 1; //Success
}

/*
 * Returns the element at the given position on the list, or returns
 * LINKEDLIST_OUT_OF_BOUNDS_EX if an illegal position is supplied.
 */
void *ll_get(linkedlist *list, int position) {
    if (position < 0 || position >= list->size)
        return LINKEDLIST_OUT_OF_BOUNDS_EX; //Illegal
    return _node_at(list, position)->element;
}

/*
 * Returns the number of elements in the list.
 */
unsigned int ll_size(linkedlist *list) {
    return list->size;
}
