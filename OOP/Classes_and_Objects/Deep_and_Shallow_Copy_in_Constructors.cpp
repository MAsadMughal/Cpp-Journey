#include <iostream>
#include <string>
using namespace std;

// ____________Deep and Shallow Copy in Copy Constructors____________ =>  01/08/2024
// Shallow Copy both objects same pointer
class Student
{
private:
    string name;
    string *dept;

public:
    Student()
    {
        name = "Asad";
        dept = new string;
        *dept = "CS";
    }

    // methods
    void changeDept(string dep)
    {
        *dept = dep;
    }

    void getInfo()
    {
        cout << name << endl;
        cout << *dept << endl;
    }
};

// // Deep Copy  => Custom Copy Constructor creating separate pointer in heap storing value of first object -> Both objects have their own pointers and values
// class Student
// {
// private:
//     string name;
//     string *dept;

// public:
//     Student()
//     {
//         name = "Asad";
//         dept = new string;
//         *dept = "CS";
//     }
//     Student(Student &obj)
//     {
//         name = obj.name;
//         dept = new string;
//         *dept = *(obj.dept);
//     }
//     // methods
//     void changeDept(string dep)
//     {
//         *dept = dep;
//     }

//     void getInfo()
//     {
//         cout << name << endl;
//         cout << *dept << endl;
//     }
// };

int main()
{
    Student t1; // Only 1 Constructor is called at a time.
    t1.getInfo();
    Student t2(t1); // Copy constructor. Object is passed by reference. So when value of t1 changes t2 changes if we use dynamic programming.
    t1.changeDept("Dept");
    t1.getInfo();
    t2.getInfo();
}


