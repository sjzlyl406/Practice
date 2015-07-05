/*************************************************************************
	> File Name: test27.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 23时33分04秒
 ************************************************************************/

/*************************************************************
 * 将二维数组按照第k列排列，如果第k列相同，则按照第k+1列排列
 * *********************************************************/
#include<stdio.h>

bool Judge(int array[][4], int i, int j, int k)
{
	while(k < 4) {
		if(array[i][k] < array[j][k])
			return true;
		else if(array[i][k] > array[j][k])
			return false;
		else
			k++;
	}
	return true;
}
void SortArray(int array[][4],int row, int k)
{
	if(array == NULL || row <= 0 || k < 0 || k >= 4) return;

	int i = 0, j = 0;
	for(i = 0; i < row-1; ++i) {
		for(j = i+1; j < row; ++j) {
			if(!Judge(array, i, j, k)) {
				for(int m = 0; m < 4; ++m){
					int tmp = array[i][m];
					array[i][m] = array[j][m];
					array[j][m] = tmp;
				}
			}
		}
	}
}

int main(void)
{
	int array[4][4] = {
		1,2,3,4,
		2,3,4,2,
		2,3,1,2,
		2,3,1,1};
	SortArray(array, 4, 1);

	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}
