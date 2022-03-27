#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
void quick_sort(int* arr,int left,int right)
{
	int temp = arr[left];
	int a = left;
	int b = right;
	if (a >= b)
		return;
	while (a<b)
	{
		while (arr[b] <= temp&& a < b)
			b--;
		while (arr[a] >= temp && a < b)
			a++;
		//交换
		int t = arr[a];
		arr[a] = arr[b];
		arr[b] = t;
	}
	arr[left] = arr[a];
	arr[a] = temp;
	quick_sort(arr, left, a-1);
	quick_sort(arr, b+1, right);
}

void delete(int* arr,int n)
{
	int i = 0,j=0;
	for (i=0;i<n;i++)
	{
		int temp = arr[i];
		while (temp != 1&&temp)
		{
			if (temp % 2 == 0)
				temp /= 2;
			else
				temp = (temp* 3 + 1) / 2;
			for (j = 0; j < n; j++)
			{
				if (arr[j] == temp)
					arr[j] = 0;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	int i = 0;
	for (i=0;i<n;i++)
	{
		scanf("%d", arr + i);
	}
	//排序
	quick_sort(arr, 0, n - 1);
	//删除重复的
	delete(arr,n);
	//确定剩余几个数，目的是控制最后一个不打印空格
	int b = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			b++;
	}
	b = n - b;
	//打印
	for (i=0;i<n;i++)
	{
		if (arr[i] != 0)
		{
			printf("%d", arr[i]);
			if (b-1)
			{
				printf(" ");
				b--;
			}
		}
	}
	free(arr);
	arr = NULL;
	return 0;
}