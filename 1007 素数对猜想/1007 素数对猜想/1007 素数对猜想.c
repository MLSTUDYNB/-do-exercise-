#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
int main()
{
	int n,i,j;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	assert(arr);
	int a = 0,count=0;
	//ÅĞ¶ÏËØÊı²¢ÇÒ´¢´æËØÊı
	for (i=2;i<=n;i++)
	{
		for (j = 2; j<= (int)sqrt(i); j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > (int)sqrt(i))
			arr[a++] = i;
	}
	//ÅĞ¶ÏÏà²î2
	for (i = 0; i < a; i++)
	{
		if (arr[i + 1] - arr[i] == 2)
			count++;
	}
	free(arr);
	arr = NULL;
	printf("%d", count);

	return 0;
}