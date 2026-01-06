/* Find the largest and smallest element. */
#include <stdio.h>

int main(void) {

    int size, smol, large;
    printf("Enter size of your array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter array elements: ");
    for(int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    smol = large = arr[0];


    for (int i = 1; i < size; ++i) {
        if(arr[i] > large) {
            large = arr[i];
        } else if(arr[i] < smol){
            smol = arr[i];
        }
    }

    printf("Large element: %d\t\tSmall element: %d\n\n",large,smol);

    return 0;
}