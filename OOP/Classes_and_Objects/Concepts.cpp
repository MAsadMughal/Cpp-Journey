#include <iostream>
#include <string>
using namespace std;

//__________POLYMORPHISM___________ => 08/07/2024
// Polymorphism is object's properties to change their behaviour based on the context in which they are defined.

// 1: Compile-Time Polymorphism

// Function overloading=> Single Class two functions

// class OL
// {
//     void show(int a)
//     {
//         cout << a << endl;
//     }
//     void show(string a)
//     {
//         cout << a << endl;
//     }
// };
// Operator overloading => example of string --> string a="3"; string b=a; here second '=' defines another behaviour of this operator where it string is copied.

// 2: Run-time Polymorphism
// Function Overriding => Concept for Inheritance
// class A
// {
// public:
//     void show()
//     {
//         cout << "Print A" << endl;
//     }
// };
// class B : public A
// {
// public:
//     void show()
//     {
//         cout << "Print B" << endl;
//     }
// };

// int main()
// {
//     B objectb;
//     objectb.show();// it will show child's show function
// }

// virtual Function

// class Parent
// {
// public:
//     virtual void show()
//     {
//         cout << "Print Parent" << endl;
//     }
//     void print()
//     {
//         cout << "Print Parent's" << endl;
//     }
// };
// class Child : public Parent
// {
// public:
//     void show()
//     {
//         cout << "Print Child" << endl;
//     }
//     void print()
//     {
//         cout << "Print Child's" << endl;
//     }
// };

// int main()
// {
//     Parent* objectp;
//     Child objectc;
//     objectp = &objectc;
//     (*objectp).show(); //here due to parent's virtual function it is not called
//     (*objectp).print(); // here parent's function is called but parent's pointer was pointing to child's object that's why virtual functions are used so that they are overridden by child class.
// }

// ______________________Abstraction_______________________ => 09-07-2024
// Abstraction refers to hiding uninportant data and showing only important parts using abstract class and pure virtual functions

// class Parent // Abstract class is used to define an interface for derived class. Can't be instantiated, Provide a base class from which other classes can be derived.
// {
// protected:
//     string name;

// public:
//     virtual void display() = 0; // can make abstract class by adding a pure virtual function.
// };
// class Child:public Parent
// {
//     void display()
//     {
//         cout << "This is display function overridden.";
//     }
// };

// int main()
// {
//     Parent *p;
//     Child c;
//     p=&c;
//     (*p).display(); //Virtual function can only be accessed by Parent Object pointer so function accessed is overridden by child function.
// }

// ______________________Static Keyword_______________________ => 09-07-2024
// Static keyword is defined once for a function has lifetime until end of program.
// Static keyword is defined for a class and are shared by all the objects.
// Not created for a function or an object but separately in memory which lasts until the end of program.

void inc()
{
    static int var = 0;  // Executed once no matter how many function is called for a program.
    var++;               // executed each time function is called
    cout << var << endl; // executed each time function is called
}

class staticClass
{
public:
    int variable;
    staticClass()
    {
        cout << "Constructor Called" << endl;
    }
    ~staticClass()
    {
        cout << "Destructor Called" << endl;
    }
    void increment()
    {
        variable++;
        cout << variable << endl;
    }
};
int main()
{

    staticClass obj1;
    staticClass obj2;
    staticClass obj3;
    obj1.increment(); // separate for each
    obj2.increment(); // separate for each
    obj3.increment(); // separate for each
    inc();            // 1 similar for each
    inc();            // 2 similar for each
    inc();            // 3 similar for each
    if (true)
    {
        static staticClass obj; // if static is used destructor is called after end of program else after end of its scope
    }
    cout << "End" << endl;
}
