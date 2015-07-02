/*************************************************************************
	> File Name: test17.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 11时17分09秒
 ************************************************************************/

/*********************************************************
 *	Remove Duplicates from sorted Array 2
 *	Input A={1,1,1,2,2,3} Output A={1,1,2,2,3} and length = 5
 * ******************************************************/
#include<stdio.h>

#define MAXLENGTH 10

int RemoveDuplicate(int *array, int length)
{
	int newLength = 0;
	if(array == NULL || length <= 0)
		newLength = 0;
	else {
		int index = 0;
		int i = 1, j = 0;
		for(i = 1; i < length; ++i) {
			if(array[i] == array[i-1]) {
				index++;
				if(index < 2) {
					j++;
					array[j] = array[i];
				}
			}
			else {
				index = 0;
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
	int array[MAXLENGTH] = {1,1,1,2,2,2,3,4,4,4};

	int newLength = RemoveDuplicate(array, MAXLENGTH);

	int i = 0;
	for(i = 0; i < newLength; ++i)
		printf("%d\t", array[i]);
	printf("\n");
	return 0;
}

