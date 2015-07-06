/*************************************************************************
	> File Name: test55.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 09时36分45秒
 ************************************************************************/

/**********************************************************************
 * 找出一个数组中满足2^N的元素。
 * 例如：输入1,2,3,5,7,8,16，则输出：符合条件的有：1 2 8 16 共4个
 * *******************************************************************/
#include<stdio.h>

int isMi(int i)
{
	if((i & (i-1)) == 0)
		return 1;
	else
		return 0;
}
int main(void)
{
	int N, array[100];
	printf("input the length of array:");
	scanf("%d", &N);
	int i = 0;
	for(i = 0; i < N; ++i) {
		scanf("%d" , &array[i]);
	}

	for(i = 0; i < N; ++i) {
		if(isMi(array[i]) == 1)
			printf("%d\t", array[i]);
	}
	printf("\n");

	return 0;
}

