#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int m, n,i,count=1,x;
	scanf("%d%d", &m, &n);
	int* a = (int*)malloc(n * sizeof(int));
	//int a[100] = { 0 };
	if (a == NULL)
	{
		return 0;
	}
	a[0] = 2;
	for (i = 3;count<=n; i++)
	{
		for (x = 2; x <= (int)sqrt(i); x++)
		{
			if (i % x == 0)
			{
				break;
			}
		}
		if (x > (int)sqrt(i))
		{
			a[count++] = i;
		}
	}
	x = 0;
	for (i = m; i <= n; i++)
	{
		printf("%d", a[i]);
		x++;
		if (x != 10&&i!=n)
		{
			printf(" ");
		}
		else if (x == 10)
		{
			x = 0;
			printf("\n");
		}
		
	}

	free(a);
	a = NULL;
	return 0;
}