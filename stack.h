//
// Created by red on 11/8/17.
//

#ifndef COLLECTIONS_STACK_H

typedef struct stack stack;

stack *alloc_stack(unsigned int capacity);
void *push(stack *stack, void *element_addr);
void *peek(const stack *stack);
void *pop(stack *stack);

void debug(stack *stack);


#define COLLECTIONS_STACK_H

#endif //COLLECTIONS_STACK_H
