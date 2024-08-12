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
Node *reversingLinkedList_Recursively(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rest = reversingLinkedList_Recursively(head->next); // 1->2->3->4->5 it returns 1->2->3-> (4<-5 returns
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int findingMiddle(Node *head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        return head->value;
    }

    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->value;
}



int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 10);
    insertAtTail(tail, 8);
    insertAtTail(tail, 5);
    insertAtTail(tail, 1);
    print(head);

    print(head);
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}