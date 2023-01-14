# ARRAYS

1. **Product of array except self** (C++) <br /> 
https://leetcode.com/problems/product-of-array-except-self/description/ <br />
My Code: [here](product_of_array_except_self.cpp) <br />
***Time complexity: O(n)*** <br />
***Space complexity: 2 approaches*** <br />
We need to find products on both sides of an index i. If for every index, we do the product every time in the left and right we will have O(n²). <br />
The catch here is : Division of the array's complete product to find the product at an index is not possible because input can have 0. Therefore, product calculation has to happen on both sides of the index.<br />
Approach 1: ***O(n)*** space. [Left and Right Product Containers] <br />
Optimized by only doing the container for the right side i.e. starting from the end of the array and storing products as we travel left towards the start. For the left side, the product can be calculated on the fly as we are travelling right to calculate result.<br />
Approach 2: ***O(1)*** space. **TODO**

2. **Valid Paranthesis** (C) <br /> 
https://leetcode.com/problems/valid-parentheses/ <br />
My Code: [here](valid_parantheses.c) <br />
***Time complexity: O(n)*** <br />
***Space complexity: O(n)*** <br />
This is a classic **stack** problem. <br />
In C we can create a dynamic allocation of the stack of the size of the input array. In C++ this can be a vector or stack container. <br />
Whenever we encounter a open parantheses, we store it in stack and we pop it of if we encounter a closing paratheses equal to the opening one. <br />
If this condition is not statisfied or if the stack is not empty in the end, we say its invalid.

3. **Removing Elements, Duplicates(from sorted array) or Move Zeros** (C) <br />
https://leetcode.com/problems/remove-element/ <br />
My Code: [Remove Element](remove_element.c) <br />
https://leetcode.com/problems/remove-duplicates-from-sorted-array/ <br />
My Code: [Remove Duplicates](remove_duplicates.c) <br />
https://leetcode.com/problems/move-zeroes/<br />
My Code: [Move Zeros](move_zeros.c) <br />
***Time complexity: O(n)*** <br />
***Space complexity: O(1)*** <br />
Fundamentally, traversing the array from start. We have a pointer tracking the new set of values being added in-place. <br />
The tracker keeps moving with the normal cursor(moving along the array) based on the replacement needs as per the question. <br />
We overwrite duplicates, target elements or zeros with the exisiting values. For zeros, we manually add it after all non-zero values are put in-place.<br />
