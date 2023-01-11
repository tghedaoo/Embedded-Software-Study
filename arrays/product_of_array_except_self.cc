// Product of Array Except Self
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3113/
// Solution: https://leetcode.com/problems/product-of-array-except-self/solutions/291880/official-solution/

#include <iostream>
#include <vector>

class Solution
{
public:

    // The catch here is : Division to find the product at an index is not possible because input can have 0.
    // We need to find products on both sides of an index i. 
    // If for every index, we do the product every time in the left and right we will have O(n²).

    // Approach 1: O(n) space. [Left and Right Product Containers]
    // Optimized by only doing the right container and doing left product on the fly.
    // This is O(n) time  
    static std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        // Find products on both sides of i. first for i = 0;
        int left_product = 1;
        int right_product_val = 1;

        std::vector<int> right_product;
        std::vector<int> result;

        // O(n)
        for (int i = nums.size()-1; i >= 0; i--)
        {
           right_product.push_back(right_product_val);
           right_product_val *= nums[i];
        }

        // O(n) for reversal.
        std::reverse(right_product.begin(), right_product.end());

        // O(n)
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(left_product * right_product[i]);
            left_product *= nums[i];
        }

        return result;
    }
};

template <typename dataType>
void print_vector(std::vector<dataType> input)
{
    std::cout << "[";
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << ",";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> input{1, 2, 3, 4};
    print_vector<int>(Solution::productExceptSelf(input));

    return 0;
}
