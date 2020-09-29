#include "array_helper.h"
#include <stdio.h>
#include <stdlib.h>

int* populate_array_int(int len_array)
// Return a pointer to an array of integers of length n
{
    int *arr = malloc( len_array * sizeof(int));

    for (int i=0; i<len_array; i++) 
    {
        int place_holder;
        printf("Insert the number at index: %d \n", i);
        scanf("%d", &place_holder);
        arr[i] = place_holder;
    }

    return arr;
}


void print_array(int* ptr_arr, int len)
//prints an array
{
    printf("[");
    for(int i=0; i<len; i++){

        if(i == len - 1){
            printf("%d]\n", ptr_arr[i]);
        } else {
            printf("%d, ", ptr_arr[i]);
        }
    }
}
