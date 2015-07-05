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
 **************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main(void)
{
	int N;
	std::cin >> N;
	std::string str;
	std::vector<int> veccount;
	for( int i = 0; i < N; ++i) {
		std::cin >> str;
		veccount.push_back(str.size());
	}

	sort(veccount.begin(), veccount.end());
	std::vector<int>::iterator iter, i;
	iter = unique(veccount.begin(), veccount.end());

	int result = 0 , m = 26;
	i = veccount.begin();
	for(iter = iter-1; iter >= i; --iter) {
		result += *iter * m--;
	}
	
	std::cout  << result << std::endl;
	return 0;
}
