// QUESTION: https://leetcode.com/explore/interview/card/apple/351/design/2053/
// SOLUTION: https://leetcode.com/problems/lru-cache/solutions/244744/official-solution/

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

    int key_;
    int value_;
    DLLNode *next_;
    DLLNode *prev_;
};

/// @brief  Main LRU Cache Class
/// Contains the hash map and corresponding DLL handling.
/// head of DLL is the most recent while tail is the least recent.
/// Any key added or touched is updated to be at the head.
/// In the event of capacity fulfilment, tail is removed.
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

    // Add Requested node to head.
    void add_to_head(DLLNode *node)
    {
        if (head_ != nullptr)
        {
            head_->prev_ = node;
            node->next_ = head_;            
            head_ = node;
        }
        else
        {
            head_ = node;
            tail_ = head_;
        }
    }

    // Remove node from between or end of the list.
    void remove_node(DLLNode* node)
    {
        DLLNode* prev_node = node->prev_;
        DLLNode* next_node = node->next_; 

        prev_node->next_ = next_node;
        
        // check if node at tail.
        if(node != tail_)
        {
            next_node->prev_ = prev_node;
        }
        else
        {
            tail_ = prev_node;
        }
            
        node->prev_ = nullptr;
        node->next_ = nullptr;
    }

    // Update head with most recently used key.
    void update_head(DLLNode *node)
    {
        // check tail
        if(node != head_)
        {
            remove_node(node);
            add_to_head(node);
        }
    }

    // Remove Least Recently Used Key.
    void remove_tail()
    {
        // From HashMap
        storage_.erase(tail_->key_);
        // From DLL
        DLLNode *tail_to_remove = tail_;
        tail_ = tail_->prev_;
        tail_->next_ = nullptr;
        delete (tail_to_remove);
    }

    void print_DLL()
    {
        DLLNode *cursor = head_;
        std::cout << "Current_size = " << current_size_ << std::endl;
        while (cursor != nullptr)
        {
            std::cout << cursor->key_ << ":" << cursor->value_;
            if (cursor->next_ != nullptr)
            {
                std::cout << "<->";
            }
            cursor = cursor->next_;
        }
        std::cout << std::endl;
    }

    // Get Value for the Key.
    int get(int key)
    {
        // If the key exists, update position and return value.
        if (storage_.find(key) != storage_.end())
        {
            update_head(storage_[key]);
            return storage_[key]->value_;
        }

        return -1;
    }

    // Put Value for the Key.
    void put(int key, int value)
    {
        // case 1: new key.
        if (storage_.find(key) == storage_.end())
        {
            DLLNode *new_node = new DLLNode(key, value);
            storage_[key] = new_node;
            // adding new nodes to head as they are naturally the most recent.
            add_to_head(new_node);

            // case 1a: if DLL has space.
            if (current_size_ < capacity_)
            {
                current_size_++;
            }
            // case 1b: if DLL is full.
            else
            {
                remove_tail();
            }
        }
        // case 2: key already exists.
        else
        {
            // update value for the key and move to head.
            storage_[key]->value_ = value;
            update_head(storage_[key]);
            // no size update.
        }
    }

private:
    std::unordered_map<int, DLLNode *> storage_;
    int current_size_;
    int capacity_;
    DLLNode *head_;
    DLLNode *tail_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // Example deployment : leetcode
    int capacity = 2;
    LRUCache *obj = new LRUCache(capacity);

    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1) << std::endl;
    obj->put(3, 3);
    std::cout << obj->get(2) << std::endl;
    obj->put(4, 4);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(4) << std::endl;

    return 0;
}