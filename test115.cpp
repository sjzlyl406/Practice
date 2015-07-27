/*************************************************************************
	> File Name: test115.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 20时11分56秒
 ************************************************************************/

/**********************************************************************
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * ******************************************************************/
#include<iostream>

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ret;
        if(a.size() < b.size()) swap(a, b);
        
        int index_a = a.size()-1;
        int index_b = b.size() - 1;
        
        while(index_a >= 0) {
            int tmp;
            if(index_b >= 0)
                tmp = (a[index_a]-'0') + (b[index_b]-'0') + carry;
            else
                tmp = (a[index_a]-'0') + carry;
            if(tmp > 1) {
                carry = 1;
                tmp %= 2;
            }
            else carry = 0;
            ret += tmp + '0';
            index_a--;  index_b--;
        }
        
        if(carry) {
            ret += '1';
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
