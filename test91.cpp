/*************************************************************************
	> File Name: test91.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月21日 星期二 22时02分33秒
 ************************************************************************/

/***********************************************************************
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
 * *******************************************************************/
#include<iostream>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if(len2 <= len1) {
            for(int i = 0; i <= (len1-len2); ++i) {
                bool flag = true;
                for(int j = 0; j != len2; ++j) {
                    if(needle[j] != haystack[i+j])
                        flag = false;
                }
                if(flag)
                    return i;
            }
        }
        return -1;
    }
};
