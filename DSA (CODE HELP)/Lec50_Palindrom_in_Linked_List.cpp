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

Node *findMid(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
bool checkPalindrom(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    Node *mid = findMid(head);

    Node *temp = mid->next;
    mid->next = reverseList(mid->next);
    Node *head1 = head;
    Node *head2 = mid->next;
    while (head2 != NULL)
    {
        if (head1->value != head2->value)
        {
            mid->next = reverseList(temp);
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    mid->next = reverseList(temp);
    return true;
}
int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(1);
    Node *head1 = n1;
    Node *head2 = n2;
    Node *tail1 = n1;
    Node *tail2 = n2;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 1);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);

    print(head1);
    print(head2);
    cout << checkPalindrom(head1);
    cout << checkPalindrom(head2);
}
