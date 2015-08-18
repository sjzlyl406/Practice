/*************************************************************************
	> File Name: test147.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时02分54秒
 ************************************************************************/

/******************************************************************
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == '\0') return false;
        bool hasdot = false;
        bool hasexp = false;
         
        if (*string == '-' || *string == '+') ++string;
         
        while(*string != '\0') {
            if (*string == '.') {
                if (hasdot || hasexp)
                    return false;
                hasdot = true;
            }
            else if (*string == 'e' || *string == 'E') {
                if (hasexp)
                    return false;
                hasexp = true;
                if (*(string+1) == '-' || *(string+1) == '+')
                    string++;
                if (*(string+1) == '\0') return false;
            }
            else if ((*string) > '9' || (*string) < '0') {
                return false;
            }
            ++string;
        }
        return true;
    }
 
};
