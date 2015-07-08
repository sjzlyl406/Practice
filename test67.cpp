/*************************************************************************
	> File Name: test67.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 22时39分49秒
 ************************************************************************/

/********************************************************************
 * 自守数是指一个数的平方的尾数等于该数自身的自然数。
 * 例如：252= 625，762= 5776，93762= 87909376。请求出n以内的自守数的个数。
 * *****************************************************************/
#include<iostream>
using namespace std;

/************* first ****************/
bool isZSNum(int n) 
{
	int count = 0;
	long long nn = n * n;
	int bit = 10;
	while(n / bit != 0) {
		bit *= 10;
	}
	return ((nn % bit) == n);
}
int foo(int n) 
{
	int count = 0;
	for(int i = 0; i < n; ++i) {
		if(isZSNum(i))
			count++;
	}
	return count;
}

int main(void)
{
	int i;
	cin >> i;
	cout << foo(i) << endl;
	return 0;
}
