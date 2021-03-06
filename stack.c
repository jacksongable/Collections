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
     * Points to the top of the stack.
     *
     * Push elements to 'stack_origin + stack_ptr'.
     * Pop elements from 'stack_origin + stack_ptr - 1.'
     *
     * The value of stack_ptr will always be equivalent to the number of
     * elements on the stack.
     */
    unsigned int stack_ptr;

    /*
     * The maximum capacity of the stack
     */
    unsigned int max_capacity;

    /*
     * The memory address of the bottom of the stack. Note: This stack grows upwards.
     */
    void **stack_origin;
} stack;

/*
 * Allocates a new stack with size 'capacity' on the heap and
 * returns a pointer to the new stack
 */
stack *alloc_stack(unsigned int capacity) {
    stack *stack = malloc(sizeof(stack));

    stack->stack_ptr = 0;
    stack->max_capacity = capacity;
    stack->stack_origin = (void**) calloc(capacity, sizeof(void*));

    return stack;
}

/*
 * Pushes a pointer to an element to the stack.
 *
 * Returns the pointer to the stack element on success, or STACK_OVERFLOW_ERR on failure.
 */
void *push(stack *stack, const void *element_ptr) {
    if (stack->stack_ptr + 1 > stack->max_capacity)
        return STACK_OVERFLOW_ERR; //Stack overflow!
    void *push_address = stack->stack_origin + stack->stack_ptr++;
    memcpy(push_address, element_ptr, sizeof(void*));
    return push_address;
}

/*
 * Returns a pointer to the element on the top of the stack. If the stack is empty,
 * returns STACK_UNDERFLOW_ERR.
 *
 * Note: Be sure to cast this function's return value into a pointer of the
 * element's type before dereferencing.
 */
void *peek(const stack *stack) {
    if ((signed)stack->stack_ptr - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    return stack->stack_ptr + stack->stack_origin - 1;
}

/*
 * Returns a pointer to the element on the top of the stack, and
 * removes the element from the stack. If the stack is empty,
 * returns STACK_UNDERFLOW_ERR
 *
 * Note: Be sure to cast this function's return value into a pointer of the
 * element's type before dereferencing.
 */
void *pop(stack *stack) {
    if ((signed)stack->stack_ptr - 1 < 0)
        return STACK_UNDERFLOW_ERR; //Stack underflow!
    return stack->stack_origin + --stack->stack_ptr;
}

/*
 * Returns the number of elements currently on the stack
 */
unsigned int stack_size(const stack *stack) {
    return stack->stack_ptr;
}

/*
 * Returns the number of elements this stack can hold
 */
unsigned int stack_capacity(const stack *stack) {
    return stack->max_capacity;
}