/*************************************************************************
	> File Name: test47.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 21时46分53秒
 ************************************************************************/

/****************************************************************
 * 输入一段英文文本，用程序统计出现频率最高和最低的两个单词;
 * 英文文本中仅出现这四类字符：空格( )、英文逗号(,)、英文句号(.)、英文大小写字母（a-z、A-Z）
 * 单词之间的分隔符仅考虑这三种：空格( )、英文逗号(,)、英文句号(.);
 * 仅大小写不同的单词算同一个单词；
 * 如果两个单词出现次数相同，则在文本中首次出现的单词优先返回。
 * 返回的单词统一用小写字母返回
 * 例如：
 * 输入字符串“Hello world, i said hello world to the world”，返回“world”,“i”
 * *************************************************************/
#include<iostream>
#include<cctype>
#include<string>
#include<map>

int main(void)
{
	std::string str;
	getline(std::cin, str);
	int len = str.size();

	std::string maxstr;
	std::string minstr;
	int mincount = 99;
	int maxcount = -1;

	int left = 0, right = 0;

	std::map<std::string, int> strmap;
	for(int i = 0; i <= len; ++i) {
		if(isalpha(str[i]))
			str[i] = tolower(str[i]);
		else if(i > 0 && isalpha(str[i-1])){
			right = i;
			std::string str2 = str.substr(left, right-left);
			strmap[str2]++;
			left = right + 1;
		}
	}
	std::map<std::string,int>::iterator iter;
	for(iter = strmap.begin(); iter != strmap.end(); ++iter) {
		if(iter -> second > maxcount) {
			maxcount = iter -> second;
			maxstr = iter -> first;
		}
		if(iter -> second < mincount) {
			mincount = iter -> second;
			minstr = iter -> first;
		}
	}
	std::cout << maxstr << ":" << minstr << std::endl;

	return 0;
}

