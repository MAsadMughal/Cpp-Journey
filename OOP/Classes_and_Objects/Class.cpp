#include <iostream>
#include <string>
using namespace std;

// ____________Classes and Objects____________ =>  01/07/2024

// class Teacher
// {
//     // properties

//     // Encapsulation is called so because methods and properties are wrapped up in a single unit class.
// private: // Access modifiers
//     string name;
//     string dept;
//     int salary; // data hiding

// public:
//     int Id;
//     // Constructor is Special method used for initialization, Invoked at the time of Object Creation.
//     // It has same name as class.
//     // Does not have a return type
//     // Only called once
//     // Memory allocation is done after constructor call
//     Teacher() // Always declared in Public members. It is a non parameterized constructor.
//     {
//         cout << "Non";
//         dept = "Computer Science";
//     }
//     Teacher(int Id, string name, string dept) // Parameterized constructor.
//     {
//         this->Id = Id; // -> this symbol is to point towards object attributes where this is referring to object.
//         this->name = name;
//         (*this).dept = dept; // this is pointer to object. So its value can be accessed with * symbol called dereferencing.
//     }
//     // methods
//     void changeDept(string dep)
//     {
//         dept = dep;
//     }
//     void getInfo()
//     {
//         cout << Id << endl;
//         cout << name << endl;
//         cout << dept << endl;
//     }
// };

// int main()
// {
//     Teacher t1(100, "Asad", "CS"); // Only 1 Constructor is called at a time.
//     t1.getInfo();
//     Teacher t2(t1); // Copy constructor. Object is passed by reference. So when value of t1 changes t2 changes if we use dynamic programming.
//     t1.Id=20;
//     t2.getInfo();
// }

// _____________Destructor And Remaining Concepts_____________ => 08/07/2024
// Destructor is also a special function which deallocates memory which was allocated to object when Constructor was called.
// It only deallocates statically allocated memory, for deallocating dynamic one need to delete it manually.

// class Class1
// {
// private:
//     string name;

// public:
//     int *ptr;
//     Class1()
//     {
//         ptr = new int;
//         *ptr = 10;
//     }
//     ~Class1()
//     {
//         cout << "Deleting memory" << endl;
//         delete ptr; //deleting dynamically allocated memory using delete
//         // deletes statically allocated memory
//     }
// };

// int main()
// {
//     Class1 obj;
//     cout << *(obj.ptr) << endl;
// }

// ___________________Inheritance___________________
// Multi Level
class Parent // Also known as base class
{
public:
    string name;
    int age;
    Parent(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout << "Parent Constructor here" << endl;
    }
    ~Parent()
    {
        cout << "Parent Destructor here" << endl;
    }
};
// There are Multiple and Multi-level Inheritances
//  There are three modes of Inheritance
//  We cannot inherit private members of Parent class.
//  In private inheritance mode public members of Parent class become private.

class Child : public Parent // Can add more classes as parent separated by commas making multiple inheritance // now it acts like other than private vars of parent class become part of child class as it is.
// Protected members can be accessed by derived classes only.
{
public:
    // No need to write parent constructor if default constructor in parent, simply define Child constructor
    // First Parent Constructor is called when object is created then child constructor.
    Child(int rollNo, string name, int age) : Parent(name, age) // not to write data types while calling Parent constructors. Alse can write default values.
    {
        cout << "Child Constructor here" << endl;
        this->rollNo = rollNo;
    }
    // Reversed order in case of destructors i.e child first
    ~Child()
    {
        cout << "Child Destructor here" << endl;
    }
    int rollNo;
};

class Student : public Child
{
public:
    string school;

    Student(string school, string name, int rollNo, int age) : Child(rollNo, name, age)
    {
        this->school = school;
    }
};

int main()
{
    Student s("Ideal", "Sikandar", 20, 30);
    cout << s.name << endl;
    cout << s.age << endl;
    cout << s.rollNo << endl;
    cout << s.school << endl;
}

// Multiple, Multi-level, heirarchial, Hybrid Inheritance


