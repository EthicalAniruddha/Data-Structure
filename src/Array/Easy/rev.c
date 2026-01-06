/* Reverse an array in place. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    printf("Enter size of your array: ");
    if(scanf("%d",&size) != 1 || size <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    int *arr = malloc(size* sizeof *arr);
    if(!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter array elements: ");
    for(int i = 0; i < size; ++i) {
        if(scanf("%d",&arr[i]) != 1) {
            printf("Invalid Input!\n");
            free(arr);
            return 1;
        }
    }

    for(int i = 0; i < size/2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    } 

    printf("Reversed array is: \n");
    for(int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }

    //printf("\nSize of the array: %zu\n",sizeof(arr));

    free(arr);
    return 0;
}