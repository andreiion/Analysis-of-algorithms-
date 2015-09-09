# include <stdlib.h>
# include <stdio.h>
# include "heap.h"

/****************************************************************************/
/*************               Heap Sort                  ********************/
/**************************************************************************/

void swap ( int *a, int *b )
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void initializeHeap(Heap *maxHeap, int lenght, int heap_size)
{
	maxHeap->elements = (int*)malloc(lenght*sizeof(int));
	maxHeap->length = lenght;
	maxHeap->heap_size = heap_size;
}

void createHeap (Heap *maxHeap, int vector[], int size)
{
	int i;
	maxHeap->elements = (int*)malloc(size*sizeof(int));
	for ( i = 0; i < size; i++ )
		maxHeap->elements[i] = vector[i];
}

void maxHeapify(Heap *maxHeap, int position)
{
												
	int left = 2*position + 1; //left child						
	int right = 2*position + 2; //right child
	int largest;
												contorHeap = contorHeap + 6; // operatiile de pe left si right
												contorHeap = contorHeap + 7 + 1; //antetul if-ului + o atribuire

	if ( ( left <= maxHeap->heap_size ) && ( *(maxHeap->elements + left) > *(maxHeap->elements + position) ) )
	{   // if we are at the end of the heap or the key of the child is greater then the key of the current position,
		// then the intex largest gets the left value ( largest = left )
		largest = left;
	}
	else largest = position;

												contorHeap = contorHeap + 7; //antetul if-ului
	
	if ( ( right <= maxHeap->heap_size ) && ( *(maxHeap->elements + right) > *(maxHeap->elements + largest) ) )
	{   // if we are the end of the heap or the key of the right child is greater then the curret creater key ( key of element[largest])
		// then the new biggest value the one of they right child's key ( largest = right)

												contorHeap = contorHeap + 1; // atribuirea

		largest = right;
	}
												contorHeap = contorHeap + 1; //antetul if-ului
	if ( largest != position )
	{
		contorHeap = contorHeap + 9 + 4 + 1; //swap-ul, pointarea si apelarea functiei
		swap(maxHeap->elements + position, maxHeap->elements + largest);
		maxHeapify(maxHeap, largest);
	}
}

void buildMaxHeap ( Heap *maxHeap )
{
	int i = 0;
												contorHeap = contorHeap + 6; //atribuirea lui i si operatiile, atribuirea lui heap->size
	i = (maxHeap->length)/2 - 1;
	maxHeap->heap_size = maxHeap->length;
	//we start to heapify from the n/2 to 0 beacause the n/2 + 1, n/2 + 2 .. n elements are leaves.
	
	while ( i >= 0 )
	{ //we but all the nodes from the tree so that they will respect the max-heap property
	  // Property of max-heap:   A[Parent(i)] >= A[i]
												contorHeap = contorHeap + 3; //antet while, apelare functie, decrementare
		maxHeapify(maxHeap, i);
		i--;
	}
}

void printMaxHeap(Heap *maxHeap)
{
	int i;
	int *array = maxHeap->elements;
	for ( i = 0; i < maxHeap->heap_size; i++ )
		printf("%d ", *array++);
}

void heapSort ( Heap *maxHeap )
{
	int i = 0;
	int heapSize = maxHeap->heap_size; // keep (in mind) the size of the heap. mwhahi
	buildMaxHeap(maxHeap); // we build the array according to the max-heap property.
	maxHeap->heap_size = maxHeap->heap_size - 1; // !*** IMPORTANT ***! This must be done because indexing is from 0 in C ;) 
	for ( i = maxHeap->length - 1; i >= 1; i-- )
	{ //at this point we swap the first and the last elements and decrease the heap size
	  //so that the first element of the max-heap will be put last one. after this we heapify for the max-heap structure to remain.
															contorHeap = contorHeap + 4; //antet-ul for-ului
		swap(maxHeap->elements + i, maxHeap->elements);		contorHeap = contorHeap + 9 + 3 + 1; //swap-ul, atribuirea si apelul functiei
		maxHeap->heap_size = maxHeap->heap_size - 1;
		maxHeapify(maxHeap, 0);
	}
															contorHeap = contorHeap + 2; //pointarea si atribuirea
	maxHeap->heap_size = heapSize; //remake the heap-size so that the array can be printed ;)
}
