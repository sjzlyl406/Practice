/*************************************************************************
	> File Name: test122.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 08时31分08秒
 ************************************************************************/

/*****************************************************************
 * 巧排数字，将1,2,...,19,20这20个数字排成一排，使得相邻的两个数字之和为一个素数，且
 * 首尾两数字之和也为一个素数。编程打印出所有的排法。
 * *************************************************************/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define N 10


void Print(const std::vector<int> &path)
{
	for(size_t i = 0; i < path.size(); ++i)
		printf("%d\t", path[i]);
	printf("\n");
}

void dfs(std::vector<int> mmap, std::vector<int> &path, const std::vector<int> &PrimNum);
void foo(void)
{
	const int num[] = {
		1,2,3,5,7,11,13,17,19,23,29,31,37};
	const std::vector<int> PrimNum(num, num + 13); 

	std::vector<int> mmap;
	for(int i = 1; i <= N; ++i)
		mmap.push_back(i);

	std::vector<int> path;
	dfs(mmap, path, PrimNum);
}

void dfs(std::vector<int> mmap, std::vector<int> &path, const std::vector<int> &PrimNum) 
{
	if(path.size() == N) {
		if(std::find(PrimNum.begin(), PrimNum.end(),
				path.back() + path.front()) != PrimNum.end() ) {
			Print(path);
		}
		else
			return;
	}

	for(size_t i = 0; i < mmap.size(); ++i) {
		if(path.empty() || std::find(PrimNum.begin(), PrimNum.end(),
				mmap[i] + path.back()) != PrimNum.end() ) {
			int value = mmap[i];
			mmap.erase(mmap.begin() + i);
			path.push_back(value);
			dfs(mmap, path, PrimNum);
			path.pop_back();
			mmap.push_back(value);
		}
	}
}

int main(void)
{
	foo();
	return 0;
}


