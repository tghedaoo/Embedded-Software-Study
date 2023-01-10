// Longest Substring Without Repeating Characters
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2009/
// Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/127839/official-solution/

#include <string>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    // Correct_solution 1: Sliding Window technique [Not optimized]
    // 2 trackers track the non-repeating substring.
    // right tracker expands until a repetition is seen.
    // light tracker moves until seen repetition is removed.
    // O(2n) worst case both trackers go n spaces = O(n) time complexity.
    // O(m) space, m - max size of window if unordered set used.
    // O(1) space if direct access table used.
    int lengthOfLongestSubstring(std::string s)
    {
        int len = s.length();

        int left = 0;
        int right = 0;
        int res = 0;

        // Direct Access Table taking 128 ASCII chars.
        uint8_t table[128] = {0}; 

        while(right < s.length())
        {
            char current_char = s.at(right);
            if(table[current_char] == 0)
            {
                table[current_char] = 1;
                int ss_len = right - left + 1;
                res = (res < ss_len) ? ss_len : res;
                ++right;
            }
            else if (table[current_char] == 1)
            {
                char left_char = s.at(left);
                table[left_char] = 0;
                ++left;
            }
        }

        return res;
    }

    // Correct_solution 2: Brute Force. 
    // Pick each char and start making a non repeating char substring out of it. Find the biggest substring.
    // In my solution here, we stop when we find a repeat char.
    // O(n²) time complexity.
    // O(min(m,n)) space.
    int lengthOfLongestSubstring_brute(std::string s)
    {
        int res = 0;
        // std::cout << s.length() - 1 << std::endl;
        for (int i = 0; i < (int)(s.length()-1); i++) // Important: typecast issue as s.length is unsigned int.
        {
            int j;
            std::unordered_set<char> substring;
            substring.insert(s.at(i));
            for (j = i+1; j < s.length(); j++)
            {
                // Saves search time as this is O(1). and doesn't create the entire substring again.
                // Even if we use a direct access table (char array [128]) here based on ASCII. this will be O(1).
                // In the O(n³) solution, here the whole substring from i to j is looped over and checked for repetition. Enumerate all substrings.
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

    // 1. Sliding Window.
    std::cout << "Sliding Window Solution" << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("au") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring(" ") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring("") << std::endl;

    // 2. Brute Force.
    std::cout << "Brute Force Solution" << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("abcabcbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("bbbbb") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("pwwkew") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("au") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute(" ") << std::endl;
    std::cout << solution_obj.lengthOfLongestSubstring_brute("") << std::endl;

    return 0;
}