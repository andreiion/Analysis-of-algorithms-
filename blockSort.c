# include <stdio.h>
# include <stdlib.h>
# include "blockSort.h"
# include "heap.h"

int FloorPowerOfTwo ( int x )
{
	x = x | ( x >> 1);
	x = x | ( x >> 2);
	x = x | ( x >> 4);
	x = x | ( x >> 8);
	x = x | ( x >> 16);

//#if __LP64__
	//x = x | ( x >> 32);
//#endif
	return x - (x >> 1);
}

void insertionSort(int arr[], int start, int end)
{
	int i, j;
	for ( i = start; i < end - 1; i++ )
	{
		contorBlock = contorBlock + 3; //for-ul
		for ( j = i + 1; j < end; j++ )
		{
			contorBlock = contorBlock + 4; //for-ul si antetul if-ului
			if ( arr[i] > arr[j] )
			{
				contorBlock = contorBlock + 8; //swap-ul
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

void mergeFunction ( int arr[], int start, int mid ,int end )
{
	int i, j = 0, k = 0;
	int *a;
	a = (int *)malloc((end-start)*sizeof(int));

	for ( i = 0; i < end - start; i++ )
	{
		contorBlock = contorBlock + 3; //for-ul
		//we check if we reached the end of the first half and the end of the second half. if not, we continue to add the elements into the array
		contorBlock = contorBlock + 13; //antetul if-ului
		if ( (  (( start + j) < mid) && arr[ start + j] < arr[mid + k] ) || ( (mid + k) >= end ) )
		{	
			contorBlock = contorBlock + 3;
			a[i] = arr[start + j];
			j++;
		}
		else 
		{
			contorBlock = contorBlock + 3;
			a[i] = arr[mid + k];
			k++;
		}		
	}
	//we copy back the elements, merged
	for ( i = 0; i < end - start; i++ )
	{
		contorBlock = contorBlock + 6; //for-ul cu totul
		arr[i + start] = a[i];
	}
}

void blockSort(int arr[], int size)
{
	//contorBlock = 0;
	
	int power_of_two;
	int lenght, i;
	int merge, start = 0, end = 0, mid = 0;
	float scale;
	

	power_of_two = FloorPowerOfTwo(size);
	scale = (size+0.0)/ power_of_two; //scale is between 1.0 <= x < 2.0
	contorBlock = contorBlock + 3; //atribuirea lui power_of_two si operatiile pentru sale
	//tratam cazul in care size < 16
	if (size < 16)
	{
		contorBlock++; //if-ul
		//facem o banala sortare
		insertionSort(arr, 0, size);
	}
	else
	{
		//face blocuri de cate 16 elemente pe care le sorteaza cu merge sort
		for ( merge = 0; merge < power_of_two; merge = merge + 16 )
		{
			contorBlock = contorBlock + 8; //for-ul cu totul
			start = merge * scale;
			end = (merge + 16) * scale;
			insertionSort(arr, start, end);
		}

		//ia fiecare block si il adauga la un block mai mare sortat
		for ( lenght = 16; lenght < power_of_two; lenght = lenght * 2 )
		{
			contorBlock = contorBlock + 4; //forul de sus

			//face merge pe fiecare 2 blockuri de dimensiune lenght
			for ( merge = 0; merge < power_of_two; merge = merge + lenght*2 )
			{
				contorBlock = contorBlock + 9; //for-ul cu totul. difera de celalalt pentru ca mai este o operatie in plus: merge = merge + lenght*2

				start = merge * scale;
				mid = (merge + lenght)*scale;
				end = (merge + lenght * 2)*scale;

				//se putea face si cu rotatie dar optimizarea asta am decis sa n-o fac. Rotatia cred ca depaseste, ca dificultate, toata tema :))
				//if ( arr[end - 1] < arr[start] )
					//rotate
				//if ( arr[mid - 1] > arr[mid] )
				mergeFunction(arr, start, mid, end);
			}			
		}
	}
	
	//we will print only if size is less than 30.
}

