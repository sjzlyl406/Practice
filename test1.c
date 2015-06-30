/*************************************************************************
	> File Name: test1.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 13时00分51秒
 ************************************************************************/

/******************************************************
 * 统计数字在排序数组中出现的次数。
 * 如输入排序数组{1,2,3,3,3,3,4,5} 和数字3
 * 输出 4
 * ****************************************************/

#include<stdio.h>

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){										\
	printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
	return INVALIDPARAMETER;										\
}																	\

int GetFirstK(int *, int, int ,int ,int );
int GetLastK(int *, int, int, int, int);
int CountNum(int *array, int length, int K)
{
	ret_val_if(array == NULL && length <= 0);
	
	int number = 0;

	int first = GetFirstK(array, length, K, 0, length-1);
	int last = GetLastK(array, length, K, 0, length-1);

	if(first >-1 && last >-1)
		number = last - first +1;

	return number;

}
int GetFirstK(int *data, int length, int k, int start, int end)
{
	ret_val_if(start > end);

	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];

	if(middleData == k) {
		if((middleIndex > 0 && data[middleIndex-1] != k)
				|| middleIndex == 0)
			return middleIndex;
		else
			end = middleIndex - 1;
	}
	else if(middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	return GetFirstK(data, length, k, start, end);
}
int GetLastK(int *data, int length, int k, int start, int end)
{
	ret_val_if(start > end);

	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];

	if(middleData == k) {
		if((middleIndex < length-1 && data[middleIndex+1] != k)
				|| middleIndex == length - 1)
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if(middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;

	return GetLastK(data, length, k, start, end);
}

int main(void)
{
	int array[] = {1,2,3,3,3,3,4,5};

	int number = CountNum(array, 8, 3);

	printf("%d\n", number);
	return 0; 
}
