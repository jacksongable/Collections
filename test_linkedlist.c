/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

void test_ll_add(linkedlist*, unsigned int, int*);
void test_ll_get(linkedlist*, unsigned int, int*);
void test_ll_delete(linkedlist*, unsigned int, int*);

void test_linkedlist() {
    const unsigned int values_count = 10;
    int values[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    linkedlist *test_list = alloc_ll();

    test_ll_add(test_list,  values_count, values);
    test_ll_get(test_list, values_count, values);
    test_ll_delete(test_list, values_count, values);
}

void test_ll_add(linkedlist *list, const unsigned int value_count, int *values) {
    for (int i = 0; i < value_count; i++) {
        assert(ll_add(list, (values + i)) == 1);
    }
}

void test_ll_get(linkedlist *list, const unsigned int value_count, int *values) {
    for (int i = 0; i < value_count; i++) {
        assert(*(int *)ll_get(list, i) == *(values + i));
    }
}

void test_ll_delete(linkedlist *list, const unsigned int value_count, int *values) {
    assert(ll_delete(list, 0) == 1); //Delete first node
    assert(*(int *)ll_get(list, 0) == *(values + 1)); // Make sure the delete went through

    assert(ll_delete(list, 5) == 1); //Same with a middle node
    assert(*(int *)ll_get(list, 5) == *(values + 7));

    assert(ll_delete(list, 7) == 1); //Now with the last node
    assert(*(int *)ll_get(list, 6) == *(values + 8));
}
