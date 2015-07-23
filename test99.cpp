/*************************************************************************
	> File Name: test99.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月23日 星期四 21时48分31秒
 ************************************************************************/

/********************************************************************
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*
* Follow up:
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* *******************************************************************/
#include<iostream>
using namespace std;

/************ first: Space O(m+n) *************/
class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
        size_t row = matrix.size();
        size_t col = matrix[0].size();
        
        vector<int> vec_row(row, 0);
        vector<int> vec_col(col, 0);
        
        for(size_t i = 0; i < row; ++i) {
            for(size_t j = 0; j < col; ++j) {
                if(matrix[i][j] == 0) {
                    vec_row[i] = 1;
                    vec_col[j] = 1;
                }
            }
        }
        
        for(size_t i = 0; i < row; ++i) {
            for(size_t j = 0; j < col; ++j) {
                if(vec_row[i] || vec_col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



/************ second: Space O(1) *************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
        bool bool_row = false;	//记录第一列有没有0
        bool bool_col = false;	//记录第一行有没有0
        
        size_t row = matrix.size();
        size_t col = matrix[0].size();
        
        for(size_t i = 0; i < row; ++i) {	
            if(matrix[i][0] == 0)
                bool_row = true;
//            matrix[i][0] = 0;
        }
        for(size_t i = 0; i < col; ++i) {
            if(matrix[0][i] == 0)
                bool_col = true;
//            matrix[0][i] = 0;
        }
        
        for(size_t i = 1; i < row; ++i) {	//判断
            for(size_t j = 1; j < col; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(size_t i = 1; i < row; ++i) {
            for(size_t j = 1; j < col; ++j) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(bool_row) {
            for(size_t i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
        if(bool_col) {
            for(size_t i = 0; i < col; ++i) 
                matrix[0][i] = 0;
        }
    }
};
