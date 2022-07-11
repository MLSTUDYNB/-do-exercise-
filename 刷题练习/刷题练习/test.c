#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
//int FirstNotRepeatingChar(char* str) {
//    int n = ('a' - 'Z' + 1);
//    int len = strlen(str);
//    int* a = (int*)malloc(sizeof(int) * n);
//    memset(a, 0, n);
//    for (int i = 0; i < len; i++)
//    {
//        a[str[i] - 'a']++;
//    }
//    for (int i = 0; i < len; i++)
//    {
//        if (a[str[i] - 'a'] == 1)
//        {
//            free(a);
//            return i;
//        }
//    }
//    free(a);
//    return -1;
//}
bool isUnique(char* astr) {
    int len = strlen(astr);
    int n = 'z' - 'a' + 1;
    int* s = (int*)malloc(sizeof(int) * n);
    memset(s, 0, n*sizeof(int));
    for (int i = 0; i < len; i++)
        s[astr[i] - 'a']++;
    for (int i = 0; i < len; i++)
    {
        if (s[astr[i] - 'a'] != 1)
        {
            free(s);
            return false;
        }
    }
    free(s);
    return true;
}

int main()
{
    //printf("jhh0");
    //FirstNotRepeatingChar("google");
    isUnique("iluhwpyk");
    return 0;
}
//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//} 
//int main()
//{
//	//char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	//fun(s);
//	//printf("\n");
//	return 0;
//}
//int main()
//{
//	//int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//	//int b = *(&a[0][0] + 5);
//	//int c = *(*(a + 1) + 1);
//	//int d = *(&a[1] + 1);
//	//int f = *(a[1] + 1);
//	int* k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}
//
//int main()
//{
//    long x, y;
//    long n, k;
//
//    scanf("%ld%ld", &n, &k);
//    long count = (n - k + 1) * (n - k) / 2;
//    for (y = k + 1; y < n; y++)
//    {
//
//        if (2 * y < n)
//        {
//            count += (n / y) * (y - k);
//        }
//        else if (2 * y == n)
//            count += (n - y - k);
//        else if ((n - y - k+1) >0)
//        {
//            count += (n - y - k+1);
//        }
//    }
//    printf("%ld", count);
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//    long y, count, n, k;
//    count = 0;
//    scanf("%ld%ld", &n, &k);
//    for (y = k + 1; y <= n; y++)
//    {
//        if(2*y<n)
//        count += ((n / y + 1) * (y - k));
//        if (2 * y == n)
//            count += n - y - k;
//        else if (n - y - k + 1 > 0)
//            count += n - y - k + 1;
//    }
//    printf("%ld", count);
//    return 0;
//}
/**
 * Definition for a binary tree node.
 *
 * };
 */
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//bool evaluateTree(struct TreeNode* root)
//{
//
//    if (root->val == 0)
//        return false;
//    if (root->val == 1)
//        return true;
//    bool L = evaluateTree(root->left);
//    bool R = evaluateTree(root->right);
//    if (root->val == 2)
//    {
//        bool x = L || R;
//        if (x)
//            root->val = 1;
//        else
//            root->val = 0;
//        return x;
//    }
//    else
//    {
//        bool x = L && R;
//        if (x)
//            root->val = 1;
//        else
//            root->val = 0;
//        return x;
//    }
//}
//
//int main()
//{
//
//    return 0;
//}
//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//int main()
//{
//
//	/*char a = 101;
//	int sum = 200;
//	a += 27; sum += a;
//	printf("%d\n", sum);*/
//	//int value = 1024;
//	//char condition = *((char*)(&value));
//	//if (condition) value += 1; condition = *((char*)(&value));
//	//if (condition) value += 1; condition = *((char*)(&value));
//	//printf("%d %d", value, condition);
//	char a[100] = { 0 };
//	func(a);
//	return 0;
//}
//int main()
//{
//    int count = 0;
//    int n;
//    scanf("%d", &n);
//    //for (int i = 2; i < n; i++)
//    //{
//    //    int j = 2;
//    //    for (; j <= (int)sqrt(i); j++)
//    //    {
//    //        if (i % j == 0)
//    //            break;
//    //    }
//    //    if ((int)sqrt(i) < j)
//    //        count++;
//    //}
//    printf("%d", count);
//    return 0;
//}