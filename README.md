# 刷题笔记

记录我的刷题过程，也希望给读者以帮助（record my brush question process,alse hope to help readers）

# [**NC107** **寻找峰值**](https://www.nowcoder.com/practice/fcf87540c4f347bcb4cf720b5b350c76?tpId=188&&tqId=38666&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking)

## 思路

**暴力遍历**

从头开始遍历，只要出现左边大于右边的就找到该峰值了。

**二分：**

中间的大于右边的，说明左边有峰值。

中间的小于右边的，说明右边有峰值。

直到区间里面就剩下一个值。

## 代码

+ 暴力

```c
int findPeakElement(int* nums, int numsLen ) {
    if(numsLen==1)
        return 0;
    if(nums[numsLen-2]<nums[numsLen-1])
        return numsLen-1;
    int i=0;
    while(i<numsLen)
    {
        if(i+1<numsLen&&nums[i]>nums[i+1])
            break;
        i++;
    }
    return i;
}

```

+ 二分

```c
int findPeakElement(int* nums, int numsLen ) {
    int left=0;
    int right=numsLen-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(nums[mid]>nums[mid+1])
            right=mid;
        else
            left=mid+1;
    }
    return left;
}
```

# [**HJ99** **自守数**](https://www.nowcoder.com/practice/88ddd31618f04514ae3a689e83f3ab8e?tpId=37&&tqId=21322&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking)

## 思路

![image-20220710165157755](https://s2.loli.net/2022/07/10/vWrV56we3i2xpug.png)

根据这个定义，自守数就是==i*(i-1)%10^m==如果为0，就是自守数。

然而题目对n是有限制的![image-20220710165340237](https://s2.loli.net/2022/07/10/OFTzvSwYj4Wnyak.png)，所以我们可以对m进行一一列举。具体的列举看代码。



## 代码

```c
#include <stdio.h>
#include <math.h>
int main()
{
    int m,n,i;
    int count=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        if(i<10)
            m=1;
        else if(i<100)
            m=2;
        else if(i<1000)
            m=3;
        else if(i<10000)
            m=4;
        else if(i<100000)
            m=5;
        if ((i*(i-1))%(int)pow(10,m)==0) 
            count++;
    }
    printf("%d",count);
    return 0;
}
```

# [**OR86** **返回小于 N 的质数个数**](https://www.nowcoder.com/practice/9e7a88d6a00e404c8418602515a5046c?tpId=182&&tqId=34812&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking)

## 思路

对于任意一个数n，在2~n-1之间出现能被n整除的，就不是素数。

进阶：不是质数一定可以写成两个数相乘的形式。那么我们只需要筛选比开方小的数就可以。

## 代码

```c
#include <stdio.h>
int main()
{
    int count=0;
    int n;
    scanf("%d",&n);
    for(int i=2;i<n;i++)
    {
        int j=2;
        for(;j<i;j++)
        {
            if(i%j==0)
                break;
        }
        if(i==j)
            count++;
    }
    //另一种写法：注意要包<math.h>
    //for (int i = 2; i < n; i++)
    //{
    //    int j = 2;
    //    for (; j <= (int)sqrt(i); j++)
    //    {
    //        if (i % j == 0)
    //            break;
    //    }
    //    if ((int)sqrt(i) < j)
    //        count++;
    //}
    printf("%d",count);
    return 0;
}
```

# [NC31第一个只出现一次的字符](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=188&&tqId=38575&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking)

## 解题思路

基本思路就是把出现的字符当作下标，每出现一次就加一。

最后遍历一遍，返回出现1的下标，否则就返回-1.

为了减少空间的浪费，我们只需要开A到z空间的大小。

## 代码

```c
int FirstNotRepeatingChar(char* str ) {
    int n=('z'-'A'+1);
    int len=strlen(str);
    int* a=(int*)malloc(sizeof(int)*n);
    memset(a, 0,sizeof(int)*n);
    for(int i=0;i<len;i++)
    {
        a[str[i]-'A']++;
    }
    for(int i=0;i<len;i++)
    {
        if(a[str[i]-'A']==1)
        {
            free(a);
            return i;
        }
    }
    free(a);
    return -1;
}
```



# [面试题 01.01. 判定字符是否唯一](https://leetcode.cn/problems/is-unique-lcci/)

## 解题思路

1.暴力的方法就是一个字符固定，然后和后面的一个一个进行比较

2.因为题目说明了都是小写字母![image-20220711195345548](https://s2.loli.net/2022/07/11/oYfhuT6JN1gwc5V.png)

所以我们从新创建一个空间，以字符的大小为下标，出现一次就在以该字符为下标的地方加1。

最后只需要遍历一下，只要没有出现不为1的，就是true，否则为false。

## 代码

+ 暴力：==时间复杂度O(N*N)，空间复杂度O(1)==

```c
bool isUnique(char* astr){
    int len=strlen(astr);
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(astr[i]==astr[j])
            return false;
        }
    }
    return true;
}
```

+ 另一种方法，==时间复杂度O(N)，空间复杂度O(1)==

```c
bool isUnique(char* astr){
    int len=strlen(astr);
    int n='z'-'a'+1;
    int* s=(int*)malloc(sizeof(int)*n);
    memset(s,0,sizeof(int)*n);
    for(int i=0;i<len;i++)
        s[astr[i]-'a']++;
    for(int i=0;i<len;i++)
    {
        if(s[astr[i]-'a']!=1)
        {
            free(s);
            return false;
        }
    }
    free(s);
    return true;
}

```

