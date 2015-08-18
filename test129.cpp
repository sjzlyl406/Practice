/*************************************************************************
	> File Name: test.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月24日 星期五 16时30分47秒
 ************************************************************************/

/**********************************************************************
 * 判断一包含n个整数a[]中是否存在i、j、k
 * 满足a[i] + a[j] = a[k]的时间复杂度为O(n^2)
 * *******************************************************************/
#include<iostream>
#include<cstdio>
#include<vector>
#include<hash_set>

bool foo(const std::vector<int> &vec) {
	__gnu_cxx::hash_set<int> set;
	for(int i = 0; i < vec.size()-1; ++i) {
		for(int j = i+1; j < vec.size(); ++j) {
			int sum = vec[i] + vec[j];
			//将结果保存到hash_set中
			if(set.find(sum) == set.end()) {
				set.insert(sum);
			}
		}
	}
	//打印出hash_set中的值
	for(auto &i : set) {
		printf("%d\t", i);
	}
	printf("\n");
	for(int j = 0; j < vec.size(); ++j) {
		//判断正确
		if(set.find(vec[j]) != set.end()) {
			return true;
		}
	}
	return false;
}

int main(void) {
	int array[] = {2,5,3,8,4,14};
	std::vector<int> vec(array, array+6);
	printf("%d\n", static_cast<int>(foo(vec)));

	return 0;
}
