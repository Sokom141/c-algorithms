#include "heap.h"

void max_heapify(int *a, int i, int size) {
    int left = left(i);
    int right = right(i);
    int largest;

    if ((left <= size) && (*(a+left) > *(a+i))) {
        largest = left;
    } else {
        largest = i;
    }

    if ((right <= size) && (*(a+right) > *(a+largest))) {
        largest = right;
    }
    if (largest != i) {
        swap(a, i, largest);
        max_heapify(a, largest, size);
    }
}

void build_max_heap(int *a, int len) {
    int size = len;
    for (int i = (len / 2); i >= 0; i--) {
        max_heapify(a, i, size);
    }
}

void heapsort(int *a, int len, int size) {
    build_max_heap(a, len);
    for (int i = len; i >= 1; i--) {
        swap(a, 1, i);
        size = size -1;
        max_heapify(a, 1, size);
    }
}