#include <stdio.h>
#include <stdlib.h>
#include "array_helper.h"

int main(void){
    SmartArray *array = create_smart_array(10);

    for(int i=0; i < array->length; i++){
        array->array[i] = i;
    } 

    for(int i=0; i < array->length; i++){
        printf("%d\n", *(array->array)+i);
    }

    free_smart_array(array);
}