/*************************************************************************
	> File Name: test45.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 21时14分21秒
 ************************************************************************/

/************************************************************
 * 输入m个字符串 和一个整数n, 把字符串M化成以N为单位的段，
 * 不足的位数用0补齐。
 * 如 n=8 m=9 ，
 * 123456789划分为：12345678   90000000
 * 123        化为 ：12300000
 * ********************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** foo(int m, int n)
{
	if(m < 0 || n <= 0) return NULL;
	int k = m / n + 1;
	int i = 1;

	char ** result = (char**)malloc(k * sizeof(char*));
	for(i = 0; i < k; ++i) {
		result[i] = (char*)malloc((n+1) * sizeof(char));
		memset(result[i], '0', ((n+1)*sizeof(char)));
		result[i][n] = '\0';
	}

	for(i = 0; i < k; ++i) {
		int j = 0;
		for(j = 1; j <= n; ++j) {
			int num = i * n + j;
			if(num <= m)
				result[i][j-1] = num + '0';
		}
	}
	for(i = 0; i < k; ++i) {
		printf("%s\n", result[i]);
	}

	return result;
}

int main(void)
{
	int n, m;
	printf("input two number :");
	scanf("%d %d", &n, &m);

	char **result = foo(m, n);

	return 0;
}

