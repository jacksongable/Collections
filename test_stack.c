#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack *test_alloc();
void test_push(stack*, unsigned int, int*);
void test_peek(stack*, unsigned int, int*);
void test_pop(stack*, unsigned int, int*);


void test_stack () {
    int *values = calloc(10, sizeof(int));
    for (int n = 0, i = 3; n < 10; n++, i += 3)
        *(values + n) = i;

    const unsigned int values_count = 10;

    stack *test_stack = test_alloc();
    test_push(test_stack, values_count, values);
    test_peek(test_stack, values_count, values);
    test_pop(test_stack, values_count, values);
}

stack *test_alloc() {
    stack *stack = alloc_stack(10);
    printf("Allocating...\n");
    //debug(stack);
    assert(stack != NULL);
    return stack;
}

void test_push(stack *stack, const unsigned int values_count, int *values) {
    for (int i = 0; i < values_count; i++) {
        int expected = *(values + i);
        int *actual = (int *)push(stack, values + i);
        printf("Pushing %d to %p\n", *(values + i), actual);
        debug(stack);
        printf("\n");
        assert(*actual == expected);
    }
}

void test_peek(stack *stack, const unsigned int expected_index, int *values) {
    int offset = expected_index - 1;
    int expected = *(values + offset);
    int actual = *(int *)peek(stack);
    assert(expected == actual);
    //debug(stack);
}

void test_pop(stack *stack, const unsigned int values_count, int *values) {
    for (int i = 0; i < values_count; i++) {
        int offset = values_count - i - 1;
        int expected = *(values + offset);
        int *actual = (int *)pop(stack);
        int actualptr = *actual;
        //printf("Address:\t%p\t\tValue:\t%d\n", actual, *(int *)actual);
        //debug(stack);
        //assert(expected == actual);
    }
}
