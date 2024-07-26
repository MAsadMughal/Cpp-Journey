#include <iostream>
#include <vector>
using namespace std;

int isPossibleSolution(vector<int> &nums, int k, int mid)
{
    int stdCount = 1;
    int currSPages = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (currSPages + nums[i] <= mid)
        {
            currSPages += nums[i];
        }
        else
        {
            stdCount++;
            // cout << "StdCount " << stdCount << endl;
            if (stdCount > k || nums[i] > mid)
            {
                return false;
            }
            currSPages = nums[i];
        }
    }
    // cout << "CurrPages for mid " << mid << " are " << currSPages << endl;

    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // cout << "Sum " << sum << endl;
    int e = sum;
    int ans = 0;
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        cout << s << " " << mid << " " << e << endl;
        if (isPossibleSolution(nums, k, mid))
        {
            e = mid - 1;
            cout << mid;
            ans = mid;
            cout << ans << endl;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + ((e - s) / 2);
    }
    cout << ans;
    return ans;
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    splitArray(arr, 2);
}