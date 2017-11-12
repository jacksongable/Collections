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

linkedlist *alloc_ll() {
    linkedlist *list = malloc(sizeof(linkedlist));
    list->size = 0;
    list->head = NULL;
    return list;
}

//Traverses the list to 'position', and returns a pointer to that node.
struct node *_node_at(linkedlist *list, int position) {
    struct node *the_node = list->head;
    if (position == 0)
        return the_node;
    for (int n = 0; n < position; n++)
        the_node = the_node->next;
    return the_node;
}

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

    return 1; //Success
}

int ll_delete(linkedlist *list, int position) {
    if (position < 0 || position >= list->size)
        return 0; //Index out of bounds

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

void *ll_get(linkedlist *list, int position) {
    if (position < 0 || position >= list->size)
        return NULL; //Illegal
    return _node_at(list, position)->element;
}

unsigned int ll_size(linkedlist *list) {
    return list->size;
}
