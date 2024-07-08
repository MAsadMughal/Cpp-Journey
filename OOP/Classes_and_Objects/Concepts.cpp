#include <iostream>
#include <string>
using namespace std;

// Polymorphism is object's properties to change their behaviour based on the context in which they are defined.

// 1: Compile-Time Polymorphism

// Function overloading=> Single Class two functions

class OL
{
    void show(int a)
    {
        cout << a << endl;
    }
    void show(string a)
    {
        cout << a << endl;
    }
};
// Operator overloading => example of string --> string a="3"; string b=a; here second '=' defines another behaviour of this operator where it string is copied.

// 2: Run-time Polymorphism
// Function Overriding => Concept for Inheritance
class A
{
public:
    void show()
    {
        cout << "Print A" << endl;
    }
};
class B : public A
{
public:
    void show()
    {
        cout << "Print B" << endl;
    }
};

// int main()
// {
//     B objectb;
//     objectb.show();// it will show child's show function
// }

// virtual Function

class Parent
{
public:
    virtual void show()
    {
        cout << "Print Parent" << endl;
    }
    void print(){
        cout << "Print Parent's" << endl;
    }
};
class Child : public Parent
{
public:
    void show()
    {
        cout << "Print Child" << endl;
    }
    void print(){
        cout << "Print Child's" << endl;
    }
};

int main()
{
    Parent* objectp;
    Child objectc;
    objectp = &objectc;
    (*objectp).show(); //here due to parent's virtual function it is not called
    (*objectp).print(); // here parent's function is called but parent's pointer was pointing to child's object that's why virtual functions are used so that they are overridden by child class.
}