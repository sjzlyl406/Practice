/*************************************************************************
	> File Name: test87.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月18日 星期六 21时50分23秒
 ************************************************************************/

/*********************************************************************
 * 把N 个鸡蛋放到 M 个篮子里，每个篮子不能为空，要满足：任意给出一个不超过 N 的数量，都能找到其中某几个篮子的鸡蛋和等于它。请写一个程序，输入 N,M ，然后输出所有鸡蛋的方法。
 * ******************************************************************/
#include<cstdio>

int* fenPei(int n, int m)
{
	if(n < m) return 0;
	int *array = new int[m]();
		for(int i = 0; i < m; ++i) {
			array[i] = 1;
		}
	int index = 1;
	unsigned int tmp = 0x01;
	for(int i = 0; i < (n-m); ++i) {
		if(array[index] >= (tmp << index))
			index++;
		array[index]++;
	}
	return array;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int *array = fenPei(n, m);
				
	for(int i = 0; i < m; ++i) 
		printf("%d ", array[i]);
	printf("\n");
					
	return 0;
}
