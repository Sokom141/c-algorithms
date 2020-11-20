#ifndef HEAP_H
#define HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef Node *NodePtr;

typedef struct heap_node {
    int value;
    NodePtr left;
    NodePtr right;
} Node;

#define parent(x) (x/2)
#define left(x) (2*x)
#define right(x) ((2*x) + 1)
#define heap_maximum(A) (A[0])

void max_heapify(NodePtr node, int i);

void build_max_heap(NodePtr node);

void heapsort(NodePtr node);

void swap(int *a, unsigned int i, unsigned int j);

#ifdef __cplusplus
}
#endif

#endif