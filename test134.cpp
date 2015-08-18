/*************************************************************************
	> File Name: test134.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时39分49秒
 ************************************************************************/

/********************************************************************
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 * 每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。 
 * 例如，当k为18时，机器人能够进入方格（35,37），
 * 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
 * 因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * *****************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0) return 0;
         
        int count(0);
        char *mmap = new char[rows*cols];
        memset (mmap, 1, rows*cols*sizeof(char));   //1没走过，0走过
         
        dfs (threshold, rows, cols, count, 0, 0, mmap);
         
        return count;
    }
private:
    void dfs (int threshold, int rows, int cols, int &count, int x, int y, char* mmap) {
        count++;
        *(mmap+y+x*cols) = 0;   //标记走过
         
        //up
        if (x > 0 && *(mmap+y+(x-1)*cols) && judge(x-1, y, threshold)) {
            dfs (threshold, rows, cols, count, x-1, y, mmap);
        }
        //down
        if (x < rows-1 && *(mmap+y+(x+1)*cols) && judge(x+1, y, threshold)) {
            dfs (threshold, rows, cols, count ,x+1, y, mmap);
        }
        //left
        if (y > 0 && *(mmap+(y-1)+x*cols) && judge(x, y-1, threshold)) {
            dfs (threshold, rows, cols, count, x, y-1, mmap);
        }
        //right
        if (y < cols-1 && *(mmap+(y+1)+x*cols) && judge(x, y+1, threshold)) {
            dfs (threshold, rows, cols, count, x, y+1, mmap);
        }
    }
     
    bool judge (int x, int y, int threshold) {
        int sum(0);
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= threshold;
    }
};
