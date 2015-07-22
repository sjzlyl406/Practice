/*************************************************************************
	> File Name: test97.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 22时36分32秒
 ************************************************************************/

/******************************************************************
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.""""""""""
 * ****************************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;


class Solution {
    enum _State {
        blank,
        num1,   //整数部分
        num2,   //小数部分
        num3,   //指数部分
        ex,		//指数符号
        dot,	//小数点
        fu1,	//开始+ -号
        fu2,	//指数后+ -号
        err,	//错误状态
        back_blank	//最后空格部分
    }state;
public:
    bool isNumber(string s) {
        state = blank;
        size_t i = 0;

		//去除开始空格
        while(isblank(s[i])) i++;
        
        for(; i < s.size(); ++i) {
            switch (state) {
                case blank : {
                    if(s[i] == '+' || s[i] == '-') state = fu1;
                    else if (isdigit(s[i])) state = num1;
                    else if(s[i] == '.' && isdigit(s[i+1])) state = dot;
                    else state = err;
                    break;
                }
                case fu1 : {
                    if(s[i] == '.' && isdigit(s[i+1])) state = dot;
                    else if (isdigit(s[i])) state = num1;
                    else state = err;
                    break;
                }
                case num1 : {
                    if(s[i] == '.') { state = dot;}
                    else if (isdigit(s[i])) state = num1;
                    else if (isblank(s[i])) state = back_blank;
                    else if ((s[i] == 'e' || s[i] == 'E')) state = ex;
                    else state = err;
                    break;
                }
                case dot : {
                    if(isdigit(s[i])) state = num2;
                    else if (s[i] == 'e' || s[i] == 'E') state = ex;
                    else if (isblank(s[i])) state = back_blank;
                    else state = err;
                    break;
                }
                case num2 : {
                    if(isdigit(s[i])) state = num2;
                    else if (s[i] == 'e' || s[i] == 'E') state = ex;
                    else if(isblank(s[i])) state = back_blank;
                    else state = err;
                    break;
                }
                case ex : {
                    if(s[i] == '+' || s[i] == '-') state = fu2;
                    else if (isdigit(s[i])) state = num3;
                    else state = err;
                    break;
                }
                case fu2 : {
                    if(isdigit(s[i])) state = num3;
                    else state = err;
                    break;
                }
                case num3 : {
                    if(isdigit(s[i])) { state = num3; }
                    else if (isblank(s[i])) state = back_blank;
                    else state = err;
                    break;
                }
                case err : {
                    return false;
                }
                case back_blank : {
                    if (isblank(s[i])) state = back_blank;
                    else state = err;
                    break;
                }
            }
        }
        if(state == err || state == blank || state == ex || state == fu2 || state == fu1)
            return false;
        return true;
    }
};


int main(void)
{
	string str = "3";
	Solution ss;
	printf("%d\n", ss.isNumber(str));
}
