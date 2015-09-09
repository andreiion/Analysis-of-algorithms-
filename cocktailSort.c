# include <stdio.h>
# include <stdlib.h>
# include "cocktailSort.h"
# include "heap.h"
# include "testingFunctions.h"

int cocktailSort ( int vector[], int size )
{
	int contor = 0;
	bool swapped = false;
	int i;
	//operatiile de mai sus nu tin de algoritm asa ca nu le-am contorizat
	do 
	{
		swapped = false; contor++;
		for ( i = 0; i < size - 2; i++ )
		{
			contor = contor + 3; //operatiile for-ului ( atribuire, comparatie si adunare )
			if (vector[i] > vector[i+1])
			{
				contor = contor + 14; //comparatie if, functia swapp si swapped;
				swap(&vector[i], &vector[i+1]);
				swapped = true;
			}
		}

		contor++;
		if (swapped == false ) //if we did not sort elements, break
			break;

		contor++;
		swapped = false;
		for ( i = size - 2; i >= 0; i-- )
		{
			contor = contor + 3; //operatiile for-ului ( atribuire, comparatie si adunare )
			if (vector[i] > vector[i + 1])
			{
				contor = contor + 14; //comparatie if, functia swapp si swapped;
				swap(&vector[i], &vector[i + 1]);
				swapped = true;
			}
		}
		contor++; //while-ul
	} while (swapped == true); //we do sorting while there is something to sort.

	return contor;

}