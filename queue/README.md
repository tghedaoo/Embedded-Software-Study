# QUEUE (LINEAR)
[Youtube](https://www.youtube.com/watch?v=zp6pBNbUB2U) <br />
***FIFO*** can be implemented as list, array/vector; used as STL container <br />
It is an **ADT** - Abstract Data Type.

**Main ops:**
|op  |action| 
|---              |---|
|Enqueue(val)     |Inset at rear|
|Dequeue()        |Remove from front|
|front()          |peek() - val at front|
|rear()           |val at rear|  
|isFull()         |check for full condition| 
|isEmpty()        |check for empty condition|    

**Conditions:**
|condition          |action| 
|---                |---|
|Init & empty       |front = -1; rear = -1|
|empty              |front > rear|    
|Full               |rear = size-1 |

**Some Use Cases:**
* Processes in Queue to be scheduled.
* Computers in Queue for printer.

[Queue using Array](queue.cc) <br />
**Drawback of Linear Queue:** if rear is at the end of the array, it's full. It's not necessary that the array holding the queue is full. dequeue op is possible and front moves. Here we **waste space in the front** of the queue. Therefore, we need a **circular queue** to efficiently use array space.<br/>
[Queue using Linked-List](queue_with_linked_list.c) <br />
With Linked List, dequeue will delete the node from memory and a count is needed to track the size. So no memory wastage.

**Thread Safety:** <br />
One issue is it's **not thread safe**. If the object is not locked, one thread might be doing an op (enQueue) for example and can be interrupted in between and the other might take over and overwrite or corrupt the previously incomplete op.

[Leetcode - Implement Stack using Queue](https://leetcode.com/problems/implement-stack-using-queues/description/) <br />
[Leetcode - Implement Queue using Stack](https://leetcode.com/problems/implement-queue-using-stacks/description/) <br />
Catch: play with push ops. (create the data structure as per implementation), therefore pop op will be the same and straight forward. <br />

# CIRCULAR QUEUE
[Youtube](https://www.youtube.com/watch?v=dn01XST9-bI) <br />
[Leetcode question](https://leetcode.com/problems/design-circular-queue/solutions/)<br />
[Circular Queue using Array](circular_queue.c) <br/>

**Main ops:** same as Linear Queue. <br/>
Differences: 
* is with the front and rear movements to the start of the array.
* and full condition.

**Conditions:** 
|condition                          |action| 
|---                                |---|
|Init & empty                       |front = -1; rear = -1|  
|Full                               |(rear + 1) % capacity == front |
|front/rear reaches end of array    |rear = (rear + 1) % capacity; front = (front + 1) % capacity|

[Circular Queue with Array](circular_queue.c) <br />
[Circular Queue with Linked List](circular_queue_with_linked_list.cc) <br />

# DEQue (Double Ended Queue).
https://www.youtube.com/watch?v=pqg0SOPRlJ4 <br />
https://www.youtube.com/watch?v=WJres9mgiAk <br />
[Leetcode](https://leetcode.com/problems/design-circular-deque/description/) <br />
**No FIFO.** Insertion & Deletion from front and rear. <br />
Has properties of both stack(LIFO) and queue(FIFO). <br />
**2 Types:**
1. Input Restricted DEQue - Insertion from one end only.
2. Output Restricted DEQue - Deletion from one end only.

**Main Operations:**
1. Enqueue_rear: moves right. (rear++)
2. Dequeue_rear: moves left. (rear--)
3. Enqueue_front: moves left. (front--)
4. Dequeue_front: moves right (front++)

**Use Case**
* Palindrome.
* multi-processor scheduling. Process ready queue is DEque.

**Implementation: Circular DEque** 
* Circular Array
* Doubly Linked List

**TODO:** 
1. Document Leetcode solutions.
2. Priority Queue.