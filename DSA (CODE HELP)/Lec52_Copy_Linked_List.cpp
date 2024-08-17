#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    Node *next;
    Node *random;
    int value;

    // Constructor to initialize the value and next pointer
    Node(int val = 0)
    {
        this->value = val;
        this->next = NULL;
        this->random = this;
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
        cout << "value " << head->value << " " << "random " << head->random->value << endl;
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

void insertWithRands(Node *&tail, int val, Node *ran)
{
    Node *temp = new Node(val);
    temp->random = ran;
    tail->next = temp;
    tail = temp;
}
// Using Map
// O(n) TC
// O(n) SC
Node *createCopyusingMap(Node *head1, map<Node *, Node *> &linked, Node *&head2, Node *&tail2)
{

    Node *temp = head1;
    while (temp != NULL)
    {
        if (head2 == NULL)
        {

            Node *newNode = new Node(temp->value);
            head2 = newNode;
            tail2 = newNode;
            linked[temp] = newNode;
        }
        else
        {
            Node *newNode = new Node(temp->value);
            tail2->next = newNode;
            tail2 = tail2->next;
            linked[temp] = newNode;
        }
        temp = temp->next;
    }
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp2 != NULL)
    {

        Node *rand = linked[temp1->random];
        temp2->random = rand;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return head2;
}

// Without Using Map
// O(n) TC
// O(n) SC
Node *createCopy(Node *head1, Node *&head2, Node *&tail2)
{
    if (head1 == NULL)
    {
        return NULL;
    }
    Node *temp = head1;
    // copying list
    while (temp != NULL)
    {
        if (head2 == NULL)
        {
            Node *newNode = new Node(temp->value);
            head2 = newNode;
            tail2 = newNode;
        }
        else
        {
            Node *newNode = new Node(temp->value);
            tail2->next = newNode;
            tail2 = tail2->next;
        }
        temp = temp->next;
    }

    Node *original = head1;
    Node *cloneNode = head2;
    // Merging Lists
    while (original != NULL)
    {
        Node *next = original->next;
        original->next = cloneNode;
        Node *next2 = cloneNode->next;
        cloneNode->next = next;
        original = next;
        cloneNode = next2;
    }
    original = head1;
    cloneNode = head2;

    // Assigning random
    while (original != NULL && original->next != NULL)
    {
        if (original->random != NULL)
        {
            original->next->random = original->random->next;
        }
        original = original->next->next;
    }

    // De merging Lists
    original = head1;
    cloneNode = head2;

    while (cloneNode != NULL && original != NULL)
    {
        original->next = cloneNode->next;
        if (original->next != NULL)
        {
            cloneNode->next = original->next->next; // adjust cloneNode's next
        }
        original = original->next;
        cloneNode = cloneNode->next;
    }
    
    return head2;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = NULL;

    Node *head1 = n1;
    Node *head2 = n2;
    Node *tail1 = n1;
    Node *tail2 = n2;

    map<Node *, Node *> linked;
    insertWithRands(tail1, 9, head1);
    insertWithRands(tail1, 2, head1->next);
    insertWithRands(tail1, 32, head1->next->next);
    print(head1);
    print(createCopy(head1, head2, tail2));
}
