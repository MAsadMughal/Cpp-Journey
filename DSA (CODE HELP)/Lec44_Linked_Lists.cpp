#include <iostream>
using namespace std;

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
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->value << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// void insertAtHead(Node *&head, int val)
// {
//     Node *temp = new Node(val);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(Node *&tail, int val)
// {
//     Node *temp = new Node(val);
//     tail->next = temp;
//     tail = temp;
// }

// void insertAtPosition(Node *&head, Node *&tail, int p, int val)
// {
//     if (p == 1)
//     {
//         insertAtHead(head, val);
//         return;
//     }
//     Node *toInsert = new Node(val);
//     Node *temp = head;
//     int count = 1;
//     while (count < p - 1 && temp->next != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }
//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, val);
//         return;
//     }
//     toInsert->next = temp->next;
//     temp->next = toInsert;
// }

// void deleteNode(Node *&head, Node *&tail, int p)
// {
//     if (p == 1) // Head Deletion
//     {
//         Node *curr = head;
//         head = head->next;
//         if (head == NULL) // If the list becomes empty
//         {
//             tail = NULL;
//         }
//         delete curr;
//         return;
//     }

//     int count = 1;
//     Node *temp = head;

//     while (count < p - 1 && temp->next != NULL) // Traverse to the node before the one to delete
//     {
//         temp = temp->next;
//         count++;
//     }

//     if (temp->next == NULL) // If p is greater than the length of the list
//     {
//         cout << "Position is out of bounds." << endl;
//         return;
//     }

//     Node *curr = temp->next;

//     if (curr->next == NULL) // Tail Deletion
//     {
//         tail = temp; // Update the tail to the previous node
//         temp->next = NULL;
//         delete curr;
//         return;
//     }

//     temp->next = curr->next; // Position Deletion
//     delete curr;
// }

//__________________________Doubly Linked List_________________________

class Node
{
public:
    Node *next;
    Node *prev;
    int value;

    // Constructor to initialize the value and next pointer
    Node(int val = 0)
    {
        this->value = val;
        this->next = NULL;
        this->prev = NULL;
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

void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        head = temp;
        tail = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int val)
{
    Node *temp = new Node(val);
    if (tail != NULL)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        tail = temp;
        head = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int p, int val)
{
    if (p == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }
    Node *toInsert = new Node(val);
    Node *temp = head;
    int count = 1;
    while (count < p - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, val);
        return;
    }
    toInsert->next = temp->next;
    toInsert->prev = temp;
    temp->next->prev = toInsert;
    temp->next = toInsert;
}

void deleteNode(Node *&head, Node *&tail, int p)
{
    if (head == NULL)
    {
        return;
    }

    if (p == 1) // Head Deletion
    {
        Node *curr = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL; // If the list becomes empty
        }
        delete curr;
        return;
    }

    int count = 1;
    Node *temp = head;
    while (count < p - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    { // Greater than size
        cout << "Greater than size" << endl;
        return;
    }
    Node *curr = temp->next;
    if (curr->next == NULL)
    {
        // tail
        temp->next = NULL;
        tail = temp;
        delete curr;
        return;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    delete curr;
}

int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 15);
    insertAtHead(head, tail, 100);
    print(head);
    insertAtPosition(head, tail, 3, 520);
    print(head);
    deleteNode(head, tail, 5);
    print(head);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}