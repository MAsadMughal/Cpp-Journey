#include <iostream>
using namespace std;
// __________________01/07/2024___________________ -> Pointers

// // Swap Function
// void swap(int *val1, int *val2) // passed by reference (without '*' address it is passed by value)
// {
//     int temp = *val1;
//     *val1 = *val2;
//     *val2 = temp;
// }

int main()
{
    // // Simple Pointers in Variables;
    // int a = 10;
    // int *ptr = &a;        // '*' is used for declaring ptr. '&' is used for getting address of variable it is used with.
    // cout << ptr << endl;  // Outputs address where variable a is stored in memory.
    // cout << *ptr << endl; // '*' can be used to access the value of ptr it is used with. Outputs value of a.

    // // Arithmetic Operations in Pointers (Only Increment and Decrement is allowed for Pointers. Not Multiplication and Division.)
    // cout << ++ptr; // outputs address stored in ptr + size of data type (Ptr increments to next memory index as integer takes 4 bytes.)
    // cout << --ptr; // outputs address stored in ptr + size of data type (Ptr increments to next memory index as integer takes 4 bytes.)

    // // Pointers in Arrays
    // int arr[5] = {1, 2, 3, 4, 5};
    // cout << arr<<endl;       // Points to address of first element. Behaves almost similar to a pointer but cannot be incremented or decremented.
    // cout << *arr;      // outputs value of first element of array.
    // int *arrPtr = arr; // Now we can increment and decrement this pointer storing array's first element address.
    // for (int i = 0; i <= 4; i++)
    // {
    //     cout << arrPtr + i << endl; // outputs five consecutive addresses of 5 array elements. As it is normal pointer so it can be incremented.
    //     //cout << arr++ << endl; //illegal
    //     cout << arr+i << endl; //legal
    // }

    // Pointers to Pointers
    // int var = 1;
    // int *ptr1 = &var;
    // int **ptr2 = &ptr1;     // We have to use ** not * because we are storing address of address in pointer.
    // cout << var << endl;    // outputs value of var =>1;
    // cout << ptr1 << endl;   // outputs address of var
    // cout << ptr2 << endl;   // outputs address of ptr1 (address of var)
    // cout << *ptr1 << endl;  // value of variable that has its location stored in ptr1.
    // cout << *ptr2 << endl;  // value of variable (ptr1) that has its location stored in ptr2.
    // cout << **ptr2 << endl; // value of variable that has its location stored in ptr1.

    // // Usage of pointers
    // int val1 = 2;
    // int val2 = 4;
    // int *ptrval1 = &val1;
    // int *ptrval2 = &val2;
    // swap(&val1, &val2);     // Swapped using addresses (passed by reference)
    // swap(ptrval1, ptrval2); // Swapped using pointers (passed by reference)
    // cout << val1 << val2; // Swapped two times (Original State).
}