#include <stdio.h>

int* moveZeroes(int* nums, int numsSize)
{
    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[k++] = nums[i];
        }
    }

    // Manually make all remaining positions zero.
    for(int i = k; i < numsSize; i++)
    {
        nums[i] = 0;
    }

    return nums;
}

void print(int* input, int inputSize)
{
    printf("{");
    for (int i = 0; i < inputSize; i++)
    {
        printf("%d,", input[i]);
    }
    printf("}\n");
}

int main()
{
    int nums1[5] = {0,1,0,3,12};
    int nums2[1] = {0};
    print(moveZeroes(nums1, 5), 5);
    print(moveZeroes(nums2, 1), 1);
    return 0;
}