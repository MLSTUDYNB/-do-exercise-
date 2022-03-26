#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
typedef struct studet
{
	char name[11];
	char id[11];
	int grade;
}stu;
int main()
{
	int n;
	scanf("%d", &n);
	stu* people = (stu*)malloc(n * sizeof(stu));
	int i = 0;
	int a = 0, b = 0, min = 0, max = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s%s%d", (people+i)->name, (people + i)->id, &(people + i)->grade);
		if (i == 0)
		{
			min = (people + i)->grade;
			max = (people + i)->grade;
		}
		if ((people + i)->grade < min)
		{
			min = (people + i)->grade;
			a = i;
		}
		if ((people + i)->grade > max)
		{
			max = (people + i)->grade;
			b = i;
		}
	}
	printf("%s %s\n", (people + b)->name, (people + b)->id);
	printf("%s %s\n", (people + a)->name, (people + a)->id);
	return 0;
}