#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	//创建字符数组
	char arr[100];
	//整数数组储存和的每个位数
	int brr[100] = { 0 };
	//创建和
	int sum = 0, i = 0, n = 0;
	//创建拼音数字数组
	char* pin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	//输入整数
	scanf("%s", arr);
	//计算各个位数之和
	while (arr[i])
	{
		sum += arr[i] - '0';
		i++;
	}
	//储存sum的各个位数，同时用n进行标记
	//从个位数进行储存的
	while (sum)
	{
		brr[n] = sum % 10;
		sum /= 10;
		n++;
	}
	//输出
	while (n)
	{
		printf("%s", pin[brr[n - 1]]);
		n--;
		if (n)//保证最后一个不打印空格
			printf(" ");
	}
	return 0;
}