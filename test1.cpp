/*************************************************************************
	> File Name: test1.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 12时39分01秒
 ************************************************************************/

/******************************************************
 * 统计数字在排序数组中出现的次数。
 * 如输入排序数组{1,2,3,3,3,3,4,5} 和数字3
 * 输出 4
 * ****************************************************/

#include<iostream>
#include<vector>
#include<stdexcept>
//#include<exception>
#include<algorithm>

int CountNum(const std::vector<int> &array, int K)
{
	if(array.size() <= 0)
		throw std::runtime_error("array is empty!");

	std::vector<int>::const_iterator iter = array.begin();
	iter = find(array.begin(), array.end(), K);

	int count = 0;
	while(iter != array.end() && *iter == K) {
		count++;
		iter++;
	}
	
	return count;
}

int main(int argc, char* argv[])
{
	const int MaxLen = 8;
	int array[MaxLen] = {1,2,3,3,3,3,4,5};
	std::vector<int> vec(array, array+MaxLen);

	try{
		int K = 3;
		std::cout << K << " : " << CountNum(vec, K) <<std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
