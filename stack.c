/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct stack {

    /*
     * Points to the top of the stack where elements should be pushed.
     * Elements should be popped from stack_ptr - 1
     */
    unsigned int stack_ptr;

    /*
     * The maximum capacity of the stack
     */
    unsigned int max_capacity;

    /*
     * The memory address of the bottom of the stack. Note: This stack grows upwards.
     */
    void **data_address;
} stack;

/*
 * Allocates a new stack with size 'capacity' on the heap and
 * returns a pointer to the new stack
 */
stack *alloc_stack(unsigned int capacity) {
    stack *stack = malloc(sizeof(stack));
    stack->max_capacity = capacity;

    stack->stack_ptr = 0;

    stack->data_address = (void**) calloc(capacity, sizeof(void*));
    return stack;
}

/*
 * Pushes a copy of the data in 'element_addr' onto the stack.
 * Returns a pointer to the element on success, or STACK_OVERFLOW_ERR on failure.
 */
void *push(stack *stack, const void *element_addr) {
    if (stack->stack_ptr + 1 > stack->max_capacity)
        return STACK_OVERFLOW_ERR; //Stack overflow!
    void *push_address = stack->stack_ptr++ + stack->data_address;
    memcpy(push_address, element_addr, sizeof(void *));
    return push_address;
}

void *peek(const stack *stack) {
    if ((signed) stack->stack_ptr - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    return stack->stack_ptr + stack->data_address - 1;
}

void *pop(stack *stack) {
    if ((signed)stack->stack_ptr - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    void *pop_addr = --stack->stack_ptr + stack->data_address;
    return pop_addr;
}

unsigned int stack_size(const stack *stack) {
    return stack->stack_ptr;
}

unsigned int stack_capacity(const stack *stack) {
    return stack->max_capacity;
}