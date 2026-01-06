/* Find all unique elements*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

typedef struct Unique {
    int value;
    size_t count;
} Unique;


void printUnique(const Array *arr);

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

    printf("Unique numbers are: ");

    printUnique(&arr);

    return EXIT_SUCCESS;
}

void printUnique(const Array *arr) {
    Unique *unique = malloc(arr->len * sizeof *unique);
    if(!unique) {
        perror("malloc");
        return;
    }

    size_t countSize=0;

    for(size_t i = 0; i < arr->len; ++i) {
        size_t j = 0;
        for(; j < countSize; ++j) {
            if(unique[j].value == arr->data[i]) {
                unique[j].count++;
                break;
            }
        }

        if(j == countSize) {
            unique[countSize].value = arr->data[i];
            unique[countSize].count = 1;
            countSize++;
        }
    }

    for(size_t i = 0; i < countSize; ++i) {
        if(unique[i].count == 1) {
            printf("%d\n",unique[i].value);
        }
    }

    free(unique);
}
