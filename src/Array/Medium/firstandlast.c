#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

    printf("Your array is: \n");
    print_array(&arr);

    int target=0;
    printf("Enter target: ");
    if(scanf("%d",&target) != 1) {
        fprintf(stderr, "Invalid input!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }

    ptrdiff_t first = array_index_of(&arr, target);
    ptrdiff_t last = array_last_index_of(&arr, target);

    if(first >= 0) {
        printf("First occurence of %d is at index %ld\n",target,first);
    } else {
        printf("%d not found in the array.\n",target);     
    }

    if(last >= 0) {
        printf("last occurence of %d is at index %ld\n",target,last);
    } else {
        printf("%d not found in the array.\n",target);     
    }

    free_array(&arr);
    return EXIT_SUCCESS;
}
