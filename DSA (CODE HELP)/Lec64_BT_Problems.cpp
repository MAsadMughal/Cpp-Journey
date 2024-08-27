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
// Zig Zag Traversal
vector<vector<int>> ZigZagTraversal(node *root)
{
    queue<node *> q;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    bool r = false;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> sub(size);
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            int ind = r ? i : size - 1 - i;
            sub[ind] = temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        r = !r;
        ans.push_back(sub);
        sub.clear();
    }
    return ans;
}

// Boundary Traversal of Tree
// Function to traverse and collect left boundary nodes (excluding leaf nodes)
void LeftTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    node *current = root->left;
    while (current != nullptr)
    {
        if (current->left != nullptr || current->right != nullptr)
        {
            ans.push_back(current->data);
        }
        if (current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}

// Function to traverse and collect leaf nodes
void LeafTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
    }
    else
    {
        LeafTraversal(root->left, ans);
        LeafTraversal(root->right, ans);
    }
}

// Function to traverse and collect right boundary nodes (excluding leaf nodes)
void RightTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    vector<int> mini;
    node *current = root->right;
    while (current != nullptr)
    {
        if (current->left != nullptr || current->right != nullptr)
        {
            mini.push_back(current->data);
        }
        if (current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    // Add collected right boundary nodes in reverse order
    for (int i = mini.size() - 1; i >= 0; i--)
    {
        ans.push_back(mini[i]);
    }
    // vector<int> arr;
    // arr.push_back(root->data);
    // LeftTraversal(root, arr);
    // LeafTraversal(root->left, arr);
    // LeafTraversal(root->right, arr);
    // RightTraversal(root, arr);
}

//_________________________
// Vertical Traversal
vector<vector<int>> verticalTraversalBinaryTree(node *root)
{
    vector<vector<int>> result;
    map<pair<int, int>, vector<node *>> dict;
    queue<pair<node *, pair<int, int>>> q;
    if (root == NULL)
    {
        return result;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<node *, pair<int, int>> curr = q.front();
            node *temp = curr.first;
            int currDistance = curr.second.first;
            int currLevel = curr.second.second;
            dict[make_pair(currDistance, currLevel)].push_back(temp);
            q.pop();
            if (temp->left)
            {
                q.push(make_pair(temp->left, make_pair(currDistance - 1, currLevel + 1)));
            }
            if (temp->right)
            {
                q.push(make_pair(temp->right, make_pair(currDistance + 1, currLevel + 1)));
            }
        }
    }

    int lastDistance = INT_MIN;
    vector<int> column;

    for (auto &entry : dict)
    {
        int distance = entry.first.first;

        if (distance != lastDistance)
        {
            if (!column.empty())
            {
                result.push_back(column);
            }
            column.clear();
            lastDistance = distance;
        }

        vector<int> sortedData;
        for (node *n : entry.second)
        {
            sortedData.push_back(n->data);
        }
        std::sort(sortedData.begin(), sortedData.end());

        for (int data : sortedData)
        {
            column.push_back(data);
        }
    }

    if (!column.empty())
    {
        result.push_back(column);
    }
    return result;
}

//_________________________
// TopView
vector<int> TopView(node *root)
{
    vector<int> result;
    map<int, node *> dict;
    queue<pair<node *, int>> q;
    if (root == NULL)
    {
        return result;
    }
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<node *, int> curr = q.front();
            node *temp = curr.first;
            int currDistance = curr.second;
            if (!dict[currDistance])
                dict[currDistance] = temp;
            q.pop();
            if (temp->left)
            {
                q.push(make_pair(temp->left, currDistance - 1));
            }
            if (temp->right)
            {
                q.push(make_pair(temp->right, currDistance + 1));
            }
        }
    }
    for (const auto &pair : dict)
    {
        result.push_back(pair.second->data);
    }
    return result;
}

// TopView
vector<int> BottomView(node *root)
{
    vector<int> result;
    map<int, node *> dict;
    queue<pair<node *, int>> q;
    if (root == NULL)
    {
        return result;
    }
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<node *, int> curr = q.front();
            node *temp = curr.first;
            int currDistance = curr.second;
            dict[currDistance] = temp;
            q.pop();
            if (temp->left)
            {
                q.push(make_pair(temp->left, currDistance - 1));
            }
            if (temp->right)
            {
                q.push(make_pair(temp->right, currDistance + 1));
            }
        }
    }
    for (const auto &pair : dict)
    {
        result.push_back(pair.second->data);
    }
    return result;
}

// Left View Using Recursion
void leftView(node *root, vector<int> &arr, int level)
{
    if (root == NULL)
    {
        return;
    }

    int size = arr.size();
    if (size == level)
    {
        arr.push_back(root->data);
    }
    leftView(root->left, arr, level + 1);
    leftView(root->right, arr, level + 1);
}
// Right View
void rightView(node *root, vector<int> &arr, int level)
{
    if (root == NULL)
    {
        return;
    }
    int size = arr.size();
    if (size == level)
    {
        arr.push_back(root->data);
    }
    rightView(root->right, arr, level + 1);
    rightView(root->left, arr, level + 1);
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
    return 0;
}
