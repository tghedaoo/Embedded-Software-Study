# Interrupts
[What is an Interrupt? NPTEL](https://www.youtube.com/watch?v=rnGVincwk30&list=PLEJxKK7AcSEGPOCFtQTJhOElU44J_JAun&index=14&t=1s) <br />

A running process on processor gets interrupted and a context switch occurs. Interrupts happen due to events.
There are 3 types of events:
1. Hardware interrupts - asynchronous, can occur at any time.
2. Traps - Context Switch (Software interrupts)
3. Exceptions - By the processor due to illegal instruction.

[My Notes](https://drive.google.com/file/d/18AfVh-4BbJQitBeYUWbYyExi1yPhDAkP/view?usp=share_link)
A computer program is **reentrant** if it can be interrupted in the middle of its execution and then be called again before the previous version has completed.

## ISR (Interrupt Service Routine)
## IRQ (Interrupt Request)

## Hardware Interrupt Context Swtich

## Non Interruptable ISR
* Global Interrupt Bit (GIB) is initialized to be set(active).
* IRQ is sensed. GIB is cleared. Context switched to ISR.
* ISR runs uninterrupted. 
* After completion of ISR, GIB enabled.
* If an IRQ exists, Next one in the queue is serviced (based on priority).
* Else, context back to the interrupted task or a task based on scheduler design.

## Nested Interrupts

## Advantages of small ISR
* No queueing of IRQs.
* Avoiding nesting of ISRs.
* Fast return to interrupted task.