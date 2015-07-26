/*************************************************************************
	> File Name: test102.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月23日 星期四 23时33分11秒
 ************************************************************************/

/**********************************************************************
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.""""
 * ********************************************************************/
#include<iostream>
#include<cctype>	//isalnum() tolower()

class Solution {
	public:
		bool isPalindrome(string s) {
			int left = 0, right = s.size() - 1;

			bool ret = true;
			while(left < right) {
				while(left < right && !isalnum(s[left])) left++;
				while(left < right && !isalnum(s[right])) right++;

				s[left]=tolower(s[left]);	s[right]=tolower(s[right]);
				if(s[left] != s[right]) {
					ret = false;
					break;
				}
				left++;	right--;
			}
			return ret;
		}
};
