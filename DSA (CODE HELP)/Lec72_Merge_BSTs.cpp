#include <iostream>
#include <map>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

// Method 1 Using n+m space and time complexity
void findInOrder(vector<node *> &arr, node *root)
{
    if (root == NULL)
    {
        return;
    }

    findInOrder(arr, root->left);
    arr.push_back(root);
    findInOrder(arr, root->right);
}

node *BSTfromInOrder(int start, int end, vector<int> &arr)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + ((end - start) / 2);
    node *root = new node(arr[mid]);
    root->left = BSTfromInOrder(start, mid - 1, arr);
    root->right = BSTfromInOrder(mid + 1, end, arr);
    return root;
}

node *merge(node *root1, node *root2)
{
    vector<node *> arr1;
    vector<node *> arr2;
    findInOrder(arr1, root1);
    findInOrder(arr2, root2);
    vector<int> arr3;
    int h1 = 0;
    int h2 = 0;
    int s1 = arr1.size();
    int s2 = arr2.size();
    while (h1 < s1 && h2 < s2)
    {
        if (arr1[h1]->data < arr2[h2]->data)
        {
            arr3.push_back(arr1[h1]->data);
            h1++;
        }
        else
        {
            arr3.push_back(arr2[h2]->data);
            h2++;
        }
    }
    while (h1 < s1)
    {
        arr3.push_back(arr1[h1]->data);
        h1++;
    }
    while (h2 < s2)
    {
        arr3.push_back(arr2[h2]->data);
        h2++;
    }

    return BSTfromInOrder(0, arr3.size() - 1, arr3);
}

// Now using Linked Lists

void BSTtoSortedDLL(node *root, node *&head)
{
    if (root == NULL)
    {
        return;
    }
    BSTtoSortedDLL(root->right, head);
    root->right = head;
    if (head)
    {
        head->left = root;
    }
    head = root;
    BSTtoSortedDLL(root->left, head);
}

node *mergeTwoDLL(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    node *head = NULL;
    node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            {
                if (head == NULL)
                {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else
                {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(node *root)
{
    int count = 0;
    while (root != NULL)
    {
        count++;
        root = root->right;
    }
    return count;
}

node *DLLsToBST(node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    node *left = DLLsToBST(head, n / 2);
    node *root = head;
    root->left = left;
    head = head->right;
    root->right = DLLsToBST(head, n - n / 2 - 1);
    return root;
}

int main()
{
    node *root1 = new node(10);
    root1->left = new node(5);
    root1->right = new node(15);

    node *root2 = new node(20);
    root2->left = new node(2);
    root2->right = new node(30);

    node *head1 = NULL;
    node *head2 = NULL;
    BSTtoSortedDLL(root1, head1);
    BSTtoSortedDLL(root2, head2);
    node *head = mergeTwoDLL(head1, head2);
    node *newRoot = DLLsToBST(head, countNodes(head));
}