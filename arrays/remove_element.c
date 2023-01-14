#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int k = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }    
    return k;
}


int main()
{
    int nums1[4] = {3,2,2,3};
    int nums2[8] = {0,1,2,2,3,0,4,2};
    printf("%d\n", removeElement(nums1, 4, 3));
    printf("%d\n", removeElement(nums2, 8, 2));
    return 0;
}