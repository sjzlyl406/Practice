/*************************************************************************
	> File Name: test16.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 11时00分17秒
 ************************************************************************/

/***************************************************
 * Remove Duplicates from Sorted Array return the new length
 * do not allocate new space
 * input A=[1,1,3] Output A=[1,3] and length = 2;
 * ************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

size_t RemoveDuplicate(vector<int> &vec)
{
	size_t newLength = 0;
	if(!vec.empty()) {
		vector<int>::iterator iter = vec.begin();
		iter = unique(vec.begin(), vec.end());
		newLength = distance(vec.begin(), iter);
	}
	return newLength;
}
int main(void)
{
	const int MaxLength = 10;
	int array[MaxLength] = {1,1,2,2,4,5,5,5,7,7};
	vector<int> vec(array, array+MaxLength);

	size_t newLength = RemoveDuplicate(vec);

	size_t i = 0;
	for(i = 0; i < newLength; ++i)
		cout<<vec[i]<<'\t';
	cout<<endl;

	return 0;
}
