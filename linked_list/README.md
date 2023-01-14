# LINKED LIST

1. **Reverse Linked List**(C) <br />
https://leetcode.com/explore/interview/card/apple/345/linked-list/2024/ <br />
My Solution: [here](reverse_linked_list.c) <br />
***Time complexity: O(n)*** <br />
***Space complexity: O(1) or O(n)*** <br />
2 approaches: <br />
* Save all node pointers in a vector and start connecting again from the last node. O(n) space.<br />
* Use three pointers. Track previous, current and next node and reverse the connection. O(1) space.<br />

2. **Merge 2 Sorted Lists** (C++) <br />
https://leetcode.com/problems/merge-two-sorted-lists/submissions/871600832/ <br />
My Solution: [here](merge_2_sorted_lists.cc) <br />
***Time complexity: O(m+n)*** <br />
***Space complexity: O(1)*** <br />
Create a dummy node to start from and compare nodes from 2 lists and select the minimum one. <br /> 