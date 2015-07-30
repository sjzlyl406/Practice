/*************************************************************************
	> File Name: test100.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月23日 星期四 22时06分31秒
 ************************************************************************/

/*******************************************************************
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 * ******************************************************************/
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
	public:
	    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			int i1 = m-1;int i2 = n-1;int i3 = m+n-1;
			while(i1>=0 && i2>=0){
				nums1[i3--] = nums1[i1]>nums2[i2]?nums1[i1--]:nums2[i2--];
			}
			while(i2 >= 0)
				nums1[i3--] = nums2[i2--];
	    }
};

int main(void) 
{
	int array1[] = {1,3,5,7,8};
	int array2[] = {2,3,5,6,11};
	vector<int> vec1(array1, array1+5);
	vector<int> vec2(array2, array2+5);
	vec1.reserve(10);
	Solution ss;
	ss.merge(vec1,5,vec2,5);
	for(size_t i = 0; i < 10; ++i) {
		printf("%d\t", vec1[i]);
	}
	printf("\n");
	return 0;
}
