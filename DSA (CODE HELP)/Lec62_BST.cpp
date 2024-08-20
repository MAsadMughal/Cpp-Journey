#include <iostream>
#include <queue>
#include <stack>
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

node *createTree(node *root)
{
    cout << "Enter Data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter Data for left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter Data for right of " << data << endl;
    root->right = createTree(root->right);
    return root;
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

void reverseOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right)
        {
            q.push(root->right);
        }
        if (root->left)
        {
            q.push(root->left);
        }
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}
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

// IN ORDER TRAVERSAL using Stack
void inorder(node *root)
{
    vector<int> ans;
    stack<node *> s;
    node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
}

void preorder(node *root)
{
    vector<int> ans;
    stack<node *> s;
    node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            ans.push_back(curr->data);
            if (curr->left == NULL)
            {
                s.push(curr);
            }
            curr = curr->left;
        }

        curr = s.top()->right;
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
}

int main()
{
    node *root = NULL;
    root = createTree(root);
    // 1 2 3 -1 -1 4 -1 -1 5 7 -1 -1 6 -1 -1
    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Reverse Level Order Traversal" << endl;
    reverseOrderTraversal(root);
    cout << endl;
    cout << "Pre Order Traversal" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "In-Order Traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "Post Order Traversal" << endl;
    postOrderTraversal(root);
}