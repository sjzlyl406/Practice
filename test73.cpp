/*************************************************************************
	> File Name: test73.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 20时32分48秒
 ************************************************************************/

/****************************************************************
 * 输入包括多个行数，首先给出整数N（1<N<10000），接着给出N行文字，
 * 每一行文字至少包括一个字符，至多100个字符。
 * 如果给定文字中“t”（或“T”）的出现次数比“s”（或“S”）多，则可能为英文，
 * 否则可能为德文。输出包括一行，
 * 如果输入文字可能为英文，则输出English，否则输出Deutsch。
 * ***********************************************************/
#include<iostream>
#include<algorithm>
#include<string>

/************** first: ***************/
inline bool istOrT(const char c)
{
	return (c =='t' || c == 'T');
}
inline bool issOrS(const char c)
{
	return (c =='s' || c == 'S');
}
/************** second ****************/
class isChar
{
	public:
		isChar(char cc):c(cc){}
		bool operator()(const char &c2) {
			return (c2==c || c2==(c-'a'+'A'));
		}
	private:
		char c;
};

int main(void)
{
	int n;
	std::string str;
	int count1(0), count2(0);
	
	std::cin >> n ;
	std::cin.clear();
	std::cout << n << std::endl;
	std::cin.get();

	for(int i = 0; i < n; ++i) {
		getline(std::cin, str);
		count1 += count_if(str.begin(), str.end(), isChar('t'));
		count2 += count_if(str.begin(), str.end(), isChar('s'));
	}

	count1 > count2 ?
		std::cout << "english" << std::endl :
		std::cout << "Deutsch" << std::endl ;
	return 0;
}
