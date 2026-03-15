#include<iostream>
#include"mergeSort.h"

void merge(int a[], int lo, int mi, int hi) {
	/*****先处理前后子向量，其中A、C为原向量中的指针，B为复制的新向量*****/
	int lenB = mi - lo + 1, lenC = hi - mi;
	int* A = a + lo;	//A[0, hi-lo] = a[lo, hi]
	int* B = new int[lenB];
	int* C = a + mi + 1;	//C[0, hi-mi] = a[mi+1, hi]

	for( int i = 0; i < lenB; i++ )
		B[i] = A[i];	//复制，B[0, mi-lo] 与 a[lo, mi]的值相同

	/*****前后子向量处理完毕*****/


	for (int i = 0, j = 0, k = 0; j < lenB || k < lenC; ) {
		if( j < lenB && ( lenC <= k || B[j] <= C[k] ) )	//C[k]已无或不小
			A[i++] = B[j++];
		if( k < lenC && ( lenB <= j || C[k] < B[j] ) )	//B[j]已无或更大
			A[i++] = C[k++];
	}
	delete []B;
}

void mergeSort(int a[], int lo, int hi) {
	if (lo < hi) {
		int mi = lo + hi >> 1;
		mergeSort( a, lo, mi );
		mergeSort( a, mi+1, hi );
		merge( a, lo, mi, hi );
	}



}