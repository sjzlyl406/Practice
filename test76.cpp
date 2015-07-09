/*************************************************************************
	> File Name: test76.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 22时47分51秒
 ************************************************************************/

/***********************************************************************
 * 有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。现在，修改过的那个单词死于字母表的下面，如下所示：
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 * T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
 * 上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。请实现下述接口，通过指定的密匙和明文得到密文。详细描述：接口说明：
 * 输入:先输入key和要加密的字符串  
 * 输出:返回加密后的字符串  
 * 样例输入: 
 * nihao
 * ni                    
 * 样例输出: le
 * ******************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

class Safty{
public:
	Safty(std::string kk):key(kk){}

	std::string Solution(const std::string &str);
private:
	std::string key;
	std::string lowerMap;
	std::string upperMap;

private:
	void ss();
};
void Safty::ss()
{
	std::string map = "abcdefghijklmnopqrstuvwxyz";
	key.erase(unique(key.begin(),key.end()), key.end());
	for(size_t i = 0; i < key.size(); ++i) {
		map.erase(map.find(key[i]),1);
	}
	lowerMap = lowerMap + key + map;
	for(size_t i = 0; i < lowerMap.size(); ++i) {
		upperMap += toupper(lowerMap[i]);
	}
}
std::string Safty::Solution(const std::string &str)
{
	ss();
	size_t i = 0;
	std::string ret;
	for(i = 0; i < str.size(); ++i) {
		if(islower(str[i]))
			ret += lowerMap[str[i]-'a'];
		else if(isupper(str[i]))
			ret += upperMap[str[i]-'A'];
		else
			ret += str[i];
	}
	return ret;
}

int main(void)
{
	std::string key;
	std::string word;
	std::cin >> key;
	std::cin.get();
	getline(std::cin, word);

	Safty ss(key);
	std::cout << ss.Solution(word) << std::endl;
	return 0;
}
