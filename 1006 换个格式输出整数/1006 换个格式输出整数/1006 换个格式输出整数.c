#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n=0,i=0,b=0;
	int arr[3]={0};
	scanf("%d", &n);
	while (n)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	while (i!=-1)
	{
		switch (i)
		{
		case 2:
			while (arr[i])
			{
				printf("B");
				arr[i]--;
			}
			break;
		case 1:
			while (arr[i])
			{
				printf("S");
				arr[i]--;
			}
			break;
		case 0:
			for (b = 1; b <= arr[i]; b++)
				printf("%d", b);
			break;
		}
		i--;
	} 
	return 0;
}