/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

typedef struct stack {
    unsigned int top, max_capacity;
    void **contents_addr;
} stack;

stack *alloc_stack(unsigned int capacity) {
    stack *stack = malloc(sizeof(stack));
    stack->max_capacity = capacity;
    stack->top = 0; //The top is where the next element will be pushed to. Element to be popped is top - 1.

    stack->contents_addr = (void**) calloc(capacity, sizeof(void*));
    return stack;
}

void *push(stack *stack, const void *element_addr) {
    if (stack->top + 1 > stack->max_capacity)
        return STACK_OVERFLOW_ERR; //Stack overflow!
    void *push_address = stack->top++ + stack->contents_addr;
    memcpy(push_address, element_addr, sizeof(void *));
    return push_address;
}

void *peek(const stack *stack) {
    if (stack->top - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    return stack->top + stack->contents_addr - 1;
}

void *pop(stack *stack) {
    if (stack->top - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    void *pop_addr = --stack->top + stack->contents_addr;
    return pop_addr;
}

unsigned int stack_size(const stack *stack) {
    return stack->top;
}

unsigned int stack_capacity(const stack *stack) {
    return stack->max_capacity;
}

void debug(stack *stack) {
    printf("Top: %d\nCapacity: %d\nStore Address: %p\n\n",
           stack->top, stack->max_capacity, *stack->contents_addr);
    for (int n = 0; n < stack->max_capacity; n++) {
        void *addr = stack->contents_addr + n;
        printf("Address: %p\tValue: %d\n", addr, *(int *)addr);
    }
    printf("\n");
}