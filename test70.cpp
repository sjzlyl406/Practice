/*************************************************************************
	> File Name: test70.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 23时28分19秒
 ************************************************************************/

/********************************************************
 * 将 电话号码 one two...nine zero翻译成1  2...9 0
 * 中间会有double
 * 例如输入：OneTwoThree
 * 输出：123
 * 输入：OneTwoDoubleTwo
 * 输出：1222
 * 输入：1Two2 输出：ERROR
 * 输入：DoubleDoubleTwo 输出：ERROR
 * 有空格，非法字符，两个Double相连，Double位于最后一个单词，都错误，输出：ERROR
 * ******************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define DISTANCE (distance(map.begin(), \
			find(map.begin(),map.end(), vec[i])))

using namespace std;

void foo(const vector<string> &vec)
{
	enum _state {
		num,
		duplicate,
		blank
	}state = blank;
	
	vector<string> map;
	map.push_back("zero");
	map.push_back("one");
	map.push_back("two");
	map.push_back("three");
	map.push_back("four");
	map.push_back("five");
	map.push_back("six");
	map.push_back("eight");
	map.push_back("nine");
	vector<int> result;

	for(int i = 0; i < vec.size(); ++i) {
		switch(state) {
			case num : 
			case blank : {
				if(vec[i] == "double") {
					 state = duplicate;
				}
				else if(find(map.begin(),map.end(),vec[i]) != map.end()) {
					state = num;
					result.push_back(DISTANCE);
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
				break;
			}
			case duplicate : {
				if(find(map.begin(),map.end(),vec[i]) != map.end()) {
					state = num;
					result.push_back(DISTANCE);
					result.push_back(DISTANCE);
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
			}
		}
	}
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << '\t' << flush;
	}
}
int main(void)
{
	vector<string> svec;
	string strtmp;
	while(cin >> strtmp) {
		svec.push_back(strtmp);
	}

	foo(svec);
	return 0;
}
