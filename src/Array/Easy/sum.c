/* Sum all elements in an array. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size, sum=0;
    printf("Enter size of the array: ");
    if(scanf("%d",&size) != 1 || size <= 0) {
        printf("Not a valid input!\n");
        return 1;
    }

    int *arr = malloc(size * sizeof *arr);
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter array elements: ");
    for(int i = 0; i < size; ++i) {
        if(scanf("%d",&arr[i]) != 1) {
            printf("Invalid input!");
            free(arr);
            return 1;
        }
        sum += i[arr];
    }

    printf("Sum of array elements: %d\n",sum);
    free(arr);
    return 0;
}