/*************************************************************************
	> File Name: test53.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 08时39分38秒
 ************************************************************************/

/******************************************************************
 * 如果数组长度n为奇数，则将数组中最大的元素放到 output[] 数组最中间的位置，如果数组长度n为偶数，则将数组中最大的元素放到 output[] 数组中间两个位置偏右的那个位置上，然后再按从大到小的顺序，依次在第一个位置的两边，按照一左一右的顺序，依次存放剩下的数。 
 * 例如：input[] = {3, 6, 1, 9, 7}      output[] = {3, 7, 9, 6, 1};            
 *       input[] = {3, 6, 1, 9, 7, 8}    output[] = {1, 6, 8, 9, 7, 3}
 * *****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

void foo(int *inarray, int len1, int **outarray)
{
	if(inarray == NULL || len1 < 0 || outarray == NULL)
		return;
	
	*outarray = (int*)malloc(len1 * sizeof(int));

	std::sort(inarray, (inarray+len1));

	if((len1 & 0x1) == 1) {
		int i = 0, p = 0;
		for(i = 1; i < len1; i = i+2, p++) {
			(*outarray)[p] = inarray[i];
		}
		(*outarray)[p++] = inarray[(len1-1)];
		for(i = len1-3; i >= 0; i= i-2, p++)
			(*outarray)[p] = inarray[i];
	}
	else {
		int i = 0, p = 0;
		for(i = 0; i< len1; i = i+2,p++) {
			(*outarray)[p] = inarray[i];
		}
		(*outarray)[p++] = inarray[len1-1];
		for(i = len1 - 3; i > 0; i= i - 2, p++) {
			(*outarray)[p] = inarray[i];
		}
	}
}

int main(void)
{
	int array[6] = {1,3,6,7,8,9};
	int *outarray;
	foo(array, 6, &outarray);
	for(int i = 0; i < 6; ++i) {
		printf("%d\t", outarray[i]);
	}
	printf("\n");
	return 0;
}
