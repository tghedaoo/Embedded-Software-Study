# BIT MANIPULATION

1. **Missing Number** (C++) <br /> 
https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3114/ <br />
My Code: [here](missing_numbers.cpp) <br />
***Time complexity: O(n)*** <br />
***Space complexity: O(1)*** <br />
XOR all the way. XOR all indexes with the given array.

2. **Add Binary** (C) <br /> 
https://leetcode.com/problems/add-binary/description/ <br />
My Code: [here](add_binary.c) <br />
***Time complexity: O(n)*** <br />
***Space complexity: O(1)*** <br />
The basic catch here is to retrieve the char as an integer and get the 0 or 1. The bit wise addition looks like this. <br />
This is a full adder circuit. <br />
Return either the first or second address of result based on carry. <br />
Note: In C, the result string has to have a '\0' or leetcode throws tantrums.
```
sum = (val_a ^ val_b ^ carry);
carry = (val_a & val_b) | (val_a & carry) | (carry & val_b);
```

