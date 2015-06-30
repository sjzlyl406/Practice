/*************************************************************************
	> File Name: test8.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 16时55分11秒
 ************************************************************************/

/******************************************************************
 * 输入英文句子，翻转句子中单词的顺序，但单词中字符顺序不变。
 * 标点符号和普通字母一样处理。
 * 输入“I am a student.” 输出 “student. a am I”.
 * ****************************************************************/
#include<stdio.h>

void Reverse(char *pBegin, char *pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
		return;

	while(pBegin < pEnd){
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++, pEnd--;
	}
}
char* ReverseSentence(char *pData)
{
	if(pData == NULL)
		return NULL;

	char *pBegin = pData;

	char *pEnd = pData;
	while(*pEnd != '\0')
		pEnd++;
	pEnd--;

	//Reverse the whole sentence
	Reverse(pBegin, pEnd);

	//reverse the word in the sentence
	pBegin = pEnd = pData;
	while(*pBegin != '\0') {
		if(*pBegin == ' ') {
			pBegin++;
			pEnd++;
		}
		else if(*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin , -- pEnd);
			pBegin = ++ pEnd;
		} 
		else
			pEnd++;
	}
	return pData;
}

int main(void)
{
	char str[] = "I am a student.";
	ReverseSentence(str);
	printf("%s\n", str);

	return 0;
}
