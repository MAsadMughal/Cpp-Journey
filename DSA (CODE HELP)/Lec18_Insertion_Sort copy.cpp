#include <iostream>
#include <vector>
using namespace std;

// // Insertion Sort
// // Time Complexity O(n) In best case because 1 comparison only when sorted instead of n-1, else O(n2)
// // Space Complexity O(1)
// Making place for ith element at its correct place

// In place sorting algorithm because does not use extra array
// Stable sorting algorithm because does not changes place of similar elements
//  Adaptable sorting algorithm because array is sorted with time
int main()
{
    vector<int> arr = {1, 7, 6, 10, 9, 14, 4, 10};
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}