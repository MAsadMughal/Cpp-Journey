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

// Two Sum In BST
void inOrderSave(node *root, vector<node *> &v)
{
    if (root == NULL)
    {
        return;
    }
    inOrderSave(root->left, v);
    v.push_back(root);
    inOrderSave(root->right, v);
}
bool findTarget(node *root, int k)
{
    vector<node *> v;
    inOrderSave(root, v);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if ((v[i]->data + v[j]->data) == k)
        {
            return true;
        }
        else if ((v[i]->data + v[j]->data) < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

//_________________________________________________________________
// Flatten BST to Sorted LinkedList
node *flattenBST(node *root)
{
    vector<node *> v;
    inOrderSave(root, v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        v[i]->left = NULL;
        v[i]->right = v[i + 1];
    }
    v[v.size() - 1]->left = NULL;
    v[v.size() - 1]->right = NULL;
    return v[0];
}

// Balance BST
node *BSTtoBalanced(int s, int e, vector<node *> &v)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + ((e - s) / 2);
    node *root = v[mid];
    root->left = BSTtoBalanced(s, mid - 1, v);
    root->right = BSTtoBalanced(mid + 1, e, v);
    return root;
}

node *balanceBST(node *root)
{
    vector<node *> v;
    inOrderSave(root, v);
    return BSTtoBalanced(0, v.size() - 1, v);
}
// CREATING BST FROM PREORDER TRAVERSAL
node *createBST(vector<int> &preorder, int min, int max, int &i)
{
    if (i >= preorder.size())
        return NULL;
    if (preorder[i] < min || preorder[i] > max)
        return NULL;
    node *root = new node(preorder[i++]);
    root->left = createBST(preorder, min, root->data, i);
    root->right = createBST(preorder, root->data, max, i);
    return root;
}
node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return createBST(preorder, INT_MIN, INT_MAX, i);
}