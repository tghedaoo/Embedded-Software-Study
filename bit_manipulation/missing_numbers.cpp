#include <iostream>
#include <vector>

class Solution {
public:
    static int missingNumber(std::vector<int>& nums) 
    {
        int ans = nums.size();
        
        // The error here was that i was setting ans that changes with every loop.
        for(int i = 0; i < nums.size(); i++) 
        {
            ans ^= (nums[i] ^ i);
        }
        
        return ans;
    }
};

class Solution1 {
public:
    static int missingNumber(std::vector<int>& nums) {
        int ans=nums.size();
        for(int i=0;i<nums.size();i++) ans ^= (nums[i]^i);
        return ans;
    }
};

int main()
{
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(1);
    std::cout << Solution::missingNumber(nums) << std::endl;
    std::cout << Solution1::missingNumber(nums) << std::endl;
    return 0;
}
