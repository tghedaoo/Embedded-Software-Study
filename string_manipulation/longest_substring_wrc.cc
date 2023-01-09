// Longest Substring Without Repeating Characters
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2009/
// Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/127839/official-solution/

#include <string>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    // Correct_solution : Sliding Window technique
    // The sliding window is a hash set. Searching in this window is O(1).
    int lengthOfLongestSubstring(std::string s)
    {
        return 0;
    }

    // Correct_solution : Brute Force. Enumerate all substrings.
    // Pick each char and start making a non repeating char substring out of it. Find the biggest substring.
    // DOUBT: O(n²) or O(n³) time complexity.
    // O(min(m,n)) space.
    int lengthOfLongestSubstring_brute(std::string s)
    {
        int res = 0;
        for (int i = 0; i < (int)(s.length()-1); i++) // Important: typecast issue as s.length is unsigned int.
        {
            int j;
            std::unordered_set<char> substring;
            substring.insert(s.at(i));
            for (j = i+1; j < s.length(); j++)
            {
                // Saves search time as this is O(1). 
                if(substring.find(s.at(j)) == substring.end()) 
                {
                    substring.insert(s.at(j));
                }
                else
                {
                    break;
                }
            }
            res = (substring.size() > res) ? substring.size() : res;
        }
        return (s.length() <= 1) ? s.length() : res;
    }

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

};

int main()
{
    Solution solution_obj;

    std::cout << solution_obj.lengthOfLongestSubstring_brute("abcabcbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("bbbbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("pwwkew") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("au") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute(" ") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("") << std::endl;

    return 0;
}