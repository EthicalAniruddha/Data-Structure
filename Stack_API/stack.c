#include "stack.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

StackValue def_bool(const bool val) {
    return (StackValue){ .type = VAL_BOOL, .of.b = val};
}

StackValue def_char(const char val) {
    return (StackValue){ .type = VAL_CHAR, .of.c = val};
}

StackValue def_int(const int val) {
    return (StackValue){ .type = VAL_INT, .of.i = val};
}

StackValue def_float(const float val) {
    return (StackValue){ .type = VAL_FLOAT, .of.f = val};
}

StackValue def_string(const char *val) {
    StackValue stringVal;
    stringVal.type = VAL_STRING;
    stringVal.of.s = strdup(val);
    return stringVal;
}

int stack_d_init(Stack *stack, size_t len) {
    if(len > SIZE_MAX/sizeof(*stack->data)) return -1;
    if(!stack || len == 0) return -1;

    stack->data = malloc(len * sizeof(StackValue));
    if(!stack->data) return -1;

    stack->len = len;
    stack->top = -1;
    return 0;
}

bool d_isFull(const Stack *stack) {
    return stack->top == (ptrdiff_t)stack->len-1;
}

bool d_isEmpty(const Stack *stack) {
    return stack->top == -1;
}

int d_push(Stack *stack, StackValue val) {
    if(!stack->data) return -1;
    if(d_isFull(stack)) return -1;
    stack->top += 1;
    stack->data[stack->top] = val;
    return 0;
}

StackValue d_pop(Stack *stack) {
    StackValue empty = {0};
    if(!stack->data) return empty;
    if(d_isEmpty(stack)) return empty;
    StackValue val = stack->data[stack->top];
    stack->top--;
    return val;
}

StackValue d_peek(const Stack *stack) {
    StackValue empty = {0};
    if(!stack->data) return empty;
    if(d_isEmpty(stack)) return empty;
    return stack->data[stack->top];
}

int d_print_single(StackValue val) {
    switch (val.type)  {
        case VAL_BOOL: printf("%s\n",val.of.b ? "true" : "false"); break;
        case VAL_CHAR: printf("%c\n",val.of.c); break;
        case VAL_INT: printf("%d\n",val.of.i); break;
        case VAL_FLOAT: printf("%f\n",val.of.f); break;
        case VAL_STRING: printf("\"%s\"\n",val.of.s); break;
    }
    return 0;
}

int d_traverse(const Stack *stack) {
    if(!stack->data || d_isEmpty(stack)) return -1;
    for(ptrdiff_t i = (ptrdiff_t)stack->top; i >= 0; --i) {
        d_print_single(stack->data[i]);
    }
    return 0;
}

void d_free_stack(Stack *stack) {
    if(!stack) return;

    for(ptrdiff_t i = 0; i <= stack->top; ++i) {
        if(stack->data[i].type == VAL_STRING) {
            free(stack->data[i].of.s);
        }
    }

    free(stack->data);
    stack->data = NULL;
    stack->len = 0;
    stack->top = -1;
}
