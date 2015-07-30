/*************************************************************************
	> File Name: test49.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 23时01分30秒
 ************************************************************************/

/****************************************************************
 * 名字的漂亮度=26*字母个数最多的+25*字母个数其次的+24*字母个数再其次的
 * (忽略大小写)+....+1*出现次数最小的。
 * 输入：整数N，N个字符串
 * 输出：N个字符串漂亮度
 * 例如：输入1 a 输出 26
 * *************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int cmp(int a, int b) 
{
	return a > b;
}

int Beauty(std::string str) 
{
	int map[26] = {0};
	for(size_t i = 0; i < str.size(); ++i) {
		map[tolower(str[i]) - 'a']++;
	}
	sort(map, map+26, cmp);
	int result = 0;
	for(int i = 0; i < 26; ++i) {
		result += map[i] * (26-i);
	}
	return result;
}

int main(void)
{
	int N;
	std::cin >> N;
	std::string str;
	
	int *array = new int[N];
	for(int i = 0; i < N; ++i) {
		std::cin >> str;
		array[i] = Beauty(str);
	}

	for(int i = 0; i < N; ++i) {
		std::cout << array[i] << '\t';
	}

	std::cout  << std::endl;
	return 0;
}
