/*************************************************************************
	> File Name: test59.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 10时53分05秒
 ************************************************************************/

/****************************************************************
 * 给定一个n*m的矩阵，请编程实现以逆时针旋转方式打印出它的每个元素，
 * 例如输入矩阵
 * 1 8 7
 * 2 9 6
 * 3 4 5
 * 则输出为1 2 3 4 5 6 7 8 9。
 * ****************************************************************/
#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	return a>b?b:a;
}

void foo(int **array, int m, int n, int i)
{
	int j = 0;
	for(j = i; j <= (m-i); ++j) {
		printf("%d\t", array[j][i]);
	}
	for(j = (i+1); j <= (n-i); ++j) {
		printf("%d\t", array[m-i][j]);
	}
	for(j = (m-i-1); j >= i; --j) {
		printf("%d\t", array[j][n-i]);
	}
	for(j = (n-i-1); j >= (i+1); --j) {
		printf("%d\t", array[i][j]);
	}

}

int main(void)
{
	int m,n;
	printf("input m & n :");
	scanf("%d %d", &m, &n);

	int **array = (int**)malloc(m * sizeof(int*));
	int i = 0; 
	for(i = 0; i < m; ++i ) {
		*(array+i) = (int*)malloc(n * sizeof(int));
	}

	for(i = 0; i < m; ++i) {
		int j = 0; 
		for(j = 0; j < n; ++j) {
			int tmp;
			scanf("%d", &tmp);
			array[i][j] = tmp;
		}
	}
	i = min((m>>1),(n>>1));

	int j = 0;
	while(j <= i) {
		foo(array, m-1, n-1, j);
		j++;
	}

	return 0;
}
