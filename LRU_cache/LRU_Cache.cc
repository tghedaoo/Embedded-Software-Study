// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// 
// Implement the LRUCache class:
// 
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

#include <unordered_map>
#include <iostream>


/// @brief  Doubly Linked List Node.
class DLLNode
{
public:
    DLLNode(int key, int value)
    {
        key_ = key;
        value_ = value;
        next_ = nullptr;
        prev_ = nullptr;
    }

    int get_val()
    {
        return value_;
    }

    void update_next(DLLNode* node)
    {
        next_ = node;
    }

    void update_prev(DLLNode* node)
    {
        prev_ = node;
    }

private:
    int key_;
    int value_;
    DLLNode* next_;
    DLLNode* prev_;
};

/// @brief  Main LRU Cache Class
/// Contains the hash map and corresponding DLL markings for tracking purposes.
class LRUCache 
{
public:
    LRUCache(int capacity) 
    {
        current_size_ = 0;
        capacity_ = capacity;
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    int get(int key) 
    {
        // If the key exists, update position and return value.   
        if (storage_.find(key) != storage_.end())
        {
            DLLNode* requested_node = storage_[key];
            if(head_ != requested_node)
            {
                // update requested node as most recently used i.e. make that the head.
            }
            return storage_[key]->get_val();
        }
        // else return -1
        return -1;     
    }
    
    void put(int key, int value) 
    {
        // case 1: empty list.
        if(current_size_ == 0)
        {   
            head_ = new DLLNode(key, value);  
            storage_[key] = head_;
            tail_ = head_;
            current_size_++;  
        }
        else
        {
            // case 2a: non-empty list. key already exists.
            if(storage_.find(key) != storage_.end())
            {
                // update value for the key and move to head.
                // no size update.
            }
            // case 2b: non-empty list. new key.
            else
            {
                // case 2b1: if DLL is full.
                if(current_size_ == capacity_)
                {
                    // remove tail as it is the oldest.
                    // add new key to head.
                }
                // case 2b2: if DLL is not full.
                else
                {
                    current_size_++;
                }

            }
        }

        // case 2: non-empty list.

        // case 3: full list.
    }

private:
    std::unordered_map<int, DLLNode*> storage_;
    int current_size_;
    int capacity_;
    DLLNode* head_;
    DLLNode* tail_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int capacity = 5;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(10,69);
    std::cout << obj->get(10) << std::endl;

    return 0;
}