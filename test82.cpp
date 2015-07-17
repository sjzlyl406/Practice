/*************************************************************************
	> File Name: test82.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月16日 星期四 21时09分04秒
 ************************************************************************/

/***********************************************************************
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where
 * index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not
 * zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * *******************************************************************/
#include<iostream>
#include<vector>
#include<unordered_map>

void OutPrint(int index1, int index2) 
{
	std::cout<<"index1="<<index1<<
		", index2="<<index2<<std::endl;
}

/*************** first:O(n^2) ************/
void Foo1(const std::vector<int> &vec, int target)
{
	for(size_t i = 0; i < vec.size() - 1; ++i) {
		for(size_t j = i+1; j < vec.size(); ++j) {
			if(vec[i] + vec[j] == target) {
				OutPrint(i+1, j+1);
				return;
			}
		}
	}
}
/*************** second:O(n) ************/
void Foo2(const std::vector<int> &vec, int target) 
{
	std::unordered_map<int, size_t> arrayMap;
	for(size_t i = 0; i < vec.size(); ++i) {
		arrayMap[vec[i]] = i+1;
	}
	std::unordered_map<int, size_t>::iterator iter;
	for(size_t i = 0; i < vec.size(); ++i) {
		int tmp = target - vec[i];
		iter = arrayMap.find(tmp);
		if(iter != arrayMap.end()) {
			OutPrint(i+1, iter->second);
			break;
		}
	}
}
int main(void)
{
	int num, target;
	std::cin >> target;
	std::cin.get();
	std::vector<int> vec;
	while(std::cin >> num)
		vec.push_back(num);
	
	Foo1(vec, target);
	return 0;
}

