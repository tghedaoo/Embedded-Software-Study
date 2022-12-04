#include <iostream>
#include <vector>

// --------------------------

class LLNode
{
public:
    LLNode() noexcept;
    explicit LLNode(int val) noexcept;
    explicit LLNode(int val, LLNode* next) noexcept;
    ~LLNode() noexcept = default;

    int value_;
    LLNode* next_;
};

LLNode::LLNode()
{
    value_ = 0;
    next_ = nullptr;
}

LLNode::LLNode(int val)
{
    value_ = val;
    next_ = nullptr;
}

LLNode::LLNode(int val, LLNode* next)
{
    value_ = val;
    next_ = next;
}

// --------------------------

void print_list(LLNode* head)
{
   LLNode* cursor = head;
   while (cursor != nullptr)
   {
    std::cout << cursor->value_ << "->";
    cursor = cursor->next_;
   } 
   std::cout << std::endl;
}

LLNode* reverse_list_On()
{
    
}

LLNode* reverse_list_O1()
{

}

int main()
{

    return 0;
}