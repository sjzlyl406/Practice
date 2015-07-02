/*************************************************************************
	> File Name: test18.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 12时34分05秒
 ************************************************************************/

/************************************************************
 * Search in Rotate Sorted Array
 * if found return its index, else return -1
 * i.e. input 4 5 6 7 0 1 2
 * *********************************************************/
#include<stdio.h>

#define MAXLENGTH 7

int SearchInRotatedSortedArray(const int *array, int length, int K)
{
	if(array == NULL || length <= 0)
		return -1;
	else {
		int left = 0, right = length;
		while(left != right) {
			int mid = (left + right) >> 1;
			if(array[mid] == K)
				return mid;
			else if(array[left] <= array[mid]) {
				if(array[left] <= K && K < array[mid])
					right = mid;
				else
					left = mid+1;
			}
			else {
				if(array[mid] < K && K <= array[right-1])
					left = mid+1;
				else
					right = mid;
			}
		}
		return -1;
	}
}
void Print(const int *array, int left, int right)
{
	if(left > right)
		printf("\n");
	else {
		int i = 0;
		for(i = left; i < right; ++i)
			printf("%d\t", array[i]);
		printf("\n");
	}
}

int main(void)
{
	int array[MAXLENGTH] = {4,5,6,7,0,1,2};

	int m = 0;

	int idx = SearchInRotatedSortedArray(array, MAXLENGTH, m);

	printf("%d\n", idx);

	return 0;
}
