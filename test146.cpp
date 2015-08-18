/*************************************************************************
	> File Name: test146.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时02分30秒
 ************************************************************************/

/******************************************************************
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。"""""""
 * ***************************************************************/
#include<iostream>
using namespace std;


class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         vec.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char mmap[256] = {0};
         
        for (auto &i : vec) {
            mmap[i]++;
        }
         
        for (auto &i : vec) {
            if (mmap[i] == 1) {
                return i;
            }
        }
        return '#';
    }
private:
    vector<char> vec;
 
};
