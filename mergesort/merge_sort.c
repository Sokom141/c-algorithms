#include <stdio.h>
#include <stdlib.h>
#include "../headers/array_helper.h"

void mergeSort(int*, int, int, int*);
void merge(int*, int, int, int, int*);

int main(void){

    int len;
    printf("Array length: ");
    scanf("%d", &len);

    int *array = populate_array_int(len);
    int *support_array = malloc(sizeof *support_array * len);

    mergeSort(array, 0, len-1, support_array);
    free(support_array);

    print_array(array, len);
    free(array);
}

void mergeSort(int *array, int first_index, int last_index, int *support) {

    if (first_index < last_index) {
        int divider = (first_index + last_index) / 2;
        mergeSort(array, first_index, divider, support);
        mergeSort(array, divider + 1, last_index, support);
        merge(array, first_index, divider, last_index, support);
    }
}

void merge(int *array, int first_index, int divider, int last_index, int *support) {

  int left = first_index;
  int right = divider + 1;
  int index = 0;

  while ( left <= divider && right <= last_index ) {
    if (array[left] <= array[right]) {
      support[index] = array[left];
      left++;
    } else {
      support[index] = array[right];
      right++;
    }
    index++;
  }
    
  while( left <= divider) {
    support[index] = array[left];
    left++;
    index++;
  }

  while( right <= last_index ) {
    support[index] = array[right];
    right++;
    index++;
  }

  for(int i=first_index; i<=last_index; i++){
    array[i] = support[i-first_index];
  }
}