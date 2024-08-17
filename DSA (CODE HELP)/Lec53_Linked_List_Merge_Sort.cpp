#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    Node *next;
    Node *child;
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

Node *getMid(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *fast = head; // Change this line
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *first, Node *second)

{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (first != NULL && second != NULL)
    {
        if (first->value < second->value)
        {
            if (head == NULL)
            {
                head = first;
                tail = first;
            }
            else
            {
                tail->next = first;
                tail = tail->next;
            }
            first = first->next;
        }
        else
        {
            if (head == NULL)
            {
                head = second;
                tail = second;
            }
            else
            {
                tail->next = second;
                tail = tail->next;
            }
            second = second->next;
        }
    }
    if (first != NULL)
    {
        tail->next = first;
    }
    if (second != NULL)
    {
        tail->next = second;
    }
    return head;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = getMid(head);
    Node *first = head;
    Node *second = mid->next;
    mid->next = NULL;
    first = mergeSort(first);
    second = mergeSort(second);
    return merge(first, second);
}
// Without Recursion
Node *FlattenLinkedList(Node *head)
{
    Node *temp = head;
    Node *next = NULL;
    while (temp->next != NULL)
    {
        while (temp->child != NULL)
        {
            next = temp->next;
            temp->next = temp->child;
            temp = temp->next;
        }
        temp->next = next;
    }
    return head;
}



int main()
{
    Node *n1 = new Node(1);

    Node *head = n1;
    Node *tail = n1;

    insertAtTail(tail, 9);
    insertAtTail(tail, 2);
    insertAtTail(tail, 32);
    print(head);
    print(mergeSort(head));
}
