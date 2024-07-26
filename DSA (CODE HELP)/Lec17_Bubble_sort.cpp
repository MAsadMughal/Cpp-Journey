#include <iostream>
#include <vector>
using namespace std;

// // Bubble Sort
// // Time Complexity O(n) //if swap checked by bool else=> O(n2)
// // Space Complexity O(1)
// In place sorting algorithm because does not use extra array
// putting ith largest element into its place in ith round
int main()
{
    vector<int> arr = {1, 7, 6, 10, 9, 14, 4, 10};
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}