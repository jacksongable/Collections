//
// Created by red on 11/4/17.
//
#include <assert.h>
#include <stdio.h>
#include "LinkedList.h"

test_LinkedList() {
    int test1 = 1, test2 = 2, test3 = 3;

    //[0] == 1, [1] == 2, [2] == 3
    assert(ll_add(&test1) == 1);
    assert(ll_add(&test2) == 1);
    assert(ll_add(&test3) == 1);

    assert(*(int *)ll_get(0) == 1);
    assert(*(int *)ll_get(1) == 2);
    assert(*(int *)ll_get(2) == 3);

    assert(ll_size() == 3);

    //Test deleting first node
    //[0] == 2, [1] == 3
    assert(ll_delete(0) == 1);
    assert(*(int *)ll_get(0) == 2);
    assert(*(int *)ll_get(1) == 3);

    //[0] == 2, [1] == 3, [2] == 1
    assert(ll_add(&test1) == 1);

    //Test deleting middle node
    //[0] == 2, [1] == 1
    assert(ll_delete(1) == 1);

    assert(*(int *)ll_get(0) == 2);
    assert(*(int *)ll_get(1) == 1);

    assert(ll_size() == 2);


    //Test deleting last node
    //[0] == 2
    assert(ll_delete(1) == 1);
    assert(*(int *)ll_get(0) == 2);

    //Test index out of bounds error for delete operation
    assert(ll_delete(-1) == 0);
    assert(ll_delete(7) == 0);

    //Test index out of bounds error for get operation
    assert(ll_get(-1) == NULL);
    assert(ll_get(10) == NULL);

}

int main () {
    test_LinkedList();
    //More data structures to come! :)
}