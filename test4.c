/*************************************************************************
	> File Name: test4.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 14时20分51秒
 ************************************************************************/

/***************************************************************
 * 一个整形数组里除了一个数字外，其他数字都出现了两次。
 * 找出只出现一次的数字。要求时间复杂度O(n),空间复杂度O(1).
 ***************************************************************/
#include<stdio.h>

#define ArrLen 9

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){										\
		printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
		return INVALIDPARAMETER;										\
}																	\

typedef int Ret;

Ret FindOnceNum(int *array, int length, int *result)
{
	ret_val_if(array == NULL && length <= 0);

	*result = 0;
	int i = 0;
	for(i = 0; i < length; ++i) {
		*result ^= array[i];
	}

	return RET_OK;
}

int main(void)
{
	int array[ArrLen] = {1,2,3,4,4,3,2,1,5};
	int result = 0;

	Ret ret = FindOnceNum( array, ArrLen, &result);
	if(ret == RET_OK)
		printf("%d\n.", result);
	
	return 0;
}

