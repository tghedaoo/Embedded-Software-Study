#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Approach 1: No Sorting. 
// Catch : Duplicate handling.
// O(n²) time approach. We will have to take 2 elements to find the 3rd that gets us the sum.
// O(n) to traverse through the list and the other O(n) for 2 sum approach.
// O(n) space - will have to hold the vector in a map for O(1) search of an element.
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        unordered_map<int, int> input_map;
        for (int i = 0; i < nums.size(); i++)
        {
            input_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size() - 2; i++)
        {
            // 2 sum approach.
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int third_number = -1 * (nums[i] + nums[j]);
                if (input_map.find(third_number) != input_map.end() && input_map[third_number] != i && input_map[third_number] != j)
                {
                    vector<int> current_res = {nums[i], nums[j], third_number};
                    // check for duplicate set.

                    res.push_back(current_res);
                }
            }
        }
        return res;
    }
};