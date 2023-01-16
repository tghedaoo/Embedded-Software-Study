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

**Mutex** <br/>
[Source](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

**Semaphore**
[Source](https://www.tutorialspoint.com/semaphores-in-operating-system)

**Mutex vs Semaphore**
[Source]()

**SpinLock**

## Issues in Synchronization
* [Priority Inversion](https://www.geeksforgeeks.org/priority-inversion-what-the-heck/)
* [Deadlock]()
* []    