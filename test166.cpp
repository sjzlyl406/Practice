/*************************************************************************
	> File Name: test166.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月20日 星期四 15时43分15秒
 ************************************************************************/

/******************************************************************
 * 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1
 * ***************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0) return -1;
         
        char mapp[500]={0};
        for (auto &i : str) {
            mapp[i]++;
        }
         
        for (int i = 0; i < str.size(); ++i) {
            if (mapp[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
