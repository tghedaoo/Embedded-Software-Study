# Embedded Systems Software / Firmware Study Material

# CONCEPTS

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

## C++ programming (OOPS covered)
TBD

## General Programming for Embedded Systems
### *Endianess*
Most machines are little endian. <br />
Standard byte order for networks is big endian, also known as network byte order. Before transferring data on network, data is first converted to network byte order (big endian). <br />
Sometimes it matters when you are using type casting. (To be avoided.)
https://www.geeksforgeeks.org/little-and-big-endian-mystery/
### *Bit manipulation*
1. Missing Number (C++) https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3114/

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

## Socket Programming
Inter host communication on a network in a client/server fashion. <br />
Inter Process Communication in the case of same host. AF_INET (Address Family) & "127.0.0.1". <br />
```
#include <sys/socket.h>
#include <netinet/in.h> // for struct sockaddr_in
#include <arpa/inet.h>  // for inet_pton
```
See notes in code [socket_programming folder]
Links:<br />
https://www.geeksforgeeks.org/socket-programming-cc/ <br />
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/ <br />
*TCP vs UDP*
https://www.lifesize.com/blog/tcp-vs-udp/#:~:text=TCP%20is%20a%20connection%2Doriented,is%20only%20possible%20with%20TCP.

## ISO 26262.
### *Issues with C*
1. Unspecified behaviour (sequence of evaluation)
2. Undefined behaviour (overflow/ underflow issues)
3. Implementation defined (memory allocation in case of zero space request)
#### MISRA C rules to avoid issues with it

# CODING QUESTIONS

## Common Links.
Code review practices: https://www.youtube.com/watch?v=3pth05Rgr8U <br />
LLDB debugging for Mac M1: https://www.youtube.com/watch?v=v_C1cvo1biI (Allow access to see code breakpoints.)

## DSA Practice
### *Linked List*
1. Reverse Linked List (C) https://leetcode.com/explore/interview/card/apple/345/linked-list/2024/
### *String manipulation*
1. First Unique Character in a String (C) https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/ <br />
2. String to Integer (atoi) (C) https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2010/ <br />
**Important points:** <br />
* On the fly - overflow and underflow check to avoid runtime output variable overflow or underflow.
```
Sign is added later. Therefore overflow checked. Underflow is represented after checking sign.
if(result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10))
```
* Appending Digits from Lsb.
```
result = 10 * result + digit;
```
* ASCII conversions (char to int)
```
isdigit();      // to check digit in C++ or do it manually
char - '0';     // get the integer digit on the char representation. (ASCII of digit - ASCII of 0) 
```
 <br />

### *Bit manipulation*
1. Missing Number (C++) https://leetcode.com/explore/interview/card/apple/344/array-and-strings/3114/