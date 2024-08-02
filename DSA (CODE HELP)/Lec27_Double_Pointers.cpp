#include <iostream>
using namespace std;

void update(int **p)
{
     // p = p + 1;
     // *p = *p + 1;
     **p = **p + 1;
}
int main()
{
     int n = 10;
     int *p = &n;
     int **q = &p;
     cout << "Before " << n << endl;
     cout << "Before " << p << endl;
     cout << "Before " << q << endl;
     update(q);
     cout << "After " << n << endl;
     cout << "After " << p << endl;
     cout << "After " << q << endl;
}