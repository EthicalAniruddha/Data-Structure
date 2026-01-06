/* Find the second largest (WITHOUT sorting) */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <array.h>

int secondLargest(const Array *arr);

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

    printf("\nSecond largest element in the array is: %d",secondLargest(&arr));

    free_array(&arr);
    return EXIT_SUCCESS;
}

int secondLargest(const Array *arr) {
    int first = 0, second = 0;
    for(size_t i = 0; i < arr->len; ++i) {
        if(arr->data[i] > first) {
            second = first;
            first = arr->data[i];
        } else if(arr->data[i] > second && arr->data[i] != first) {
            second = arr->data[i];
        }
    }
    return second;
}
