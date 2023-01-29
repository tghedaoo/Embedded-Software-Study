// QUEUE WITH LINKED LIST
// In C, Linked List can ensure that the queue can grow without restriction.
// Queue operations modify the list. Implements FIFO.
// Pop removes the first node. Push adds the node to the end.
// No memory wastage. But Heap used.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct QueueMember
{
    int val;
    struct QueueMember* next;
};
typedef struct QueueMember QueueNode;

// List Trackers.
QueueNode* head = NULL;
QueueNode* tail = NULL;

// Add a new element to the queue in the end.
void enQueue(int val)
{
    QueueNode* new_entry = (QueueNode*)malloc(sizeof(QueueNode));
    new_entry->val = val;
    new_entry->next = NULL;
    
    head = (head == NULL) ? new_entry : head;
    
    if(tail != NULL)
    {
        tail->next = new_entry;
    }
    tail = new_entry;    
}

// remove head node. That's the first element in the queue.
void deQueue()
{
    QueueNode* current_head = head;
    head = head->next;
    free(current_head); //Free the memory to avoid memory leak.
}

// get the first element in the queue.
int peek()
{
    return (head->val);
}

// Check if queue is empty
bool empty()
{
    return (head == NULL);
}

void print_queue()
{
    QueueNode* cursor = head;
    while(cursor != NULL)
    {
        printf("%d - ", cursor->val);
        cursor = cursor->next;
    }
    printf("|\n");
}

// --- MAIN ---
int main()
{

    enQueue(10);
    enQueue(20);
    deQueue();
    deQueue();
    printf("%d\n", empty());
    enQueue(30);
    printf("%d\n", peek());
    enQueue(40);
    enQueue(50);
    deQueue();
    printf("%d\n", empty());
    printf("%d\n", peek());

    print_queue();

    return 0;
}