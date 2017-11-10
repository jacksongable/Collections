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

    stack->contents_addr = (void**) malloc(sizeof(void**));
    *stack->contents_addr = calloc(capacity, sizeof(void*));
    return stack;
}

void *push(stack *stack, void *element_addr) {
    if (stack->top + 1 > stack->max_capacity)
        return NULL; //Stack overflow!

    void **push_address = stack->top++ + stack->contents_addr;
    memcpy(push_address, element_addr, sizeof(void *));
    //printf("Pushed\t%d\t----->\t%p\n", *(int *)push_address, push_address);
    return push_address;
}

void *peek(const stack *stack) {
    if (stack->top - 1 < 0)
        return NULL; //Stack underflow!

    return stack->top - 1 + stack->contents_addr;
}

void *pop(stack *stack) {
    if (stack->top - 1 < 0)
        return NULL; //Stack underflow!
    void *pop_addr = stack->top-- + stack->contents_addr - 1;
    return pop_addr;
}

void debug(stack *stack) {
    printf("Top: %d\nCapacity: %d\nStore Address: %p\n\n",
           stack->top, stack->max_capacity, stack->contents_addr);
    for (int n = 0; n < stack->max_capacity; n++) {
        void *addr = (stack->contents_addr + n);
        printf("Address: %p\tValue: %d\n", addr, *(int *)addr);
    }
    printf("\n");
}