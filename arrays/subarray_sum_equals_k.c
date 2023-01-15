#include <stdio.h>

// moving window approach
// This is not necessarily a sorted array.
int subarraySum(int* nums, int numsSize, int k)
{
    int subarray_count = 0;
    int left = 0;
    int right = 0;
    int current_sum = 0;

    while (left < numsSize || right < numsSize)
    {

        if(current_sum == k)
        {
            subarray_count++;
            left++;
        }
    }

    return subarray_count;
}

int main()
{

    return 0;
}