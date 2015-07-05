/*************************************************************************
	> File Name: test48.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 22时45分18秒
 ************************************************************************/

/********************************************************************
 * 将整数倒序输出，剔除重复数据
 * 输入一个整数，如12336544，或1750，然后从最后一位开始倒过来输出，
 * 最后如果是0，则不输出，输出的数字是不带重复数字的，
 * 所以上面的输出是456321和571。如果是负数，比如输入-175，输出-571。
 * *****************************************************************/
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

int Reverse(int m) 
{
	std::stringstream ss;
	std::string str;
	ss << m;
	ss >> str;

	size_t i = 0;
	std::string result;
	if(str[0] == '-') {
		i = 1;
	}
	reverse(str.begin() + i, str.end());
	std::string::iterator iter = unique(str.begin(), str.end());
	size_t dis = distance(str.begin(), iter);

	result = str.substr(0, dis);
	std::cout << result << std::endl;

	ss.clear();
	ss << result;
	int ret ;
	ss >> ret;

	return ret;

}

int main(void)
{
	int m;
	std::cin >> m;

	int result = Reverse(m);

	std::cout << result << std::endl;

	return 0;
}
