/* Count frequency of each value. */
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct {
    int *data;
    size_t len;
}Array;

typedef struct {
    int value;
    size_t freq;
} Frequency;


void printFreq(const Array *arr) {
    Frequency *freq = malloc(arr->len * sizeof *freq);
    if(!freq) {
        perror("malloc");
        return;
    }

    size_t freq_size=0;

    for(size_t i = 0; i < arr->len; ++i) {
        size_t j =0;
        for(j = 0; j < freq_size; ++j) {
            if(freq[j].value == arr->data[i]) {
                freq[j].freq++;
                break;
            }
        }

        if(j == freq_size) {
            freq[freq_size].value = arr->data[i];
            freq[freq_size].freq = 1;
            freq_size++;
        }
    }

    for(size_t i = 0; i < freq_size; ++i) {
        printf("%d -> %zu\n",freq[i].value,freq[i].freq);
    }
    free(freq);
}


int main(void) {
    Array arr = {0};

    long long tmp;

    printf("Enter array size: ");
    if(scanf("%lld",&tmp) != 1 || tmp <= 0) {
        fprintf(stderr, "Invalid input!");
        return EXIT_FAILURE;
    }

    if((unsigned long long)tmp > SIZE_MAX/sizeof *arr.data) {
        fprintf(stderr, "Size too long!");
        return EXIT_FAILURE;
    }

    arr.len = (size_t)tmp;

    arr.data = malloc(arr.len * sizeof *arr.data);
    if(!arr.data) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("Enter array elements: ");
    for(size_t i = 0; i < arr.len; ++i) {
        if(scanf("%d",&arr.data[i]) != 1) {
            fprintf(stderr,"Bad input!");
            free(arr.data);
            return EXIT_FAILURE;
        }
    }

    printFreq(&arr);

    free(arr.data);
    return EXIT_SUCCESS;
}