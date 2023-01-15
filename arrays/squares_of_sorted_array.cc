#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // Approach 1: O(n). The 2 pointer approach.
    static vector<int> sortedSquares(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;

        // This is needed to populate the ends of this vector.
        // Or push as usual and reverse. [reversing is O(n)].
        vector<int> res(nums.size()); 
        int res_pos = right;

        while(left <= right)
        {
            int square = 0;
            if(abs(nums[left]) > abs(nums[right]))
            {
                square = nums[left];
                left++;
            }
            else
            {
                square = nums[right];
                right--;
            }
            res[res_pos] = square * square;
            res_pos--;
        }
        return res;
    }

    // Approach 2: O(nlog(n)). Straight forward but to square result sorting.
    static vector<int> sortedSquares_sort(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};

void print(vector<int> input)
{
    for(auto i : input)
    {
        cout << i << ",";
    }
    cout << endl;
}

int main()
{
    vector<int> input1 = {-4,-1,0,3,10};
    vector<int> input2 = {-7,-3,2,3,11};

    cout << "2 pointer approach" << endl;
    print(Solution::sortedSquares(input1));
    print(Solution::sortedSquares(input2));

    cout << "sorting" << endl;
    print(Solution::sortedSquares_sort(input1));
    print(Solution::sortedSquares_sort(input2));

    return 0;
}