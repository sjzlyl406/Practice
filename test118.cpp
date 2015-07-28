/*************************************************************************
	> File Name: test118.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月28日 星期二 22时39分44秒
 ************************************************************************/

/****************************************************************
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 *
 *
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 * [[1,2,4]]
 *
 * Example 2:
 *
 * Input: k = 3, n = 9
 *
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 * ***************************************************************/
#include<iostream>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(k, 1, n, 0, path);
        return result;
    }
    
    void dfs(int k, int left, int right, int loop, vector<int> &path) {
        if(k == loop && right == 0) {
            result.push_back(path);
            return;
        }
        
        for(int i = left; i <= min(right,9); ++i) {
            path.push_back(i);
            dfs(k, i+1, right-i, loop+1, path);
            path.pop_back();
        }
    }
    
private:
    vector<vector<int> > result;
};

