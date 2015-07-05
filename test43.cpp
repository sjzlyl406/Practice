/*************************************************************************
	> File Name: test43.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 19时02分58秒
 ************************************************************************/

/******************************************************************
 * 实现输入一组大于等于0的整数，根据从小到大的顺序排序后输出，
 * 排序后有连续数时，只输出连续数中最小和最大的两个数。
 * 样例输入:	1,4,3,110,2,90,7
 * 样例输出:	1 4 7 90 110
 * ****************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

std::vector<int> foo(std::vector<int> vec)
{
	std::vector<int> ret;
	if(vec.size() == 0) return ret;

	sort(vec.begin(), vec.end());
	size_t i = 0;
	int m = vec[0]-2;
	bool state = false;

	for(i = 0; i < vec.size(); ++i) {
		if(++m == vec[i]) {
			m = vec[i];
			if(state == false) {
				state = true;
			}
		}
		else {
			if(state == true) {
				ret.push_back(--m);
				state = false;
			}
			m = vec[i];
			ret.push_back(m);
		}
	}
	if(state == true)
		ret.push_back(vec.back());

	return ret;
}
int main(void)
{
	std::vector<int> vec;
	int i = 1;

	while(std::cin >> i){
		vec.push_back(i);
		char c ;
		std::cin >>c;
	}

	for(int i = 0; i < vec.size(); ++i) 
		std::cout << vec[i] << " ";
	std::cout<<std::endl;

	vec = foo(vec);

	for(int i = 0; i < vec.size(); ++i) 
		std::cout << vec[i] << " ";

	std::cout<<std::endl;
	return 0;
}
