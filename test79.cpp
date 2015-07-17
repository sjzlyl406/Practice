/*************************************************************************
	> File Name: test79.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月11日 星期六 21时12分09秒
 ************************************************************************/

/***********************************************************
 * 输入一个数字，转换为时间，按DDD：HH：MM：SS的格式输出
 * 例如：输入100000 显示001:03:46:40
 * **********************************************************/
#include<iostream>
#include<string>
#include<sstream>

void Zero(std::string &str, int n)
{
	while(str.size() < n) {
		str.insert(str.begin(), '0');
	}
}
std::string foo(int second)
{
	std::string DDD, HH, MM, SS;
	std::stringstream ss;
	ss << (second / (60*60*24));
	ss >> DDD;
	Zero(DDD, 3);
	ss.clear();
	second %= (60*60*24);
	ss << ((second / (60*60)));
	ss >> HH;
	Zero(HH, 2);
	ss.clear();
	second %= (60*60);
	ss << (second / 60);
	ss >> MM;
	Zero(MM, 2);
	ss.clear();
	second %= 60;
	ss << second;
	ss >> SS;
	Zero(SS, 2);
	ss.clear();

	std::string result;
	result += DDD + ":" + HH + ":" + MM + ":" + SS;

	return result;
}
int main(void)
{
	int num;
	std::cin >> num;
	std::cout << foo(num) << std::endl;
	return 0;
}

