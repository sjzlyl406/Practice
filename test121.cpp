/*************************************************************************
	> File Name: test121.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 08时22分24秒
 ************************************************************************/

/************************************************************
 * 实现下列程序
 * *
 * *.*.
 * *..*..*..
 * *...*...*...*...
 * *....*....*....*....*....
 * *.....*.....*.....*.....*.....*.....
 * *......*......*......*......*......*......*......
 * *.......*.......*.......*.......*.......*.......*.......*.......
 * *********************************************************/
#include<iostream>
#include<cstdio>

#define N 8
int main(void)
{
	int row = 0;
	int i = row + 1;
	int j = row;
	for(row = 0; row < N; ++row) {
		for(i = 0; i < row+1; ++i) {
			printf("*");
			for(j = 0; j < row; ++j) {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}

