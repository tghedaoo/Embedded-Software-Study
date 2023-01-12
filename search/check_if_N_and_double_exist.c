#include <stdbool.h>
#include <stdio.h>

// Binary search log(n)
// Hash map searching would be way way better.
bool search_num(int val, int* arr, int start, int end, int index)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        // Having 0 in the array is corner case.
        // mid != index checks if its val is 0 and in the same spot.
        if(arr[mid] == val && mid != index) 
        {
            return true;
        }
        else if (arr[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1; 
        }
    }

    return false;
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

// nlog(n) solution
bool checkIfExist(int* arr, int arrSize)
{
    // Here sorting is needed to get the binary search working
    // nlog(n) time
    qsort(arr, arrSize, sizeof(int), cmpfunc);   

    for(int i = 0; i < arrSize-1; i++)
    {
        // Note : 
        // left shift and right shift is feasible if the numbers are positive.
        // negative numbers would need an additional mask for the MSb to save the signage.
        int doub = arr[i] * 2; 
        if(search_num(doub, arr, 0, arrSize-1, i))
        {
            return true;
        }
    }
    return false;
}


void print(bool input)
{
    if(input)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}

int main()
{
    int array_input[4] = {10,2,5,3};
    print(checkIfExist(array_input,4));
    int array_input2[3] ={-16,-13,8};
    print(checkIfExist(array_input2,3));
    int array_input3[8] ={-20,8,-6,-14,0,-19,14,4};
    print(checkIfExist(array_input3,8));
    int array_input4[2] ={0,0};
    print(checkIfExist(array_input4,2));
    return 0;
}