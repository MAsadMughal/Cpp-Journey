#include <iostream>
#include <queue>
#include <unordered_map>
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

// Check greater number of nodes
void largestBloodLineSumFromRootToLeaf(node *root, int sum, int &largestSum, int level, int &maxlevel)
{
    if (root == NULL)
    {
        if (level > maxlevel)
        {
            largestSum = sum;
            maxlevel = level;
        }
        else if (level == maxlevel)
        {
            largestSum = max(sum, largestSum);
        }
        return;
    }

    sum += root->data;

    largestBloodLineSumFromRootToLeaf(root->left, sum, largestSum, level + 1, maxlevel);
    largestBloodLineSumFromRootToLeaf(root->right, sum, largestSum, level + 1, maxlevel);
}

// Common Ancestor (Unique Nodes)
node *commonAncestor(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = commonAncestor(root->left, n1, n2);
    node *right = commonAncestor(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (right == NULL && left != NULL)
    {
        return left;
    }
    else if (right != NULL && left == NULL)
    {
        return right;
    }
    else
    {
        return NULL;
    }
}

// K sum paths
void kPaths(node *root, int k, int &count, vector<int> path)
{

    if (root == NULL)
        return;
    path.push_back(root->data);
    kPaths(root->left, k, count, path);
    kPaths(root->right, k, count, path);
    int size = path.size();
    int sum = 0;
    for (int i = size; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}

// K paths optimized using unordered map
void kPathsOpt(node *root, int target, long long int currSum, int &count, unordered_map<long long int, int> &m)
{
    if (root == NULL)
    {
        return;
    }
    currSum += root->data;
    if (currSum == target)
    {
        count++;
    }
    count += m[currSum - target];
    m[currSum]++;
    kPathsOpt(root->left, target, currSum, count, m);
    kPathsOpt(root->right, target, currSum, count, m);
    m[currSum]--;
}

// Find KthAncestors of Node
void findKthAncestor(node *root, int &k, node *&found, node *target)
{
    if (root == NULL)
    {
        return;
    }

    if (root == target)
    {
        found = root;
    }

    findKthAncestor(root->left, k, found, target);
    findKthAncestor(root->right, k, found, target);
    if (k == 0 && found != NULL)
    {
        found = root;
        return;
    }
    else if (found != NULL)
    {
        k--;
    }
}

pair<int, int> findMaxSumOfAdjNodes(node *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> left = findMaxSumOfAdjNodes(root->left);
    pair<int, int> right = findMaxSumOfAdjNodes(root->right);

    int first = root->data + left.second + right.second;
    int second = max(left.first, left.second) + max(right.first, right.second);
    return make_pair(first, second);
}

int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(6);
    root->left->right = new node(1);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->right = new node(3);
    int k = 1;
    node *found = NULL;

    findKthAncestor(root, k, found, root->left->right);
    cout << found->data;
    return 0;
}
