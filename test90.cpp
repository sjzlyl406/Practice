/*************************************************************************
	> File Name: test90.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月21日 星期二 21时50分13秒
 ************************************************************************/

/************************************************************************
 *  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * **********************************************************************/
#include<iostream>
class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(size_t i = 0; i != s.size(); ++i) {
            switch (s[i]) {
                case '(' :{
                    Stack.push(s[i]);
                    break;
                }
                case ')' : {
                    if(Stack.empty() || Stack.top() != '(')
                        return false;
                    Stack.pop();
                    break;
                }
                case '[' :
                case '{' : {
                    Stack.push(s[i]);
                    break;
                }
                case ']' :
                case '}' : {
                    if(Stack.empty() || Stack.top() != (char)(s[i]-2))
                        return false;
                    else
                        Stack.pop();
                    break;
                }
                default :
                    break;
            }
        }
        if(Stack.empty())
            return true;
        else
            return false;
    }
};
