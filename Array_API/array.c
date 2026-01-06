#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int init_array(Array *arr, size_t len) {
    if(len > SIZE_MAX/sizeof *arr->data) return -1;

    arr->data = len ? malloc(len * sizeof *arr->data) : NULL;
    if(!arr->data) return -1;

    arr->len = len;

    return 0;
}

void free_array(Array *arr) {
    if(!arr->data) return;
    free(arr->data);
    arr->data = NULL;
    arr->len = 0;
}

int read_array(Array *arr) {
    if(!arr || !arr->data) return -1;

    for(size_t i = 0; i < arr->len; ++i) {
        if(scanf("%d",&arr->data[i]) !=  1) {
            return -1;
        }
    }

    return 0;
}

void print_array(const Array *arr) {
    if(!arr || !arr->data) return;

    for(size_t i = 0; i < arr->len; ++i) {
        printf("arr[%zu] => %d\n",i,arr->data[i]);
    }
}

int delete_element(Array *arr, const ptrdiff_t index) {
    if(!arr || !arr->data || arr->len == 0) return -1;
    if(index < 0 || (size_t)index >= arr->len) return -1;
    for(size_t i = (size_t)index; i+1 < arr->len; ++i) {
        arr->data[i] = arr->data[i+1];
    }
    arr->len--;
    return 0;
}

int insert_element(Array *arr, const ptrdiff_t index, const int value) {
    if(!arr || !arr->data || arr->len == 0) return -1;
    if(index < 0 || (size_t)index > arr->len) return -1;

    size_t newLen = arr->len+1;

    int *tmp = realloc(arr->data, newLen * sizeof *arr->data);
    if(!tmp) return -1;

    arr->data = tmp;

    for(size_t i = newLen-1; i > (size_t)index; --i) {
        arr->data[i] = arr->data[i-1];
    }

    arr->data[index] = value;
    arr->len = newLen;
    return 0;
}

int shit_left(Array *arr, const ptrdiff_t n) {
    if(!arr || !arr->data || arr->len == 0) return -1;

    if(n < 0) return -1;

    size_t k = (size_t)n;

    if(k >= arr->len) {
        for(size_t i = 0; i < arr->len; ++i) {
            arr->data[i] = 0;
        }
        return 0;
    } else {
        for(size_t i = k; i < arr->len; ++i) {
            arr->data[i-k] = arr->data[i];
        }

        for(size_t i = arr->len-k; i < arr->len; ++i) {
            arr->data[i] = 0;
        }

        return 0;
    }
}

int shift_right(Array *arr, const ptrdiff_t n) {
    if(!arr || !arr->data || arr->len == 0) return -1;
    
    if(n < 0) return -1;

    size_t k = (size_t)n;
    if(k >= arr->len) {
        for (size_t i = 0; i < arr->len; ++i) {
            arr->data[i] = 0;
        }
        return 0;
    } else {
        for(size_t i = arr->len; i-- > k;) {
            arr->data[i] = arr->data[i-k];
        }
        for(size_t i = 0; i < k; ++i) {
            arr->data[i] = 0;
        }

        return 0;
    }
}

ptrdiff_t array_index_of(const Array *arr, int target) {
    if(!arr || !arr->data || arr->len == 0) return -1;

    for(size_t i = 0; i < arr->len; ++i) {
        if(arr->data[i] == target) return (ptrdiff_t) i;
    }

    return -1;
}

ptrdiff_t array_last_index_of(const Array *arr, int target) {
    if(!arr || !arr->data || arr->len == 0) return -1;

    for(size_t i = arr->len-1; i-- > 0;) {
        if(arr->data[i] == target) return (ptrdiff_t)i;
    }

    return -1;
}