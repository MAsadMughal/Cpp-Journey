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

Node *reverseList(Node *head) // Iteratively
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int sum(Node *first, Node *second)
{
    int f = 0;
    int s = 0;
    while (first != NULL)
    {
        f = (f * 10) + first->value;
        first = first->next;
    }
    while (second != NULL)
    {
        s = (s * 10) + second->value;
        second = second->next;
    }
    cout << f + s;
}
int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(9);
    Node *head1 = n1;
    Node *head2 = n2;
    Node *tail1 = n1;
    Node *tail2 = n2;

    insertAtTail(tail1, 9);
    insertAtTail(tail2, 9);

    print(head1);
    print(head2);
    cout << sum(head1, head2);
}
