/*************************************************************************
	> File Name: test58.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 10时27分25秒
 ************************************************************************/

/**********************************************************
 * 求两个整型数组的异集，即A+B-(A与B的交集)。
 * 例如a[]={1,2,3,4,5}, b[]={2,3}，则a,b的异集为{1,4,5}。
 * *********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxLength 100

int main(void)
{
	int N1, N2;
	int array1[MaxLength], array2[MaxLength];
	printf("intput the length of two array:(N1 & N2)");
	scanf("%d %d", &N1, &N2);
	int i = 0; 
	for(i = 0; i < N1; ++i) {
		scanf("%d", &array1[i]);
	}
	for(i = 0; i < N2; ++i) {
		scanf("%d", &array2[i]);
	}
	int *array = (int*)malloc((N1+N2)*sizeof(int));
	int *visit = (int*)malloc(N2 *sizeof(int));
	memset(visit, 0, N2*sizeof(int));
	int p = 0;

	for(i = 0; i < N1; ++i) {
		int flag = 0, j = 0;
		for(j = 0; j < N2; j++) {
			if(array1[i] == array2[j]) {
				visit[j] = 1;
				flag = 1;
			}
		}
		if(flag != 1) {
			array[p++] = array1[i];
		}
	}
	for(i = 0; i < N2; ++i) {
		if(visit[i] != 1)
			array[p++] = array2[i];
	}

	for(i = 0; i < p; ++i)
		printf("%d\t", array[i]);
	printf("\n");

	return 0;

}

