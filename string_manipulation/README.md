# STRING MANIPULATION

1. **First Unique Character in a String** (C) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/ <br />
Create ***unordered_map of index and freq*** of a particular char (or) ***arrays of 26*** where the char number can be tracked with array indices.
Step 1: Get all chars and their corresponding latest indices and the number of times they appear. <br />
Step 2: Check the frequency array/map and see which char only appears once ie. a unique char. <br />
Step 3: Check the most minimum index among them. That is the first unique char ie. first index which a unique char appears. <br />

2. **String to Integer (atoi)** (C) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2010/ <br />
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
2 Approaches: <br />
    * ***Sliding window*** (fast) <br />
    
    * ***Brute force*** (slow and not favorable)<br />
    Enumerate all substrings. <br />
    Pick each char and start making a non repeating char substring out of it. Find the biggest substring. <br />
    DOUBT: O(n²) or O(n³) time complexity. <br />
    O(min(m,n)) space.



