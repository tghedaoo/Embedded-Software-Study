// QUEUE WITH ARRAY

#include <iostream>
#include <memory>

class Queue
{
public:
    Queue(int queue_size)
    {
        // creating a dynamically allocated queue space.
        queue_ = new int(queue_size);
        front_ = -1;
        rear_ = -1;
    }

    ~Queue()
    {
        // freeing dynamically allocated memory.
        delete(queue_);
    }

    bool enqueue(int value)
    {
        if(isFull())
        {
            return false;
        }

        // first element / empty case.
        if(isEmpty())
        {
            front_ = 0;
            rear_ = 0;
        }
        else
        {
            rear_++;
        }
        
        queue_[rear_] = value;
        return true;
    }

    bool dequeue()
    {
        if(isEmpty())
        {
            return false;
        }

        // One element corner case.
        if(front_ == rear_)
        {
            front_ = -1;
            rear_ = -1;
        }
        else
        {
            front_++;
        }

        return true;
    }


    // What to return depends on the contains of the queue. -1 may not be ideal for int.
    int front() //peek()
    {
        return (isEmpty()) ? -1 : queue_[front_];
    }

    // What to return depends on the contains of the queue. -1 may not be ideal for int.
    int rear()
    {
        return (isEmpty()) ? -1 : queue_[rear_];
    }

    bool isEmpty()
    {
        return (front_ == -1 && rear_ == -1);
    }

    bool isFull()
    {
        return (rear_ == capacity_ - 1); //This is inefficient and therefore circular queue.
    }

    void display()
    {
        for (int i = front_; i <= rear_; i++)
        {
            std::cout << queue_[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* queue_;
    int front_;
    int rear_;
    int capacity_;
};


int main()
{
    Queue queue(5); 

    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(1);
    queue.display();
    std::cout << queue.front() << std::endl;
    queue.dequeue();
    std::cout << queue.front() << std::endl;
    std::cout << queue.rear() << std::endl;
    queue.display();
    

    return 0;
}