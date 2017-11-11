/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack *test_alloc(unsigned int);
void test_push(stack*, unsigned int, int*);
void test_peek(stack*, unsigned int, const int*);
void test_pop(stack*, unsigned int, const int*);
void test_stack_overflow_failsafe(stack*, const int*);

void test_stack () {
    printf("Starting stack test...\n");
    int *values = calloc(10, sizeof(int));
    for (int n = 0, i = 3; n < 10; n++, i += 3)
        *(values + n) = i;

    const unsigned int values_count = 10;

    printf("Testing stack allocation...");
    stack *test_stack = test_alloc(values_count);
    printf(" Success.\n"); //Assertions in test method will halt execution if a test fails.

    printf("Testing push operation...");
    test_push(test_stack, values_count, values);
    printf(" Success.\n");

    printf("Testing peek operation...");
    test_peek(test_stack, values_count, values);
    printf(" Success.\n");

    printf("Testing pop operation...");
    test_pop(test_stack, values_count, values);
    printf(" Success.\n");

    printf("Testing stack overflow error failsafe...");
    test_stack_overflow_failsafe(test_stack, values);
    printf("Success.\n");

    printf("Stack tests passed.\n");
}

stack *test_alloc(unsigned int capacity) {
    stack *stack = alloc_stack(capacity);
    assert(stack != NULL);
    return stack;
}

void test_push(stack *stack, const unsigned int values_count, int *values) {
    for (int i = 0; i < values_count; i++) {
        int expected = *(values + i);
        int *actual = (int *)push(stack, values + i);
        assert(*actual == expected);
    }
}

void test_peek(stack *stack, const unsigned int expected_index, int const *values) {
    int offset = expected_index - 1;
    int expected = *(values + offset);
    int actual = *(int *)peek(stack);
    assert(expected == actual);
}

void test_pop(stack *stack, const unsigned int values_count, int const *values) {
    for (int i = 0; i < values_count; i++) {
        int offset = values_count - i - 1;
        int expected = *(values + offset);
        int actual = *(int *)pop(stack);
        assert(expected == actual);
    }
}

void test_stack_overflow_failsafe(stack *stack, int const *values) {
    unsigned int to_overflow = stack_capacity(stack) + 1;
    for (int i = 0; i < to_overflow; i++) {
        if (i != to_overflow - 1) { //Fill up the stack
            push(stack, values + i);
            continue;
        }
        assert(push(stack, values) == STACK_OVERFLOW_ERR);
    }

}
