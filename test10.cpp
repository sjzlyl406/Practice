/*************************************************************************
	> File Name: test10.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 19时34分18秒
 ************************************************************************/

/*******************************************************************
 * 把n个色子扔在地上，所有色子朝上一面的点数之和为s。
 * 输入n，打印出s的所有可能值出现的概率。
 * ****************************************************************/

#include<iostream>
#include<unordered_map>
#include<cmath>

using namespace std;

void dfs(int, int, int, std::unordered_map<int, int> &);
void PrintProbility( int n ) 
{
	if(n < 1) return ;

	std::unordered_map<int, int> CountMap;
	int loop = 0, count = 0;

	dfs(n, loop, count, CountMap);

	std::unordered_map<int, int>::iterator iter = CountMap.begin();
	while(iter != CountMap.end()) {
		std::cout<<iter->first << ":"
			<< (iter -> second)/pow(6.0, n) <<std::endl;
		iter++;
	}

	return;
}
void dfs(int n, int loop,int count, std::unordered_map<int, int> &map)
{
	if( n == loop ){
		map[count]++;
		return;
	}

	for(int i = 1; i < 7; ++i)
		dfs(n, loop+1, count+i, map);
}
int main(void)
{
	int i = 1;
	std::cin >>  i;
	PrintProbility(i);
	return 0;
}
