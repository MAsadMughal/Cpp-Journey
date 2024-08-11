#include <iostream>
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
void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reversingLinkedList_Iteratively(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = head->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}
int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 15);
    insertAtTail(tail, 10);
    insertAtTail(tail, 5);
    print(head);
    reversingLinkedList_Iteratively(head);
    print(head);
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}