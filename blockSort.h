#ifndef BLOCKSORT_H_
#define BLOCKSORT_H_

int contorBlock;

int FloorPowerOfTwo ( int x );
void blockSort(int arr[], int size);
void insertionSort ( int arr[], int start, int end);
void mergeFunction ( int arr[], int start, int mid, int end);

#endif