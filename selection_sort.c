#include <stdio.h>
#include <stdlib.h>

int * populate_array(int len_array);
void swap_min(int pos_min, int pos_to, int* arr_ptr);
void selection_sort(int* arr_to_sort, int len);
void print_array(int* ptr_arr, int len);

int main(void) 
{
    int len_array = 0;
    int *arr;

    printf("Insert a length for the array: ");
    scanf("%d", &len_array);

    arr = populate_array(len_array);

    printf("Unordered array:\n");
    print_array(arr, len_array);

    selection_sort(arr, len_array);

    printf("Ordered array:\n");
    print_array(arr, len_array);

    free(arr);
    return 0;
}

int * populate_array(int len_array)
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

void swap_min(int pos_min, int pos_to, int* arr_ptr)
{
   int place_holder = arr_ptr[pos_to];
   arr_ptr[pos_to] = arr_ptr[pos_min];
   arr_ptr[pos_min] = place_holder;
}

void selection_sort(int* arr_to_sort, int len) 
{
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
            swap_min(pos_min, j, arr_to_sort);
        }
    }
}

void print_array(int* ptr_arr, int len)
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
