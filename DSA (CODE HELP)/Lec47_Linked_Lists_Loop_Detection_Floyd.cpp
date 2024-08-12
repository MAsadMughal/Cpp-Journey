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

bool hasLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *detectLoopFloyd(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

Node *startOfLoop(Node *head)
{
    Node *met = detectLoopFloyd(head);
    Node *slow = head;
    while (slow != met)
    {
        slow = slow->next;
        met = met->next;
    }
    return slow;
}
void breakLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *match = startOfLoop(head);
    Node *temp = match;
    while (temp->next != match)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 100);
    insertAtTail(tail, 5);
    insertAtTail(tail, 8);
    Node *f = head->next->next;
    tail->next = f;
    breakLoop(head);
    print(head);
}

// FLOYD CYCLCE DETECTION ALGO H.W
