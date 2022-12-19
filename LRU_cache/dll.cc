#include "dll.hh"

DLLNode::DLLNode()
: value_(0), prev_(nullptr), next_(nullptr)
{

}

DLLNode::DLLNode(int value)
: value_(0), prev_(nullptr), next_(nullptr)
{
    value_ = value;
    prev_ = nullptr;
    next_ = nullptr;    
}

void DLLNode::update_prev(DLLNode* prev)
{
    prev_ = prev;
}

void DLLNode::update_next(DLLNode* next)
{
    next_ = next;
}

int DLLNode::get_value()
{
    return value_;
}

DLLNode* DLLNode::get_next()
{
    return next_;
}

// -------- 

DLL::DLL()
: head_(nullptr), tail_(nullptr), capacity_(0)
{

}

DLL::~DLL()
{
    // delete_dll();
}

void DLL::create_n_node_dll(int num_nodes)
{
    DLLNode* prev_node = nullptr;
    std::vector<DLLNode*> res;

    for(int i = 0; i < num_nodes; i++)
    {
       DLLNode* ptr = new DLLNode(i);
       // assuming we get a dynamically allocated block succcessfully.
       if(i == 0)
       {
            head_ = ptr;
            prev_node = head_;
            tail_ = head_;
       }
       else
       {
            ptr->update_prev(prev_node);
            prev_node->update_next(ptr);
            prev_node = ptr;
            tail_ = ptr;
       } 
       ++capacity_;
    }
}

void DLL::print_dll()
{
    DLLNode* cursor = head_;
    
    while(cursor != nullptr)
    {
        std::cout << cursor->get_value() << " <-> ";
        cursor = cursor->get_next();
    }
    std::cout << "END" << std::endl;
}

int DLL::dll_capacity()
{
    return capacity_;
}