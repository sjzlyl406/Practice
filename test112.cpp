/*************************************************************************
	> File Name: test112.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 19时20分24秒
 ************************************************************************/

/*******************************************************************
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.'
 * *****************************************************************/
#include<iostream>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            //find the val from left
            while(left < nums.size() && nums[left] != val) ++left;
            
            //find the instances not of val
            while(right >= 0 && nums[right] == val) --right;
            
            if(left < right) swap(nums[left++], nums[right--]);
        }
        return right + 1;
    }
};
