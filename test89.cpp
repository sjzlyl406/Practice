/*************************************************************************
	> File Name: test89.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月21日 星期二 21时31分17秒
 ************************************************************************/

/***********************************************************************
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *         (-1, 0, 1)
 *         (-1, -1, 2)
 * *********************************************************************/
#include<iostream>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        const int target = 0;
       
        if(nums.size() >= 3) {
            for(size_t i = 0; i != nums.size()-2; ++i) {
                size_t left = i+1, right = nums.size()-1;
                if(i != 0 && nums[i] == nums[i-1]) continue;
                while(left < right) {
                    if(nums[left] + nums[right] + nums[i] == target) {
                        ret.push_back({nums[i], nums[left], nums[right]});
                        do{
                            left++;
                        }while(left < right && nums[left] == nums[left-1]);
                        do{
                            right--;
                        }while(left < right && nums[right] == nums[right+1]);
                    }
                    else if(nums[left] + nums[right] + nums[i] > target)
                        do{
                            right--;
                        }while(left < right && nums[right] == nums[right+1]);
                    else
                        do{
                            left++;
                        }while(left <right &&nums[left] == nums[left-1]);
                }
            }
        }
        return ret;
    }
};
