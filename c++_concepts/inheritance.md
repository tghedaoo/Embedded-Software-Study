# Inheritance
* Base class with common functionality.
* Derived class inherits(takes in) base class and adds functionality or overrides it with new functionality using the same symbols from base class.

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
    Shape(string n) 
    {
        name = n;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }
};

// Derived class. - CIRCLE
class Circle : public Shape                     // [1]
{
private:
    double radius;                              // [3]

public:
    Circle(string n, double r) : Shape(n)       // [2]
    {
        radius = r;
    } 

    void setRadius(double r)                    // [3]
    {
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }
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

    void setLength(double l)                        // [3]
    {
        length = l;
    }

    void setWidth(double w)
    {
        width = w;
    }

    double getLength() const
    {
        return l;
    }

    double getWidth() const
    {
        return w;
    }
};

int main()
{
    // Creating a base class object.
    Shape s("Shape");
    cout << s.getName() << endl;

    // Creating a derived class object.
    Circle c("Circle", 2.1);
    cout << c.getName() << " " << c.getRadius() << endl;

    // Creating one more derived class object.
    Rectangle r("Rectangle", 4, 2);
    cout << r.getName() << " " << r.getLength() << endl;
}

```
1. Making access specifier - public, only public members are accessable.
2. Since we don't have a default constructor for the base class, we have to create a constructor for derived class that constructs the base class too.
3. We can add extra methods and members to the derived class. Therefore, the derived class will have both the base class and its own members.
4. Since the **access specifier is public**, the derived classes can't access private members of the base class. (to change name, we had to use the base class constructor)
5. Since the **access specifier is protected**, only derived/child classes can access that member directly. [More on Access Specifiers](https://www.w3schools.com/cpp/cpp_access_specifiers.asp)
