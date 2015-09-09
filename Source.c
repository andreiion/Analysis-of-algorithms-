#pragma warning(disable: 4996) //surpresing the message warning from 'scanf' function. ;)
//if you don't want to use the #pragma stuff, use 'scanf_s';)

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <math.h>
# include "heap.h"
# include "binaryTree.h"
# include "linkedList.h"
# include "radixSort.h"
# include "testingFunctions.h"
# include "splayTree.h"
# include "strandSort.h"
# include "blockSort.h"
# include "cocktailSort.h"


int main ()
{
	int vectorTestMode[TESTSIZE];
	int i;
	int option;
	Heap maxHeap;
	Heap *pointerMaxHeap = &maxHeap;
	
	BinaryTree *binaryTree;
	SplayTree *node;
	SplayTree *pnode;

	printf("Alegeti una din urmatoarele optiuni: \n");
	printf("1 - Modul Testare \n2 - Modul Analiza ");
	scanf("%d", &option);

	switch(option)
	{
		case 1:
			// Heap Sort
			initializeHeap(pointerMaxHeap, TESTSIZE, 0);
			randomGenTestMode(pointerMaxHeap->elements);
			pointerMaxHeap->heap_size = TESTSIZE;
			printf("Heap Sort:\n");
			heapSort(&maxHeap);
			printMaxHeap(&maxHeap);
			printf("\n");

			// Tree Sort
			randomGenTestMode(vectorTestMode);
			binaryTree = NULL;
			treeSort(&binaryTree, NULL, TESTSIZE, vectorTestMode);
			printf("\nBinary Tree\n");
			inorderPrint(binaryTree);
			printf("\n\n");
			free(binaryTree);
			
			// Radix Sort
			printf("Radix Sort:\n");
			randomGenTestMode(vectorTestMode);
			radixSort(vectorTestMode, 5, TESTSIZE);
			for ( i = 0; i < TESTSIZE; i++ )
				printf("%d ", vectorTestMode[i]);
			printf("\n\n");	
			
			// Splay Sort
			randomGenTestMode(vectorTestMode);
			node = NULL;
			splaySort(&node, TESTSIZE, vectorTestMode);
			printf("SplayTree Sort: \n");
			inorderPrintSplayTree(node);
			printf("\n");
			
			//Strand Sort
			randomGenTestMode(vectorTestMode);
			strandSort(vectorTestMode, TESTSIZE);
			printf("\nStrand Sort\n");
			for ( i = 0; i < TESTSIZE; i++ )
				printf("%d ", vectorTestMode[i]);
			printf("\n");

			//Block Sort
			randomGenTestMode(vectorTestMode);
			blockSort(vectorTestMode, TESTSIZE);
			printf("\nBlock Sort\n");
			for(i = 0; i < TESTSIZE; i++ )
				printf("%d ", vectorTestMode[i]);

			//Cocktail Sort
			randomGenTestMode(vectorTestMode);
			cocktailSort(vectorTestMode, TESTSIZE);
			printf("\n\nCocktail Sort\n");
			for ( i = 0; i < TESTSIZE; i++ )
				printf("%d ", vectorTestMode[i]);

			break;
		case 2:
			//modul analiza
			createArraysForAnalysis();
			cocktail();
			block();
			binaryT();
			heap();
			radix();
			splay();
			strand();
			break;
	}
	
	getch();
	return 0;
}