# RAII
## Resource Allocation Is Initialization.
*Code in this file is indicative*

Technique for resource management through a class that defines a resouce. Constructor initializes the resource. Deconstructor destroys/frees the resource. The life cycle of the resource is determined by the object scope. 

[Bo Qian Youtube](https://www.youtube.com/watch?v=ojOUIg13g3I) <br />
[My notes](https://drive.google.com/file/d/1xCQoYIr7LiIE30WXv8zhtixDbBNPwm4b/view?usp=share_link) <br />

Uses objects to manage resources:
* thread/process syncs (mutexes)
* memory (using smart pointers)
* hardware device
* network handle <br />

Get an encapsulation for a particular resource as an object. As the object goes out of scope, the resource is freed. Guarantees resource safety.

### Mutex Example
```
mutex_t mu = MUTEX_INIT;

void function()
{
    mutex_lock(&mu);
    ... // Do something
    mutex_unlock(&mu); // May not be executed.
}
```

*Possible failures in the above example:*
* Function may return immaturely before unlock is called.
* Exceptions occurance can change the code flow.

*Resulting in*
* Memory Leaks. (Memory is not deallocated from heap)
* Other resource freeing issues.

**Mutex RAII Solution:** <br />
In the constructor, mutex is locked and in the destrcutor, its unlocked.
Need not worry about unlocking as it would be taken care by the destructor when the object goes out of scope (when the function returns, the object gets popped off the stack). <br />
The only code that is guaranteed to run on an exception is the destrcutor and that will unlock the mutex.
```
class Lock
{
    private:
        mutex_t* pm_;
    public: 
        explicit Lock(Mutex_t* pm)
        {
            mutex_lock(pm);
            pm_ = pm;
        }

        ~Lock()
        {
            mutex_unlock(&pm_);
        }
};

mutex_t mu = MUTEX_INIT;

void function()
{
    Lock my_lock(&mu);
}
```

### Smart Pointer Example
Smart Pointer does the allocation of memory in the object construction implicitly and deallocates the memory when the smart pointer goes out of scope.

More on it here [smart pointers](smart_pointer.md)

```
int function()
{
    std::shared_ptr<dog> pd(new dog());
    // pd destroyed as it goes out of scope. Memory Leak not an issue here.
}
```

### Parameter Passing and Object Creation
```
train(std::shared_ptr<dog> pd(new dog()), getTrick());
// The following statements need to occur:
//  1. new dog()
//  2. getTrick()
//  3. shared_ptr<dog>()
```
C++ compiler doesn't define the order of the execution of statements as shown above. <br />
If we consider the order as stated in the snippet, the 'new dog()' statement will allocate memory. Now, if an exception occurs in the getTrick() function, the allocated memory is never assigned to the shared_ptr which inturn is not created. This causes a **memory leak**. <br />
Therefore, always break the statements and check for failure cases. Keep RAII object creation standalone to avoid their interruption. <br />

### Resource Management Object Copy
```
Lock myLock(&mu);
Lock myOtherLock = myLock; 
// The copy constructor can be deleted by default to avoid copy.
```
Depending upon the resource and the sharing agreement, the object can be controlled. This can be done through:
* copy or move constructors in the resource class. [Move & Copy Semantics]()
* shared_ptr or unique_ptr for the resource in question. [Smart Pointers](smart_pointer.md)
