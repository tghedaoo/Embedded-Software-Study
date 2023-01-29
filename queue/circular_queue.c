// CIRCULAR QUEUE WITH ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

// Global Queue Trackers and Holders. C++ helps encapsulation.
int front = -1;
int rear = -1;
int* queue;
int capacity = CAPACITY;

bool isEmpty_()
{
    return (front == -1 && rear == -1);
}

bool isFull_()
{
    return (((rear+1) % capacity) == front);
}

bool enQueue_(int value)
{
    if(isFull_())
    {
        printf("queue full: not allowed.\n");
        return false;
    }

    if(isEmpty_())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % capacity; // This is the circular case catch.
    }  

    queue[rear] = value;
    return true;
}

bool deQueue_()
{
    if(isEmpty_())
    {
        printf("queue empty: not allowed.\n");
        return false;
    }

    // Only one element in list
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }

    return true;
}

int peek_front_()
{
    // -1 is not an efficient return value considering int in the queue.
    return (front == -1) ? -1 : queue[front]; 
}

int peek_rear_()
{
    // -1 is not an efficient return value considering int in the queue.
    return (rear == -1) ? -1 : queue[rear];
}



void display_()
{
    // special printing style to handle cyclic case.
    int iter = front;
    while(iter != rear)
    {
        printf("%d ", queue[iter]);
        iter = (iter+1) % capacity;
    }
    printf("%d .\n", queue[iter]);
}

int main(int argc, char* argv[])
{
    queue = (int*)malloc(sizeof(int) * capacity);
    
    enQueue_(2);
    enQueue_(1);
    enQueue_(5);
    enQueue_(6);
    enQueue_(7);
    
    display_();
    
    deQueue_();
    deQueue_();
    
    display_();
    
    enQueue_(0);
    
    printf("front = %d \n", peek_front_());
    printf("rear = %d \n", peek_rear_());
    display_();

    enQueue_(10);
    enQueue_(12);

    display_();
    
    free(queue);
    return 0;
}

