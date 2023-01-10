// Roman to Integer
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3107/
// Solution: https://leetcode.com/problems/roman-to-integer/solutions/529760/official-solution/

#include <string>
#include <unordered_map>
#include <iostream>

// This class might be slowing things down. Better to put the mapping in the solution function itself.
class R2Imapping
{
public:
    R2Imapping()
    {
        r2i_map['I'] = 1;
        r2i_map['V'] = 5;
        r2i_map['X'] = 10;
        r2i_map['L'] = 50;
        r2i_map['C'] = 100;
        r2i_map['D'] = 500;
        r2i_map['M'] = 1000;
    } 
    std::unordered_map<char, int> r2i_map;
};

class Solution 
{
public:
    static int romanToInt(std::string s) 
    {
        R2Imapping map;
        int sum = 0;
        int prev_val = 0;
        int curr_val = 0;

        for (int i = 0; i < s.length(); i++)
        {
            curr_val = map.r2i_map[s.at(i)];
            // In the leetcode solution, the one char ahead is also checked in every loop and iterator jumps 2 steps if satisfied. 
            if (prev_val < curr_val)
            {
                curr_val -= (2 * prev_val);
            }
            sum += curr_val;
            prev_val = curr_val;
        }

        return sum;
    }
};

int main()
{
    while(1)
    {
        std::cout << "enter roman number : ";
        std::string input;
        std::cin >> input;

        std::cout << "Integer: " << Solution::romanToInt(input) << std::endl;
    }

    return 0;
}