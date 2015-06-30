/*************************************************************************
	> File Name: test10.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 18时48分33秒
 ************************************************************************/

/*******************************************************************
 * 把n个色子扔在地上，所有色子朝上一面的点数之和为s。
 * 输入n，打印出s的所有可能值出现的概率。
 * ****************************************************************/

#include<stdio.h>
#include<math.h>   //pow
#include<stdlib.h>   //malloc
#include<string.h>   //memset

void dfs(int *, int ,int, int, int *);
void PrintProbility(int n)
{
	if(n < 1)	return;

	const int MapLen = 5 * n + 1;
	int *CountMap = (int*)malloc(MapLen * sizeof(int));
	memset(CountMap, 0, MapLen * sizeof(int));

	int loop = 0, count = 0;
	int Map[6] = {1,2,3,4,5,6};

	dfs(Map, n, loop, count, CountMap);

	double TotalS = pow(6.0, n);
	int i = 0;
	for(i = 0; i < MapLen; ++i)
		printf("%d : %f\n", i+n, CountMap[i]/TotalS);

	free(CountMap);
	CountMap = NULL;

	return;
}
void dfs(int *map, int n, int loop, int count, int *CountMap)
{
	if(loop == n) {
		CountMap[count-n]++;
		return;
	}

	int i = 0;
	for(i = 0; i < 6; ++i) {
		dfs(map, n, loop+1, count+map[i], CountMap);
	}
}

int main(void)
{
	int n = 1;

	scanf("%d", &n);

	PrintProbility(n);

	return 0;
}
