/*************************************************************************
	> File Name: test84.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月17日 星期五 19时51分47秒
 ************************************************************************/

/******************************************************************
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
 * target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * *****************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

/*************** first:O(n^3) *****************/
int foo(const std::vector<int> &vec, int target)
{
	int iSum (1000);
	int iCurSum (0);
	for(size_t i = 0; i < vec.size()-2; ++i) {
		for(size_t j = i+1; j < vec.size()-1; ++j) {
			for(size_t k = j+1; k < vec.size(); ++k) {
				iCurSum = vec[i] + vec[j] + vec[k];
				if(fabs(target - iCurSum) < fabs(target - iSum))
					iSum = iCurSum;
			}
		}
	}
	return iSum;
}

/*************** second:O(n^2) ******************/
int foo2(std::vector<int> &vec, int target)
{
	int iSum (1000);
	int iCurSum (0);
	sort(vec.begin(), vec.end());
	for(size_t i = 0; i < vec.size(); ++i) {
		int left = i+1, right = vec.size()-1;
		while(left < right) {
			iCurSum = vec[i] + vec[left] + vec[right];
			if(iCurSum == target) {
				return iCurSum;
			}
			else if(fabs(iCurSum-target) < fabs(iSum-target)) {
				iSum = iCurSum;
			}
			if(iCurSum > target)
				right--;
			else
				left++;
		}
	}
	return iSum;
}

int main(void)
{
	int num;
	std::vector<int> vec;
	while(std::cin >> num) {
		vec.push_back(num);
	}
	std::cout<< foo(vec, 1) << std::endl;
	std::cout<< foo2(vec, 1) << std::endl;

	return 0;
}
