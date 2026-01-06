#ifndef STACK_H
#define STACK_H

/* Stack */
typedef struct Stack {
    /*Store raw memory*/
    void *data;
    /*Length of the array*/
    size_t len;
    /*Total allocated elements*/
    size_t capacity;
    /*Size of one element*/
    size_t eleSize;
} Stack;

int stack_init(Stack *stack, size_t capacity, size_t ele_size);
int push(Stack *stack, const void *ele);
int pop(Stack *stack, void *ele);
void *peek(const Stack *stack, size_t idx);
int 

#endif