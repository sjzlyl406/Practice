/*************************************************************************
	> File Name: test123.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 09时20分35秒
 ************************************************************************/

/************************************************************************
 * 打印一个N*N的方阵，N为每边字符的个数（ 3〈N〈20 ），要求最外层为"X"，第二层为"Y"，从第三层起每层依次打印数字0，1，2，3，...
 * 例子：当N =5，打印出下面的图形：
 *  X X X X X
 *  X Y Y Y X
 *  X Y 0 Y X
 *  X Y Y Y X
 *  X X X X X 
 * *******************************************************************/
#include<iostream>
#include<cstdio>

const char array[] = {'X', 'Y', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9'};

int main(void)
{
	int N;
	printf("input an N : ");
	scanf("%d", &N);

	int **ret = new int*[N]();
	for(int i = 0; i < N; ++i) 
		ret[i] = new int[N]();

	for(int i = 0; i < N; ++i) {
		if(i <= (N >> 1)) {
			for(int j = 0; j < N; ++j) {
				if(j < i)
					ret[i][j] = array[j];
				else if (j >= N-i)
					ret[i][j] = array[N-j-1];
				else
					ret[i][j] = array[i];
			}
		}
		else {
			for(int j = 0; j < N; ++j) {
				ret[i][j] = ret[N-i-1][j];
			}
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			printf("%c ", ret[i][j]);
		}
	printf("\n");
	}

	return 0;
}
