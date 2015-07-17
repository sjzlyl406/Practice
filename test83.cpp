/*************************************************************************
	> File Name: test83.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月16日 星期四 21时58分08秒
 ************************************************************************/

/*********************************************************************
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique
 * triplets in the array which gives the sum of zero.
 * Note:
 * • Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * • The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4}.
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 * ******************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>

std::vector<std::vector<int> > foo(std::vector<int> &vec) 
{
	std::vector<std::vector<int> > ret;
	std::sort(vec.begin(), vec.end());
	if(vec.size() < 3) return ret;
	
	for(size_t i = 0; i < vec.size()-2; ++i) {
		size_t left = i+1, right = vec.size()-1;
		int itmp = 0 - vec[i];
		if(i>0 && vec[i] == vec[i-1]) continue;
		while(left < right) {
			if(vec[left] + vec[right] == itmp) {
				ret.push_back({vec[i], vec[left], vec[right]});
				left++, right--;
				while(left<right && vec[left]==vec[left-1] && vec[right]==vec[right+1])
					left++;
			}
			else if(vec[left] + vec[right] < itmp) {
				left++;
				while(left<right && vec[left]==vec[left-1])
					left++;
			}
			else {
				right--;
				while(left<right && vec[right] == vec[right+1])
					right--;
			}
		}
	}
}

int main(void)
{
	int num;
	std::vector<int> vec;
	while(std::cin>>num) {
		vec.push_back(num);
	}
	std::vector<std::vector<int> > ret = foo(vec);
	for(size_t i = 0; i < ret.size(); ++i) {
		for(size_t j = 0; j < ret[i].size(); ++j) {
			std::cout<< ret[i][j] << " ";
		}
		std::cout<< std::endl;
	}
	return 0;
}

