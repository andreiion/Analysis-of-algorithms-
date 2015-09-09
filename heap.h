#ifndef HEAP_H_
#define HEAP_H_

typedef struct heap Heap;
struct heap //This sructure is used for Heap sort
{
	int* elements;
	int length;
	int heap_size;
};

int contorHeap;

void swap ( int *a, int *b );
void initializeHeap(Heap *maxHeap, int lenght, int heap_size);
void maxHeapify(Heap *maxHeap, int position);
void buildMaxHeap ( Heap *maxHeap );
void printMaxHeap(Heap *maxHeap);
void heapSort ( Heap *maxHeap );

void createHeap (Heap *maxHeap, int vector[], int size);

#endif 