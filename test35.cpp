/*************************************************************************
	> File Name: test35.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 15时42分19秒
 ************************************************************************/

/**************************************************************
 * 在给定字符串中找出单词（“单词”由大写字母和小写字母字符构成，
 * 其他非字母字符视为单词的间隔，如空格、问号、数字等等；
 * 另外单个字母不算单词）；找到单词后，按照长度进行降序排序，
 * （排序时如果长度相同，则按出现的顺序进行排列），
 * 然后输出到一个新的字符串中；如果某个单词重复出现多次，则只输出一次；
 * 如果整个输入的字符串中没有找到单词，请输出空串。
 * 输出的单词之间使用一个“空格”隔开，最后一个单词后不加空格.
 * **********************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>

int cmp(std::string str1, std::string str2)
{
	if(str1.size() < str2.size())
		return 0;
	else if(str1.size() > str2.size())
		return 1;
	else{
		if(str1 == str2)
			return 3;
		else
			return 4;
	}
}

void sort(std::vector<std::string> &vec)
{
	size_t len = vec.size();
	size_t i = 0, j = 0;
	for(i = 0; i < len-1; ++i) {
		for(j = i+1; j < len; ++j) {
			if(cmp(vec[i], vec[j]) == 0) {
				std::string tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
			}
		}
	}

}

std::string foo(std::string str)
{
	std::vector<std::string> vec;
	size_t i = 0;
	std::string tmp;
	for(i = 0; i < str.size(); ++i) {
		if(isalpha(str[i])) {
			tmp += str[i];
		}
		else {
			if(!tmp.empty()  &&
				find(vec.begin(), vec.end(), tmp) == vec.end()) {
					vec.push_back(tmp);
			}
			tmp.clear();
		}
	}
	sort(vec);

	std::string result;
	for(i = 0; i < vec.size()-1; ++i) {
		result += vec[i];
		result+=" ";
	}
	result += vec[i];

	return result;
}

int main(void)
{
	std::vector<std::string> vec;
	vec.push_back("helo");
	vec.push_back("world");
	vec.push_back("worll");
	vec.push_back("dsfa");

	std::string str = "hello wrold is our. hello language did you know!";
	std::string result = foo(str);
	std::cout<<result<<std::endl;

//	for(int i = 0; i < vec.size(); ++i)
//		std::cout<< vec[i] << std::endl;

	return 0;
}
