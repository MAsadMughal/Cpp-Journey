#include <iostream>
#include <map>
using namespace std;

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

// SORT 0s AND 1s and 2s
void insertVal(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
void sortList(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->value == 0)
        {
            insertVal(zeroTail, temp);
            temp = temp->next;
        }
        else if (temp->value == 1)
        {
            insertVal(oneTail, temp);
            temp = temp->next;
        }
        else
        {
            insertVal(twoTail, temp);
            temp = temp->next;
        }
    }

    // MERGING List
    if (oneHead->next == NULL)
    {
        zeroTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = oneHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

// Works fine
Node *mergeLists(Node *first, Node *second)
{
    Node *newList = new Node(-1);
    Node *tail = newList;
    while (first != NULL && second != NULL)
    {
        if (first->value <= second->value)
        {
            tail->next = first;
            first = first->next;
        }
        else
        {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    if (first == NULL)
    {
        tail->next = second;
    }
    else
    {
        tail->next = first;
    }
    Node *mergedHead = newList->next; // Head of the merged list
    delete newList;                   // Clean up dummy node
    return mergedHead;
}
// Not working for similar nodes
// Node *mergeLists(Node *first, Node *second)
// {
//     if (first == NULL)
//     {
//         return second;
//     }
//     if (second == NULL)
//     {
//         return first;
//     }
//     Node *fprev = first;
//     Node *fnext = first->next;
//     Node *s = second;
//     while (s != NULL && fnext != NULL)
//     {
//         if (s->value >= fprev->value && s->value <= fnext->value)
//         {
//             cout << fprev->value << " " << s->value << " " << fnext->value << endl;
//             Node *temp = s->next;
//             fprev->next = s;
//             s->next = fnext;
//             s = temp;
//         }
//         else
//         {
//             fprev = fnext;
//             fnext = fnext->next;
//         }
//     }
//     if (fnext == NULL)
//     {
//         fprev->next = s;
//     }

//     return first;
// }

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(1);
    Node *head1 = n1;
    Node *head2 = n2;
    Node *tail1 = n1;
    Node *tail2 = n2;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 4);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);

    print(head1);
    print(head2);
    print(mergeLists(head1, head2));
}
