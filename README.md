# Embedded Systems Software / Firmware Study Material

# CONCEPTS

## C++ programming 
*see c++ concepts folder for notes*
* STL - string
* STL - vector
* STL - unordered_map & map
* Copy and Move semantics
* RAII
* Smart pointer
* Inheritance
* Friend class
* Dynamic Polymorphism
* Virtual Functions
* Static Polymorphism
* Operator Overloading
* Function Overloading
* Diamond problem
* V-Table
* specifiers : static, volatile, const, constexpr, noexcept, final, override.

## C programming
* String Functions <br />
https://www.programiz.com/c-programming/string-handling-functions
* Dynamic Memory Allocation: <br />
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/ 
* Variable Arguments for a function: <br />
https://www.geeksforgeeks.org/variable-length-argument-c/ <br />
Good Example: https://en.cppreference.com/w/c/variadic
* Volatile Keyword <br />
https://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766

### C POSIX Library (IEEE 1003)
https://en.wikipedia.org/wiki/C_POSIX_library <br />
Frequently used.
* <errno.h>
* <limits.h>
* <math.h>
* <pthread.h>
* <semaphore.h>
* <signal.h>
* <stdargs.h>
* <stdbool.h>
* <stddef.h>
* <stdint.h>
* <stdio.h>
* <stdlib.h>
* <string.h>
* <sys/socket.h>
* <sys/wait.h>
* <time.h>
* <unistd.h>

## General Programming for Embedded Systems
### *Endianess*
Most machines are little endian. <br />
Standard byte order for networks is big endian, also known as network byte order. Before transferring data on network, data is first converted to network byte order (big endian). <br />
Sometimes it matters when you are using type casting. (To be avoided.)
https://www.geeksforgeeks.org/little-and-big-endian-mystery/
### *Socket Programming*
### *Bit Manipulation*

## Operating Systems
### *Thread and Process*
#### System Calls
https://www.geeksforgeeks.org/introduction-of-system-call/
#### Process Creation System Calls. [ fork() and exec() ]
https://www.geeksforgeeks.org/difference-fork-exec/
### *Thread Synchronization*
#### Mutex vs Semaphore
https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/
https://www.tutorialspoint.com/mutex-vs-semaphore
#### Others
https://www.geeksforgeeks.org/priority-inversion-what-the-heck/
### *Process Synchronization (Inter-Process Communication IPC)*
#### Pipe
https://www.geeksforgeeks.org/pipe-system-call/
#### Shared Memory
#### Socket (Local)
Refer "Socket Programming" for more. C
#### Signaling
### *Virtual Memory, Paging, TLB Cache*
### Shell Concepts
#### Redirection

## ISO 26262.
### *Issues with C*
1. Unspecified behaviour (sequence of evaluation)
2. Undefined behaviour (overflow/ underflow issues)
3. Implementation defined (memory allocation in case of zero space request)
#### MISRA C rules to avoid issues with it

## Code Review Practices.
Code review practices: https://www.youtube.com/watch?v=3pth05Rgr8U <br />

## LLDB Debugger.
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

# CODING QUESTIONS

## DSA Practice
1. Linked List
2. String mainpulation
3. Bit manipulation

### *Advanced Questions*
1. LRU Cache (C++) https://leetcode.com/problems/lru-cache/description/ <br />
LRU Cache needs a hash map mapping the nodes of a Doubly Linked List. The DLL tracks the least recently used key. <br />
When a new key or a recently used key comes in, the DLL updates in such a way that the key in question ends up at the head. <br />
Naturally the tail node becomes the least recently used one. This is removed whenever the list reaches capacity. <br />
Note: To avoid time exceed issue, remove extra functions from the class and hard code the ops. <br />
