#include <iostream>
#include <stack>
using namespace std;

void push(stack<int> &s, int val, int &min)
{
    if (min < val)
    {
        s.push(val);
        cout << "Pushed " << val << " Min is " << min << endl;
    }
    else
    {
        int v = 2 * val - min;
        s.push(v);
        min = val;
        cout << "Pushed " << val << " Min is " << min << endl;
    }
}
void pop(stack<int> &s, int &min)
{
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    if (s.top() > min)
    {
        cout << "Popped " << s.top() << " Now Min is " << min << endl;
        s.pop();
    }
    else
    {
        int v = 2 * min - s.top();
        cout << "Popped " << s.top() << " Now Min is " << v << endl;
        s.pop();
        min = v;
    }
}

void printStack(stack<int> s)
{
    if (s.empty())
    {
        cout << "Current Stack " << endl;
        return;
    }
    int v = s.top();
    s.pop();
    printStack(s);
    cout << v << " ";
    s.push(v);
}
int main()
{
    stack<int> s;
    s.push(5);
    int min = 5;
    printStack(s);
    cout << endl;

    push(s, 2, min);
    printStack(s);
    cout << endl;

    push(s, 1, min);
    printStack(s);
    cout << endl;

    push(s, 3, min);
    printStack(s);

    pop(s, min);
    printStack(s);
    cout << endl;

    pop(s, min);
    printStack(s);
    cout << endl;
}