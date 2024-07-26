#include <iostream>
#include <vector>
using namespace std;

// // Finding first and last occurence of element
// //  First Occurence
// int firstOcc(int arr[], int size, int num)
// {
//     int start = 0;
//     int end = size - 1;
//     int mid = (start + end) / 2;
//     int ans = -1;
//     while (start <= end)
//     {
//         if (arr[mid] == num)
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else if (num > arr[mid] && mid != size - 1)
//         {
//             start = mid + 1;
//         }
//         else if (num < arr[mid] && mid != 0)
//         {
//             end = mid - 1;
//         }
//         mid = (start + end) / 2;
//     }
//     return ans;
// }
// int lastOcc(int arr[], int size, int num)
// {
//     int start = 0;
//     int end = size - 1;
//     int mid = (start + end) / 2;
//     int ans = -1;
//     while (start <= end)
//     {
//         cout << start << " " << mid << " " << end << endl;
//         if (arr[mid] == num)
//         {
//             ans = mid;
//             start = mid + 1;
//         }
//         else if (num > arr[mid])
//         {
//             start = mid + 1;
//         }
//         else if (num < arr[mid])
//         {
//             end = mid - 1;
//         }
//         mid = (start + end) / 2;
//     }
//     return ans;
// }
// // Last Occurence
// int main()
// {
//     const int size = 11;
//     int arr[size] = {3, 7, 9, 9, 11, 11, 11, 11, 11, 13, 19};
//     int left = firstOcc(arr, size, 11);
//     int right = -1;
//     if (left != -1)
//     {
//         right = lastOcc(arr, size, 11);
//     }
//     cout << left << right;
// }

// //_______________
// // Peak Element of array
// int main()
// {
//     vector<int> arr = {1, 2, 3, 5, 3};
//     int start = 0;
//     int end = arr.size() - 1;
//     int mid = start + (end - start) / 2;
//     while (start < end)
//     {
//         if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
//         {
//             break;
//         }
//         else if (arr[mid] < arr[mid + 1])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     cout << arr[mid];
// }

//_______________
// Pivot Index of array
int main()
{
    vector<int> arr = {1, 2, 4, 3};
    int leftSum = 0;
    int rightSum = 0;
    int mid = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        rightSum += arr[i];
    }
    while (rightSum != leftSum && mid < arr.size() - 1) // Instead of while for loop is far better approach
    {
        cout << leftSum << " " << rightSum << endl;
        mid++;
        leftSum += arr[mid - 1];
        rightSum -= arr[mid];
        cout << leftSum << " " << rightSum << endl;
    }
    if (rightSum == leftSum)
    {
        cout << mid;
        return mid;
    }
    else
    {
        cout << -1;
        return -1;
    }
}
