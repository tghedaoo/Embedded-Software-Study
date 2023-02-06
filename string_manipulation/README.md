# STRING MANIPULATION

1. **First Unique Character in a String** (C) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/ <br />
My Code: [here](first_unique_character.c) <br />
Create ***unordered_map of index and freq*** of a particular char (or) ***arrays of 26*** where the char number can be tracked with array indices.
Step 1: Get all chars and their corresponding latest indices and the number of times they appear. <br />
Step 2: Check the frequency array/map and see which char only appears once ie. a unique char. <br />
Step 3: Check the most minimum index among them. That is the first unique char ie. first index which a unique char appears. <br />

2. **String to Integer (atoi)** (C) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2010/ <br />
My Code: [here](string_to_integer_atoi.c) <br />
**Important points:** <br />
* On the fly - overflow and underflow check to avoid runtime output variable overflow or underflow.
```
Sign is added later. Therefore overflow checked. Underflow is represented after checking sign.
if(result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10))
```
* Appending Digits from Lsb.
```
result = 10 * result + digit;
```
* ASCII conversions (char to int)
```
isdigit();      // to check digit in C++ or do it manually
char - '0';     // get the integer digit on the char representation. (ASCII of digit - ASCII of 0) 
```
 <br />

3. **Longest Substring Without Repeating Characters** (C++) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2009/ <br />
My Code: [here](longest_substring_wrc.cc) <br />
2 Approaches: <br />
    * ***Sliding window*** (fast) <br />
    **TODO**: optimized version which uses index array. <br />
    Uses **2 pointer approach**. This creates a window of non-repeating substrings. <br />
    Right pointer expands until a repetition is seen.  <br />
    Light pointer moves until seen repetition is removed. <br />
    O(2n) worst case both trackers go n spaces = O(n) time complexity. <br />
    O(m) space, m - max size of window if unordered set used. <br />
    O(1) space if direct access table used.
    * ***Brute force*** (slow and not favorable)<br />
    Pick each char and start making a non repeating char substring out of it. Find the biggest substring. <br />
    O(n²)T ; O(min(m,n))S: <br />
    Stop enumerating when we find a repeat char. Substring handling is opitmized with an unordered set. char search is O(1) <br />
    O(n³)T ; O(1)S : <br />
    Enumerate all substrings even if a repeat found. if at each step the entire substring is checked for repition which is O(n). <br />

Consider the following:
```
int res = s.length() - 1
```
*If s.length is 0, the res is not -1, instead it is 18446744073709551615 which is (2⁶⁴ - 1) as it is naturally converted to unsigned int (int is 64 bits in my machine). Return type of s.length() is unsigned int and therefore explicitly typecast it to 'int' to avoid this issue.*

4. **Roman to Integer** (C++) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3107/ <br/>
My Code: [here](roman_to_integer.cc) <br />
The roman numerals and corresponding integers are put in a hash map (unordered map). <br />
In the leetcode solution, the one char ahead is also checked in every loop and iterator jumps 2 steps if satisfied. This is further optimized by putting the combined special characters eg. IV in the mapping itself.<br />
In my solution, I have touched only one char at a time and have stored the previous value. If prev is less than the current, I subtract the values from the sum and the current val and add the remainder to the sum. <br />

5. **Valid Anagram** (C) <br /> https://leetcode.com/explore/interview/card/apple/346/sorting-and-searching/2027/