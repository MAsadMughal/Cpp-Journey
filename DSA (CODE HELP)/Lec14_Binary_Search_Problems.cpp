#include <iostream>
#include <vector>
using namespace std;

// int searchPivot()
// {
//     const int size = 5;
//     int arr[size] = {3, 8, 10, 17, 1};
//     int start = 0;
//     int end = size - 1;
//     int mid = start + ((end - start) / 2);
//     while (start < end)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + ((end - start) / 2);
//     }
//     cout << mid;
// }

// int searchElementUsingPivot()
// {
//     // Find pivot element first
//     int key = 3;
//     const int size = 5;
//     int arr[size] = {3, 8, 10, 17, 1};
//     int start = 0;
//     int end = size - 1;
//     int mid = start + ((end - start) / 2);
//     while (start < end)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + ((end - start) / 2);
//     }

//     if (arr[0] <= key && key <= arr[mid - 1])
//     {
//         int s = 0;
//         int e = mid - 1;
//         int m = s + ((e - s) / 2);
//         while (s <= e)
//         {
//             if (arr[m] == key)
//             {
//                 cout << m;
//                 return m;
//             }
//             else if (key < arr[m])
//             {
//                 e = m - 1;
//             }
//             else
//             {
//                 s = m + 1;
//             }
//             m = s + ((e - s) / 2);
//         }
//     }
//     else
//     {
//         int s = mid;
//         int e = size - 1;
//         int m = s + ((e - s) / 2);
//         while (s <= e)
//         {
//             if (arr[m] == key)
//             {
//                 cout << m;
//                 return m;
//             }
//             else if (key < arr[m])
//             {
//                 e = m - 1;
//             }
//             else
//             {
//                 s = m + 1;
//             }
//             m = s + ((e - s) / 2);
//         }
//     }
//     cout << -1;
//     return -1;
// }


int sqrt(int x)
{
    int s = 0;
    int e = x;
    int ans = 0;
    int mid = s + ((e - s) / 2);
    while (s < e)
    {
        cout << s << " " << mid << " " << e << endl;
        if (mid * mid == x)
        {
            ans = mid;
            cout << ans;
            return ans;
        }
        else if (mid * mid > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }

        mid = s + ((e - s) / 2);
    }
    cout << ans;
    return ans;
}
int main()
{
    sqrt(36);
}