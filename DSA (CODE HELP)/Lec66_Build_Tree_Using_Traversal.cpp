#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
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

node *buildTree(vector<int> preOrder, vector<int> inorder, int inorderStart, int inOrderEnd, int &ind, int n, map<int, int> m)
{
    // LNR ->InOrder
    // RLN ->PostOrder
    // NLR ->PreOrder
    if (ind >= n || inorderStart > inOrderEnd)
    {
        return NULL;
    }
    node *root = new node(preOrder[ind]);
    int posInOrder = m[preOrder[ind]];
    root->left = buildTree(preOrder, inorder, inorderStart, posInOrder - 1, ind, n, m);
    root->right = buildTree(preOrder, inorder, posInOrder + 1, inOrderEnd, ind, n, m);
    return root;
}
int main()
{
    vector<int> inorder;
    vector<int> preOrder;

    map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
}