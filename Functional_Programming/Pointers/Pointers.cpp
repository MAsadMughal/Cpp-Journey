#include <iostream>
using namespace std;
int main()
{
    // 7/1/2024 -> Pointers

    // Simple Pointers in Variables;
    int a = 10;
    int *ptr = &a;        // '*' is used for declaring ptr. '&' is used for getting address of variable it is used with.
    cout << ptr << endl;  // Outputs address where variable a is stored in memory.
    cout << *ptr << endl; // '*' can be used to access the value of ptr it is used with. Outputs value of a.

    // Arithmetic Operations in Pointers
    cout << ++ptr;   // outputs address stored in ptr + size of data type (Ptr increments to next memory index as integer takes 4 bytes.)
    cout << --ptr;   // outputs address stored in ptr + size of data type (Ptr increments to next memory index as integer takes 4 bytes.)
    cout << ptr * 4; // outputs address stored in ptr + size of data type (Ptr increments to next memory index as integer takes 4 bytes.)
}