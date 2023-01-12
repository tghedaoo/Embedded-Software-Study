#include <stdio.h>

// O(log(n)) time. O(1) space. Less stack usage as no recursion.
int search(int* nums, int numsSize, int target)
{
    int start = 0;
    int end = numsSize-1; // Take care here too.

    while (start <= end) // Equal because there can be one element only too.
    {
        int mid = (start + end) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1; 
        }
    }

    return -1;
}

int main()
{
    int array_input[6] ={-1,0,3,5,9,12};
    printf("%d\n", search(array_input, 6, 9));
    return 0;
}