/*************************************************************************
	> File Name: test19.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 14时20分54秒
 ************************************************************************/

/***************************************************************
 * The Kth Number of Two Sorted Arrys
 * ***********************************************************/
#include<stdio.h>

int KthNumber(int *arrayA, int lengthA, int *arrayB, int lengthB, int K)
{
	if(lengthA + lengthB < K || arrayA == NULL || arrayB == NULL)
		return -1;
	
	int pA = 0, pB = 0;
	int i = 0;
	for(i = 0; i < K; ++i) {
		if(i == K-1)
			return arrayA[pA]<arrayB[pB]?arrayA[pA]:arrayB[pB];
		if(arrayA[pA] < arrayB[pB])
			pA++;
		else
			pB++;
	}
}
int main(void)
{
	int arrayA[5] = {1,4,6,8,9};
	int arrayB[5] = {2,3,4,7,8};

	int m;
	scanf("%d", &m);

	int k = KthNumber(arrayA, 5, arrayB, 5, m);

	printf("%d\n", k);
	return 0;
}
