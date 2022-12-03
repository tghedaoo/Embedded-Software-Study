#include <stdio.h>
#include "linked_list/linked_list.h"

// Reverse a linked list using pointer storage in an array.
// O(n) time, O(n space)
llnode* reverse_ll(llnode* head)
{

}

int main()
{
    llnode* head = create_n_num_list(5);
    print_list(head);
    delete_list(head);
    return 0;
}