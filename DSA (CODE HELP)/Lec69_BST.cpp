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

void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
//_________________________________________________________________________________
// This VIDEO STARTS HERE
// INORDER IS ALWAYS SORTED FOR BST
node *insertData(node *root, int target)
{
    if (root == NULL)
    {
        node *n = new node(target);
        return n;
    }
    if (target < root->data)
    {
        root->left = insertData(root->left, target);
    }
    else
    {
        root->right = insertData(root->right, target);
    }
    return root;
}

node *searchData(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *temp = root;
    while (temp)
    {
        if (target == temp->data)
        {
            return temp;
        }
        else if (target < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return NULL;
}

int FindMin(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}

int FindMax(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}

node *deleteNode(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int minInRightTree = FindMin(root->right);
            root->data = minInRightTree;
            root->right = deleteNode(root->right, minInRightTree);
            return root;
        }
    }
    else if (target < root->data)
    {
        deleteNode(root->left, target);
    }
    else if (target > root->data)
    {
        deleteNode(root->right, target);
    }
}

int main()
{
    int data = 0;
    node *root = NULL;
    cin >> data;
    while (data != -1)
    {
        root = insertData(root, data); // Update root with the return value
        cin >> data;
    }

    cout << "Traversals" << endl;
    cout << "IN ORDER TRAVERSAL" << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "PRE ORDER TRAVERSAL" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "POST ORDER TRAVERSAL" << endl;
    postOrderTraversal(root);
    cout << endl;
    if (searchData(root, 1))
    {
        cout << "Found 1" << endl;
    }
    else
    {
        cout << "Not Found 1" << endl;
    }
    cout << endl;
}
