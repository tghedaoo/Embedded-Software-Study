#include <memory>
#include <iostream>
#include <vector>

// Doubly Linked List Node Class.
class DLLNode
{
public:
    DLLNode();
    ~DLLNode() = default;
    explicit DLLNode(int value);

    void update_prev(DLLNode* prev);
    void update_next(DLLNode* next);

    int get_value();
    DLLNode* get_next();

private:
    int value_;
    DLLNode* prev_;
    DLLNode* next_;
};

class DLL
{
public:
    DLL();
    ~DLL();

    // return head and tail of the created list.
    void create_n_node_dll(int num_nodes);
    
    // print values and capacities.
    void print_dll();
    int dll_capacity();

    // Search for values at a specific location.
    int value_at_n_from_head(int n);
    int value_at_n_from_tail(int n);

    // Delete given DLL.
    void delete_dll();

private:
    DLLNode* head_;
    DLLNode* tail_;
    int capacity_;
};