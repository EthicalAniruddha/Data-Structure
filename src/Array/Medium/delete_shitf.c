#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

int main(void) {

    Array arr = {0};
    long long tmp;
    printf("Enter array size: ");

    printf("Enter array size: ");
    if(scanf("%lld",&tmp) != 1 || tmp <= 0) {
        fprintf(stderr, "Invalid size!\n");
        return EXIT_FAILURE;
    }

    if(init_array(&arr, (size_t)tmp) != 0) {
        fprintf(stderr, "Array allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Enter array elements: ");
    if(read_array(&arr) != 0) {
        fprintf(stderr, "Bad input!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }

    ptrdiff_t index=0;
    printf("Enter index: ");
    if(scanf("%ld",&index) != 1) {
        fprintf(stderr, "Invalid input!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }

    if(delete_element(&arr,index) != 0) {
        fprintf(stderr, "Invalid index!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    } else {
        printf("New array is: \n");
        print_array(&arr);
    }

    free_array(&arr);
    return EXIT_SUCCESS;
}