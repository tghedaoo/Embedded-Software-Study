# Inheritance
[Youtube Source](https://www.youtube.com/watch?v=77eueMbWI0Y)
* Base class with common functionality.
* Derived class inherits(takes in) base class and adds functionality.
* (or/and) overrides some or all of base class methods with new functionality using 'virtual' and overriding.

**Benefits:**
* Avoids code duplication.
* Helps achieve Dynamic Polymorphism.

**Creating a Base and Derived Classes**
```
class Shape
{
// protected:                           // [5]
    string name;                        // [4]

public:
    Shape(string n) {name = n;}

    void setName(string n) {name = n;}
    string getName() const {return name;}

//  virtual double getArea() const = 0;         // [6]
};

// Derived class. - CIRCLE
class Circle : public Shape                     // [1]
{
private:
    double radius;                              // [3]

public:
    Circle(string n, double r) : Shape(n) {radius = r;}   // [2]

    void setRadius(double r) {radius = r;}                // [3]
    double getRadius() const {return radius;}

    double getArea() const {return radius * radius * 3.14;} //[6]
};

// Derived class. - RECTANGLE
class Rectangle : public Shape                     // [1]
{
private:
    double length;                                 // [3]
    double width;               

public:
    Rectangle(string n, double l, double w) : Shape(n)           // [2]
    {
        length = l;
        width = w;
    } 

    void setLength(double l) {length = l;}        // [3]
    void setWidth(double w) {width = w;}
    double getLength() const {return l;}
    double getWidth() const {return w;}

    double getArea() const {return length * width;}     // [6]
};

// level 2 inheritance.
class Solid : public Rectangle                          // [7]
{
    double depth;

public:
    Solid(string n, double l, double w, double d)
    : Rectangle(n, l, w)
    {
        depth = d;
    }

    double getArea() const {return getLength() * getWidth() * depth;}

};

int main()
{
    // Creating a base class object.
    Shape s("Shape");                   // [6]
    cout << s.getName() << endl;

    // ----

    // Creating a derived class object.
    Circle c("Circle", 2.1);
    cout << c.getName() << " " << c.getRadius() << endl;

    // Creating one more derived class object.
    Rectangle r("Rectangle", 4, 2);
    cout << r.getName() << " " << r.getLength() << endl;

    // ----

    // Creating a indirect inheritance class object.
    Solid sol("Solid", 5, 4, 3);
    cout << sol.getName() << " " << sol.getArea() << endl;

    // ----

    // Creating a initialization list and do dynamic polumorphism on the base class.
    vector<Shape*> shapes { new Circle("Circle", 2.1), new Rectangle("Rectangle", 2 , 4), new Solid("Solid", 1, 2, 3) };    // [8]
    
    for(auto* s : shapes)
    {
        cout << s->getName() << " " << s->getArea() << endl; 
    }

    for(auto* s : shapes)
    {
        delete(s);
    }
}

```
1. Making access specifier - public, only public members are accessable.
2. Since we don't have a default constructor for the base class, we have to create a constructor for derived class that constructs the base class too.
3. We can add extra methods and members to the derived class. Therefore, the derived class will have both the base class and its own members.
4. Since the **access specifier is public**, the derived classes can't access private members of the base class. (to change name, we had to use the base class constructor)
5. Since the **access specifier is protected**, only derived/child classes can access that member directly. [More on Access Specifiers](https://www.w3schools.com/cpp/cpp_access_specifiers.asp)
6. For a method that has multiple definitions based on the child class requirement, we declare it as a **pure virtual function.** [See keyword - virtual](keywords.md)
    * The function will therefore not need a definition in the base class. 
    * The derived classes will have their own definitions for it. But this makes the base class an **abstract class.**
    * A class that contains a pure virtual function is known as an abstract class.
    * Abstract class can't be initialized ie. **no object creation possible.**
    * The derived class **must define** the pure virtual function.
7. **Indirect Inheritance**: We now go a level further and inherit the derived class. This indirectly inherits the base class.
8. **Dynamic Polymorphism**: the derived class object pointer can be accessed through the base class pointer. C++ does dynamic binding of methods based on based class. [See keyword - virtual](keywords.md)

## Multiple Inheritance and Diamond Problem.

