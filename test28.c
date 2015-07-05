/*************************************************************************
	> File Name: test28.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 07时45分10秒
 ************************************************************************/

/**************************************************************
 * 求两个长长整形数据的和并输出
 * ************************************************************/
#include<stdio.h>
#include<string.h>

#define N 100
int main(void)
{
	char s1[N],s2[N];

	int a[N]={0},b[N]={0},l1,l2,c,k,i;
	puts("请输入两个较大的数字（Note：输完一个按一次回车）：");
	scanf("%s %s", s1, s2);

	l1=strlen(s1);
	l2=strlen(s2);
	if(l1<l2) 
		k=l2;
	else 
		k=l1;
	c=k;
	for(i=0;i<l1;k--,i++)
		a[k]=s1[l1-1-i]-'0';
	for(k=c,i=0;i<l2;k--,i++)
		b[k]=s2[l2-1-i]-'0';
											
	printf("\n");
	for(i=c;i>=0;i--)
	{
		a[i]+=b[i];
		if(a[i]>=10) {
			a[i]-=10;
			a[i-1]++;}
	}
	printf("此两数相加之和为：");
	if(a[0]!=0)
	{	
		for(i=0;i<=c;i++)
			printf("%d",a[i]);
	}
	else 
	{
		for(i=1;i<=c;i++)
			printf("%d",a[i]);
	}
																				printf("\n");
}
