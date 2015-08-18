/*************************************************************************
	> File Name: test136.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时42分52秒
 ************************************************************************/

/********************************************************************
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
 * 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
 * {[2,3,4],2,6,2,5,1}， 
 * {2,[3,4,2],6,2,5,1}， 
 * {2,3,[4,2,6],2,5,1}， 
 * {2,3,4,[2,6,2],5,1}， 
 * {2,3,4,2,[6,2,5],1}， 
 * {2,3,4,2,6,[2,5,1]}。
 * *****************************************************************/
#include<iostream>
using namespace std;



class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        if (num.size() == 0 ||  size < 1 || num.size() < size) return result;
        if (size == 1) return num;
         
        int left(0), right(size-1);
        int index = doindex(num, left, right);
         
        for ( ; right < num.size(); ++right, ++left) {
            if (index < left) {
                index = doindex (num, left, right);
            }
            else {
                if (num[index] < num[right]) {
                    index = right;
                }
            }
            result.push_back(num[index]);
        }
         
        return result;
    }
     
private:
    int doindex (const vector<int> & vec, int left, int right) {
        int index(left);
        for (int i = left+1; i <= right; ++i) {
            if (vec[index] < vec[i])
                index = i;
        }
        return index;
    }
};
