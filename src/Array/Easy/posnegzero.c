#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct {
    int *data;
    size_t len;
} Array;

int main(void) {
    Array arr = {0};
    size_t size;
    printf("Enter array len: ");
    if(scanf("%zu", &size) != 1 || size == 0) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    if(size > SIZE_MAX/sizeof *arr.data) {
        fprintf(stderr, "Too LOONG!!!!");
        return EXIT_FAILURE;
    }

    arr.len = size;
    arr.data = malloc(size * sizeof *arr.data);
    if(!arr.data) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    
    size_t countPos = 0, countNeg = 0, countZero = 0;

    printf("Enter array elements: ");
    for(size_t i = 0; i < size; ++i) {
        if(scanf("%d",&arr.data[i]) != 1) {
            fprintf(stderr, "Bad input!");
            free(arr.data);
            return EXIT_FAILURE;
        }
        if(arr.data[i] > 0) ++countPos;
        else if(arr.data[i] < 0) ++countNeg;
        else ++countZero;
    }

    printf("Positive numbers: %zu\n",countPos);
    printf("Negative numbers: %zu\n",countNeg);
    printf("Zeros: %zu\n",countZero);

    free(arr.data);
    return EXIT_SUCCESS;
}