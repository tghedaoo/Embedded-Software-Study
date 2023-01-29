# Embedded Systems Software / Firmware Study Material

# CONCEPTS

## Embedded Systems
1. [Endianess](endianess_check/README.md)
2. [Socket Programming](socket_programming/README.md)
3. [Bit Manipulation](bit_manipulation/README.md)
4. [Operating Systems](operating_systems/README.md)
5. [Peripherals](peripherals/README.md)
6. [Boot Sequence](operating_systems/boot_process.md)

## Data Structures & Algorithms
1. [Arrays](arrays/README.md) 
2. [Linked List](linked_list/README.md)
3. [Search Algos](search_algos/README.md)
4. [Queue](queue/README.md)
5. [Stack]()
6. [Tree](tree/README.md) 
7. [String mainpulation](string_manipulation/README.md)

## C++ programming
### Encapsulation, Inheritance, Polymorphism, Abstraction. 
* [Inheritance](c++_concepts/inheritance.md) - Base & Derived Class, Indirect Inheritance, Abstract Class, Dynamic Polymorphism. 
(TODO - Friend class, multiple inheritance, Diamond problem)
* Dynamic Polymorphism - Runtime polymorphism. See Inheritance and Keywords doc.
* [Static Polymorphism]()
(TODO - Templates and Overloading - Operator, Function.)
* [Move and Copy Semantics](c++_concepts/move_copy_semantics.md)
* [RAII](c++_concepts/RAII.md)
* [Smart pointer](c++_concepts/smart_pointer.md)
* [V-Table](c++_concepts/VTable.md)
* [keywords](c++_concepts/keywords.md): static, volatile, const, virtual
(TODO - virtual class, constexpr, noexcept)
* Design Patterns: Factory, Visitor.
* STL - string, vector, stack, map, unordered_map, set, unordered_set.

## C programming
* [String Functions](https://www.programiz.com/c-programming/string-handling-functions)
* [Dynamic Memory Allocation](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
* [Variable Arguments for a function](https://www.geeksforgeeks.org/variable-length-argument-c/)
    * Good Example: [here](https://en.cppreference.com/w/c/variadic)
* [Volatile Keyword](https://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766)
* [C Posix Library IEEE 1003](https://en.wikipedia.org/wiki/C_POSIX_library)
* [Structure padding and packing](structures_union/structure_padding_and_packing.md)

# CODING QUESTIONS



## Advanced Questions
1. **LRU Cache** (C++) <br />
https://leetcode.com/problems/lru-cache/description/ <br />
[My Code](LRU_Cache/LRU_Cache.cc)
LRU Cache needs a hash map mapping the nodes of a Doubly Linked List. The DLL tracks the least recently used key. <br />
When a new key or a recently used key comes in, the DLL updates in such a way that the key in question ends up at the head. <br />
Naturally the tail node becomes the least recently used one. This is removed whenever the list reaches capacity. <br />
Note: To avoid time exceed issue, remove extra functions from the class and hard code the ops. <br />

# Code Review Practices.
Code review practices: https://www.youtube.com/watch?v=3pth05Rgr8U <br />

# LLDB Debugger.
LLDB debugging for Mac M1: https://www.youtube.com/watch?v=v_C1cvo1biI (Allow access to see code breakpoints.) <br />
General command flow: 
Add a breakpoint at main or any line number of your choice.
```
lldb 'your_exec_file'
b main
run
gui
```
Use command "help" to see all commands.<br />
In gui, it's easy to visually see the current variables and states. Useful for investigating seg faults.<br />
'n' to go next line. <br />
's' to step in. <br />

# ISO 26262.
### *Issues with C*
1. Unspecified behaviour (sequence of evaluation)
2. Undefined behaviour (overflow/ underflow issues)
3. Implementation defined (memory allocation in case of zero space request)
#### MISRA C rules to avoid issues with it
