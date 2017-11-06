/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <stdlib.h>
#include "LinkedList.h"

typedef struct node Node;

struct node {
    void *element;
    Node *next;
};

int size = 0;

//Pointer to first node in the list
Node *HEAD = NULL;

//Traverses the list to the node the cursor is set to, and returns a pointer to that node.
Node *node(int position) {
    Node *node = HEAD;
    if (position == 0)
        return node;
    for (int n = 0; n < position; n++)
            node = node->next;
    return node;
}

int ll_add(void *element) {
    size++;
    int position = size - 1; //Move cursor to last node in list
    Node *new_node = malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;

    if (HEAD == NULL)
        HEAD = new_node;
    else
        node(position - 1)->next = new_node;

    return 1; //Success
}

int ll_delete(int position) {
    if (position < 0 || position >= size)
        return 0; //Index out of bounds

    Node *to_delete = node(position);

    if (position == 0) // Deleting head node
        HEAD = HEAD->next;

    if (position != size - 1) { //Deleting a node in the middle of the list
        //"Glue" the nodes before and after the node to delete together
        node(position - 1)->next = node(position + 1);
    }

    else //Deleting the last node
        node(position - 1)->next = NULL;

    //Free up dat RAM
    free(to_delete);
    size--;
    return 1; //Success
}

void *ll_get(int position) {
    if (position < 0 || position >= size)
        return NULL; //Illegal
    return node(position)->element;
}

int ll_size() {
    return size;
}
