/*************************************************************************
	> File Name: test33.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 15时03分25秒
 ************************************************************************/

/***************************************************************
 * 删除子串，只要是原串中有相同的子串就删掉，不管有多少个都删除，返回子串个数。
 * 输入字符串为：123abc12de234fg1hi34j123k，子串为：123
 * 则输出为：abc12de234fg1hi34jk   2
 * ************************************************************/
#include<iostream>
#include<string>
#include<algorithm>

int deleteSubString(std::string &str, std::string substr)
{
	int count = 0;
	size_t len = substr.size();
	size_t pos = str.find(substr);

	while(pos != std::string::npos){
		str.erase(pos, len);
		count++;
		pos = str.find(substr);
	}
	
	return count;
}
int main(void)
{
	std::string str, substr;
	std::cout<<"input a string:";
	std::cin>>str;
	std::cout<<"input a substring:";
	std::cin>>substr;

	int count = deleteSubString(str, substr);

	std::cout<<str<<":"<<count<<":"<<substr<<std::endl;

	return 0;
}

