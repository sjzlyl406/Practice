/*************************************************************************
	> File Name: test156.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时12分19秒
 ************************************************************************/

/******************************************************************
 * JOBDU最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        reverse(str.begin(), str.end());
        int left(0), right(0);
        for (right = 0; right < str.size(); ++right) {
            if (str[right] == ' ' ) {
                reverse(str.begin() + left, str.begin() + right);
                left = right + 1;
            }
        }
        if(left < str.size())
            reverse(str.begin() + left, str.end());;
        return str;
    }
};
