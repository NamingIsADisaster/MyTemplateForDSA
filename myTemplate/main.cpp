#include<iostream>
#include<cstdio>
#include"Sort/quickSort.h"
#include"Sort/mergeSort.h"
#include"Search/binSearch.h"
using namespace std;
int main(void) {
    int n, a[10010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // quickSort1(a, 0, n-1);
    // mergeSort(a, 0, n-1);
    // binSearch_C(a, );
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);


	
	return 0;
}