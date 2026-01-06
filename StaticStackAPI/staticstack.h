#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stddef.h>

/* Stack*/
typedef struct Stack{
    /* Integer array to store data*/
    int *data;
    /* Points to topmost element*/
    ptrdiff_t top;
    /*Length of the array*/
    size_t len;
}Stack;

/* Initialize the stack*/
int stack_init(Stack *stack, size_t len);

/* Check if the stack is full*/
int isFull(Stack *stack);

/* Check if the stack is empty*/
int isEmpty(Stack *stack);

/*Push value at the top index*/
int push(Stack *stack, const int value);

/*Remove the top value*/
int pop(Stack *stack);

/* Get the top value*/
int peek(Stack *stack);

/*List all the elements present in the stack*/
int traverse(const Stack *stack);

/* Free the stack*/
void free_stack(Stack *stack);

#endif