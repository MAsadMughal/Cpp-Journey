#include <iostream>
#include <vector>
using namespace std;
// Leetcode Problems

// // Reverse Array
// void reverseArray(vector<char> &s)
// {
//     int st = 0;
//     int e = s.size() - 1;
//     while (st < e)
//     {
//         swap(s[st], s[e]);
//         st++;
//         e--;
//     }
// }

// // merging sorted Arrays
// void mergeArrays()
// {
//     const int m = 5;
//     const int n = 3;
//     int nums1[m] = {9, 8, 6, 4, 2};
//     int nums2[n] = {3, 5, 7};

//     int arr3[m + n] = {};
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     while (i < m && j < n)
//     {
//         if (nums1[i] < nums2[j])
//         {
//             arr3[count++] = nums1[i++];
//         }
//         else
//         {
//             arr3[count++] = nums2[j++];
//         }
//     }
//     while (i < m)
//     {
//         arr3[count++] = nums1[i++];
//     }
//     while (j < n)
//     {
//         arr3[count++] = nums2[j++];
//     }

//     for (int i = 0; i < m + n; i++)
//     {
//         cout << arr3[i] << " ";
//     }
// }

// // Merge into single Array
// void mergeIntoArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     int i = m - 1;     // Pointer for nums1's last element in the initial portion
//     int j = n - 1;     // Pointer for nums2's last element
//     int k = m + n - 1; // Pointer for the last element of the merged array

//     // Merge from the end to the beginning
//     while (i >= 0 && j >= 0)
//     {
//         if (nums1[i] > nums2[j])
//         {
//             nums1[k--] = nums1[i--];
//         }
//         else
//         {
//             nums1[k--] = nums2[j--];
//         }
//     }

//     // If there are remaining elements in nums2, copy them
//     while (j >= 0)
//     {
//         nums1[k--] = nums2[j--];
//     }
// }

// Move Zeroes
int main()
{
    vector<int> arr = {0,1, 5, 7, 3, 6, 5, 0};

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
    for (int v : arr)
    {
        cout << v << " " << endl;
    }
}