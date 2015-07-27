/*************************************************************************
	> File Name: test113.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 19时36分02秒
 ************************************************************************/

/**********************************************************************
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * ********************************************************************/
#include<iostream>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto index = next(nums.rbegin());
        while(index != nums.rend()) {
            if(*index >= *prev(index)) ++index;
            else break;
        }
        if(index == nums.rend())
            reverse(nums.begin(), nums.end());
        else {
            auto index2 = nums.rbegin();
            while(*index2 <= *index) ++index2;
            swap(*index2, *index);
            reverse(nums.rbegin(), index);
        }
    }
};

