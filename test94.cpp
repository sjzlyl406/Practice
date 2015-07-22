/*************************************************************************
	> File Name: test94.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 15时20分50秒
 ************************************************************************/

/***********************************************************************
 * LCS问题：动归+回溯
 * ********************************************************************/
#include<vector>
#include<cstdio>
#include<cstring>

enum {kInit, kleft, kup, kleftup};

void Lcs_print(int**, char*, char*, int ,int);
int LCS(char *ptr1, char *ptr2) {
	if(ptr1 == NULL || ptr2 == NULL) return 0;

	int len1 = strlen(ptr1);
	int len2 = strlen(ptr2);
	if(len1 == 0 || len2 == 0) return 0;

	int **map_length, **map_direction;
	map_length = (int**) new int[len1];
	map_direction = (int**) new int[len1];
	for(int i = 0; i < len1; ++i) {
		map_length[i] = new int [len2];
		map_direction[i] = new int [len2];
	}
	for(int i = 0; i < len1; ++i) {
		for(int j = 0; j < len2; ++j) {
			map_length[i][j] = 0;
			map_direction[i][j] = kInit;
		}
	}

	for(int i = 0; i < len1; ++i) {
		for(int j = 0; j < len2; ++j) {
			if(i == 0 || j == 0) {
				if(ptr1[i] == ptr2[j]) {
					map_length[i][j] = 1;
					map_direction[i][j] = kleftup;
				}
				else {
					if(i > 0) {
						map_length[i][j] = map_length[i-1][j];
						map_direction[i][j] = kup;
					}
					if(j > 0) {
						map_length[i][j] = map_length[i][j-1];
						map_direction[i][j] = kleft;
					}
				}
			}
			else if(ptr1[i] == ptr2[j]) {
				map_length[i][j] = map_length[i-1][j-1];
				map_direction[i][j] = kleftup;
			}
			else if(map_length[i-1][j] < map_length[i][j-1]) {
				map_length[i][j] = map_length[i][j-1];
				map_direction[i][j] = kleft;
			}
			else {
				map_length[i][j] = map_length[i-1][j];
				map_direction[i][j] = kup;
			}
		}
	}
	
	Lcs_print(map_direction, ptr1, ptr2, len1-1, len2-1);
	return map_length[len1-1][len2-1];
}

void Lcs_print(int** map_direction, char* ptr1, char* ptr2, int len1,int len2) {
	if(ptr1 == NULL || ptr2 == NULL) return;

	if(len1 == 0 && len2 == 0) {
		if(map_direction[len1][len2] == kleftup)
			printf("%c",ptr1[len1]);
		return;
	}
	if(map_direction[len1][len2] == kleftup) {
		if(len1 > 0 && len2 > 0) 
			Lcs_print(map_direction, ptr1, ptr2, len1-1, len2-1);
		printf("%c", ptr1[len1]);
	}
	else if(map_direction[len1][len2] == kleft) {
		if(len2 > 0)
			Lcs_print(map_direction, ptr1, ptr2, len1, len2-1);
	}
	else if(map_direction[len1][len2] == kup) {
		if(len1 > 0)
			Lcs_print(map_direction, ptr1, ptr2, len1-1, len2);
	}
}

int main(void) 
{
	char* ptr1 = "abcde";
	char* ptr2 = "acde";
	LCS(ptr1, ptr2);
	printf("\n");

	return 0;
}
