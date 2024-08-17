#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

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
    vector<vector<char>> arr = {{'0', '1', '1', '0'},
                                {'1', '1', '1', '1'},
                                {'1', '1', '1', '1'},
                                {'1', '1', '0', '0'}};
    int size = arr.size();
    vector<int> nums(size);
    int size2 = arr[0].size();
    for (int i = 0; i < size2; i++)
    {
        nums[i] = arr[0][i] - '0';
    }
    int area = getLargestArea(nums);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << nums[j] << " ";
            if (arr[i][j] == '1')
            {
                nums[j] += (arr[i][j] - '0');
            }
            else
            {
                nums[j] = 0;
            }
        }
        cout<<endl;
        area = max(area, getLargestArea(nums));
    }
    cout << area;
}
