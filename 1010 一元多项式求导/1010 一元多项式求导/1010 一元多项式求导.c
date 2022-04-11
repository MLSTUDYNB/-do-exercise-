#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
    int arr[100], brr[100];
    int i = 0, j = 0, a;
    while (scanf("%d %d", &arr[i], &brr[i]) != EOF)
    {
        if (arr[0] == 0 && brr[0] == 0)
        {
            printf("0 0");
        }
        if (brr[i] == 0);
        else
        {
            arr[j] = arr[i] * brr[i];
            brr[j] = brr[i] - 1;
            j++;
        }
        i++;
    }
    for (a = 0; a < j; a++)
    {
        printf("%d %d", arr[a], brr[a]);
        if (a != j - 1)
            printf(" ");
    }
    return 0;
}