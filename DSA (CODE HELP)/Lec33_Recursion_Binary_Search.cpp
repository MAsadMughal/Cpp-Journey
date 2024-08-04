#include <iostream>
#include <vector>
using namespace std;

bool isSorted(int arr[], int size)
{
     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;
     if (size == 0 || size == 1)
     {
          return true;
     }

     if (arr[0] > arr[1])
     {
          return false;
     }

     return isSorted(arr + 1, size - 1);
}
int getSum(int arr[], int size)
{

     // for (int i = 0; i < size; i++)
     // {
     //      cout << arr[i] << " ";
     // }

     if (size == 0)
     {
          return 0;
     }

     if (size == 1)
     {
          return arr[0];
     }

     int sum = arr[0] + getSum(arr + 1, size - 1);
     return sum;
}

bool linearSearch(int arr[], int size, int key)
{

     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl
          << endl;
     if (size == 0)
     {
          return false;
     }

     if (key == arr[0])
     {
          return true;
     }

     return linearSearch(arr + 1, size - 1, key);
}

bool binarySearch(int arr[], int start, int end, int key)
{

     if (start > end)
     {
          return false;
     }
     int mid = start + (end - start) / 2;
     if (key == arr[mid])
     {
          return true;
     }
     if (key < arr[mid])
     {
          return binarySearch(arr, start, mid - 1, key);
     }
     else
     {
          return binarySearch(arr, mid + 1, end, key);
     }
}

// MEMORY LIMIT EXCEEDED
int pivotIndex(vector<int> &arr, int curr, int leftSum, int rightSum)
{
     int size = arr.size();
     if (curr >= size)
     {
          return -1;
     }
     if (rightSum == leftSum)
     {
          return curr;
     }
     return pivotIndex(arr, curr + 1, leftSum + arr[curr], rightSum - (curr + 1 < size ? arr[curr + 1] : 0));
}

int sqroot(int x, int start, int end, int ans)
{
     int mid = start + (end - start) / 2;
     if (start > end)
     {
          return ans;
     }
     if (mid == x / mid)
     {
          return mid;
     }
     if (mid < x / mid)
     {
          ans = mid;
          return sqroot(x, mid + 1, end, ans);
     }
     else
     {
          return sqroot(x, start, mid - 1, ans);
     }
}
int main()
{
     int num;
     cin >> num;
     cout << sqroot(num, 0, num, 0);
}
