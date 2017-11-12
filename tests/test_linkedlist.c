/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../linkedlist.h"

linkedlist* test_ll_alloc();
void test_ll_add(linkedlist*, unsigned int, int*);
void test_ll_get(linkedlist*, unsigned int, int*);
void test_ll_delete(linkedlist*, unsigned int, int*);
void test_ll_out_of_bounds_failsafe(linkedlist*, unsigned int);

void test_linkedlist() {
    printf("Starting linked list test...\n");

    const unsigned int values_count = 10;
    int values[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    printf("Testing linked list allocation...");
    linkedlist *test_list = test_ll_alloc();
    printf(" Success.\n");

    printf("Testing add operation...");
    test_ll_add(test_list,  values_count, values);
    printf(" Success.\n");

    printf("Testing get operation...");
    test_ll_get(test_list, values_count, values);
    printf(" Success.\n");

    printf("Testing delete operation...");
    test_ll_delete(test_list, values_count, values);
    printf(" Success.\n");

    printf("Testing out-of-bounds failsafe...");
    test_ll_out_of_bounds_failsafe(test_list, values_count);
    printf(" Success.\n");

    printf("Linked list tests passed.\n\n");
}

linkedlist *test_ll_alloc() {
    linkedlist *list = alloc_ll();
    assert(list != NULL);
    return list;
}

void test_ll_add(linkedlist *list, const unsigned int value_count, int *values) {
    for (int i = 0; i < value_count; i++) {
        assert(ll_add(list, (values + i)) == LINKEDLIST_OK);
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

void test_ll_out_of_bounds_failsafe(linkedlist *list, const unsigned int value_count) {
    int high_out_of_bounds = value_count * 2;
    int low_out_of_bounds = -1 * value_count;

    assert(ll_delete(list, high_out_of_bounds) == LINKEDLIST_OUT_OF_BOUNDS_EX);
    assert(ll_delete(list, low_out_of_bounds) == LINKEDLIST_OUT_OF_BOUNDS_EX);
    assert(ll_get(list, high_out_of_bounds) == LINKEDLIST_OUT_OF_BOUNDS_EX);
    assert(ll_get(list, low_out_of_bounds) == LINKEDLIST_OUT_OF_BOUNDS_EX);
}