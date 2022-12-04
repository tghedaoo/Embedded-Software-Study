#include <stdio.h>
#include "linked_list.h"

// Reverse a linked list using pointer storage in an array.
// O(n) time, O(n) space
llnode* reverse_ll_s1(llnode* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    int list_size = size_of_ll(head);
    llnode** node_list = (llnode**)malloc(sizeof(llnode*) * list_size);
    if(node_list == NULL)
    {
        return NULL;
    }

    // store all node addresses.
    llnode* cursor = head;
    int iter = 0;
    while (cursor != NULL)
    {
        node_list[iter] = cursor;
        cursor = cursor->next;
        iter++;
    }

    // reverse the list by traversing from the back of the stored list.
    for(int i = list_size-1; i > 0; i--)
    {
        node_list[i]->next = node_list[i-1];
    }
    node_list[0]->next = NULL;
    head = node_list[list_size-1];

    // https://www.quora.com/How-do-I-correctly-free-a-double-pointer-in-C
    free(node_list); // The entities in the node_list is not freed as they are a part of the linked list.
    return head;
}

// Reverse a linked list using 3 pointer approach.
// Here we are sharing the reference to the head address, so that we can modify the head.
// O(n) time, O(1) space
void reverse_ll_s2(llnode** head)
{
    if(*head == NULL)
    {
        return;
    }

    llnode* cursor = *head;
    llnode* prev_cursor = NULL;
    llnode* next_cursor = NULL;

    while (cursor != NULL)
    {
        next_cursor = cursor->next;
        cursor->next = prev_cursor;
        prev_cursor = cursor;
        cursor = next_cursor;
    }

    *head = prev_cursor;
}

int main()
{
    // Solution 1: Store addresses.
    llnode* head = create_n_num_list(5);
    print_list(head);
    printf("%d \n", size_of_ll(head));
    llnode* new_head = reverse_ll_s1(head);
    print_list(new_head);
    delete_list(new_head);

    // Solution 2: Three pointers and on the spot change.
    llnode* head2 = create_n_num_list(10);
    print_list(head2);
    printf("%d \n", size_of_ll(head2));
    reverse_ll_s2(&head2);
    print_list(head2);
    delete_list(head2);

    return 0;
}