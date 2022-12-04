# Embedded Systems Software / Firmware Study Material

## DSA Practice
### *Linked List*
The linked list folder has a practice level implementation of a singly linked list. Implemented in C and C++. <br />
Questions:
1. Reverse Linked List (C)
### String manipulation
1. First Unique Character in a String https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/


## General Programming for Embedded Systems
### *Endianess*
Code in the repo. <br />
Standard byte order for networks is big endian, also known as network byte order. Before transferring data on network, data is first converted to network byte order (big endian). <br />
Sometimes it matters when you are using type casting. (To be avoided.)
https://www.geeksforgeeks.org/little-and-big-endian-mystery/
### *Bit manipulation*
Questions:
1. Missing Numbers in N Natural Number List. (C++)

## C programming
Dynamic Memory Allocation: <br />
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/ 
### C POSIX Library (IEEE 1003)
https://en.wikipedia.org/wiki/C_POSIX_library <br />
Frequently used.
* <errno.h>
* <limits.h>
* <math.h>
* <pthread.h>
* <semaphore.h>
* <signal.h>
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

## C++ programming (OOPS covered)
TBD

## Operating Systems
### *Thread and Process*
#### Process Creation System Calls. [ fork() and exec() ]
https://www.geeksforgeeks.org/difference-fork-exec/
### *Thread Synchronization*
#### Mutex vs Semaphore
#### Others
### *Process Synchronization (Inter-Process Communication IPC)*
#### Pipe
#### Shared Memory
#### Socket (Local)
Refer "Socket Programming" for more.
### *Virtual Memory, Paging, TLB Cache*
### Shell Concepts
#### Redirection

## Socket Programming
Inter host communication on a network in a client/server fashion. <br />
Inter Process Communication in the case of same host. AF_LOCAL. <br />
#include <sys/socket.h>

Links:<br />
https://www.geeksforgeeks.org/socket-programming-cc/ <br />
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/ <br />

## Common Links.
Code review practices: https://www.youtube.com/watch?v=3pth05Rgr8U <br />
LLDB debugging for Mac M1: https://www.youtube.com/watch?v=v_C1cvo1biI (Allow access to see code breakpoints.)