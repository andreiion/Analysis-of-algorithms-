#ifndef TESTINGFUNCTIONS_H_
#define TESSTINGFUNCTIONS_H_

#define SIZE1 10
#define SIZE2 300
#define SIZE3 10000
#define TESTSIZE 11

#ifndef bool
    #define bool int
    #define false ((bool)0)
    #define true  ((bool)1)
#endif

int arr10rand[SIZE1], arr10sorted[SIZE1], arr10descr[SIZE1];
int arr300rand[SIZE2], arr300sorted[SIZE2], arr300descr[SIZE2];
int arr10000rand[SIZE3], arr10000sorted[SIZE3], arr10000descr[SIZE3];
int arr10Aux[SIZE1], arr300Aux[SIZE2], arr10000Aux[SIZE3+100];


void randomGenTestMode(int v[]);
void randomGenAnalysisMode(int v[], int size);
int power(int base, int exponent);
//void swap(int a, int b);

void createArraysForAnalysis();
void copyArray (int A[], int B[], int size);
void invert (int A[], int B[], int size);
void equal (int A[], int B[], int size);
void quickSort(int v[], int left, int right);

// Modul Analiza
void heap ();
void binaryT ();
void radix ();
void splay ();
void strand ();
void block ();
void cocktail ();

#endif