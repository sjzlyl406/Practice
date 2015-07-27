/*************************************************************************
	> File Name: test108.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月26日 星期日 23时06分31秒
 ************************************************************************/

/*********************************************************************
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * ******************************************************************/
#include<iostream>

class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500,400,100,90,50,40,10,9,5,4,1};
        const string symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ret;
        while(num) {
            for(int i = 0; i < 13; ++i) {
                if(num >= radix[i]) {
                    ret.append(symbols[i]);
                    num -= radix[i];
                    break;
                }
            }
        }
        return ret;
    }
};
