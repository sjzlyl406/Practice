/*************************************************************************
	> File Name: test117.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月28日 星期二 21时33分20秒
 ************************************************************************/

/************************************************************************
 * 给定一个排好升序的数组A[1]、A[2]、……、A[n]，其元素的值都两两不相等。
 * 请设计一高效的算法找出中间所有A[i] = i的下标。
 * *******************************************************************/
#include<iostream>
#include<cstdio>


void foo(int *array, int len)
{
	int left = 0, right = len-1, index = -1, mid;
	while(left <= right) {
		mid = left + ((right - left) >> 1);
		if(array[mid] < mid)
			left = mid + 1;
		else if (array[mid] > mid)
			right = mid - 1;
		else if (mid == 0 || 
				(array[mid] == mid && array[mid-1] != mid-1)) {
			index = mid;
			break;
		}
		else right = mid - 1;
	}

	if(index == -1) 
		printf("not found!");
	else {
		do{
			printf("%d\t", array[index++]);
		}while(index < len && array[index] == index);
	}
	printf("\n");
}

int main(void)
{
	int num, len;
	printf("input the length of array:");
	scanf("%d", &len);
	int *array = new int[len];
	for(int i = 0; i < len; ++i) {
		scanf("%d", &num);
		array[i] = num;
	}

	foo(array, len);

	return 0;
}
