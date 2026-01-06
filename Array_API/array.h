#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

/* An array*/
typedef struct Array {
    /* Array to store some shits*/
    int *data;
    /* Length of that shit*/
    size_t len;
} Array;

/* Creates an array of given length. 
   Returns 0 on success and non-0 on failure like yourself*/
int init_array(Array *arr, size_t len);

/* Frees the array */
void free_array(Array *arr);

/* Read elements from stdin */
int read_array(Array *arr);

/* Prints the array */
void print_array(const Array *arr);

/* Deletes and shifts the array at the target index */
int delete_element(Array *arr, const ptrdiff_t index);

/* Inserts and shifts the array at the target index and with given value */
int insert_element(Array *arr, const ptrdiff_t index, const int value);

/* Shifts the array by nth position towards left*/
int shit_left(Array *arr, const ptrdiff_t n);

/* Shifts the array by nth position towards right*/
int shift_right(Array *arr, const ptrdiff_t n);

/* Returns non-negative integer if and only if the target is found else returns -1 fahhh*/
ptrdiff_t array_index_of(const Array *arr, int target);

/* Returns non-negative integer if and only if the target is found else returns -1 fahhh*/
ptrdiff_t array_last_index_of(const Array *arr, int target);

#endif