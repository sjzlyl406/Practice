/*************************************************************************
	> File Name: test106.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月26日 星期日 11时41分44秒
 ************************************************************************/

/**************************************************************
 * memcpy()
 * *************************************************************/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void* memcpy(void *_dst, const void*_src, size_t len)
{
	assert(_dst!= NULL && _src != NULL);

	if(_dst <= _src || (char*)_dst >= (char*)_src + len) {
		//没有内存覆盖
		while(len--) {
			printf("%c\n", *(char*)(_src));
			*(char*)_dst = *(char*)_src;
			(char*)_dst++;
			(char*)_src++;
		}
	}
	else {
		//内存覆盖
		do{
			*(char*)(_dst+len-1) = *(char*)(_src+len-1);
		}while(--len);
	}
	return _dst;
}
int main(void)
{
	char *str1 = (char*)malloc(6*sizeof(char));
	char *str2 = "hello";

	printf("%x,%x\n", (int)str1, (int)str2);
	memcpy(str1, str2, 6);
	printf("%s\n", str1);
	return 0;
}
