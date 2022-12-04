#include <stdio.h>
#include "linked_list.h"

// Reverse a linked list using pointer storage in an array.
// O(n) time, O(n space)
llnode* reverse_ll(llnode* head)
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

    return head;
}

int main()
{
    llnode* head = create_n_num_list(5);
    print_list(head);
    printf("%d \n", size_of_ll(head));

    llnode* new_head = reverse_ll(head);
    print_list(new_head);
      
    delete_list(new_head);

    return 0;
}