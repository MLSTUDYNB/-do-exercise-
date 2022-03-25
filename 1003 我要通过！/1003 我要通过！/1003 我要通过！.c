#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,a,b,c;
	scanf("%d", &n);
	char arr[10][100];
	int i = 0;
	for (i=0;i<n;i++)
	{
		scanf("%s", arr[i]);
	}
	i = 0;
	//统计P,T前a，中b,后c中A的个数
	while (i<n)
	{
		a = 0; b = 0; c = 0;
		char* temp = (char*)arr[i];
		while (*temp)
		{
			if (*temp == 'A')
				a++;
			else if (*temp == 'P')
				b++;
			else if (*temp == 'T')
				c++;
			else
				break;
			temp++;
		}
		if (b!=1||c!=1||a==0)
		{
			printf("NO\n");
			i++;
		}
		else if (*temp!='\0')
		{
			printf("NO\n");
			i++;
		}
		else
		{
			a = 0; b = 0; c = 0;
			temp = (char*)arr[i];
			while (*temp++ != 'P'&& *temp)
			{
				a++;
			}
			while (*temp++ != 'T' && *temp)
			{
				b++;
			}
			while (*temp)
			{
				c++;
				temp++;
			}
			while (c)
			{
				if (a && c && c != a && c % a == 0)
				{
					c = c - a;
					b--;
				}
				else
					break;
			}
			if (b == 1 && c == a)
				printf("YES\n");
			else if (a == 0 && c == a)
				printf("YES\n");
			else
				printf("NO\n");
			i++;
		}
	}
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//int f(char arr[],char brr[])
//{
//	int i = 0;
//	for ()
//	{
//
//	}
//}
//int main()
//{
//	char arr[6] = "123456";
//	char brr[3] = "234";
//	int ret=f(arr,brr);
//	return 0;
//}
