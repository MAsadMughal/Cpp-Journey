#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;

// reverse string (Reverse application of stack)
string reverseString(string str)
{
    stack<char> s;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        s.push(str[i]);
    }
    str = "";
    while (!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }
    return str;
}

void printStack(stack<int> s)
{
    if (s.empty())
    {
        return;
    }

    int element = s.top();
    s.pop();
    printStack(s);
    cout << element << " ";
    s.push(element);
}
// Delete middle element of stack
void deleteMiddleElement(stack<int> &s, int count, int size)
{

    if (count == size / 2)
    {
        s.pop();
        cout << endl
             << endl;
        return;
    }
    int element_to_be_pushed_again = s.top();
    s.pop();
    deleteMiddleElement(s, count + 1, size);
    s.push(element_to_be_pushed_again);
}
// Check Valid Parenthesis
bool validParanthesis(string str)
{
    if (str.length() == 1)
    {
        return false;
    }
    if (str.length() == 0)
    {
        return true;
    }

    stack<char> s;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            if ((str[i] == ')' && s.top() == '(') || (str[i] == '}' && s.top() == '{') || (str[i] == ']' && s.top() == '['))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Push element at bottom of Stack
void pushAtBottom(stack<int> &s, int num)
{
    if (s.empty())
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    pushAtBottom(s, num);
    s.push(n);
}
// Reverse a Stack using recursion
void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, num);
}

// Sort Elements of Stack
void insertSorted(stack<int> &s, int num)
{
    if (s.empty() || s.top() <= num)
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    insertSorted(s, num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, num);
}

// Brackets are redundant(faltu)
bool redundantBrackets(string str)
{
    stack<char> s;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            s.push(str[i]);
        }
        else
        {

            if (str[i] == ')')
            {
                bool isRedundent = true;
                while (s.top() != '(')
                {
                    if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                    {
                        isRedundent = false;
                    }
                    s.pop();
                }
                if (isRedundent)
                {
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}

// Check Number of Brackets needed to reverse to get a valid pattern
int numOfChanges(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    int l = str.length();
    stack<char> s;
    for (int i = 0; i < l; i++) // removes pairs
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (!s.empty() && str[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
    }

    int a = 0, b = 0;
    while (!s.empty()) // Counts remaining
    {
        if (s.top() == '(')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }
    return (((a + 1) / 2) + ((b + 1) / 2)); // formula
}
int main()
{
    cout << numOfChanges("))))()");
}
