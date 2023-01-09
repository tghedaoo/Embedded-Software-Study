# STRING MANIPULATION

1. First Unique Character in a String (C) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/ <br />

2. String to Integer (atoi) (C) <br />
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

3. Longest Substring Without Repeating Characters (C++) <br />
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2009/ <br />