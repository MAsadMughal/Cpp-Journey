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

node* parentMapping(node* root, map<node*, node*>& m,
                            int target) {
        node* ans = NULL;
        queue<node*> q;
        q.push(root);
        m[root] = NULL;
        while (!q.empty()) {
            node* curr = q.front();
            q.pop();
            if (curr->data == target) {
                ans = curr;
            }

            if (curr->left) {
                q.push(curr->left);
                m[curr->left] = curr;
            }

            if (curr->right) {
                q.push(curr->right);
                m[curr->right] = curr;
            }
        }
        return ans;
    }

    int burnTree(node* root, map<node*, node*>& m,
                 map<node*, bool>& visit) {
        int ans = 0;
        queue<node*> q;
        q.push(root);
        visit[root] = true;
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++) {
                node* curr = q.front();
                q.pop();
                if (curr->left && !visit[curr->left]) {
                    q.push(curr->left);
                    visit[curr->left] = 1;
                    flag = true;
                }
                if (curr->right && !visit[curr->right]) {
                    q.push(curr->right);
                    visit[curr->right] = 1;
                    flag = true;
                }
                if (m[curr] && !visit[m[curr]]) {
                    q.push(m[curr]);
                    visit[m[curr]] = 1;
                    flag = true;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(4);
    root->left->left = new node(2);
    root->left->left->left = new node(3);
}

