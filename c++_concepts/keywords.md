# Keywords

## static
* scope - restriction of the variable/function to the file it's in.
* (local variable) lives not in stack but in data section. Alive throughout the life of process.
* member of class - only one instance for any number of objects created. Can be accessed by ' :: ' scope resolution.

## volatile
[Source](https://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766)
* Don't optimize the variable. As in **don't cache** the varibles in register.
* Each access will hit the actual memory location of that variable. (in process memory in RAM)
* Hardware flags, interrupts, inputs - **asynchronous events**, can happen anytime. Cache will not have latest value.

## const
[Microsoft documentation](https://learn.microsoft.com/en-us/cpp/cpp/const-cpp?view=msvc-170)
* object or variable: not modifiable. 
* member function: The function cannot modify the contents of the class itself ie. can't modify non-static members and can't call non-const functions in the class. [See inheritance example](inheritance.md)

## constexpr

# Dynamic Polymorphism Keywords

## virtual 
The virtual keyword declares a virtual function or a virtual base class.
* **virtual function**:
[Source - Programiz](https://www.programiz.com/cpp-programming/virtual-functions)
    * member functions in the base class that are **redefined** in the derived class.
    * virtual keyword is used to **override** the definition in the derived class.
    * this is the basis of **dynamic polymorphism**
    * See the example in source: if virtual not used, base class function is called. No override.
    * if the virtual function is declared with ' = 0 ', its **pure virtual function** and the class becomes **abstract**. [See Inheritance for more](inheritance.md)

* **virtual base class**:
[Source - Scalar Topics](https://www.scaler.com/topics/virtual-base-class-in-cpp/)
* To avoid [Diamond Problem](inheritance.md), virtual classes are used.
* Ensures only one copy of parent class during multiple inheritance.
* Saves space and avoids ambiguity. 

## override 
[Source - Programiz](https://www.programiz.com/cpp-programming/virtual-functions)
* Specify that the function in the derived class is overriding a virtual function in the base class. 
* This is to be explicit and **avoid bugs**.
* Compiler will throw error messages to prompt corrections.

```
class Base 
{
public:
    Base(){}

    virtual void print()        // virtual - function to be overriden
    {
        // code
    }
};

class Derived : public Base
{
public:
    Derived(){}

    void print() override       // override - explicitly defining the base function override.
    {
        // code
    }
};

int main()
{
    Base b1;
    b1.print();                 // calls base class function
    
    Derived d1;
    d1.print();                 // calls derived class function

    Derived d2;
    Base* b2 = &d2;

    // if virtual, function in derived called.
    // else, function in base called.
    b2->print();                

    return 0;
}
```

## final
[Source - cppreference](https://en.cppreference.com/w/cpp/language/final)
* virtual function: The last override possible for a virtual function. 
* class/struct: The last time it can be derived / inherited.

```
struct Base
{
    virtual void foo();
};
 
struct A : Base
{
    void foo() override final;      // Base::foo is overridden and A::foo is the final override
    void bar() final;               // Error: bar cannot be final as it is non-virtual
};
 
struct B final : A                  // struct B is the final derivation.
{
    void foo() override;            // Error: foo cannot be overridden as it is final in A
};
 
struct C : B {};                    // Error: B is final, can't inherit further.
```