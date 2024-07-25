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