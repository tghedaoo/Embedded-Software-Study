# SEARCH ALGOS

## ALGOS
**Linear Search** <br /> 
* O((n)) <br />
As we go through all the elements one by one.

**Binary Search** <br /> 
* O(log(n)) <br />
[My Notes](https://drive.google.com/file/d/1vUzO_HPzV1Ad8uRkqTfZSd2SRPrV6DNF/view?usp=share_link) <br />
Pre-requisite: The array needs to be sorted. <br />
Start from the mid of the sorted array and if the value is less go towards the left else go right.

**STL Container Searches** <br /> 
[Source Article](https://medium.com/@gx578007/searching-vector-set-and-unordered-set-6649d1aa7752#:~:text=The%20time%20complexity%20to%20find,complexity%20notation%20ignores%20constant%20factors.) <br />
***find()*** method is used to search for a key(in case of map/set) or value(in case of vector) in the container.
An iterator to the element, if an element with specified key is found, or ***end()*** otherwise.
* O(1) for unordered map/set. O(n) worst case. This is hash table.
* O(log(n)) for ordered map/set because the elements are sorted in Balanced Binary Search tree (BST).
* O(n) for vector due to linear search.

**Interpolation Search** <br /> 
[My Notes](https://drive.google.com/drive/folders/1dvLXpJWTN4uBqwFptThfbtKwj1xAyN1a) <br />
(Only asked by Tesla)

## LEETCODE
1. **Binary Search** (C) <br /> 
https://leetcode.com/problems/binary-search/ <br />
My Code: [here](binary_search.cpp) <br />
***Time complexity: O(log(n))*** <br />
***Space complexity: O(1)*** <br />

2. **Check If N and Its Double Exist** (C / C++) <br /> 
https://leetcode.com/problems/check-if-n-and-its-double-exist/ <br />
My Code: [C here](check_if_N_and_double_exist.c) <br />
My Code: [C++ here](check_if_N_and_double_exist.cpp) <br />
***Time complexity: O(nlog(n)) or O(n)*** <br />
***Space complexity: O(1) or O(n)*** <br />
Important: ***mid != index*** Check if the found double is at the same index, because the array might have 0s.<br />
C++ Solution: Save the array in a unordered_map (save the indexes also). Find double and verify index. Therefore O(n) time and space. <br />
C Solution: binary search but for that too work we need to sort the array. Also cross-check current index. Therefore O(nlog(n)) time. <br />

3. https://leetcode.com/problems/top-k-frequent-words/submissions/887757590/