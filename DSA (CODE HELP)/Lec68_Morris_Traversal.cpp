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

void MorrisInorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == curr)
            {
                cout << curr->data << " ";
                prev->right = NULL;
                curr = curr->right;
            }
            else
            {
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
}

void flatten(node *root)
{
    node *c = root;
    while (c)
    {
        if (c->left)
        {
            node *prev = c->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = c->right;
            c->right = c->left;
            c->left = NULL;
        }
        c = c->right;
    }
}

void MorrisPreorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == curr)
            {
                prev->right = NULL;
                curr = curr->right;
            }
            else
            {
                cout << curr->data << " ";
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(4);
    root->left->left = new node(2);
    root->right->left = new node(7);
    root->right->left->left = new node(3);
    MorrisPreorderTraversal(root);
}