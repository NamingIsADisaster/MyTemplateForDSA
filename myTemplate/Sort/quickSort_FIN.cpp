#include"quickSort.h"
#include<algorithm>
//1. easy-to-rem type
void quickSort0(int a[], int lo, int hi) {
	if (hi <= lo) return;
	int i = lo - 1, j = hi + 1, p = a[lo];
	while (i < j) {
		do i++; while (a[i] < p);
		do j--; while (p < a[j]);
		if (i < j) std::swap(a[i], a[j]);
		else break;
	}
	quickSort0(a, lo, j);
	quickSort0(a, j + 1, hi);
}

//2. no-vector type
int partition(int a[], int lo, int hi) {
	//仅需在原版上稍作修改就完成了随机选择pivot的任务，活用当前代码，好思路！
	int pivotIndex = lo + hi >> 1;
	std::swap( a[lo], a[pivotIndex] );

	int pivot = a[lo];
	while (lo < hi) {
		while (lo < hi && pivot <= a[hi])
			hi--;
		a[lo] = a[hi];

		while (lo < hi && a[lo] <= pivot)
			lo++;
		a[hi] = a[lo];
	}
	a[lo] = pivot;
	return lo;
}

void quickSort1(int a[], int lo, int hi) {
	if (lo < hi) {
		int p = partition(a, lo, hi);
		quickSort1(a, lo, p - 1);
		quickSort1(a, p + 1, hi);
	}
}

//3. 三路快排，对相同值进行一次处理而非多次重复处理
//思路见https://www.runoob.com/data-structures/3way-qiuck-sort.html
//简单说，就是恒令lo ~ lt, lt ~ gt, gt ~ hi-1分别为小于pivot、等于pivot和大于pivot的元素
void quickSort3(int a[], int lo, int hi) {
	if( lo >= hi ) return;
	int pivot = a[lo + hi >> 1];
	int lt = lo, gt = hi, i = lo;
	while (i <= gt) {
		if( a[i] < pivot )
			std::swap( a[i++], a[lt++] );
		else if( a[i] == pivot )
			i++;
		else
			std::swap( a[i], a[gt--] );
	}
	quickSort3(a, lo, lt - 1);
	quickSort3(a, gt + 1, hi);
}