#include <iostream>
#include <vector>
using namespace std;

// // Selection Sort
// // Time Complexity O(n2) O(n2)
// // Space Complexity O(1)

// // Use selection sort when memory constraint or small size of array.

int main()
{
    vector<int> arr = {6, 2, 8, 4, 10};
    for (int i = 0; i <= arr.size() - 2; i++)
    {
        int minInd = i;
        for (int j = i + 1; j <= arr.size() - 1; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        swap(arr[minInd], arr[i]);
    }
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
}