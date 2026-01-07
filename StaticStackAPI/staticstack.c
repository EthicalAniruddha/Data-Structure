#include "staticstack.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 100

/* Initialize the stack */
int stack_init(Stack *stack, size_t len) {
    if(len > SIZE_MAX/sizeof *stack->data) return -1;
    if(len > CAPACITY) return -1;

    stack->data = malloc(len * sizeof *stack->data);
    if(!stack->data) return -1;

    stack->len = len;
    stack->top = -1;

    return 0;
}

/* Returns 1 if true else returns 0*/
int isFull(const Stack *stack) {
    if(stack->top == (ptrdiff_t)stack->len - 1) return 1;
    return 0;
}

/* Returns 1 if true else returns 0*/
int isEmpty(const Stack *stack) {
    if(stack->top == -1) return 1;
    return 0;
}

/* Push value into stack*/
int push(Stack *stack, const int value) {
    if(!stack->data) return -1;
    if(isFull(stack)) return -1;
    stack->top += 1;
    stack->data[stack->top] = value;
    return 0;
}

/* Pop value from stack*/
int pop(Stack *stack) {
    if(!stack->data) return -1;
    if(isEmpty(stack)) return -1;
    int val = stack->data[stack->top];
    stack->top -= 1;
    return val;
}

/* Peek value*/
int peek(Stack *stack) {
    if(!stack->data) return -1;
    if(isEmpty(stack)) return -1;
    int val = stack->data[stack->top];
    return val;
}

/* Print all the values in the stack*/
int traverse(const Stack *stack) {
    if(!stack->data) return -1;
    if(isEmpty(stack)) return -1;
    for(ptrdiff_t i = (ptrdiff_t)stack->top; i >= 0; --i) {
        printf("%d\n",stack->data[(size_t)i]);
    }
    return 0;
}

/* Free the stack*/
void free_stack(Stack *stack) {
    if(!stack) return;
    free(stack->data);
    stack->data = NULL;
    stack->len = 0;
    stack->top = -1;
}
