/*************************************************************************
	> File Name: test81.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月16日 星期四 20时43分10秒
 ************************************************************************/

/*******************************************************************
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
 * 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 * ******************************************************************/
#include<iostream>
#include<vector>
#include<unordered_set>

int foo(const std::vector<int> &vec)
{
	std::unordered_set<int> arraySet;
	int ret = 0;
	for(size_t i = 0; i < vec.size(); ++i) {
		arraySet.insert(vec[i]);
	}
	for(size_t i = 0; i < vec.size(); ++i) {
		int curLen = 1;
		int tmp = vec[i];
		while(arraySet.find(--tmp) != arraySet.end()) ++curLen;
		tmp = vec[i];
		while(arraySet.find(++tmp) != arraySet.end()) curLen++;
		if(curLen > ret) ret = curLen;
	}
	return ret;
}

int main(void)
{
	int num;
	std::vector<int> vec;
	while(std::cin >> num) {
		vec.push_back(num);
	}
	std::cout<< "Length:" << foo(vec) << std::endl;

	return 0;
}

