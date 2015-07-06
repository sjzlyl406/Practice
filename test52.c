/*************************************************************************
	> File Name: test52.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 08时10分13秒
 ************************************************************************/

/**********************************************************************
 * 比较两个数组，要求从数组最后一个元素开始逐个元素向前比较，如果2个数组长度不等，则只比较较短长度数组个数元素。请编程实现上述比较，并返回比较中发现的不相等元素的个数
 * 比如：数组{1,3,5}和数组{77,21,1,3,5}按题述要求比较，不相等元素个数为0
 *       数组{1,3,5}和数组{77,21,1,3,5,7}按题述要求比较，不相等元素个数为3
 * ******************************************************************/
#include<stdio.h>
#include<stdlib.h>

int Compare(int *array1, int len1, int *array2, int len2)
{
	if(array1 == NULL || array2 == NULL || len1 < 0 || len2 < 0)
		return -1;
	int index1, index2;
	int result = 0;
	if(len1 < len2) {
		index1 = len1 - 1;
		index2 = len2 - 1;
		while(index1 >= 0) {
			if(array1[index1] != array2[index2])
				result++;
			index1--;	index2--;
		}
	}
	else {
		index1 = len2 - 1;
		index2 = len1 - 1;
		while(index1 >= 0) {
			if(array2[index1] != array1[index1])
				result++;
			index1--;	index2--;
		}
	}

	return result;
}

int main(void) {
	int N1, N2;
	printf("input the length of array1");
	scanf("%d", &N1);
	int *array1 = (int*)malloc(N1 * sizeof(int));
	int i = 0, tmp = 0;
	for(i = 0; i < N1; ++i)  {
		scanf("%d" , &tmp);
		array1[i] = tmp;
	}

	printf("input the length of array2");
	scanf("%d", &N2);
	int *array2 = (int*)malloc(N2 * sizeof(int));
	for(i = 0; i < N2; ++i)  {
		scanf("%d" , &tmp);
		array2[i] = tmp;
	}

	
	printf("%d\n", Compare(array1, N1, array2, N2));

	return 0;
}
