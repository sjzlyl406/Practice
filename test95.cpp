/*************************************************************************
	> File Name: test95.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 17时26分44秒
 ************************************************************************/

/******************************************************************
 * 根据上排给出十个数，在其下排填出对应的十个数
 * 要求下排每个数都是先前上排那十个数在下排出现的次数。
 * 上排的十个数如下：
 * 【0，1，2，3，4，5，6，7，8，9】
 * 举一个例子，
 * 数值: 【 0,1,2,3,4,5,6,7,8,9 】
 * 分配: 【 6,2,1,0,0,0,1,0,0,0 】
 * ***************************************************************/
#include<cstdio>
#include<unordered_map>

#define MaxLen 10

bool Check(int *array, int *ret)
{
	std::unordered_map<int, int> Imap;
	//统计ret中数字频率
	for(int i = 0; i < MaxLen; ++i) {
		Imap[ret[i]]++;
	}
	//判断结果正确性
	bool result = true;
	for(int i = 0; i < MaxLen; ++i) {
		if(Imap.find(array[i]) == Imap.end()) {
			if(ret[i])
				result = false;
		}
		else if(Imap[array[i]] != ret[i]) {
			result = false;
		}
	}
	return result;

}
bool dfs(int*, int*, int, int);
void foo(int *array)
{
	int ret[MaxLen] = {};
	dfs(array, ret, MaxLen, 0);
}
bool dfs(int *array, int *ret, int fenpei, int loop) {
	if(loop == MaxLen) {
		if(Check(array, ret)) { 
			for(int i = 0; i < MaxLen; ++i) {
				printf("%d\t", ret[i]);
			}
			printf("\n");
			return true;
		}
		return false;
	}

	for(int i = 0; i <= fenpei; ++i) {
		ret[loop] = i;
		dfs(array, ret, fenpei-i, loop+1);
	}
}


int main(void)
{
	int array[MaxLen] = {0,1,2,3,4,5,6,7,8,9};
	foo(array);
	return 0;
}
