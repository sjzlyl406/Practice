/*************************************************************************
	> File Name: test57.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 10时04分35秒
 ************************************************************************/

/*********************************************************************
 * 对一个数组，将数组中偶数从大到小排序，奇数从小到大排序,
 * 奇数和偶数交叉着放且输出数组第一位放奇数  若奇数和偶数不等长，
 * 则把剩下的直接放到数组中。
 * ******************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int cmp(int a, int b)
{
	return a > b;
}

int *Merge(int *array1, int len1, int *array2, int len2)
{
	int len = len1 + len2;
	int *result = (int *)malloc(len * sizeof(int));
	int i = 0, m = 0;
	while(i != len1 && i != len2) {
		result[m++] = array1[i];
		result[m++] = array2[i];
		i++;
	}
	if(i == len1) {
		while(m != len) {
			result[m++] = array2[i++];
		}
	}
	if(i == len2) {
		while(m != len) {
			result[m++] = array1[i++];
		}
	}
	return result;
}

void foo(int *array, int len)
{
	if(array == NULL || len < 0)
		return ;
	int *array1 = (int *)malloc(len * sizeof(int));
	int *array2 = (int *)malloc(len * sizeof(int));

	int i = 0, j = 0, k = 0;
	for(k = 0; k < len; ++k) {
		if((array[k] & 0x1) == 1) {
			array1[i++] = array[k];
		}
		else {
			array2[j++] = array[k];
		}
	}
	std::sort(array1, array1+i);
	std::sort(array2, array2 + j, cmp);

	int *result = Merge(array1, i, array2, j);

	for(k = 0; k < (i+j); k++) {
		printf("%d\t", result[k]);
	}
}
int main(void)
{
	int array[5] = {1,3,9,8,6};
	foo(array, 5);
	return 0;
}
