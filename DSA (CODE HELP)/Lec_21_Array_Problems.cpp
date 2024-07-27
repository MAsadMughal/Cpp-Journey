#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Leetcode Problems
// // Rotate Array
// int rotateArr(vector<int> arr, int k)
// {
//     int size = arr.size();
//     vector<int> a(size);
//     for (int i = 0; i < size; i++)
//     {
//         a[(i + k) % size] = arr[i];
//     }
//     arr = a;
//     for (int val : arr)
//     {
//         cout << val << " ";
//     }
// }
// int main()
// {
//     vector<int> arr = {1, 3, 4, 5};
//     rotateArr(arr, 2);
// }

// //______________________
// // Rotate Array
// int checkSortedAndRotated(vector<int> arr)
// {
//     int size = arr.size();
//     int count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             count++;
//         }
//     }
//     return count <= 1;
// }
// int main()
// {
//     vector<int> arr = {3, 4, 5, 1, 2};
//     checkSortedAndRotated(arr);
// }

//______________________
// Sum of integer and arrayInt
vector<int> IntArraySum(vector<int> num, int k)
{
    int carry = 0;
    int size = num.size();
    for (int i = size - 1; i >= 0; i--)
    {
        int sum = (k % 10) + num[i] + carry;
        num[i] = sum % 10;
        carry = sum / 10;
        k = k / 10;
    }
    while (k > 0 || carry > 0)
    {
        int sum = (k % 10) + carry;
        num.insert(num.begin(), sum % 10);
        carry = sum / 10;
        k = k / 10;
    }
    return num;
}
int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    vector<int> arr2;
    arr2 = IntArraySum(arr, 110);
    for (int a : arr2)
    {
        cout << a << " ";
    }
}