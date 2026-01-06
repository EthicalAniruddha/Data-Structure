/* Count duplicate elements*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

typedef struct Duplicate {
    int value;
    size_t count;
} Duplicate;


void printDups(const Array *arr);

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

    printf("Unique numbers with count are: ");

    printDups(&arr);

    return EXIT_SUCCESS;
}

void printDups(const Array *arr) {
    Duplicate *dup = malloc(arr->len * sizeof *dup);
    if(!dup) {
        perror("malloc");
        return;
    }

    size_t countSize=0;

    for(size_t i = 0; i < arr->len; ++i) {
        size_t j = 0;
        for(; j < countSize; ++j) {
            if(dup[j].value == arr->data[i]) {
                dup[j].count++;
                break;
            }
        }

        if(j == countSize) {
            dup[countSize].value = arr->data[i];
            dup[countSize].count = 1;
            countSize++;
        }
    }

    for(size_t i = 0; i < countSize; ++i) {
        if(dup[i].count != 1) {
            printf("%d -> %zu\n",dup[i].value, dup[i].count);
        }
    }

    free(dup);
}
