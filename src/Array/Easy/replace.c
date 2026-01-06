/* Replace all negative numbers with 0 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h> 

typedef struct {
    int *data;
    size_t len;
} Array;

void replace(Array *arr) {
    if(!arr || !arr->data) return;
    for(size_t i = 0; i < arr->len; ++i) {
        if(arr->data[i] < 0) arr->data[i] = 0;
    }
}

void printArr(const Array *arr) {
    if(!arr || !arr->data) return;
    printf("Array is: \n");
    for(size_t i = 0; i < arr->len; ++i) {
        printf("arr[%d] -> %d\n",i,arr->data[i]);
    }
}

int main(void) {
    Array arr = {0};
    long long size;
    printf("Enter size of the array: ");
    if(scanf("%lld",&size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid size of array!\n");
        return EXIT_FAILURE;
    }

    if((unsigned long long)size >  SIZE_MAX/sizeof *arr.data) {
        fprintf(stderr,"Size too long!\n");
        return EXIT_FAILURE;
    }

    arr.len = (size_t)size;

    arr.data = malloc(arr.len * sizeof *arr.data);
    if(!arr.data) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("Enter array elements: ");
    for(size_t i = 0; i < arr.len; ++i) {
        if(scanf("%d",&arr.data[i]) != 1) {
            fprintf(stderr, "Bad input!\n");
            free(arr.data);
            return EXIT_FAILURE;
        }
    }

    replace(&arr);
    printArr(&arr);

    free(arr.data);
    return EXIT_SUCCESS;
}