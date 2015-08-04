/*************************************************************************
	> File Name: test128.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月04日 星期二 21时33分00秒
 ************************************************************************/

/*********************************************************************
 * 洗牌法
 * 将洗牌看作全排列，随机取出一种排列方式，
 * 概率问题 将1～54看作54张牌，
 * rand()%54与第一张牌交换，rand()%53+i与第二张牌交换
 * ******************************************************************/
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<algorithm>

void get_rand_number(std::vector<int> &vec)
{
	srand((unsigned int) time(0));
	for(int i = 0; i < 54; ++i) {
		size_t index = rand()%(54-i) + i;
		std::swap(vec[i], vec[index]);
	}

	for(int i = 0; i < 54; ++i) {
		if(i % 10 == 0) {
			printf("\n");
		}
		printf("%d\t", vec[i]);
	}
}
int main(void)
{
	std::vector<int> vec;
	for(int i = 1; i <= 54; ++i)
		vec.push_back(i);

	get_rand_number(vec);
	return 0;
}
