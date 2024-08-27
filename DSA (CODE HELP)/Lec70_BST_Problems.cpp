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

//______________________________________________
// This Video Starts here
//______________________________________________
// VALID BINARY SEARCH TREE
bool IsValidBinaryTree(node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = IsValidBinaryTree(root, min, root->data);
        bool right = IsValidBinaryTree(root, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
// KTH SMALLEST AND LARGEST ELEMENTS IN BST
int findKthSmallestInBST(node *root, int &i, int &k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = findKthSmallestInBST(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    if (++i == k)
    {
        return root->data;
    }
    return findKthSmallestInBST(root->right, i, k);
}

int KthLargestInBST(node *root, int &i, int &k)
{
    if (root == NULL)
    {
        return -1;
    }
    int right = KthLargestInBST(root->right, i, k);
    if (right != -1)
    {
        return right;
    }
    if (++i == k)
    {
        return root->data;
    }
    return KthLargestInBST(root->left, i, k);
}

// FIND PRE AND SUCCESSOR IN BST
void findPreSuc(node *root, node *&pre, node *&suc, int data)
{
    pre = NULL;
    suc = NULL;

    node *temp = root;
    while (temp != NULL && temp->data != data)
    {
        if (data > temp->data)
        {
            pre = temp;
            temp = temp->right;
        }
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }
    if (temp != NULL)
    {
        if (temp->left != NULL)
        {
            node *leftTree = temp->left;
            while (leftTree->right != NULL)
            {
                leftTree = leftTree->right;
            }
            pre = leftTree;
        }
        if (temp->right != NULL)
        {
            node *rightTree = temp->right;
            while (rightTree->left != NULL)
            {
                rightTree = rightTree->left;
            }
            suc = rightTree;
        }
    }
}

// LCA IN A BST
// USING RECURSION
node *LCA(node *root, int &a, int &b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > a && root->data > b)
    {
        return LCA(root->left, a, b);
    }
    else if (root->data < a && root->data < b)
    {
        return LCA(root->right, a, b);
    }
    else
    {
        return root;
    }
}
// Iteratively
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    while (root != NULL)
    {
        if (root->data > p->data && root->data > q->data)
        {
            root = root->left;
        }
        else if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}