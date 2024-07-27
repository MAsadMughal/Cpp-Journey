#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// // Book Allocation Problem Binary Search
// int isPossibleSolution(vector<int> &nums, int k, int mid)
// {
//     int stdCount = 1;
//     int currSPages = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (currSPages + nums[i] <= mid)
//         {
//             currSPages += nums[i];
//         }
//         else
//         {
//             stdCount++;
//             // cout << "StdCount " << stdCount << endl;
//             if (stdCount > k || nums[i] > mid)
//             {
//                 return false;
//             }
//             currSPages = nums[i];
//         }
//     }
//     // cout << "CurrPages for mid " << mid << " are " << currSPages << endl;

//     return true;
// }

// int splitArray(vector<int> &nums, int k)
// {
//     int s = 0;
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//     }
//     // cout << "Sum " << sum << endl;
//     int e = sum;
//     int ans = 0;
//     int mid = s + ((e - s) / 2);
//     while (s <= e)
//     {
//         cout << s << " " << mid << " " << e << endl;
//         if (isPossibleSolution(nums, k, mid))
//         {
//             e = mid - 1;
//             cout << mid;
//             ans = mid;
//             cout << ans << endl;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + ((e - s) / 2);
//     }
//     cout << ans;
//     return ans;
// }

// int main()
// {
//     vector<int> arr = {7, 2, 5, 10, 8};
//     splitArray(arr, 2);
// }

// //______________________________________________
// // Painter Partition Problem Binary Search
// int isPossibleSolution(vector<int> &nums, int k, int mid)
// {
//     long long int painterCount = 0;
//     int size = nums.size();
//     for (int i = 0; i < size; i++)
//     {
//         painterCount += (nums[i] + mid - 1) / mid;

//         if (painterCount > k)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int findTime(vector<int> &nums, int k)
// {
//     int s = 1;
//     int max = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] > max)
//             max = nums[i];
//     }
//     int e = max;
//     int ans = 0;
//     int mid;
//     while (s <= e)
//     {
//         mid = s + ((e - s) / 2);
//         if (isPossibleSolution(nums, k, mid))
//         {
//             e = mid - 1;
//             ans = mid;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> arr = {5, 5, 5, 5};
//     findTime(arr, 4);
// }

//______________________________________________
// Aggressive Cows Problem Binary Search
int isPossibleSolution(vector<int> &nums, int k, int mid)
{
    int cows = 1;
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - curr >= mid)
        {
            cows++;
            if (cows == k)
            {
                return true;
            }
            curr = nums[i];
        }
    }
    return false;
}

int findDistance(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int s = 1;
    int e = nums[nums.size() - 1] - nums[0];
    int ans = -1;
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        cout << s << " " << mid << " " << e << endl;
        if (isPossibleSolution(nums, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    cout << ans;
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 7};
    findDistance(arr, 3);
}