#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nextSmallElement(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size(), -1);
    int size = arr.size();
    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (!s.empty() && s.top() >= curr)
        {
            s.pop();
        }
        if (!s.empty()) // If stack is not empty, top element is the next smaller element
        {
            ans[i] = s.top();
        }
        s.push(curr);
    }
    return ans;
}

// Largest Area of Histogram
vector<int> nextSmall(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    int size = v.size();
    vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmall(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    int size = v.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int getLargestArea(vector<int> arr)
{
    int size = arr.size();
    vector<int> prev(size);
    vector<int> next(size);
    prev = prevSmall(arr);
    next = nextSmall(arr);
    int maxArea = 0;
    for (int i = 0; i < size; i++)
    {
        int length = arr[i];
        if (next[i] == -1)
        {
            next[i] = size;
        }
        int breadth = next[i] - prev[i] - 1;
        int area = length * breadth;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << getLargestArea(arr);
}