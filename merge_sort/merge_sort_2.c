#include <stdio.h>
#include <stdlib.h>
#include "../headers/array_helper.h"

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(void){

    int len;
    printf("Array length: ");
    scanf("%d", &len);

    int *array = populate_array_int(len);

    mergeSort(array, 0, len-1);
    print_array(array, len);

    free(array);
}

void mergeSort(int *array, int first_index, int last_index) {

    if (first_index < last_index) {
        int divider = (first_index + last_index) / 2;
        mergeSort(array, first_index, divider);
        mergeSort(array, divider + 1, last_index);
        merge(array, first_index, divider, last_index);
    }
}

void merge(int *array, int first_index, int divider, int last_index) {
    
    int len_1 = divider - first_index + 1;
    int len_2 = last_index - divider;

    int left[len_1];
    int right[len_2];

    for(int i=0; i<len_1; i++)
       left[i] = array[first_index + i];

    for(int j=0; j<len_2; j++)
        right[j] = array[divider + j + 1];
    
    int i = 0;
    int j = 0;
    int k = first_index;

    // TODO
    while ( k < last_index ) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    
    while( i < len_1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while( j < len_2) {
        array[k] = right[j];
        j++;
        k++;
    }

}