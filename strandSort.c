# include <stdio.h>
# include <stdlib.h>
# include "strandSort.h"
# include "linkedList.h"


void strandSort(int arr[], int size)
{
	int i, ok = 0;
	int val, val2;			
	LinkedList *subList=NULL, *sortedList=NULL, *allElements;
	LinkedList *pointerToElements = NULL;
	LinkedList *aux;

	allElements = (LinkedList *)malloc(sizeof(LinkedList));
	allElements->next = NULL;

	allElements->key = arr[0];
	contorStrand = contorStrand + vectorToList(allElements, arr, size) + 5; // 5 de la celelalte operatii dinainte de while
	
	pointerToElements = (LinkedList *)malloc(sizeof(LinkedList *));
	//While we still have elements in list
	while ( allElements != NULL )
	{																		contorStrand = contorStrand + 20; // tot ce este in while + antet			
		pointerToElements = (LinkedList *)malloc(sizeof(LinkedList *));
		pointerToElements->next = NULL;
		if(allElements->next != NULL)
			pointerToElements->key = allElements->next->key;		
		
		subList = (LinkedList *)malloc(sizeof(LinkedList *));
		subList->key = allElements->key;
		subList->next = NULL;

		allElements = allElements->next;
		val = subList->key;
		ok = 0;
		while ( pointerToElements != NULL )
		{										contorStrand = contorStrand + 3; //antet while si if 
			//we pass though the allElements
			if ( val < pointerToElements->key )
			{
												contorStrand = contorStrand + 6 + 8 + 8;// 8 inserare - 8 stergere - 6 operatii de atribuire si pointare
				//the problem with this algorithm is that runs in O(n^3) beacuse the removeNode and insertNode functions run in O(n) time.
				if(ok == 0)
				{
												contorStrand = contorStrand + 2;
					allElements = allElements->next;
				}
				val = pointerToElements->key;
				//we remove the element that has been aded to sublist by connecting the previous element to the next element of the pointerTo elements

				aux = pointerToElements->next;
				insert_node_to_List(&subList, pointerToElements);
				pointerToElements = aux; //we recreate the elements because the insertion breaks the joints 
				removeFromList(&allElements, val); //we remove from our initial list the node with the key = val.
			}		
			else
			{										contorStrand = contorStrand + 3;
				ok = 1;
				pointerToElements = pointerToElements->next;
			}
		}
		//after we created the sublist we introduce the sorted elements into the sortedList
		contorStrand = contorStrand + interclass(&sortedList, subList);
	}
	contorStrand = contorStrand + listToVector(sortedList, arr);
}