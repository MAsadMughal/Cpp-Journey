#include <iostream>
using namespace std;

int main()
{
    // Any data type pointer takes 8 bytes
    int n = 50;
    int *p = &n;
    // cout << p << " ";
    // cout << *p;
    // cout << (*p)++;
    bool arr[6] = {0};
    cout << arr << endl
         << &arr << endl
         << &arr[0] << endl;

    bool *arrPtr = arr;
    cout << &arrPtr << endl
         << arrPtr << endl
         << *arrPtr << endl;

    // arr++ is not allowed only with real pointers
    cout << ++arrPtr;
}