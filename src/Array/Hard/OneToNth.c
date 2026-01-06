/* Find the missing number in [1..N] */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

int findMissing(const Array *arr);

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

    printf("The missing element is: %d\n", findMissing(&arr));

    free_array(&arr);
    return EXIT_SUCCESS;
}

int findMissing(const Array *arr) {
    int max = arr->data[0];
    long long sum = 0;
    for(size_t i = 0; i < arr->len; ++i) {
        if(arr->data[i] > max) {
            max = arr->data[i];
        }
        sum += arr->data[i];
    }

    long long expected = (long long)max * (max+1) / 2;
    return (int)(expected-sum);
}
