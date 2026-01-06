#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "staticstack.h"

int main(void) {

    Stack stack = {0};

    long long tmp;
    printf("Enter len of stack: ");
    if(scanf("%lld",&tmp) != 1 || tmp < 0) {
        fprintf(stderr, "Invalid input!");
        return -1;
    }

    if(stack_init(&stack, (size_t)tmp) != 0) {
        fprintf(stderr, "Stack initialization failed");
        return -1;
    }

    int c = 0;

    do {
        printf("Enter 1: Push || 2: Pop || 3: Peek || 4: Traverse\t0: Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&c) != 1) {
            fprintf(stderr,"Bad input!");
            free_stack(&stack);
            return -1;
        }
        
        switch (c)
        {
        case 1:
            printf("\nEnter a value to push: ");
            int val;
            if(scanf("%d",&val) != 1) {
                fprintf(stderr,"Bad input!");
                free_stack(&stack);
                return -1;
            }
            if(push(&stack, val) != 0) {
                printf("\nThe stack is full!\n");
            }
            break;

        case 2:
            int popVal = pop(&stack);
            if(popVal == -1) {
                printf("\nThe stack is empty!\n");
            } else {
                printf("\nPopped value: %d\n",popVal);
            }
            break;

        case 3:
            int peekVal = peek(&stack);
            if(peekVal == -1) {
                printf("\nThe stack is empty!\n");
            } else {
                printf("\nPeeked value: %d\n",peekVal);
            }
            break;

        case 4: 
            printf("\nCurrent stack is: \n");
            traverse(&stack);
            break;

        case 0:
            free_stack(&stack);
            return 0;
        
        default:
            printf("\nInvalid Choice!\n");
            break;
        }
    } while (c != 0);
}