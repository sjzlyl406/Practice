/*************************************************************************
	> File Name: test64.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 21时43分21秒
 ************************************************************************/

/****************************************************************
 * 我们把只包含因子2，3，5的数称为丑数，把1当作第一个丑数，求从小到大的第n个丑数（还有质素）
 * 输入：n  输出：第n个丑数。
 * ************************************************************/
#include<iostream>
using namespace std;

/************** first : O(n^2) ****************/
bool isUgly(int n)
{
	int k = 0;
	while((n % 2) == 0) {
		n = n / 2;
	}
	while((n % 3) == 0) {
		n = n / 3;
	}
	while((n % 5) == 0) {
		n = n / 5;
	}
	return (n == 1);
}
int theKthUglyNumber(int n) 
{
	if(n <= 0) 
		return 0;
	int i = 0, count = 0;;
	while(count != n) {
		i++;
		if(isUgly(i))
			count++;
	}
	return i;
}
/************* second : O(n) *****************/
int min(int a, int b, int c)
{
	return a >= b ?
		b >= c ? c : b :
		a >= c ? c : a ;
}
int theKthUglyNumber2(int n) 
{
	if(n <= 0)
		return 0;
	int i = 0, j = 0, k = 0;
	int count = 0;
	int *map = new int[n]();
	map[0] = 1;
	int minnum = 0;

	while(count != n-1) {
		count++;
		minnum = min(map[i]*2, map[j]*3, map[k]*5);
		if(minnum == map[i]*2) i++;
		if(minnum == map[j]*3) j++;
		if(minnum == map[k]*5) k++;
		map[count] = minnum;
	}

	int result = map[count];

	delete [] map;
	return result;
}

int main(void)
{
	int number = 0;
	std::cin >> number;
	std::cout << theKthUglyNumber2(number) << std::endl;
	return 0;
}
