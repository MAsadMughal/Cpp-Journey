#include <iostream>
#include <string>
using namespace std;

int fibonacci(int n)
{

     if (n <= 1)
     {
          return n;
     }
     return fibonacci(n - 1) + fibonacci(n - 2);
}

void sayDigit(int n, string arr[])
{
     if (n == 0)
     {
          return;
     }
     int digit = n % 10;
     n = n / 10;
     sayDigit(n, arr);
     cout << arr[digit] << " ";
}

int main()
{
     string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
     sayDigit(7356, arr);
}

