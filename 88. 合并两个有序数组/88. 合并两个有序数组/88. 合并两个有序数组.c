#define _CRT_SECURE_NO_WARNINGS 1

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int a, b, c;
    a = m - 1;
    b = n - 1;
    c = nums1Size - 1;
    while (a && b)
    {
        if (nums1[a] > nums2[b])
        {
            nums1[c--] = nums1[a--];
        }
        else
        {
            nums1[c--] = nums2[b--];
        }
    }
    if (a == 0)
        while (b)
        {
            nums1[c--] = nums2[b--];
        }
}

int main()
{
    int nums1[6] = { 1, 2, 3, 0, 0, 0 }, m = 3, nums2[3] = { 2, 5, 6 }, n = 3;
    merge(nums1, 6, m, nums2, 3, n);
    return 0;
}