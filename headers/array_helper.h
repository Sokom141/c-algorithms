#ifndef ARRAY_HELPER_H_
#define ARRAY_HELPER_H_

int *populate_array_int(int len_array);
void print_array(int* ptr_arr, int len);
void swap(int pos_from, int pos_to, int *ptr_arr);

typedef struct SmartArray{

    int *array;
    int length;

} SmartArray;

SmartArray *create_smart_array(int length);
void free_smart_array(SmartArray *a);

#endif