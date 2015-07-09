/*************************************************************************
	> File Name: test72.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 20时08分09秒
 ************************************************************************/

/***********************************************************************
 * 编程的时候，if条件里面的“(”、“)”括号经常出现不匹配的情况导致编译不过，请编写程序检测输入一行if语句中的圆括号是否匹配正确。同时输出语句中出现的左括号和右括号数量，如if((a==1)&&(b==1))是正确的，而if((a==1))&&(b==1))是错误的。注意if语句的最外面至少有一对括号。
 * 输入：if((a==1)&&(b==1))
 * 输出：RIGTH 3 3
 * 输入：if((a==1))&&(b==1))
 * 输出：WRONG 3 4
 * *********************************************************************/
#include<iostream>
#include<string>

class Judge {
	public:
		Judge(std::string str1=""):str(str1),leftcount(0),rightcount(0){}
		void Result();

	private:
		const std::string str;
		int leftcount;
		int rightcount;

	private:
		void Print(std::ostream& os, bool flag) const;
};
void Judge::Result()
{
	std::string::size_type index(0);
	int count(0);
	bool ret = true;
	index += 2;
	if(str[index] != '(')
		ret = false;
	for(index = 2; index != str.size(); ++index) {
		if(str[index] == '(') {
			leftcount++;
			count++;
		}
		if(str[index] == ')') {
			rightcount++;
			if(count == 0)
				ret = false;
			else
				count--;
		}
	}
	if(count || str[index-1] != ')')
		ret = false;
	Print(std::cout, ret);

}
inline void Judge::Print(std::ostream& os, bool flag) const
{
	if(flag)
		os << "RIGTH " << leftcount << " " << rightcount << std::endl;
	else
		os << "WRONG " << leftcount << " " << rightcount << std::endl;
}

int main(void)
{
	std::string str;
	while(std::cin >> str) {
		if(str == "exit")
			break;
		Judge instance(str);
		instance.Result();
	}
	return 0;
}
