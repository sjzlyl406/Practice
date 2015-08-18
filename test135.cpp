/*************************************************************************
	> File Name: test135.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时41分26秒
 ************************************************************************/

/********************************************************************
 * 设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，
 * 向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，
 * 则该路径不能再进入该格子。 
 * 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，
 * 但是矩阵中不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
 * 路径不能再次进入该格子。""""
 * ******************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        char *mmap = new char[rows*cols];
        memset(mmap, 1, rows*cols*sizeof(char));
        bool ret(false);
         
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (*(matrix+j+i*cols) == *str) {
                    memset (mmap, 1, rows*cols*sizeof(char));
                    *(mmap+j+i*cols) = 0;
                    ret = dfs (matrix, rows, cols, str+1, mmap, i, j);
                    if (ret)
                        return ret;
                }
            }
        }
         
        return ret;
    }
private:
    bool dfs (char* matrix, int rows, int cols, char*str, char* mmap, int x, int y) {
        if (*str == '\0') return true;
         
        bool up(false), down(false), left(false), right(false);
        //up
        if (*(mmap+y+(x-1)*cols) && x > 0 && *(matrix+y+(x-1)*cols) == *str) {
            *(mmap+y+(x-1)*cols) = 0;
            up = dfs (matrix, rows, cols, str+1, mmap, x-1, y);
        }
        //down
        if (*(mmap+y+(x+1)*cols) && x < rows-1 && *(matrix+y+(x+1)*cols) == *str) {
            *(mmap+y+(x+1)*cols) = 0;
            down = dfs (matrix, rows, cols, str+1, mmap, x+1, y);
        }
        //left
        if (*(mmap+y-1+x*cols) && y > 0 && *(matrix+y-1+x*cols) == *str) {
            *(mmap+y-1+x*cols) = 0;
            left = dfs (matrix, rows, cols, str+1, mmap, x, y-1);
        }
        //right
        if (*(mmap+y+1+x*cols) && y < cols-1 && *(matrix+y+1+x*cols) == *str) {
            *(mmap+y+1+x*cols) = 0;
            right = dfs (matrix, rows, cols, str+1, mmap, x, y+1);
        }
         
        return up || down || left || right;
    }
 
};

