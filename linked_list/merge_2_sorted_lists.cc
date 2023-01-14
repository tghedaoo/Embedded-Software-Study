// Merge Two Sorted Lists
// https://leetcode.com/explore/interview/card/apple/345/linked-list/2022/
// https://leetcode.com/problems/merge-two-sorted-lists/solutions/127763/official-solution/

#include <memory>
#include <iostream>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *cursor1 = list1;
        ListNode *cursor2 = list2;

        // Important: start with a dummy node to link the nodes from both the lists.
        // Dummy node not exactly needed. (Try to have a non-pointer variable here)
        // ListNode *result = new ListNode();
        // Try smart pointer here for dummy node.
        std::shared_ptr<ListNode> result = std::make_shared<ListNode>();
        ListNode *cursor = result.get(); // Get the pointer from smart pointer object.
        // This node will get deallocated once the merge is complete as it goes out of scope.

        while(cursor1 != nullptr && cursor2 != nullptr)
        {
            if(cursor1->val <= cursor2->val)
            {
                cursor->next = cursor1;
                cursor1 = cursor1->next;
            }
            else
            {
                cursor->next = cursor2;
                cursor2 = cursor2->next;
            }
            cursor = cursor->next;
        }

        // --- Instead of 
        // if(cursor1 == nullptr)
        // {
        //     cursor->next = cursor2;
        // }
        // else if(cursor2 == nullptr)
        // {
        //     cursor->next = cursor1;
        // }
        // --- Complete in one line. 
        // If cursor1 is not null then cursor2 is null as the above loop exits in this case too.
        // Even if both are null, it will pick it up as null.
        cursor->next = (cursor1 == nullptr) ? cursor2 : cursor1;

        return result->next;
    }
};

ListNode* getList(int* list, int num)
{
    ListNode* head = new ListNode(list[0]);
    ListNode* cursor = head;
    for(int i = 1; i < num; i++)
    {
        cursor->next = new ListNode(list[i]);
        cursor = cursor->next;   
    }
    return head;
}

void print_list(ListNode* head)
{
   ListNode* cursor = head;
   while (cursor != nullptr)
   {
    std::cout << cursor->val << " ";
    cursor = cursor->next;
   } 
   std::cout << std::endl;
}

int main()
{
    int list_1[] = {1,4,5}; 
    int list_2[] = {1,2,3,6}; 
    
    ListNode* list1 = getList(list_1, 3);
    print_list(list1);
    ListNode* list2 = getList(list_2, 4);
    print_list(list2);
    ListNode* result = Solution::mergeTwoLists(list1, list2);
    print_list(result);

    return 0;
}