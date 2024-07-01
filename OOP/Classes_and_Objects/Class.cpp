#include <iostream>
#include <string>
using namespace std;

// ____________Classes and Objects____________ =>  01/07/2024

class Teacher
{
    // properties

    // Encapsulation is called so because methods and properties are wrapped up in a single unit class.
private: // Access modifiers
    string name;
    string dept;
    int salary; // data hiding

public:
    int Id;
    // Constructor is Special method used for initialization, Invoked at the time of Object Creation.
    // It has same name as class.
    // Does not have a return type
    // Only called once
    // Memory allocation is done after constructor call
    Teacher() // Always declared in Public members. It is a non parameterized constructor.
    {
        cout << "Non";
        dept = "Computer Science";
    }
    Teacher(int Id, string name, string dept) // Parameterized constructor.
    {
        this->Id = Id; // -> this symbol is to point towards object attributes where this is referring to object.
        this->name = name;
        (*this).dept = dept; // this is pointer to object. So its value can be accessed with * symbol called dereferencing.
    }
    // methods
    void changeDept(string dep)
    {
        dept = dep;
    }
    void getInfo()
    {
        cout << Id << endl;
        cout << name << endl;
        cout << dept << endl;
    }
};

int main()
{
    Teacher t1(100, "Asad", "CS"); // Only 1 Constructor is called at a time.
    t1.getInfo();
    Teacher t2(t1); // Copy constructor. Object is passed by reference. So when value of t1 changes t2 changes if we use dynamic programming.
    t1.Id=20;
    t2.getInfo();
}
