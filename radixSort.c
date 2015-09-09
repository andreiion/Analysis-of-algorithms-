# include <stdio.h>
# include <stdlib.h>
# include "radixSort.h"
# include "linkedList.h"

/*****************************************************************************/
/*********************************** Radix Sort *****************************/
/***************************************************************************/


void radixSort ( int arr[], int digit, int size )
{
	int j, i, k = 0, index = 0;

	LinkedList *B[10];
	LinkedList *pointerB[10];

	for ( j = 0; j < digit; j++ )
	{// We must sort the array on every digit using a stable sort algorithm.
	 // A stable sort algorithm is an algorithm that does not changhe the place of the elements that have the same value.
	 // This algorithm has 2 ways of being implemented. 
	 // First is by using Counting sort. This method was a little hard for me to understand so...i let it be.
	 // The second method is by Bucket sort. This method was quite intuitive. The general method of this algorithm is
	 //   by asuming the imput values are from the interval [0, 1) and you put this values into an array lists (bucket) by a formula n*A[i].
	 // After the values are insterted every bucket (hehe) is sorted with Instertion sort. The final step is to concatenate the buckets and increase digit.
	 // Our algorithm, for Radix-Sort, is a little modified and
	 // more optimal (No sorting is required, but we must but the values back, into the array, sorted after digit j). Let's get to the actual code!
		//we initialize the actual buckets
												contorRadix = contorRadix + 3; //antetul for-ului
		for ( i = 0; i < 10; i++ )
		{
												contorRadix = contorRadix + 3 + 3 + 2; //antet-ul for-ului, 3 indexari si 2 atribuiri
			B[i] = NULL;
			pointerB[i] = B[i];
		}

		for ( i = 0; i < size; i++ )
		{
												contorRadix = contorRadix + 3; //antetul for-ului
			index = (arr[i]/power(10, j))%10;   contorRadix = contorRadix + 1 + 1 + 2 + 1 + 1; //am decis ca functia pow sa fie o singura operatie elementara deoarece nu tine de algoritm
			if ( B[index] != NULL )
			{//if the starting element is not NULL we just insert the element
												contorRadix = contorRadix + 8; // inserarea
				insertList(&B[index], arr[i]);
			}
			else
			{//if we don't have any elements in the list we must allocate memory for it and point to the start of every list
												contorRadix = contorRadix + 7;								
												//am decis sa iau inserarea intr-o lista ca fiind 3 operatii elementara:indexare, inserare
												contorRadix = contorRadix + 8; //inserarea, sa fie in O(1)
				B[index] = (LinkedList *)malloc(sizeof(LinkedList*));
				B[index]->next = NULL;
				insertList(&B[index], arr[i]);
				pointerB[index] = B[index];
			}
		}

		//we put in the array every element from the array of lists, sorted by digit j
		i = 0;
		k = 0;									contorRadix = contorRadix + 2; // i = 0, k = 0
		for ( i = 0; i < 10; i++ )
		{
												contorRadix = contorRadix + 3; //antetul for-ului
			while ( pointerB[i] != NULL )
			{									contorRadix = contorRadix + 2; //antet-ul while-ului
												contorRadix = contorRadix + 9; // 4 indexari, 2 atribuiri, 2 pointari, adunare
				arr[k] = pointerB[i]->key;
				pointerB[i] = pointerB[i]->next;
				k++;
			}
		}	
	}
}