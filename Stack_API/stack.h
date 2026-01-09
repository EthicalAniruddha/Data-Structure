#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

/* For dynamic experiance value types!*/
typedef enum {
    VAL_BOOL,
    VAL_CHAR,
    VAL_INT,
    VAL_FLOAT,
    VAL_STRING,
} ValueType;

/* Tagged value of stack*/
typedef struct {
    ValueType type;
    union {
        bool b;
        char c;
        int i;
        float f;
        char *s;
    } of;
} StackValue;

/* Dyanamic Stack*/
typedef struct Stack{
    /*Array of StackValue to store multiple datatypes*/
    StackValue *data;
    /*Points to the top of the array*/
    ptrdiff_t top;
    /*Length of the stack*/
    size_t len;
} Stack;

/* For defining boolean stack*/
StackValue def_bool(const bool val);
/* For defining character stack*/
StackValue def_char(const char val);
/* For defining integer stack*/
StackValue def_int(const int val);
/* For defining float stack*/
StackValue def_float(const float val);
/* For defining string stack*/
StackValue def_string(const char* val);

/* Initializing the stack*/
int stack_d_init(Stack *stack, size_t len);
/* Check if the stack is full or not*/
bool d_isFull(const Stack *stack);
/* Check if the stack is empty or not*/
bool d_isEmpty(const Stack *stack);
/* Push a value into the stack*/
int d_push(Stack *stack, StackValue val);
/* Remove the value from top*/
StackValue d_pop(Stack *stack);
/* Spectate the value at the top*/
StackValue d_peek(const Stack *stack);
/* Prints the StackValue val*/
int d_print_single(StackValue val);
/* Traverse through all the elements of the stack*/
int d_traverse(const Stack *stack);
/* Free the stack*/
void d_free_stack(Stack *stack);

#endif