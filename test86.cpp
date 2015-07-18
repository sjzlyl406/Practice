/*************************************************************************
	> File Name: test86.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月17日 星期五 21时34分41秒
 ************************************************************************/

/********************************************************************
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permu-
 * tation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascend-
 * ing order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the
 * right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * ******************************************************************/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

void NextPermutation(std::vector<int> &vec)
{
	std::vector<int>::reverse_iterator r_iter1 = vec.rbegin();
	for(r_iter1 = std::next(vec.rbegin(), 1); r_iter1 != vec.rend(); ++r_iter1) {
		if(*r_iter1 < *std::prev(r_iter1, 1))
			break;
	}
	if(r_iter1 != vec.rend()) {
		auto r_iter2 = vec.rbegin();
		for(r_iter2 = vec.rbegin(); r_iter2 != vec.rend(); ++r_iter2) {
			if(*r_iter2 > *r_iter1)
				break;
		}
		std::swap(*r_iter1, *r_iter2);
		reverse(vec.rbegin(), r_iter1);
	}
	else
		reverse(vec.begin(), vec.end());
	
	for(size_t i = 0; i < vec.size(); ++i) {
		std::cout<<vec[i]<<" ";
	}
	std::cout<<std::endl;
}

int main(void)
{
	int array[] = {1,2,3};
	std::vector<int> vec(array, array+3);
	for(int i = 0; i < 3; ++i) {
		NextPermutation(vec);
	}
	return 0;

}
