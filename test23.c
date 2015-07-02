/*************************************************************************
	> File Name: test23.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 21时10分24秒
 ************************************************************************/

/*************************************************************
 * 输入整型数组求数组的最小数和最大数之和，例
 * 如输入1,2,3,4则输出为5，当输入只有一个数的时候，则最小数和最大数都是该数，
 * 例如只输入1，则输出为2；数组的长度不超过50。
 * **********************************************************/
#include<stdio.h>
#include<limits.h>

int main(void)
{
	int maxNum = INT_MIN;
	int minNum = INT_MAX;
	int i = 0;

	int n = 0;
	printf("input the length of array:(less than 50)");
	scanf("%d", &n);
	printf("input array:\n");

	int array[50] = {0};
	for(i = 0; i < n; ++i)
		scanf("%d", &array[i]);

	for(i = 0; i < n; ++i) {
		if(array[i] > maxNum)
			maxNum = array[i];
		if(array[i] < minNum)
			minNum = array[i];
	}

	int sum = minNum + maxNum;
	printf("the sum is :%d .\n", sum);

	return 0;
}
