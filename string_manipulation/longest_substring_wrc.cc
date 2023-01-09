// Longest Substring Without Repeating Characters
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2009/
// Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/127839/official-solution/

#include <string>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    // Incorrect solution as it doesn't check for previously touched chars.
    // Using hash_set though is the fastest as searching the substring is O(1)
    int lengthOfLongestSubstring_incorrect(std::string s) 
    {
        if(s.length() <= 1)
            return s.length();

        int res = 0;
        int current_res = 0;
        
        std::unordered_set<char> substring; 

        for (int iter = 0; iter < s.length(); iter++)
        {
            if(substring.find(s.at(iter)) == substring.end())
            {
                ++current_res;
                substring.insert(s.at(iter));
            }
            else
            {
                substring.clear();
                substring.insert(s.at(iter));
                res = (current_res > res) ? current_res : res;
                current_res = 1;
            }
        }
        return (current_res > res) ? current_res : res;
    }

    // Correct_solution : Sliding Window technique
    // The sliding window is a hash set. Searching in this window is O(1).
    int lengthOfLongestSubstring(std::string s)
    {

    }
};

int main()
{
    Solution solution_obj;

    std::cout << solution_obj.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("pwwkew") << std::endl;

    int res = solution_obj.lengthOfLongestSubstring("au");
    std::cout << res << std::endl;

    return 0;
}