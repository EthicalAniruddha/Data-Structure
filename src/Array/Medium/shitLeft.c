/* Shift all elements left by n*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

int main(void) {

    Array arr = {0};
    long long tmp;

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

    long long n;
    printf("Enter nth value to shift to left: ");
    if(scanf("%lld",&n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }
    

    if(shit_left(&arr, (ptrdiff_t)n) != 0) {
        fprintf(stderr, "Something went wrong!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }

    print_array(&arr);


    free_array(&arr);
    return EXIT_SUCCESS;
}
