# THREADS & CONCURRENCY
[My Notes based on UPenn lectures](https://drive.google.com/file/d/1aYTq_zreyI6VwZuPKOl_k7kOrtvZsZOZ/view?usp=share_link)

## Concurrency vs Parallelism
[Source](https://freecontent.manning.com/concurrency-vs-parallelism/#:~:text=Concurrency%20is%20about%20multiple%20tasks,resources%20like%20multi%2Dcore%20processor.) <br />

**Concurrency** <br />
Multiple tasks or substasks running conceptually at the same time. They may be active in one time interval, overlapping and taking turns to execute. This is generally a system view. <br />
This is when a single core, runs multiple tasks, one task at a time. We can never have paralelism in one core. <br />
The catch here is the tasks are not completing before a new task is started. Its not sequential. <br />
**Parallelism** <br />
Multiple tasks or subtasks running literally at the same time. This requires hardware with multiple computing resources. <br />
This is only possible with mutli-core setup.

## Threads
[Source](https://www.scaler.com/topics/operating-system/threads-in-operating-system/) <br />
* Threads are a part of the process. It's the subtasks of a process and a flow definer.
* Increases overall system **performance**. Supports concurrency and parallelism.
* Increases **responsiveness**. One part of program blocked will not affect other parts of the program.
* A thread has different PC, SP, CPU regs. (Execution Part of PCB. see [process](process.md))
* Uses the same process virtual memory space. Common resources are shared (Process memory space, Fds etc.)

## Types of threads
| User Level | Kernel Level |
|---|---|
|No context switching overhead as it is in user space. It's faster to switch.           | Context Switch little heavier as it traps to kernel.|
|Thread Control Block (Thread Table) in user space. Kernel (OS) sees it as one process. |TCB is in kernel. So OS knows the threads.|
|When a process(or a thread) is blocked, all threads are blocked.                       |One thread block doesn't block other threads or the process at large.|

## Process vs Threads
| Process | Thread |
|---|---|
| Process Control Block book keeping is heavy.  | Thread table is light as smaller tracking parameter group.        |
| Process creation is very heavy. A whole new memory space and associated tracking is created | Thread creation is light as it uses process resources.|
| Context switching is heavy. slow.             | Context switching is little.                                      |
| Memory between processes are isolated.        | Memory of the process is shared between threads.                  |
| IPC is slow.                                  | Thread sync/comms is fast.                                        |

## Thread Synchronization

**Atomic** - non interruptable task or execution. Will complete fully. Eg: instruction execution. <br />
**Race Condition & Critical Section** <br />
[source 1](https://www.tutorialspoint.com/critical-section-problem) <br />
[source 2](https://www.tutorialspoint.com/race-condition-critical-section-and-semaphore) <br />
A section of code containing shared resource is critical section. Only one thread or process can access and modify it. <br /> 
If mutiple processes/threads access them without synchronization, the resource modified might have undefined or unexpected outcomes. This is a race condition where the processes/threads might race to modify the section first.<br />
Critical section needs an atomic lock on it, so that it is systematically accessed. <br />
Conditions for implementing this:
* Mutual Exclusion - only one process/thread allowed. The critical section is to be atomic.
* Progress - if a process is not needing it, it should not stop.
* Bounded Waiting - a process should only stop for a limited time to access it.

**Mutex** <br/>
[Source](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

**Semaphore** <br />
[Source](https://www.tutorialspoint.com/semaphores-in-operating-system) <br />
Semaphores are **integer variables** that are used to solve the critical section problem by using two atomic operations, wait and signal that are used for process synchronization. Semaphore is useful to set an upper bound on a collection of resources. <br />
If there are N instance of the resource, it can be distributed across N askers. The others would then get blocked. 

Two atmoic instructions used:
* wait()   / pend() - decreases count till 0. if 0, blocked.
* signal() / post() - increases count. signals the blocked thread/process. <br />

Two types:
* Binary - Only one thread can access the resource. Acts like a mutex.
* Counting - Multiple threads can access the resource. based on count.

**Mutex vs Semaphore** <br />
[Source](https://medium.com/freethreads/mutex-v-s-semaphore-v-s-spinlock-98c6884356b9) <br />
[Source Main](https://www.tutorialspoint.com/difference-between-semaphore-and-mutex) <br />
[My Notes](https://drive.google.com/file/d/1Y8AiMmGqVmthaDK4InhadK68fpQTPU_K/view?usp=share_link) <br />
|Mutex|Semaphore|
|---|---|
| Object | Integer Variable |
| It's a resource. mutual exclusion object shared between threads.                              | A thread waiting for a semaphore can be signalled by another thread.
| Locking Mechanism                                                                             | Signaling Mechanism |
| Ownership of Lock, only 1 thread can have it, the thread has to release it for others to use. | No ownership |

**Busy Wait**<br />
A process/task waits and constantly checks for a condition to be satisfied before proceeding with its execution. <br />
Here the condition would be if the resource is freed by checking a shared flag between threads. <br />
The process/thread on the contrary gets scheduled (instead of being put in the block queue) and it burns through CPU cycles stuck at that condition. <br />
**SpinLock**<br />
Uses busy wait, but the lock is acquired atomically.

## Issues in Synchronization
* **Deadlock** <br />
[Source](https://www.tutorialspoint.com/starvation-and-deadlock) <br />
Two or more process/threads are blocked due to resource being taken by a process/thread that is also blocked. Inturn, everybody gets blocked. **Circular Wait** is a very common example. <br />
Deadlock can be prevented by eliminating any of the four necessary conditions, which are **mutual exclusion, hold and wait, no preemption, and circular wait.**

* **Priority Inversion** <br /> 
[Source](https://www.digikey.com/en/maker/projects/introduction-to-rtos-solution-to-part-11-priority-inversion/abf4b8f7cd4a4c70bece35678d178321) <br />
A high priority task gets preempted by lower priority task indirectly. It's not letting the high priority task get scheduled to run as it's using a resource and not freeing it for example. <br />
There are 2 types:
    * Bounded: High(H) gets blocked by Low(L). Low has the resource (can be a lock) and High is only unblocked when resource is freed.
    * Unbounded: A Mid(M) guy comes in. Now L blocks H for a resource(R1). M is running and blocks L for a different resource (R2). M can now block H indirectly for an unbounded time. M has to free R2 to unblock L. L frees R1 to unblock H.


