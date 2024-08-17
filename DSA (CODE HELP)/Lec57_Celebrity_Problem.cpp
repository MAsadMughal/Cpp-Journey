#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int findCelebrity(vector<vector<int>> arr)
{
    stack<int> s;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        s.push(i);
    }
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (arr[a][b] == 1) // checks if a knows b then ignore a
        {
            s.push(b);
        }
        else // ignore b because it is not known by a
        {
            s.push(a);
        }
    }
    int c = s.top();
    // Verify
    // checkstatus
    bool status = true;
    // Check Celebrity knows no Body
    for (int i = 0; i < size; i++)
    {
        if (arr[c][i] == 1 && i != c)
        {
            status = false;
            break;
        }
    }
    if (status == true)
    {
        // Everyone Knows Celebrity
        for (int i = 0; i < size; i++)
        {
            if (arr[i][c] == 0 && i != c)
            {
                status = false;
                break;
            }
        }
    }

    if (status == true)
    {
        return c;
    }
    else
    {
        return -1;
    }
}

// ______________________________________________
// Largest Rectangular Area of Matrix
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
    vector<vector<int>> arr = {{0, 1, 1, 0},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 0, 0}};
    int size = arr.size();
    int area = getLargestArea(arr[0]);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] += arr[i - 1][j];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
        area = max(area, getLargestArea(arr[i]));
    }
    cout << area;
}