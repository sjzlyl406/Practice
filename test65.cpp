/*************************************************************************
	> File Name: test65.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 22时11分31秒
 ************************************************************************/

/****************************************************************
 * 相关数：判断比整数N小的数里，有多少个与7相关的数（比如7、14、17、27）。
 * 只需要给出总的个数，不需要输出。
 * **************************************************************/
#include<iostream>
using namespace std;

bool isRelatedToSeven(int i)
{
	if((i%7) == 0)
		return true;
	while(i) {
		if((i % 10) == 7)
			return true;
		i = i / 10;
	}
	return false;
}

int foo(int i )
{
	if(i < 7)
		return 0;
	int count = 0;
	for(int k = 7; k < i; ++k) {
		if(isRelatedToSeven(k))
			count++;
	}
	return count;
}

int main(void)
{
	int i;
	cin >> i;
	i = foo(i);
	cout << i;

	return 0;
}
