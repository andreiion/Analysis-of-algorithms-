# include <stdio.h>
# include <stdlib.h>
# include "testingFunctions.h"

# include "cocktailSort.h"
# include "blockSort.h"
# include "heap.h"
# include "binaryTree.h"
# include "radixSort.h"
# include "splayTree.h"
# include "strandSort.h"

/*****************************************************************************/
/************* Metode pentru Analiza algoritmilor de sortare ****************/
/***************************************************************************/

void randomGenTestMode(int v[])
{
	int i;
	for (i = 0; i < TESTSIZE; i++)
		v[i] = rand() % 100;
}

void randomGenAnalysisMode(int v[], int size)
{
	int i;
	for ( i = 0; i < size; i++ )
		v[i] = rand () % 32000;
}


int power(int base, int exponent)
{
	int i, result = 1;
	for ( i = 1; i <= exponent; i++ )
		result = result * base;
	if (exponent == 0 )
		result = 1;
	return result;
}


void copyArray (int A[], int B[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		A[i] = B[i];
}

void invert (int A[], int B[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		A[i] = B[size-i-1];
}

void equal (int A[], int B[], int size)
{
	int i;
	for ( i = 0; i < size; i++ )
		B[i] = A[i];
}

void quickSort(int v[], int left, int right)
{
	int i, j, pivot, aux;

	if (left == right) 
	{
		return;
	}
	i = left;
	j = right;
	pivot = v[(left + right)/2];

	//Split
	do
	{
		while (v[i] < pivot)
		{
			i++;
		}
		while (v[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
	{
		quickSort(v, left, j);
	}
	if (i < right)
	{
		quickSort(v, i, right);
	}

}

void createArraysForAnalysis()
{
	//Create Random arrays
	randomGenAnalysisMode(arr10rand, SIZE1);
	randomGenAnalysisMode(arr300rand, SIZE2);
	randomGenAnalysisMode(arr10000rand, SIZE3);

	//Create Sorted arrays
	copyArray (arr10sorted, arr10rand, SIZE1);
	copyArray (arr300sorted, arr300rand, SIZE2);
	copyArray (arr10000sorted, arr10000rand, SIZE3);
	quickSort(arr10sorted, 0,  SIZE1 - 1);
	quickSort(arr300sorted, 0, SIZE2 - 1);
	quickSort(arr10000sorted, 0, SIZE3 - 1);
	//user a sort method

	//Create Descending order arrays
	invert(arr10descr, arr10sorted, SIZE1);
	invert(arr300descr, arr300sorted, SIZE2);
	invert(arr10000descr, arr10000sorted, SIZE3);
}


void heap ()
{
	Heap maxHeap;
	Heap *pointerMaxHeap = &maxHeap;

	printf("\n \t \t Heap Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE1,SIZE1);
			createHeap(pointerMaxHeap, arr10Aux, SIZE1);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE2,SIZE2);
			createHeap(pointerMaxHeap, arr300Aux, SIZE2);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE3,SIZE3);
			createHeap(pointerMaxHeap, arr10000Aux, SIZE3);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE1,SIZE1);
			createHeap(pointerMaxHeap, arr10Aux, SIZE1);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE2,SIZE2);
			createHeap(pointerMaxHeap, arr300Aux, SIZE2);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE3,SIZE3);
			createHeap(pointerMaxHeap, arr10000Aux, SIZE3);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE1,SIZE1);
			createHeap(pointerMaxHeap, arr10Aux, SIZE1);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE2, SIZE2);
			createHeap(pointerMaxHeap, arr300Aux, SIZE2);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			contorHeap = 0;
			initializeHeap(pointerMaxHeap, SIZE3,SIZE3);
			createHeap(pointerMaxHeap, arr10000Aux, SIZE3);
			heapSort(&maxHeap);
			printf("%d \n", contorHeap);
}

void binaryT ()
{
	BinaryTree *bTree = NULL;
	printf("\n \t \t Binary Tree Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			treeSort(&bTree, NULL, SIZE1, arr10Aux);
			printf("%d \n", contorTree);
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE2, arr300Aux);			
			printf("%d \n", contorTree);;
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE3, arr10000Aux);			
			printf("%d \n", contorTree);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE1, arr10Aux);
			printf("%d \n", contorTree);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE2, arr300Aux);
			printf("%d \n", contorTree);
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE3, arr10000Aux);
			printf("%d \n", contorTree);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE1, arr10Aux);
			printf("%d \n", contorTree);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE2, arr300Aux);
			printf("%d \n", contorTree);
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			contorTree = 0;
			bTree = NULL;
			treeSort(&bTree, NULL, SIZE3, arr10000Aux);
			printf("%d \n", contorTree);
}

void radix ()
{
	printf("\n \t \t Radix Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			contorRadix = 0;
			radixSort(arr10Aux, 5, SIZE1);
			printf("%d \n", contorRadix);
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorRadix = 0;
			radixSort(arr300Aux, 5, SIZE2);
			printf("%d \n", contorRadix);
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			contorRadix = 0;
			radixSort(arr10000Aux, 5, SIZE3);
			printf("%d \n", contorRadix);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorRadix = 0;
			radixSort(arr10Aux, 5, SIZE1);
			printf("%d \n", contorRadix);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorRadix = 0;
			radixSort(arr300Aux, 5, SIZE2);
			printf("%d \n", contorRadix);
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			contorRadix = 0;
			radixSort(arr10000Aux, 5, SIZE3);
			printf("%d \n", contorRadix);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorRadix = 0;
			radixSort(arr10Aux, 5, SIZE1);
			printf("%d \n", contorRadix);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorRadix = 0;
			radixSort(arr300Aux, 5, SIZE2);
			printf("%d \n", contorRadix);
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			contorRadix = 0;
			radixSort(arr10000Aux, 5, SIZE3);
			printf("%d \n", contorRadix);

}

void splay ()
{
	SplayTree *node = NULL;

	printf("\n \t \t Splay Tree Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE1, arr10Aux);
			printf("%d \n", contorSplay);			
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE2, arr300Aux);
			printf("%d \n", contorSplay);
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE3, arr10000Aux);
			printf("%d \n", contorSplay);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE1, arr10Aux);
			printf("%d \n", contorSplay);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE2, arr300Aux);
			printf("%d \n", contorSplay);
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE3, arr10000Aux);
			printf("%d \n", contorSplay);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE1, arr10Aux);
			printf("%d \n", contorSplay);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE2, arr300Aux);
			printf("%d \n", contorSplay);
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			contorSplay = 0;
			node = NULL;
			splaySort(&node, SIZE3, arr10000Aux);
			printf("%d \n", contorSplay);

}

void strand ()
{
	printf("\n \t \t Strand Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			contorStrand = 0;
			strandSort(arr10Aux, SIZE1);
			printf("%d \n", contorStrand);
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorStrand = 0;
			strandSort(arr300Aux, SIZE2);
			printf("%d \n", contorStrand);
		//printf("Vector sortat crescator cu 10000 elemente: ");
		//	equal(arr10000sorted, arr10000Aux, SIZE3);
		//	contorStrand = 0;
		//	strandSort(arr10000Aux, SIZE3);
		//	printf("%d \n", contorStrand);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorStrand = 0;
			strandSort(arr10Aux, SIZE1);
			printf("%d \n", contorStrand);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorStrand = 0;
			strandSort(arr300Aux, SIZE2);
			printf("%d \n", contorStrand);
		//printf("Vector aleator cu 10000 elemente: ");
		//	equal(arr10000rand, arr10000Aux, SIZE3);
		//	contorStrand = 0;
		//	strandSort(arr10000Aux, SIZE3);
		//	printf("%d \n", contorStrand);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorStrand = 0;
			strandSort(arr10Aux, SIZE1);
			printf("%d \n", contorStrand);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorStrand = 0;
			strandSort(arr300Aux, SIZE2);
			printf("%d \n", contorStrand);
		//printf("Vector descrescator cu 10000 elemente: ");
		///	equal(arr10000descr, arr10000Aux, SIZE3);
		//	contorStrand = 0;
		//	strandSort(arr10000Aux, SIZE3);
		//	printf("%d \n", contorStrand);
}

void block ()
{
	printf("\n \t \t Block Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			contorBlock = 0;
			blockSort(arr10Aux, SIZE1);
			printf("%d \n", contorBlock);
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			contorBlock = 0;
			blockSort(arr300Aux, SIZE2);
			printf("%d \n", contorBlock);
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			contorBlock = 0;
			blockSort(arr10000Aux, SIZE3);
			printf("%d \n", contorBlock);

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			contorBlock = 0;
			blockSort(arr10Aux, SIZE1);
			printf("%d \n", contorBlock);
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			contorBlock = 0;
			blockSort(arr300Aux, SIZE2);
			printf("%d \n", contorBlock);
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			contorBlock = 0;
			blockSort(arr10000Aux, SIZE3);
			printf("%d \n", contorBlock);

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			contorBlock = 0;
			blockSort(arr10Aux, SIZE1);
			printf("%d \n", contorBlock);
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			contorBlock = 0;
			blockSort(arr300Aux, SIZE2);
			printf("%d \n", contorBlock);
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			contorBlock = 0;
			blockSort(arr10000Aux, SIZE3);
			printf("%d \n", contorBlock);
}

void cocktail ()
{
	printf("\n \t \t Cocktail Sort \n\n");

		printf("\nVector sortat crescator cu 10 elemente: ");
			equal(arr10sorted, arr10Aux, SIZE1);
			printf("%d \n", cocktailSort(arr10Aux, SIZE1));
		printf("Vector sortat crescator cu 300 elemente: ");
			equal(arr300sorted, arr300Aux, SIZE2);
			printf("%d \n", cocktailSort(arr300Aux, SIZE2));
		printf("Vector sortat crescator cu 10000 elemente: ");
			equal(arr10000sorted, arr10000Aux, SIZE3);
			printf("%d \n", cocktailSort(arr10000Aux, SIZE3));

		printf("\nVector aleator cu 10 elemente: ");
			equal(arr10rand, arr10Aux, SIZE1);
			printf("%d \n", cocktailSort(arr10Aux, SIZE1));
		printf("Vector aleator cu 300 elemente: ");
			equal(arr300rand, arr300Aux, SIZE2);
			printf("%d \n", cocktailSort(arr300Aux, SIZE2));
		printf("Vector aleator cu 10000 elemente: ");
			equal(arr10000rand, arr10000Aux, SIZE3);
			printf("%d \n", cocktailSort(arr10000Aux, SIZE3));

		printf("\nVector descrescator cu 10 elemente: ");
			equal(arr10descr, arr10Aux, SIZE1);
			printf("%d \n", cocktailSort(arr10Aux, SIZE1));
		printf("Vector descrescator cu 300 elemente: ");
			equal(arr300descr, arr300Aux, SIZE2);
			printf("%d \n", cocktailSort(arr300Aux, SIZE2));
		printf("Vector descrescator cu 10000 elemente: ");
			equal(arr10000descr, arr10000Aux, SIZE3);
			printf("%d \n", cocktailSort(arr10000Aux, SIZE3));

}

