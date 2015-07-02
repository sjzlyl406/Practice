/*************************************************************************
	> File Name: test20.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 19时45分23秒
 ************************************************************************/

/**************************************************************
 * 输入10个数字，按各个位的和从小到大排序
 * 如输入 11 3 2 4 5 9 8 7 10 6
 * 输出 10 2 11 3 4 5 6 7 8 9
 * ***********************************************************/
#include<iostream>
#include<algorithm>

using namespace std;

int sum(int x)
{
	int sum = 0;
	while(x != 0) {
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}
bool cmp(int a, int b)
{
	if(sum((int)a) > sum((int)b))
		return false;
	else if(sum((int)a) < sum((int)b))
		return true;
	else if((int)a < (int)b)
		return true;
	else
		return false;
}
int main(void)
{
	int array[10];
	for(int i = 0; i < 10; ++i)
		std::cin >> array[i];

	sort(array, array+10, cmp);

	for(int i = 0; i < 9; ++i)
		std::cout<< array[i] << " " ;

	std::cout << array[9]<< std::endl;

	return 0;
}
