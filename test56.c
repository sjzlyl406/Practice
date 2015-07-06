/*************************************************************************
	> File Name: test56.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 09时43分09秒
 ************************************************************************/

/**********************************************************************
 * 求一个二维数组每列的最小值和二维数组的最小值。
 * ******************************************************************/
#include<stdio.h>
#include<limits.h>

#define col 4

int Min(int (*array)[col], int row)
{
	int mincol[col] = {0};
	int i = 0;
	for(i = 0; i < col; ++i) {
		mincol[i] = INT_MAX;
	}

	int j = 0;
	for(i = 0; i < row; ++i) {
		for(j = 0; j < col; ++j) {
			if(mincol[j] > array[i][j]) {
				mincol[j] = array[i][j];
			}
		}
	}

	int minmin = INT_MAX;
	for(i = 0; i < col; ++i) {
		printf("%d\t", mincol[i]);
		if(minmin > mincol[i])
			minmin = mincol[i];
	}
	printf("\n %d \n", minmin);
	return minmin;
}
int main(void)
{
	int array[4][col] = 
	{1,2,5,3,
	 2,3,4,2,
	 8,5,2,7,
	 6,3,6,3};

	int min = Min(array, 4);
	return 0;
}
