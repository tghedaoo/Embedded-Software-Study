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
Approach 2: ***O(1)*** space.

* valid_parantheses
* remove element & remove duplicates & move zeros to end.
* check if N and its double exist
