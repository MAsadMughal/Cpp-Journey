#include <iostream>
using namespace std;
// Recursive function is one which is called by itself
// In recursive function Bigger problem depemds on smaller problem
// Recursive function has this structure

// Head Recursion
// Base Case
// Recursive Relation
// Processing

// Tail Recursion
// Base Case
// Processing
// Recursive Relation

int fact(int n)
{
     // Recursive Tree
     // 5=>4=>3=>2=>1=>0
     // 24<=6<=2<=1<=1<= Answer is 24*5
     if (n == 0)
     {
          return 1;
     }
     int smallerProblem = fact(n - 1);
     int biggerProblem = n * smallerProblem;
     return biggerProblem;
}
int power(int n)
{
     if (n == 0)
     {
          return 1;
     }
     int smallerProblem = power(n - 1);
     int biggerProblem = 2 * smallerProblem;
     return biggerProblem;
}
void print(int n)
{
     if (n == 0)
     {
          return;
     }
     print(n - 1); // Head Recursion
     cout << n << endl;
}

int main()
{
     print(5);
}