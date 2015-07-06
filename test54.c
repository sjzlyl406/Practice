/*************************************************************************
	> File Name: test54.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 09时19分16秒
 ************************************************************************/

/*********************************************************************
 * 算分数，去掉一个最高分一个最低分，求平均分。
 * ******************************************************************/
#include<stdio.h>

double MeanScore(int *array, int len) 
{
	if(array == NULL || len < 2) return 0.0;

	int maxscore = -1;
	int minscore = 200;
	if(array[0] > array[1]) {
		maxscore = array[0];
		minscore = array[1];
	}
	else {
		maxscore = array[1];
		minscore = array[0];
	}

	long long sum = 0;
	int i = 2;
	for(i = 2; i < len; ++i) {
		if(array[i] > maxscore) {
			sum += maxscore;
			maxscore = array[i];
		}
		else if(array[i] < minscore) {
			sum += minscore;
			minscore = array[i];
		}
		else {
			sum += array[i];
		}
	}

	double result = sum / (double)len;
	return result;
}
int main(void)
{
	int array[100];
	int N;
	printf("input the length of array:");
	scanf("%d", &N);
	int i = 0;
	for(i = 0; i < N; ++i) {
		scanf("%d", &array[i]);
	}
	double result = MeanScore(array, N);

	printf("%f\n", result);
	return 0;
}
