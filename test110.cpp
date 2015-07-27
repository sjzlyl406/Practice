
/*************************************************************************
	> File Name: test110.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 18时36分24秒
 ************************************************************************/

/************************************************************************
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * ********************************************************************/

#include<iostream>

class Solution {
private:
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        string path;
        dfs(n, 0, 0, path);
        return result;
    }
    
private:
    void dfs(const int &n, int left_count, int right_count, string &path) {
        if(path.size() == n * 2) {
            result.push_back(path);
            return;
        }
        
        if(left_count == right_count) {
            path.append("(");
            dfs(n, left_count+1, right_count, path);
            path.erase(prev(path.end()));
        }
        else if(left_count > right_count) {
            if(left_count < n) {
                path.append("(");
                dfs(n, left_count+1, right_count, path);
                path.erase(prev(path.end()));
            }
            path.append(")");
            dfs(n,left_count, right_count+1, path);
            path.erase(prev(path.end()));
        }
    }
};
