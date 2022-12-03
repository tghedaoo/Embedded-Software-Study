#include "linked_list.h"

llnode* create_ll_node(int val)
{
    llnode* node = (llnode*)malloc(sizeof(llnode));
    if(node != NULL)
    {
        node->value = val;
        node->next = NULL;
    }
    return node;
}

llnode* create_n_num_list(int n)
{
    if(n == 0)
    {
        return NULL;
    }

    llnode* head = create_ll_node(1);
    llnode* prev_node = head;

    for(int i = 2; i <= n; i++)
    {
        llnode* current_node = create_ll_node(i);
        // Here the problem is checking if a node is not successfully allocated.
        // Partial list can be formed here, or a seg fault may occur in the next cycle. (prev_node will be NULL)
        prev_node->next = current_node;
        prev_node = current_node;
    }

    return head;
}

void print_list(llnode* head)
{
    llnode* cursor = head;
    while(cursor != NULL)
    {
        printf("%d ",cursor->value);
        cursor = cursor->next;
    }
    printf(".\n");
}

void delete_list(llnode* head)
{
    llnode* cursor = head;
    llnode* current_node = NULL;
    
    while(cursor != NULL)
    {
        current_node = cursor;
        cursor = cursor->next;
        free(current_node);
    }
}