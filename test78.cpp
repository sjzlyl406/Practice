/*************************************************************************
	> File Name: test78.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 23时27分38秒
 ************************************************************************/

/***************************************************************
 *	统计一个数二进制表达中0的个数（首位1之前0不计）。
 * *********************************************************/
#include<iostream>
#include<cmath>

int main(void)
{
	int num;
	std::cin >> num;
	unsigned int mm = 0x1;
	num = fabs(num);
	unsigned int unum = num;
	std::cout<<"unsigned int :" << unum << std::endl;

	int count = 0;
	while(num) {
		if((num & mm) == 0 )
			count++;
		num = num >> 1;
	}
	std::cout << count <<std::endl;
	return 0;
}
