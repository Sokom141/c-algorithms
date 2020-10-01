#include "array_helper.h"
#include <stdio.h>
#include <stdlib.h>

// Return a pointer to an array of integers of length n
int *populate_array_int(int len_array){
    int *arr = malloc(sizeof *arr * len_array);

    for (int i=0; i<len_array; i++) 
    {
        printf("Insert the number at index: %d \n", i);
        scanf("%d", &arr[i]);
    }

    return arr;
}

// prints an array
void print_array(int *ptr_arr, int len){
    printf("[");
    for(int i=0; i<len; i++){
        printf((i == len - 1) ? "%d]\n" : "%d, ", ptr_arr[i]);
    }
}

// swap to position of an integer array
void swap(int pos_from, int pos_to, int *ptr_arr){
   int place_holder = ptr_arr[pos_to];
   ptr_arr[pos_to] = ptr_arr[pos_from];
   ptr_arr[pos_from] = place_holder;
}