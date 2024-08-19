#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Print Queue
void print(queue<int> q)
{
    if (q.empty())
    {
        return;
    }
    int n = q.front();
    q.pop();
    print(q);
    cout << n << " ";
    q.push(n);
}

// Reverse Queue
void reverseQusingStack(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
// Reverse Queue using recursion
void reverseQusingRecursion(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int n = q.front();
    q.pop();
    reverseQusingRecursion(q);
    q.push(n);
}

// First Negative integer in Window
vector<int> firstNegativeInWindow(vector<int> arr, int k)
{

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    if (!q.empty())
    {
        ans.push_back(arr[q.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    int size = arr.size();
    for (int i = k; i < size; i++)
    {
        if (!q.empty() && i - q.front() >= k)
        {
            q.pop();
        }

        if (arr[i] < 0)
        {
            q.push(i);
        }
        if (!q.empty())
        {
            ans.push_back(arr[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

// Reverse First k elements of Queue
void reverseKElements(queue<int> &q, int k)
{
    // O(n)
    // O( k);
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
}

// First Unique Character in String
int firstUniqChar(string s)
{
    int f[26] = {0};
    for (char c : s)
    {
        f[c - 'a'] += 1;
    }
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (f[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

// Traversing across Petrol Pumps Problem (Imp)
int validStartForTravel(vector<int> petrol, vector<int> dis)
{
    int start = 0;
    int deficit = 0;
    int balance = 0;
    int size = petrol.size();
    for (int i = 0; i < size; i++)
    {
        balance = petrol[i] - dis[i];

        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

// Interleave First Half Using Stack (Best Approach is doing it using new Queue)
void interleaveQueue(queue<int> &q)
{
    stack<int> s;
    int t = q.size() / 2;
    // 8 7 1 3 2 5
    while (t--)
    {
        s.push(q.front());
        q.pop();
    }
    // 3 2 5
    // s-> 8 7 1
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    // 3 2 5 1 7 8
    t = q.size() / 2;
    while (t--)
    {
        q.push(q.front());
        q.pop();
    }
    // 1 7 8 3 2 5
    t = q.size() / 2;
    while (t--)
    {
        s.push(q.front());
        q.pop();
    }

    // 3 2 5
    // 1 7 8
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    // 8 3 7 2 1 5
}

//______________________________________
// N QUEUES IN ARRAY
class Queue
{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int size;
    int free;
    Queue(int size, int k)
    {
        free = 0;
        this->size = size;
        arr = new int[size];
        front = new int[k];
        rear = new int[k];
        next = new int[size];

        for (int i = 0; i < size - 1; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
    }

    void push(int val, int q)
    {
        if (free == -1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        int ind = free;
        free = next[ind];
        cout << "Pushed " << val << " at position " << ind << " for queue " << q + 1 << endl;
        if (front[q] == -1)
        {
            // Val is First Element to be pushed
            front[q] = ind;
        }
        else
        {
            next[rear[q]] = ind;
        }
        next[ind] = -1;
        rear[q] = ind;
        arr[ind] = val;
    }
    void pop(int q)
    {
        if (front[q] == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int index = front[q];
        cout << "Popped " << arr[index] << " from position " << index << " and queue " << q + 1 << endl;
        front[q] = next[index];
        next[index] = free;
        free = index;
    }
    void print(int k)
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < k; i++)
        {
            cout << "Front and Rear for Queue " << i + 1 << " are " << front[i] << " and " << rear[i] << endl;
        }
        cout << "Now free Index is " << free << endl;
    }
};

// Return Sum of Maxs and Mins window of size k for an array
int sumOfMinAndMaxOfWindow(vector<int> arr, int k)
{
    int size = arr.size();
    deque<int> mini;
    deque<int> maxi;

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        mini.push_back(i);
        maxi.push_back(i);
    }

    int sum = 0;
    sum += arr[mini.front()] + arr[maxi.front()];
    for (int i = k; i < size; i++)
    {
        // Summing up

        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        mini.push_back(i);
        maxi.push_back(i);
        sum += arr[mini.front()] + arr[maxi.front()];
    }
    return sum;
}
int main()
{
    vector<int> arr = {1, 3, 4, -1, 4, 2};
    cout << sumOfMinAndMaxOfWindow(arr, 3);
}