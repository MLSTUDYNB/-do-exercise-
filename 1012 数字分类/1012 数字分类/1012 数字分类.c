#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
int find = 0;
int f1(int* a, int n)
{
	find = 0;
	int i = 0,sum=0;
	for (; i < n; i++)
	{
		if (a[i] % 5 == 0&&a[i]%2==0)
		{
			find = 1;
			sum += a[i];
		}
	}
	return sum;
}
int f2(int* a, int n)
{
	find = 0;
	int i = 0, sum = 0, x = 1;
	for (; i < n; i++)
	{
		if (a[i] % 5 == 1)
		{
			find = 1;
			sum += x * a[i];
			x = -1*x;
		}
	}
	return sum;
}
int f3(int* a, int n)
{
	find = 0;
	int i = 0, sum = 0;
	for (; i < n; i++)
	{
		if (a[i] % 5 == 2 )
		{
			find = 1;
			sum++;
		}
	}
	return sum;
}
double f4(int* a, int n)
{
	find = 0;
	int i = 0, sum = 0,count=0;
	for (; i < n; i++)
	{
		if (a[i] % 5 == 3 )
		{
			find = 1;
			sum += a[i];
			count++;
		}
	}
	return (double)sum/count;
}
int f5(int* a, int n)
{
	find = 0;
	int i = 0, max = 0;
	for (; i < n; i++)
	{
		if (a[i] % 5 == 4)
		{
			find = 1;
			if(max<a[i])
			max = a[i];
		}
	}
	return max;
}
int main()
{
	int n,i;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	if (a == NULL)
	{
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}

	int ret=f1(a, n);
	if (find == 0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ",ret);
	}
	ret=f2(a, n);
	if (find == 0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", ret);
	}
	ret = f3(a, n);
	if (find == 0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", ret);
	}
	double b=f4(a, n);
	if (find == 0)
	{
		printf("N ");
	}
	else
	{
		printf("%.1lf ", b);
	}
	ret = f5(a, n);
	if (find == 0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", ret);
	}
	free(a);
	a=NULL:
	return 0;
}
//enum 
//{
//	red,
//	yell
//};
//int main()
//{
//	int a = red;
//	return 0;
//}
//struct
//{
//	int a;
//};
//int main()
//{
//	struct b ;
//
//	return 0;
//}