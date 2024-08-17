#include <iostream>
#include <map>
using namespace std;

// Stack Implementation using array
// class Stack
// {
// public:
//     int *arr;
//     int top;
//     int size;
//     // Constructor to initialize the value and next pointer
//     Stack(int size = 0)
//     {
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }
//     void push(int val)
//     {
//         if (top < size - 1)
//         {
//             top++;
//             arr[top] = val;
//             cout << "Pushed " << val << endl;
//         }
//         else
//         {
//             cout << "Stack overflow" << endl;
//         }
//     }
//     void pop()
//     {
//         if (top >= 0)
//         {
//             int ans = arr[top];
//             top--;
//             cout << "Popped " << ans << endl;
//         }
//         else
//         {
//             cout << "Stack Underflow" << endl;
//         }
//     }

//     void peak()
//     {
//         if (top >= 0)
//         {
//             cout << "Top " << arr[top] << endl;
//         }
//         else
//         {
//             cout << "Stack is Empty" << endl;
//         }
//     }

//     ~Stack()
//     {
//         cout << "Destructor Called" << endl;
//     }
// };

//____________________________________________
// STACK IMPLEMENTATION USING LINKED LIST
// Single Node in Linked List
// class Node
// {
// public:
//     Node *next;
//     int value;

//     // Constructor to initialize the value and next pointer
//     Node(int val = 0)
//     {
//         this->value = val;
//         this->next = NULL;
//     }
//     ~Node()
//     {
//         cout << "Freeing memory for " << this->value << endl;
//     }
// };

// class Stack
// {
// public:
//     Node *head;
//     // Constructor to initialize the value and next pointer
//     Stack()
//     {

//         this->head = NULL;
//     }
//     void push(int val)
//     {
//         Node *temp = new Node(val);
//         if (!temp)
//         {
//             cout << "\nStack Overflow";
//         }
//         cout << "Pushed " << val << endl;
//         temp->next = head;
//         head = temp;
//     }
//     void pop()
//     {
//         if (head == NULL)
//         {
//             cout << "Empty Stack" << endl;
//             return;
//         }
//         Node *temp = head;
//         head = head->next;
//         cout << "Popped " << temp->value << endl;
//         delete temp;
//     }

//     void peak()
//     {
//         if (head != NULL)
//         {
//             cout << "TOP " << head->value << endl;
//         }
//         else
//         {
//             cout << "Empty Stack" << endl;
//         }
//     }

//     ~Stack()
//     {
//         cout << "Destructor Called" << endl;
//     }
// };

// ______________________
// Two stacks in One array
class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;
    // Constructor to initialize the value and next pointer
    Stack(int size = 0)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int val)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = val;
            cout << "Pushed " << val << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void push2(int val)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = val;
            cout << "Pushed " << val << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            cout << "Popped " << ans << endl;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    void pop2()
    {
        if (top2 <= size - 1)
        {
            int ans = arr[top2];
            top2++;
            cout << "Popped " << ans << endl;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    void peak1()
    {
        if (top1 >= 0)
        {
            cout << "Top " << arr[top1] << endl;
        }
        else
        {
            cout << "Stack is Empty" << endl;
        }
    }

    void peak2()
    {
        if (top2 < size)
        {
            cout << "Top " << arr[top2] << endl;
        }
        else
        {
            cout << "Stack is Empty" << endl;
        }
    }

    ~Stack()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    Stack s(4);
    s.push1(5);
    s.push1(4);
    s.push1(3);
    s.push2(4);
    s.push2(2);
    s.push2(1);
    s.pop1();
    s.pop1();
    s.pop2();
    s.pop2();
    s.peak1();
    s.peak2();
}

//reverse string (Reverse application of stack)


//Delete middle element of stack
//Check Valid Parenthesis
//Push element at bottom of Stack
//Reverse a Stack using recursion