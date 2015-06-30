/*************************************************************************
	> File Name: test6.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 15时24分15秒
 ************************************************************************/

/************************************************************
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，
 * 使得他们的和正好是s。如果有多对数组的和为s，输出任意一对。
 * *********************************************************/

#include<stdio.h>

#define ArrayLength 10

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){										\
		printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
		return INVALIDPARAMETER;										\
}																	\

typedef int Ret;

Ret SumOfTwoNumEqualToS(int *array, int length, int s, int *result)
{
	ret_val_if(array == NULL || length < 2);

	int left = 0, right = length - 1;
	while(left != right && array[left]+array[right] != s) {
		if(array[left] + array[right] > s)
			right--;
		else
			left++;
	}

	result[0] = array[left];
	result[1] = array[right];

	if(left == right)
		return RET_ERR;
	else
		return RET_OK;
}

int main(void)
{
	int array[ArrayLength] = {1,2,3,4,5,6,7,8,9,10};
	int result[2] = {0};
	int ToSum = 8;

	Ret ret = SumOfTwoNumEqualToS(array, ArrayLength, ToSum, result);

	if(ret == RET_OK)
		printf("%d + %d = %d \n", result[0], result[1], ToSum);

	return 0;
}
