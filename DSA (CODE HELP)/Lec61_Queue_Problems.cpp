#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Reverse Queue
void reverseQusingStack(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void reverseQusingRecursion(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int n = q.front();
    q.pop();
    reverseQusingRecursion(q);
    q.push(n);
}
void print(queue<int> q)
{
    if (q.empty())
    {
        return;
    }
    int n = q.front();
    q.pop();
    print(q);
    cout << n << " ";
    q.push(n);
}
int main()
{
    queue<int> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    print(q);
    reverseQusingRecursion(q);
    cout << endl;
    print(q);
}