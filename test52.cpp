/*************************************************************************
	> File Name: test52.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 08时25分35秒
 ************************************************************************/

/***********************************************************************
 * 比较两个数组，要求从数组最后一个元素开始逐个元素向前比较，如果2个数组长度不等，则只比较较短长度数组个数元素。请编程实现上述比较，并返回比较中发现的不相等元素的个数
 * 比如：数组{1,3,5}和数组{77,21,1,3,5}按题述要求比较，不相等元素个数为0
 *       数组{1,3,5}和数组{77,21,1,3,5,7}按题述要求比较，不相等元素个数为3
 * ********************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>

int Compare(std::vector<int> vec1, std::vector<int> vec2) 
{
	if(vec1.size() >  vec2.size())
		swap(vec1, vec2);
	reverse(vec1.begin(), vec1.end());
	reverse(vec2.begin(), vec2.end());

	int result = 0;
	std::vector<int>::iterator iter1 = vec1.begin();
	std::vector<int>::iterator iter2 = vec2.begin();

	while(iter1 != vec1.end()) {
		if(*iter1 != *iter2)
			result++;
		iter1++;	iter2++;
	}
	return result;
}
int main(void)
{
	std::vector<int> vec1, vec2;
	int tmp;
	int N1, N2;
	std::cin >> N1 >> N2;
	for(int i = 0; i < N1; ++i) {
		std::cin >> tmp;
		vec1.push_back(tmp);
	}
	for(int i = 0; i < N2; ++i) {
		std::cin >> tmp;
		vec2.push_back(tmp);
	}
	

	std::cout << Compare(vec1, vec2) << std::endl;

	return 0;
}
