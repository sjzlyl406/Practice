/*************************************************************************
	> File Name: test12.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 21时50分13秒
 ************************************************************************/

/**********************************************************************
 * 0，1，...，n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里
 * 删除第m个数字。求出这个圆圈剩下最后一个数字。
 * ********************************************************************/
#include<iostream>
#include<list>

using namespace std;

int foo(unsigned int n, unsigned int m)
{
	if(n < 1 || m < 1) return -1;

	std::list<int> List;
	for(int i = 0; i < n; i++)
		List.push_back(i);

	std::list<int>::iterator iter = List.begin();

	while(List.size() != 1) {
		for(int i = 1; i < m; ++i) {
			iter++;
			if(iter == List.end())
				iter = List.begin();
		}
		List.erase(iter++);
	}
	return *iter;
}
int main(void)
{
	int n = 0, m = 0;
	std::cin >> n >> m;
	std::cout << foo(n, m) << std::endl;

	return 0;
}
