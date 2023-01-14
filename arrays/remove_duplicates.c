#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int k = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i] != nums[k])
        {
            nums[++k] = nums[i];
        }
    }
    return k+1;
}

int main()
{
    int nums1[3] = {1,1,2};
    int nums2[10] = {0,0,1,1,1,2,2,3,3,4};
    printf("%d\n", removeDuplicates(nums1, 3));
    printf("%d\n", removeDuplicates(nums2, 10));
    return 0;
}