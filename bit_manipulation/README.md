# BIT MANIPULATION

## CHEAT SHEAT
[My Notes](https://drive.google.com/file/d/1yMp2blLH92lSgOJexTKLZR8p5Uy2qVIe/view?usp=sharing) <br />
*Here (or) is ' | '. Doing this due to markdown syntax* <br />

**BASICS**
|Task   | Expression  | Thoughts |
|---|---|---|
|set bit        | x (or)= (1 << pos)    | -|
|clear bit      | x &= ~(1 << pos)      | -|
|toggle bit     | x ^= (1 << pos)       | jumps between 1 and 0         |
|status check   | x &= (1 << pos)       | check if x is 0, else its 1.  |
|invert bits    | ~x                    | 1's compliement               |
|negative num   | ~x + 1                | 2's compliement               |
|right shift    | x >> 1                | division by 2, in power of 2 if multiple positions shifted    | 
|left shift     | x << 1                | multiplied by 2, in power of 2 if multiple positions shifted  |

**POSSIBLE QUESTIONS** <br />
More in the leetcode section. 
|Question   | Expression  | Thoughts |
|---|---|---|
|odd or even                | x & 1                 | if 1 its odd, else even   (x % 2 ==0)                 |
|convert any number to odd  | x | 1                 | if even, last bit changed. Else unchanged             | 
|Lowest set bit (LSb side)  | ans = x & -x          |                                                       |
|Power of 2  (approach 1)   | x = x & -x            | same number retrieved -> only one 1 bit in number set |
|Power of 2  (approach 2)   | 0 == x & (x-1)        | removes the only set bit thats is at the lowest bit position  |    
|**Hamming Weight**         | ans = x & (x-1)       | removes lowest set bit from number. loop ans until 0. |
|**Swap Bits**              | a = a ^ (1 << n) ^ (1 << m) | if bits same, return. Else, flip the bits       |       

## LEETCODE
[My Notes](https://drive.google.com/file/d/1Bgyo1it-MCAvFo60YM1Y6CWE8xdxUk5y/view?usp=sharing) <br />

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
Note: In C, the result string has to have a **'\0' (null termination)** or leetcode throws tantrums.
```
sum = (val_a ^ val_b ^ carry);
carry = (val_a & val_b) | (val_a & carry) | (carry & val_b);
```
3. **Add String** (C) <br /> 
4. **Counting Bits & Number of 1 Bits** (C) <br />
5. **Power of 2** (C) <br />
6. **Reverse Bits** (C) <br />
7. **Swap Bits in a given number** (C) <br /> 


