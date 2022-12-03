#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct llnode
{
    int value;
    struct llnode* next;
}llnode;

// Function declarations.
// create one node
llnode* create_ll_node(int val);
// create n natural number list.
llnode* create_n_num_list(int n);
// print the contents of the node.
void print_list(llnode* head);
// delete the list. [This is C, so no RAII containment]
void delete_list(llnode* head);

#endif

