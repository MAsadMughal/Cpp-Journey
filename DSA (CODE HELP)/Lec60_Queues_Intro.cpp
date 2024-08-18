#include <iostream>
using namespace std;

// class Queue
// {
// public:
//     int front;
//     int rear;
//     int *arr;
//     int size;
//     Queue(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         front = 0;
//         rear = 0;
//     }
//     void push(int val)
//     {
//         if (rear == size)
//         {
//             cout << "Queue is Full" << endl;
//             return;
//         }

//         arr[rear++] = val;
//         cout << "pushed " << val << " at position " << rear - 1 << endl;
//     }
//     void pop()
//     {
//         if (rear == front)
//         {
//             cout << "Queue is Empty" << endl;
//             return;
//         }
//         cout << "popped " << arr[front] << " from position " << front << endl;
//         arr[front++] = -1;
//         if (front == rear)
//         {
//             front = 0;
//             rear = 0;
//         }
//     }
// };

//__________________________________
// Circular Queue Does not wastes space
class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
        {
            // If Empty
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        cout << "pushed " << val << " at position " << rear << endl;
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "popped " << arr[front] << " from position " << front << endl;

        arr[front] = -1;
        // if 1 element
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

//_________________________________________
// Doubly ended Queue Does not wastes space
class Deque
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_back(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
        {
            // If Empty
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        cout << "pushed " << val << " at position " << rear << endl;
    }
    void push_front(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
        cout << "Pushed " << val << " at position " << front << endl;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "popped " << arr[front] << " from position " << front << endl;

        arr[front] = -1;
        // if 1 element
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "popped " << arr[rear] << " from position " << rear << endl;
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0 && front != size - 1)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size);
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void print()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deque d(5);
    d.print();
    d.push_front(3);
    d.push_front(5);
    d.push_front(7);
    d.print();
    d.pop_back();
    d.print();
    d.pop_front();
    d.print();
}