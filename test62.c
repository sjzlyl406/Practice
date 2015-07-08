/*************************************************************************
	> File Name: test62.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 23时41分33秒
 ************************************************************************/

/*******************************************************************
 * 最小公约数和最大公倍数
 * ****************************************************************/
#include<stdio.h>

/*************** first *****************/
int gcd(int v1, int v2) 
{
	while(v2 != 0) {
		int tmp = v2;
		v2 = v1 % v2;
		v1 = tmp;
	}
	return v1;
}

/*************** second *****************/
int gcd2(int v1, int v2)
{
	while(v1 != v2) {
		if(v1 > v2)
			v1 = v1 - v2;
		else if( v1 < v2)
			v2 = v2 - v1;
	}
	return v1;
}

int lcm(int v1, int v2)
{
	int tmp = gcd2(v1, v2);
	return (v1 * v2) / tmp;
}

int main(void)
{
	int i, j;
	printf("input i & j  :");
	scanf("%d %d", &i, &j);

	printf("gcd1 : %d\n", gcd(i, j));
	printf("gcd2 : %d\n", gcd2(i, j));
	printf("lcd : %d\n", lcm(i, j));

	return 0;
}
