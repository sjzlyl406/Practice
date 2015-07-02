/*************************************************************************
	> File Name: test16.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 10时25分49秒
 ************************************************************************/

/***************************************************
 * Remove Duplicates from Sorted Array return the new length
 * do not allocate new space
 * input A=[1,1,3] Output A=[1,3] and length = 2;
 * ************************************************/
#include<stdio.h>

#define SWAP(a,b) {(a)=(a)^(b);(b)=(a)^(b);(a)=(a)^(b);}
#define MAXLENGTH 10

int RemoveDuplicate(int *array, int length)
{
	int newLength = 0;
	if(array == NULL || length <= 0)
		newLength = 0;
	else {
		int i = 1, j = 0;
		for(i = 1; i < length; ++i) {
			if(array[i] != array[i-1]) {
				j++;
				array[j] = array[i];
			}
		}
		newLength = ++j;
	}
	return newLength;
}

int main(void)
{
	int array[MAXLENGTH] = {1,1,2,2,2,3,4,5,6,6};

	int len = RemoveDuplicate(array, MAXLENGTH);

	int i = 0; 
	for(i = 0; i < len; ++i)
		printf("%d\t", array[i]);

	printf("\n");
	return 0;
}
