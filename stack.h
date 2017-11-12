/*
 * Copyright (c) 2017 Jackson Gable
 *
 * This file is released under the MIT License.
 */

#ifndef COLLECTIONS_STACK_H

#ifndef STACK_OVERFLOW_ERR
#define  STACK_OVERFLOW_ERR (void*)(-1)
#endif

#ifndef STACK_UNDERFLOW_ERR
#define STACK_UNDERFLOW_ERR (void*)(-2)
#endif

#define COLLECTIONS_STACK_H

typedef struct stack stack;

stack *alloc_stack(unsigned int capacity);
void *push(stack *stack, const void *element_addr);
void *peek(const stack *stack);
void *pop(stack *stack);

unsigned int stack_size(const stack *stack);
unsigned int stack_capacity(const stack *stack);

void debug(stack *stack);

#endif //COLLECTIONS_STACK_H
