/*************************************************************************
	> File Name: test30.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 11时12分34秒
 ************************************************************************/

/*************************************************************
 * 输入两行字符串正整数，第一行是被减数，第二行是减数，
 * 输出第一行减去第二行的结果。
 * **********************************************************/
#include<iostream>
#include<sstream>
using namespace std;

int main(void)
{
	stringstream ss;
	string s1,s2;
	cin >> s1 >> s2;

	long long l1, l2;

	ss << s1;
	ss >> l1;

	ss.clear();

	ss << s2;
	ss >> l2;

	cout << l1 - l2 << endl;

	return 0;
}

