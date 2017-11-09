/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <assert.h>
#include <stdlib.h>
#include "LinkedList.h"

int VALUES[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void test_ll_add();
void test_ll_get();
void test_ll_delete();

void test_linkedlist() {
    test_ll_add();
    test_ll_get();
    test_ll_delete();
}

void test_ll_add() {
    for (int i = 0; i < 10; i++) {
        assert(ll_add(&VALUES[i]) == 1);
    }
}

void test_ll_get() {
    for (int i = 0; i < 10; i++) {
        assert(*(int *)ll_get(i) == VALUES[i]);
    }
}

void test_ll_delete() {
    assert(ll_delete(0) == 1); //Delete first node
    assert(*(int *)ll_get(0) == VALUES[1]); // Make sure the delete went through

    assert(ll_delete(5) == 1); //Same with a middle node
    assert(*(int *)ll_get(5) == VALUES[7]);

    assert(ll_delete(7) == 1); //Now with the last node
    assert(*(int *)ll_get(6) == VALUES[8]);
}