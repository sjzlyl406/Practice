/*************************************************************************
	> File Name: test151.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时04分14秒
 ************************************************************************/

/******************************************************************
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        enum _state state = blank;
        for (int i = 0; i < str.size(); ++i) {
            switch (state) {
                case blank :
                case exponent :{
                    if (isdigit(str[i]))
                        state = num;
                    else if (str[i] == '+' || str[i] == '-') {
                        state = minus;
                    }
                    else
                        state = end;
                    break;
                }
                case minus : {
                    if ( isdigit(str[i]))
                        state = num;
                    else
                        state = end;
                    break;
                }
                case num : {
                    if (isdigit(str[i])) {
                        state = num;
                    } else if (str[i] == 'e') {
                        state = exponent;
                    } else
                        state = end;
                    break;
                }
                case end : {
                    return false;
                }
            }
        }
        stringstream ss(str);
        int ret(0);
        ss >> ret;
        return ret;
    }
     
private:
    enum _state{
        blank,
        num,
        minus,
        exponent,
        end
    };
};
