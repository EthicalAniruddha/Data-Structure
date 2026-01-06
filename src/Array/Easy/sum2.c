/* Sum all elements in an array. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int *data;
    size_t len;
} Array;

int array_sum(const Array *arr) {
    if(!arr || !arr->data) return 0;
    int sum = 0;
    for(size_t i = 0; i < arr->len; ++i) {
        sum += arr->data[i];
    }
    return sum;
}

int main(void) {
    Array arr = {0};
    
    long long tmp;

    printf("Enter array size: ");
    if(scanf("%lld",&tmp) != 1 || tmp <= 0) {
        fprintf(stderr, "Invalid Size!\n");
        return EXIT_FAILURE;
    }

    if((unsigned long long)tmp > SIZE_MAX / sizeof *arr.data) {
        fprintf(stderr, "Size too large!\n");
        return EXIT_FAILURE;
    }

    arr.len = (size_t)tmp;

    arr.data = malloc(arr.len * sizeof *arr.data);
    if(!arr.data) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("Enter array elements: \n");
    for(size_t i = 0; i < arr.len; ++i) {
        if(scanf("%d",&arr.data[i]) != 1) {
            fprintf(stderr,"Invalid input!\n");
            free(arr.data);
            return EXIT_FAILURE;
        }
    }

    printf("Sum of elements: %d",array_sum(&arr));

    free(arr.data);
    return EXIT_SUCCESS;
}