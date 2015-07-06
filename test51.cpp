/*************************************************************************
	> File Name: test51.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 08时01分20秒
 ************************************************************************/

/*************************************************************
 * 判断是否为回文数组（无论从左到右还是从右到左读出来都一样的）。
 * *********************************************************/
#include<iostream>
#include<string>

bool isPalindrome(std::string str) 
{
	size_t left = 0;
	size_t right = str.size() - 1;

	bool result = true;
	while(left < right) {
		if(str[left] != str[right])
			result = false;
		left++;
		right--;
	}
	return result;
}

int main(void)
{
	std::string str;
	std::cin >> str;

	std::cout << std::boolalpha << isPalindrome(str) << std::endl;

	return 0;
}
