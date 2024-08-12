#include <iostream>
using namespace std;
// class Node
// {
// public:
//     Node *next;
//     Node *prev;
//     int value;

//     // Constructor to initialize the value and next pointer
//     Node(int val = 0)
//     {
//         this->value = val;
//         this->next = NULL;
//         this->prev = NULL;
//     }
//     ~Node()
//     {
//         cout << "Freeing memory for " << this->value << endl;
//     }
// };

// void reversing_doubly_Iteratively(Node *&head)
// {
//     Node *curr = head;
//     Node *prev = NULL;
//     Node *forward = NULL;
//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         curr->prev = forward;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
// }

// void insertAtHead(Node *&head, Node *&tail, int val)
// {
//     Node *temp = new Node(val);
//     if (head != NULL)
//     {
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
//     else
//     {
//         head = temp;
//         tail = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int val)
// {
//     Node *temp = new Node(val);
//     if (tail != NULL)
//     {
//         temp->prev = tail;
//         tail->next = temp;
//         tail = temp;
//     }
//     else
//     {
//         tail = temp;
//         head = temp;
//     }
// }

class Node
{
public:
    Node *next;
    int value;

    // Constructor to initialize the value and next pointer
    Node(int val = 0)
    {
        this->value = val;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Freeing memory for " << this->value << endl;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

Node *reversingKgroups(Node *head, int k)
{
    // Singly List Reversal
    if (head == NULL)
    {
        return head;
    }
    int count = 0;
    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reversingKgroups(next, k); // 1->2->3->4->5 it returns 1->2->3-> (4<-5 returns
    }
    return prev;
}
void makeCircular(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        cout << "Circular" << endl;
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        cout << endl
             << "Circular" << endl;
        return true;
    }
    else
    {
        cout << endl
             << "Not Circular" << endl;
        return false;
    }
}

int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    makeCircular(head);
    isCircular(NULL);
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// FLOYD CYCLCE DETECTION ALGO H.W
