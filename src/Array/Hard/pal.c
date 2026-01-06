/* Check if array is a palindrome*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

int isPal(Array *arr);

int main(void) {

    Array arr = {0};
    long long tmp;
    printf("Enter array size: ");
    if(scanf("%lld",&tmp) != 1 || tmp < 0) {
        fprintf(stderr, "Not a valid input!\n");
        return EXIT_FAILURE;
    }

    if(init_array(&arr, (size_t)tmp) != 0) {
        fprintf(stderr, "Array allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Enter array elements: ");
    if(read_array(&arr) != 0) {
        fprintf(stderr,"Bad input!\n");
        free_array(&arr);
        return EXIT_FAILURE;
    }

    if(isPal(&arr) == 0) {
        printf("The array is palindrome!\n");
    } else {
        printf("The array is not palindrome!\n");
    }

    free_array(&arr);
    return EXIT_SUCCESS;
}

int isPal(Array *arr) {
    size_t left, right;
    left = 0; right = arr->len-1;
    while(left < right) {
        if(arr->data[left] != arr->data[right]) {
            return -1;
        }
        left++;
        right--;
    }
    return 0;
}