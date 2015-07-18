/*************************************************************************
	> File Name: test85.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月17日 星期五 20时16分11秒
 ************************************************************************/

/*********************************************************************
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * • Elements in a quadruplet (a, b, c, d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * • The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
 * (-1, 0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2, 0, 0, 2)
 * *****************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>

/*************** first:O(n^3) ****************/
std::vector<std::vector<int> > foo1(std::vector<int> vec, int target)
{
	std::vector<std::vector<int> > ret;
	std::sort(vec.begin(), vec.end());
	for(size_t i = 0; i < vec.size()-3; ++i) {
		for(size_t j = i+1; j < vec.size()-2; ++j) {
			size_t left = j+1, right = vec.size()-1;
			while(left < right) {
				int sum = vec[i] + vec[j] + vec[left] + vec[right];
				if(sum == target) {
					ret.push_back({vec[i], vec[j], vec[left], vec[right]});
					left++;	right--;
				}
				else if(sum < target)
					left++;
				else
					right--;
			}
		}
	}
	return ret;
}
/**************** second:O(n^2) ******************/
std::vector<std::vector<int> > foo2(std::vector<int> vec, int target) 
{
	std::vector<std::vector<int> > ret;
	std::sort(vec.begin(), vec.end());
	
	std::unordered_map<int, std::vector<std::pair<int, int> > > cache;
	for(size_t i = 0; i < vec.size()-1; ++i) {
		for(size_t j = i+1; j < vec.size(); ++j) {
			cache[vec[i]+vec[j]].push_back(std::make_pair(i, j));
		}
	}

	for(size_t i = 0; i < vec.size()-1; ++i) {
		for(size_t j = i+1; j<vec.size(); ++j) {
			const int sum = target - vec[i] - vec[j];
			if(cache.find(sum) == cache.end())
				continue;
			for(size_t k = 0; k < cache[sum].size(); ++k) {
				if(i <= cache[sum][k].second)
					continue;
				ret.push_back({vec[cache[sum][k].first], vec[cache[sum][k].second], vec[i], vec[j]});
			}
		}
	}
	return ret;
}

int main(void)
{
	int num;
	std::vector<int> vec;
	while(std::cin>> num)
		vec.push_back(num);

	std::vector<std::vector<int> > ret1 = foo1(vec, 0);
	std::vector<std::vector<int> > ret2 = foo2(vec, 0);

	for(size_t i = 0; i < ret1.size(); ++i) {
		for(size_t j = 0; j < ret1[i].size(); ++j) {
			std::cout<<ret1[i][j] << " ";
		}
		std::cout<<std::endl;
	}
	for(size_t i = 0; i < ret2.size(); ++i) {
		for(size_t j = 0; j < ret2[i].size(); ++j) {
			std::cout<<ret2[i][j] << " ";
		}
		std::cout<<std::endl;
	}
}



