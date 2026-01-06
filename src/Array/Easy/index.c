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
    int target = 0;
    long long point=-1;
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
    
    size_t countEven = 0, countOdd = 0;

    printf("Enter array elements: ");
    for(size_t i = 0; i < size; ++i) {
        if(scanf("%d",&arr.data[i]) != 1) {
            fprintf(stderr, "Bad input!");
            free(arr.data);
            return EXIT_FAILURE;
        }
    }

    printf("Enter a number to find: ");
    if(scanf("%d",&target) != 1) {
        fprintf(stderr,"Not a valid input!\n");
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < size; ++i) {
        if(arr.data[i] == target) {
            point = i;
            break;
        }
    }

    if(point == -1) {
        printf("Target not found!\n");
    } else {
        printf("Target found at index: %lld\n", point);
    }

    free(arr.data);
    return EXIT_SUCCESS;
}