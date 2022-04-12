#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n,i;
	int a[11], b[11], c[11];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", a + i, b + i, c + i);
	}
	for (i = 1; i <= n; i++)
	{
		if (((double)a[i - 1] / 2 + (double)b[i - 1] / 2) > (double)c[i - 1] / 2)
		{
			printf("Case #%d: true\n", i);
		}
		else
		{
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}