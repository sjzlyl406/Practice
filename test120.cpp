/*************************************************************************
	> File Name: test120.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月02日 星期日 18时55分36秒
 ************************************************************************/

/*******************************************************************
 * 实现8大排序算法，
 * 冒泡排序、插入排序、希尔排序、选择排序、归并排序、快速排序、基数排序、堆排序
 * 时间复杂度分析。
 * ****************************************************************/

#include<cstdio>
#include<algorithm>
template<class T>
void Print(T *array, size_t len) 
{
	static int count = 0;
	printf("times: %d\n", count++);
	for(int i = 0; i < len; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");	
}

/************** 冒泡排序 **************/
template<class T>
void BubbleSort(T *array, size_t len)
{
	for(size_t i = 0; i < len-1; ++i) {
		for(size_t j = len-1; j > i; --j) {
			if(array[j-1] > array[j]) {
				T tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
		}
	}
}
/************** 插入排序 **************/
template<class T>
void InsertSort(T *array, size_t len)
{
	size_t j ;
	for(size_t i = 0; i < len-1; ++i) {
		j = i + 1;
		while(j > 0 && array[j] < array[j-1]) {
			T tmp = array[j];
			array[j] = array[j-1];
			array[j-1] = tmp;
			j--;
		}
	}
}
/************** 希尔排序 **************/
template<class T>
void ShellSort(T *array, size_t len) 
{
	size_t i = 0;
	size_t mid ;
	
	for(mid = len >> 1; mid >= 1; mid = mid>>1) {
		for(i = 0; i <mid; i++) {
			for(size_t j = mid + i; j < len; j += mid) {
				size_t m = j;
				while(m >= mid && array[m] < array[m-mid]) {
					std::swap(array[m], array[m-mid]);
					m = m-mid;
				}
			}
		}
	}
}
/************** 选择排序 **************/
template<class T>
void SelectSort(T *array, size_t len)
{
	size_t min_index = 0;
	for(size_t i = 0; i < len-1; ++i) {
		for(size_t j = i+1; j < len; ++j) {
			if(array[j] < array[min_index])
				min_index = j;
		}
		std::swap(array[i], array[min_index]);
	}
}
/************** 归并排序 **************/
template<class T>
void Merge(T *array, size_t len, size_t index);
template<class T>
void MergeSort(T *array, size_t len)
{
	if(len <= 1) return;
	if(len == 2) {
		if(array[0] > array[1])
			std::swap(array[0],array[1]);
	}
	MergeSort(array, len>>1);
	MergeSort(array+(len>>1), len-(len>>1));
	Merge(array, len, len >> 1);
}
template<class T>
void Merge(T *array, size_t len, size_t index)
{
	T *left = new T[index];
	T *right = new T[len-index];
	for(size_t i = 0; i < index; ++i) {
		left[i] = array[i];
	}
	for(size_t i = 0; i < len-index; ++i) {
		right[i] = array[index + i];
	}
	int index_left = 0;
	int index_right = 0;
	int index_array = 0;
	while(index_left < index && index_right < len-index) {
		if(left[index_left] < right[index_right])
			array[index_array++] = left[index_left++];
		else
			array[index_array++] = right[index_right++];
	}
	
	while(index_left < index) {
		array[index_array++] = left[index_left++];
	}
	while(index_right < len-index) {
		array[index_array++] = right[index_right++];
	}
	
	delete [] left;
	delete [] right;
}
/************** 快速排序 **************/
template<class T>
size_t Partition(T *array, size_t len);
template<class T>
void QuickSort(T *array, size_t len)
{
	if(len <= 1) return;
	size_t mid = Partition(array, len);
	QuickSort(array, mid);
	QuickSort(array+mid+1, len-mid-1);
}
template<class T>
size_t Partition(T *array, size_t len)
{
	int value = array[0];
	int left = 1;
	int right = len-1;
	while(left <= right) {
		while(left <= right && array[left] <= value) left++;
		while(left <= right && array[right] >= value) right--;
		if(left <= right)
			std::swap(array[left++], array[right--]);
	}
	left--;
	std::swap(array[left], array[0]);
	return left;
}
/************** 堆排序 **************/
template<class T>
void BuildHeap(T *array, size_t len);
template<class T>
void HeapSort(T *array, size_t len)
{
	for(size_t i = len; i > 0; --i) {
		BuildHeap(array, i);
		std::swap(array[0], array[i-1]);
	}
}
template<class T>
void MaxHeap(T *array, size_t len, size_t i)
{
	size_t max_index = i;
	size_t left = (i << 1) + 1;
	size_t right = (i << 1) + 2;
	if(left < len && array[left] > array[i])
		max_index = left;
	if(right < len && array[right] > array[max_index])
		max_index = right;
	std::swap(array[i], array[max_index]);
	if(max_index != i)
		MaxHeap(array, len, max_index);
}
template<class T>
void BuildHeap(T *array, size_t len)
{
	for(int i = len+1>>1; i >= 0; --i) {
		MaxHeap(array, len, i);
	}
}
/************** 基数排序 **************/
template<class T>
void JiShuSort(T *array, size_t len)
{
	
}


int main(void)
{
	printf("0 : BubbleSort\n");
	printf("1 : InsertSort\n");
	printf("2 : ShellSort\n");
	printf("3 : SelectSort\n");
	printf("4 : MergeSort\n");
	printf("5 : QuickSort\n");
	printf("6 : HeapSort\n");
	printf("7 : JiShuSort\n");
	int num;
	printf("input a num :");
	scanf("%d", &num);

	int array[] = {8,6,3,5,2,9,4,1,0,7};
	printf("before sort : ");
	for(int i = 0; i < 10; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
	switch(num){
		case 0 : BubbleSort(array, 10); break;
		case 1 : InsertSort(array, 10); break;
		case 2 : ShellSort(array, 10); break;
		case 3 : SelectSort(array, 10); break;
		case 4 : MergeSort(array, 10); break;
		case 5 : QuickSort(array, 10); break;
		case 6 : HeapSort(array, 10); break;
		case 7 : JiShuSort(array, 10); break;
	}

	printf("after sort : ");
	for(int i = 0; i < 10; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
	return 0;
}
