/*************************************************************************
	> File Name: test160.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时14分04秒
 ************************************************************************/

/******************************************************************
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * ***************************************************************/
#include<iostream>
using namespace std;

/************ first *************/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
         
        int sum(0);
        for (auto &i : data) {
            sum ^= i;
        }
         
        int x = 0x01;
        while(sum & x == 0) x = x << 1;
         
        int left(0), right(data.size()-1);
        while (left < right) {
            while (left < data.size() && data[left] & x != 1) left++;
            while (right > 0 && data[right] & x != 0) right--;
            if (left < right) {
                swap (data[left++], data[right--]);
            }
        }
         
        *num1 = 0;  *num2 = 0;
        for (int i = 0; i < left; ++i) {
            *num1 = *num1 ^ data[i];
        }
        for (int i = left; i < data.size(); ++i) {
            *num2 = *num2 ^ data[i];
        }
         
        return;
    }
};
/************ second *************/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
         
        int num(0);
        for (auto &i : data) num ^= i;
         
        int x = 0x01;
        while ((num & x) == 0) x = x << 1;
         
        *num1 = 0;  *num2 = 0;
        for (auto &i : data) {
            if ( (x & i) == 0) (*num1) ^= i;
            else (*num2) ^= i;
        }
         
        return;
    }
};
