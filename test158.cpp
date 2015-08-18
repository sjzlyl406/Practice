/*************************************************************************
	> File Name: test158.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时13分08秒
 ************************************************************************/

/******************************************************************
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int left(0), right(array.size()-1);
        vector<int> result;
         
        while (left < right) {
            if(array[left] + array[right] == sum) {
                result.push_back(array[left]);
                result.push_back(array[right]);
                return result;
            } else if (array[left] + array[right] > sum) {
                right--;
            } else {
                left++;
            }
        }
         
        return result;
    }
};
