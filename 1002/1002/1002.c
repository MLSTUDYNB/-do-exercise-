#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	//�����ַ�����
	char arr[100];
	//�������鴢��͵�ÿ��λ��
	int brr[100] = { 0 };
	//������
	int sum = 0, i = 0, n = 0;
	//����ƴ����������
	char* pin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	//��������
	scanf("%s", arr);
	//�������λ��֮��
	while (arr[i])
	{
		sum += arr[i] - '0';
		i++;
	}
	//����sum�ĸ���λ����ͬʱ��n���б��
	//�Ӹ�λ�����д����
	while (sum)
	{
		brr[n] = sum % 10;
		sum /= 10;
		n++;
	}
	//���
	while (n)
	{
		printf("%s", pin[brr[n - 1]]);
		n--;
		if (n)//��֤���һ������ӡ�ո�
			printf(" ");
	}
	return 0;
}