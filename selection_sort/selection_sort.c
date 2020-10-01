#include "../headers/array_helper.h"
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr_to_sort, int len);

int main(void) {
    int len_array = 0;
    int *arr;

    printf("Insert a length for the array: ");
    scanf("%d", &len_array);

    arr = populate_array_int(len_array);

    printf("Unordered array:\n");
    print_array(arr, len_array);

    selection_sort(arr, len_array);

    printf("Ordered array:\n");
    print_array(arr, len_array);

    free(arr);
    return 0;
}

void selection_sort(int* arr_to_sort, int len) {
    int min; 
    int pos_min;

    for (int j=0; j<len-1; j++) {

        pos_min = j;

        for(int i=j+1; i<len; i++) {

            if (arr_to_sort[pos_min] > arr_to_sort[i]) {
                pos_min = i;
            }
        }

        if (pos_min != j) {
            swap(pos_min, j, arr_to_sort);
        }
    }
}