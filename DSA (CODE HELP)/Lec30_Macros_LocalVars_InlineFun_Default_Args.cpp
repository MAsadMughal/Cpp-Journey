#include <iostream> //#include works before compilation to paste code of cout and cin from iostream file.
using namespace std;

#define PI 3.14 // Macros Here it does not occupy memory but before compilation where PI is used its value is pasted there. For Readability.
int gvar = 2;   // Not recommended bcause can be changed by any function.
              // We can use pass by reference in place of global variable.

inline int max(int a, int b) // Inline function does not take memory but its content is pasted before compilation into main function or where it is called.
// If function is 1 to 3 lines it is inline by compiler otherwise if 3 to 7 it is decided by compiler else it is not inline even with the keyword
{
     return a > b ? a : b;
}
int main()
{
     int a = 3;
     int b = 2;
     int ans = max(a, b);
     cout << ans;
     b++;
     ans = max(a, b);
     cout << ans;
     a++;
     a++;
     ans = max(a, b);
     cout << ans;
}