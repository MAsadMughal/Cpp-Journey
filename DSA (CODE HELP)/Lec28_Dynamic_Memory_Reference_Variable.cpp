#include <iostream>
using namespace std;

void update(int &p) // Pass by reference(No new memory created just another variable created using the old memory of variable passed)
{
     p = p + 1;
}
int &update2() // Not a good Practice because memory of local variable is cleared after block
{
     int n = 10;
     int &p2 = n;
     cout << &n << endl;
     cout << &p2 << endl;
     return p2;
}
int *update3() // Not a good Practice
{
     int n = 10;
     int &p2 = n;
     cout << &n << endl;
     cout << &p2 << endl;
     return &p2;
}
int main()
{
     int n = 10;
     cout << n << endl;
     int &j = n; // This is called reference variable which is just another name of a variable pointing at the same memory
     update(j);
     cout << n << endl;
     cout << update2(); // Returns reference to a variable . Here printing its address.
     int *ptr = &update2();
     cout << *ptr;

     //___________Dynamic and static memory_________________
     // _____________heap and stack memory_________________
     // Stack memory is small memory than heap memory allocated to a program.
     // That's why arr[n] is not a good practice. It may exceed the stack memory allocated to program.
     // So we use Dynamic memory or heap memory with address pointer to it.
     int *p = new int; // takes 12 bytes 8stack+4heap
     int *p2 = new int[200];
     delete p; // We have to delete dynamic memory not static memory.
     delete[] p2;
}