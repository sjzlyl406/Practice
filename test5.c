/*************************************************************************
	> File Name: test4.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 14时20分51秒
 ************************************************************************/

/***************************************************************
 * 一个整形数组里除了两个数字外，其他数字都出现了两次。
 * 找出只出现一次的数字。要求时间复杂度O(n),空间复杂度O(1).
 * **************************************************************/
#include<stdio.h>

#define ArrLen 10

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){										\
		printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
		return INVALIDPARAMETER;										\
}																	\

typedef int Ret;

int FindOnceNum(int *array, int left, int right)
{
	int i = left, result = 0;
	for(i = left; i < right; ++i) {
		result ^= array[i];
	}

	return result;
}

Ret FindTwoOnceNum(int *array, int length, int *result)
{
	ret_val_if(array == NULL && length < 2 && result == NULL);

	result[0] = result[1] = 0;

	int i = 0;
	int tmp = 0;
	for(i = 0; i < length; ++i) {
		tmp ^= array[i];
	}

	unsigned int indexOfOne = 0x1;
	while(indexOfOne != 0 && (tmp & indexOfOne) == 0)
		indexOfOne << 1;
	if(indexOfOne == 0)
		return RET_ERR;

	int j = 0;
	for(i = 0; i < length; ++i) {
		if((indexOfOne & array[i]) == 0) {
			tmp = array[j];
			array[j++] = array[i];
			array[i] = tmp;
		}
	}

	result[0] = FindOnceNum(array, 0, j);
	result[1] = FindOnceNum(array, j, length);

	return RET_OK;
}

int main(void)
{
	int array[ArrLen] = {1,2,3,4,4,3,2,1,5,6};
	int result[2] = {0};

	Ret ret = FindTwoOnceNum(array, ArrLen, result);
	if(ret == RET_OK)
		printf("%d & %d\n.", result[0], result[1]);
	
	return 0;
}

