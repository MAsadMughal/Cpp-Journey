#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Stack Implementation using array
class Stack
{
public:
    int *arr;
    int *top;
    int *next;
    int freeCurr;
    // Constructor to initialize the value and next pointer
    Stack(int k, int size = 0)
    {
        arr = new int[size];
        top = new int[k];
        next = new int[size];

        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        freeCurr = 0;
    }
    void push(int val, int s)
    {
        if (freeCurr == -1)
        {
            return;
        }
        int ind = freeCurr;
        freeCurr = next[ind];
        arr[ind] = val;
        next[ind] = top[s - 1];
        top[s - 1] = ind;
        cout << "Pushed " << val << " at position " << ind << " in stack " << s << endl;
    }
    void pop(int s)
    {
        if (top[s - 1] == -1)
        {
            return;
        }
        int ind = top[s - 1];
        top[s - 1] = next[ind];
        next[ind] = freeCurr;
        freeCurr = ind;
        cout << "Popped " << arr[ind] << " from stack " << s;
    }

    void print(int size1, int size2)
    {
        // Actual Array
        cout << endl
             << "Actual Array" << endl;
        for (int i = 0; i < size1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        //  Top Array
        cout << endl
             << "Top Array" << endl;
        for (int i = 0; i < size2; i++)
        {
            cout << top[i] << " ";
        }
        cout << endl;
        // Next Array
        cout << endl
             << "Next Array" << endl;
        for (int i = 0; i < size1; i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{

    Stack s(3, 5);
    s.print(5, 3);

    s.push(1, 2);
    s.print(5, 3);

    s.push(2, 1);
    s.print(5, 3);

    s.push(5, 2);
    s.print(5, 3);

    s.push(4, 3);
    s.print(5, 3);

    s.pop(2);
    s.print(5, 3);
}