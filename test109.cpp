/*************************************************************************
	> File Name: test109.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月26日 星期日 23时18分26秒
 ************************************************************************/

/*************************************************************************
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * **********************************************************************/
#include<iostream>
#include<cstdio>
#include<string>
using std::string;

/**************** first ******************/
//判断所有条件，容易想，易出错。
class Solution {
public:
    int romanToInt(string s) {
       	 int ret = 0;
        
        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == 'M') ret += 1000;
            else if(s[i] == 'C') {
                if(i+1 < s.size() && s[i+1] == 'M') {ret += 900; i++;}
                else if(i+1 < s.size() && s[i+1] == 'D') {ret += 400; i++;}
                else ret += 100;
            }
            else if(s[i] == 'D') ret += 500;
            else if(s[i] == 'X') {
                if(i+1 < s.size() && s[i+1] == 'C') { ret+= 90;i++;}
                else if(i +1 < s.size() && s[i+1] == 'L') {ret+=40; i++;}
                else ret+= 10;
            }
            else if(s[i] == 'L') ret += 50;
            else if(s[i] == 'I') {
                if(i+1 < s.size() && s[i+1] == 'X') {ret += 9; i++;}
                else if (i+1 < s.size() && s[i+1] == 'V') { ret+= 4; ++i;}
                else ret+= 1;
            }
            else if(s[i] == 'V') ret += 5;
        }
        
        
        return ret;
    }
};

/************ second *************/
//记录前一个值，如果前一个值小于当前值，则用当前值减去前一个值。
class Solution {
public:
    int romanToInt(string s) {
        const int radix[] = {1000,  500, 100, 50, 10, 5,  1};
        const char* symbols[] = {"M","D","C","L","X","V","I"};
        
        int pre_num = 1000;
        int result = 0;
        
        for(size_t j = 0; j < s.size(); ++j) {
            for(int i = 0; i < 13; ++i) {
                if(s[j] == *symbols[i]) {
                    int cur_num = radix[i];
                    if(pre_num < cur_num) {	//两个子母表示一个数字
                        result -= pre_num;
                        pre_num = cur_num - pre_num;
                    }
                    else pre_num = cur_num;	//一个字母表示一个数字
                    result += pre_num;
                    break;
                }
            }
            
        }
        
        return result;
    }
};


int main(void)
{
	string str = "MCMXCVI";
	Solution ss;
	printf("%d\n", ss.romanToInt(str));
	return 0;
}
