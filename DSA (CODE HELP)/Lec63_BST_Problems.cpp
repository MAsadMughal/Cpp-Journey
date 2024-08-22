#include <iostream>
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

int getHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getDiameter(node *root, int &height)
{
    int lh = 0, rh = 0, ld = 0, rd = 0;
    if (root == NULL)
    {
        height = 0;
        return 0;
    }
    ld = getDiameter(root->left, lh);
    rd = getDiameter(root->right, rh);

    height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ld, rd));
}

bool checkBalanced(node *root, int &height)
{
    int lh = 0, rh = 0;
    if (root == NULL)
    {
        height = 0;
        return true;
    }
    bool bl = checkBalanced(root->left, lh);
    bool br = checkBalanced(root->right, rh);

    height = max(lh, rh) + 1;
    return (bl && br && abs(lh - rh) <= 1);
}

bool checkIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    bool left = checkIdentical(root1->left, root2->left);
    bool right = checkIdentical(root1->right, root2->right);
    return root1->data == root2->data && left && right;
}

bool checkSumTree(node *root, int &sum)
{
    int rsum = 0, lsum = 0;
    if (root == NULL)
    {
        sum = 0;
        return true;
    }
    if (root->right == NULL && root->right == NULL)
    {
        sum = root->data;
        return true;
    }
    int l = checkSumTree(root->left, lsum);
    int r = checkSumTree(root->right, rsum);
    sum = lsum + rsum + root->data;
    return (l && r && lsum + rsum == root->data);
}

int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(3);
    int sum = 0;
    cout << checkSumTree(root, sum) << endl;

    return 0;
}
