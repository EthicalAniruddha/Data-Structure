#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "stack.h"

int take_input_from_user(char choice);

Stack stack;

int main(void) {

    long long tmp;
    printf("Enter len of stack: ");
    if(scanf("%lld",&tmp) != 1 || tmp < 0) {
        fprintf(stderr, "Invalid input!");
        return -1;
    }

    if(stack_d_init(&stack, (size_t)tmp) != 0) {
        fprintf(stderr, "Stack initialization failed");
        return -1;
    }

    int c = 0;

    do {
        printf("Enter 1: Push || 2: Pop || 3: Peek || 4: Traverse\t0: Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&c) != 1) {
            fprintf(stderr,"Bad input!");
            d_free_stack(&stack);
            return -1;
        }
        
        switch (c) {
        case 1:
            printf("\nChoose your type to input!\n b: boolean\tc: char\ti: int\tf: float\ts: string\nEnter your choice: ");
            char ch;
            if(scanf(" %c",&ch) != 1) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            int check = take_input_from_user(ch);
            if(check != 0) return -1;
            break;

        case 2:
            if(d_isEmpty(&stack)) {
                printf("\nThe stack is empty!\n");
            } else {
                StackValue popVal = d_pop(&stack);
                d_print_single(popVal);
                if(popVal.type == VAL_STRING) free(popVal.of.s);
            }
            break;

        case 3:
            StackValue peekVal = d_peek(&stack);
            if(peekVal.type == 0 && stack.top == -1) {
                printf("\nThe stack is empty!\n");
            } else {
                d_print_single(peekVal);
            }
            break;

        case 4: 
            printf("\nCurrent stack is: \n");
            d_traverse(&stack);
            printf("\n");
            break;

        case 0:
            d_free_stack(&stack);
            return 0;
        
        default:
            printf("\nInvalid Choice!\n");
            break;
        }
    } while (c != 0);
}

int take_input_from_user(char choice) {
    switch (choice) {
        case 'b':
            printf("\nEnter a boolean value(1: true || 0: false): ");
            int val_b;
            if(scanf("%d",&val_b) != 1 || (val_b != 1 && val_b != 0)) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            if(d_push(&stack, def_bool((bool)val_b)) != 0) {
                printf("\nThe stack is full!\n");
            } 
            break;

        case 'c':
            printf("\nEnter a char value: ");
            char val_c;
            if(scanf(" %c",&val_c) != 1) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            if(d_push(&stack, def_char(val_c)) != 0) {
                printf("\nThe stack is full!\n");
            } 
            break;

        case 'i':
            printf("\nEnter a integer value: ");
            int val_i;
            if(scanf("%d",&val_i) != 1) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            if(d_push(&stack, def_int(val_i)) != 0) {
                printf("\nThe stack is full!\n");
            } 
            break;

        case 'f':
            printf("\nEnter a float value: ");
            float val_f;
            if(scanf("%f",&val_f) != 1) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            if(d_push(&stack, def_float(val_f)) != 0) {
                printf("\nThe stack is full!\n");
            } 
            break;

        case 's':
            printf("\nEnter a string value: ");
            char val[80];
            if(scanf(" %79[^\n]",val) != 1) {
                fprintf(stderr,"Bad input!");
                d_free_stack(&stack);
                return -1;
            }
            if(d_push(&stack, def_string(val)) != 0) {
                printf("\nThe stack is full!\n");
            } 
            break;
            
        default: printf("\nUnsupported type\n"); break;
    }
    return 0;
}
