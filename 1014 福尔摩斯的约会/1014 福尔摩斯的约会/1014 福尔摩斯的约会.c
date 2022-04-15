#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int ret[4];
void find1(char* s1,char* s2)
{
	int i =0,n=0;
	while (s1[i]&&s2[i])
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] >= 'A' && s1[i] <= 'G')
			{
				ret[n++] = i;
			}
			else if(((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')) && n == 1)
			{
				ret[n++] = i;
			}
		}
		i++;
	}
}

void find2(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			if ((s1[i] >= 'A' && s1[i] <= 'Z')|| (s1[i] >= 'a' && s1[i] <= 'z'))
				ret[0] = i;
		}
		i++;
	}
}
/*MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日*/
int main()
{
	char a1[61], a2[61], b1[61], b2[61];
	char* day[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	scanf("%s%s%s%s", a1, a2, b1, b2);
	find1(a1, a2);
	if (a1[ret[1]] >= 'A')
		ret[1] = a1[ret[1]] - 'A' + 10;
	else
		ret[1] = a1[ret[1]] - '0';
	printf("%s %02d", day[a1[ret[0]]-'A'], ret[1]);
	find2(b1, b2);
	printf(":%02d", ret[0]);
	return 0;
}

