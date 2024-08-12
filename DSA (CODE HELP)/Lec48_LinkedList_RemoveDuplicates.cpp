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
Node *deleteDuplicatesInSortedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->value == temp->value)
        {
            Node *toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

// Worst Approach N2 Time complexity
Node *deleteDuplicatesIn_UnSortedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp1 = head;
    Node *temp2 = head;

    while (temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->value == temp2->next->value)
            {
                Node *toDel = temp2->next;
                temp2->next = temp2->next->next;
                delete toDel;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return head;
}
//N time complexity using map
Node *deleteDuplicatesIn_UnSortedListUsingMap(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    map<int, bool> check;
    check[head->value] = true;
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (check[temp->next->value] != true)
        {
            check[temp->next->value] = true;
            temp = temp->next;
        }
        else
        {
            Node *toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
    }
    return head;
}
//
Node *RemoveDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    map<int, bool> check;
    check[head->value] = true;
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (check[temp->next->value] != true)
        {
            check[temp->next->value] = true;
            temp = temp->next;
        }
        else
        {
            Node *toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
    }
    return head;
}

int main()
{
    // -100
    Node *n1 = new Node(-100);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, -88);
    insertAtTail(tail, 1);
    insertAtTail(tail, 3);
    insertAtTail(tail, -55);
    insertAtTail(tail, 4);
    insertAtTail(tail, 25);
    insertAtTail(tail, -88);
    insertAtTail(tail, 25);
    insertAtTail(tail, 4);
    insertAtTail(tail, 25);
    insertAtTail(tail, 26);
    insertAtTail(tail, 33);
    insertAtTail(tail, 43);
    insertAtTail(tail, 45);
    insertAtTail(tail, 55);
    insertAtTail(tail, 66);
    insertAtTail(tail, 66);
    insertAtTail(tail, 77);
    insertAtTail(tail, 77);
    insertAtTail(tail, 77);
    insertAtTail(tail, 77);
    insertAtTail(tail, 77);
    insertAtTail(tail, 100);
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 100);

    print(head);
    deleteDuplicatesIn_UnSortedListUsingMap(head);
    print(head);
}

// FLOYD CYCLCE DETECTION ALGO H.W
