/*************************************************************************
	> File Name: test75.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月09日 星期四 21时28分13秒
 ************************************************************************/

/*********************************************************************
 * 在路由器中，一般来说转发模块采用最大前缀匹配原则进行目的端口查找，具体如下：
 * IP地址和子网地址匹配：
 * IP地址和子网地址所带掩码做AND运算后，得到的值与子网地址相同，则该IP地址与该子网匹配。
 * 
 * 比如：
 * IP地址：192.168.1.100
 * 子网：192.168.1.0/255.255.255.0，其中192.168.1.0是子网地址，255.255.255.0是子网掩码。
 * 192.168.1.100&255.255.255.0 = 192.168.1.0，则该IP和子网192.168.1.0匹配
 * IP地址：192.168.1.100
 * 子网：192.168.1.128/255.255.255.192
 * 192.168.1.100&255.255.255.192 = 192.168.1.64，则该IP和子网192.168.1.128不匹配
 * 最大前缀匹配：
 * 任何一个IPv4地址都可以看作一个32bit的二进制数，
 * 比如192.168.1.100可以表示为：11000000.10101000.00000001.01100100，
 * 192.168.1.0可以表示为11000000.10101000.00000001.00000000
 * 最大前缀匹配要求IP地址同子网地址匹配的基础上，二进制位从左到右完全匹配的位数尽量多（从左到右子网地址最长）。比如：
 * IP地址192.168.1.100，同时匹配子网192.168.1.0/255.255.255.0和子网192.168.1.64/255.255.255.192，
 * 但对于子网192.168.1.64/255.255.255.192，匹配位数达到26位，多于子网192.168.1.0/255.255.255.0的24位，因此192.168.1.100最大前缀匹配子网是192.168.1.64/255.255.255.192。
 * 示例 
 * 输入：
 * ip_addr = "192.168.1.100"
 * net_addr_array[] =
 * {
 * "192.168.1.128/255.255.255.192",
 * "192.168.1.0/255.255.255.0",
 * "192.168.1.64/255.255.255.192",
 * "0.0.0.0/0.0.0.0",
 * ""
 * }
 * 输出：n = 2
 * ****************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

void toNum(std::string str,unsigned int *num)
{
	std::stringstream ss(str);
	char c;
	ss >> num[0] >> c >> num[1] >> c >> num[2] >> c >> num[3];
}
bool isMatch(unsigned int *ipnum, unsigned int *net, unsigned int *mat)
{
	bool ret = true;
	for(int i = 0; i < 4; ++i) {
		if((ipnum[i]&mat[i]) != (net[i]&mat[i]))
			ret = false;
	}
	return ret;
}
bool isMaxMatch(const std::string &str1, const std::string &str2)
{
	size_t index = str1.find('/');
	std::string netstr1(str1.substr(index+1));
	index = str2.find('/');
	std::string netstr2(str2.substr(index+1));

	return netstr1 > netstr2;
}
int ip(std::string ipstr, std::vector<std::string> netvec)
{
	unsigned int ipnum[4] = {0};
	unsigned int net[4] = {0};
	unsigned int mat[4] = {0};
	int ret = -1;
	size_t index = 0;
	toNum(ipstr, ipnum);

	for(index = 0; index != netvec.size(); ++index) {
		size_t Dash = netvec[index].find('/');
		toNum(netvec[index].substr(0, Dash), net);
		toNum(netvec[index].substr(Dash+1), mat);

			std::cout << net[3] << mat[3] << ipnum[3]<< std::endl;

		if(isMatch(ipnum, net, mat)) {
			if(ret == -1)
				ret = index;
			else {
				if(isMaxMatch(netvec[index], netvec[ret]))
					ret = index;
			}
		}
	}
	return ret+1;
}

int main(void)
{
	std::string ip_addr;
	std::vector<std::string> net_addr_array;
	std::string tmp;
	std::cin >> ip_addr;
	std::cin.get();
	while(std::cin >> tmp) {
		net_addr_array.push_back(tmp);
	}
	int n = ip(ip_addr, net_addr_array);
	std::cout << n << std::endl;
	return 0;
}
