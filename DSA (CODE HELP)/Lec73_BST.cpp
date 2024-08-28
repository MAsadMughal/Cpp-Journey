#include <iostream>
#include <map>
#include <queue>
using namespace std;

class info
{
public:
    int min;
    int max;
    bool isBST;
    int size;
};

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

info largestBSTinBinaryTree(node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, true, 0};
    }
    info left = largestBSTinBinaryTree(root->left, ans);
    info right = largestBSTinBinaryTree(root->right, ans);
    info curr;

    curr.size = left.size + right.size + 1;
    curr.min = min(root->data, left.min);
    curr.max = max(root->data, right.max);

    if (left.isBST && right.isBST && (root->data > left.max) && (root->data < right.min))
    {
        curr.isBST = true;
    }
    else
    {
        curr.isBST = false;
    }
    if (curr.isBST)
    {
        ans = max(ans, curr.size);
    }
    return curr;
}

info largestSumOfBigBSTinBinaryTree(node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, true, 0};
    }
    info left = largestSumOfBigBSTinBinaryTree(root->left, ans);
    info right = largestSumOfBigBSTinBinaryTree(root->right, ans);
    info curr;

    curr.size = left.size + right.size + root->data;
    curr.min = min(root->data, left.min);
    curr.max = max(root->data, right.max);

    if (left.isBST && right.isBST && (root->data > left.max) && (root->data < right.min))
    {
        curr.isBST = true;
    }
    else
    {
        // curr.isBST = false;
        return {0, 0, false, 0};
    }
    if (curr.isBST)
    {
        ans = max(ans, curr.size);
    }
    return curr;
}

int main()
{
    int ans = 0;
    node *root = new node(1);
    root->left = new node(4);
    root->left->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(2);
    root->right->right = new node(5);
    root->right->right->left = new node(4);
    root->right->right->right = new node(6);
    largestSumOfBigBSTinBinaryTree(root, ans);
    cout << ans;
}