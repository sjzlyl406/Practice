/*************************************************************************
	> File Name: test21.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 20时05分34秒
 ************************************************************************/

/***********************************************************************
 * 操作系统任务调度问题。操作系统任务分为系统任务和用户任务两种。其中，
 * 系统任务的优先级 < 50，用户任务的优先级 >= 50且 <= 255。优先级大于255的为非法任务，应予以剔除。
 * 现有一任务队列task[]，长度为n，task中的元素值表示任务的优先级，数值越小，优先级越高。 
 * 函数scheduler实现如下功能：
 * 将task[] 中的任务按照系统任务、用户任务依次存放到 system_task[] 数组和 user_task[] 数组中 
 * （数组中元素的值是任务在task[] 数组中的下标），并且优先级高的任务排在前面，数组元素为-1表示结束。
 * 例如：
 * task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99}    
 * system_task[] = {0, 3, 1, 7, -1}    
 * user_task[]  =  {4, 8, 2, 6, -1}
 * 接口函数：
 * void scheduler(int task[], int n, int system_task[], int user_task[])
 * ********************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

typedef struct _TaskNode
{
	int index;
	int value;
}TaskNode;

void scheduler(int task[], int n, int system_task[], int user_task[])
{
	TaskNode *TaskMap = new TaskNode[n * sizeof(TaskNode)];
	for(int i = 0; i < n; ++i) {
		TaskMap[i].index = i;
		TaskMap[i].value = task[i];
	}

	for(int i = 0; i < n-1; ++i) {
		for(int j = i+1; j < n; ++j) {
			if(TaskMap[i].value > TaskMap[j].value) {
				TaskNode tmp = TaskMap[i];
				TaskMap[i] = TaskMap[j];
				TaskMap[j] = tmp;
			}
		}
	}

	int length1 = 0, length2 = 0;
	for(int i = 0; i < n; ++i) {
		if(TaskMap[i].value >= 0 && TaskMap[i].value <50)
			system_task[length1++] = TaskMap[i].index;
		else if(TaskMap[i].value >= 50 && TaskMap[i].value <= 255)
			user_task[length2++] = TaskMap[i].index;
	}

	system_task[length1] = -1;
	user_task[length2] = -1;

	delete [] TaskMap;

	for(int i = 0; i <= length1; ++i)
		cout<<system_task[i]<<" ";
	cout<<endl;
	for(int i = 0; i <= length2; ++i)
		cout<<user_task[i]<<" ";
	cout<<endl;
}
int main(void)
{
	int tase[] = {0, 30, 155, 1, 80, 300, 170, 40, 99};
	int system_task[10] = {0};
	int user_task[10] = {0};

	scheduler(tase, 9, system_task, user_task);

	return 0;
}
