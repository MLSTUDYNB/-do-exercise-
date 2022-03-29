#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//void f(int* arr,int m,int n)
//{
//	int temp = arr[m-1];
//	int i = 0;
//	if (n == 0)
//		return;
//	for (i = m; i >0; i--)
//	{
//		arr[i-1] = arr[i -2];
//	}
//	arr[0] = temp;
//	f(arr, m, n-1);
//}
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	int* arr = (int*)malloc(m * sizeof(int));
//	assert(arr);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	f(arr,m, n);
//	for (i = 0; i < m; i++)
//	{
//		printf("%d", arr[i]);
//		if (i != m - 1)
//			printf(" ");
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int* arr = (int*)malloc(m * sizeof(int));
	assert(arr);
	int i = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", arr + i);
	}
	while (n)
	{
		int temp = arr[m - 1];
		memmove(arr+1, arr, (m - 1) * 4);
		arr[0] = temp;
		n--; 
	}
	for (i = 0; i < m; i++)
	{
		printf("%d", arr[i]);
		if (i != m - 1)
			printf(" ");
	}
	free(arr);
	arr = NULL;
	return 0;
}