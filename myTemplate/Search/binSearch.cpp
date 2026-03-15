#include"binSearch.h"
//!!!注意，在二分中我们的数据范围是左闭右开的 [lo, hi)
//我的建议是，记住版本A和版本C，忽略版本B



// 二分(A)，最符合直观思路的做法
int binSearch_A( int a[], int e, int lo, int hi ){
	while (lo < hi) {
		int mi = lo + hi >> 1;
		if( e < a[mi] ) hi = mi;
		else if( a[mi] < e ) lo = mi + 1;
		else return mi;	//版本C中，此处删去
	}
	return -1;			//版本C中，此处返回 --lo
}

// 二分(B)，将查找成功的情况并入后子向量以实现查找从三分支变为两分支
int binSearch_B( int a[], int e, int lo, int hi ){
	while( 1 < hi - lo ){	//区间宽度为 1 时停止
		int mi = lo + hi >> 1;
		( e < a[mi] ) ? hi = mi : lo = mi;
	}
	return ( e == a[lo] ) ? lo : -1;
}

//二分(C)，返回不大于e的最后一个元素，即多个元素命中时返回秩最大者，失败时返回小于e的最大者
int binSearch_C( int a[], int e, int lo, int hi ){
	while( lo < hi ){
		int mi = lo + hi >> 1;
		( e < a[mi] ) ? hi = mi : lo = mi + 1;		//hi = mi是因为判断条件导致e一定不会在mi，而此处为[lo, hi)-type
	}
	return --lo;
}

// [lo, hi] vesion
int binSearch_closed_interval( int a[], int e, int lo, int hi ){
	while (lo <= hi) {
		int mi = lo + ( hi - lo >> 1 );
		( e < a[mi] ) ? hi = mi - 1 : lo = mi + 1;	//hi = mi-1是因为判断条件导致e一定不会在mi
	}

	return hi;
}
/*****
int binSearch(int a[], int e, int length ) {
	int lo = binSearch( a, e, 0, length - 1 );
	return lo;
}
 *****/