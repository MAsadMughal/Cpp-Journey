#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Printing Array as SIN Wave
// int main()
// {
//     const int rows = 2;
//     const int cols = 3;
//     int arr[rows][cols] = {1, 2, 3, 4, 5, 6};

//     for (int i = 0; i < cols; i++)
//     { // we can also use if else separately
//         int start = i % 2 == 0 ? 0 : rows - 1;
//         int end = i % 2 == 0 ? rows : -1;
//         for (int j = start; i % 2 == 0 ? j < end : j > end; i % 2 == 0 ? j++ : j--)
//         {
//             cout << arr[j][i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// // Printing Spiral
// int main()
// {
//     vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     vector<int> arr2;
//     int rows = arr.size();
//     int cols = arr[0].size();
//     int count = 0;
//     int total = rows * cols;
//     int firstRow = 0;
//     int lastCol = cols - 1;
//     int lastRow = rows - 1;
//     int firstCol = 0;

//     while (count < total)
//     {
//         for (int i = firstCol; i <= lastCol && count < total; i++)
//         {
//             arr2.push_back(arr[firstRow][i]);
//             cout << arr[firstRow][i] << " ";
//             count++;
//         }
//         firstRow++;

//         for (int i = firstRow; i <= lastRow && count < total; i++)
//         {
//             arr2.push_back(arr[i][lastCol]);
//             cout << arr[i][lastCol] << " ";
//             count++;
//         }
//         lastCol--;

//         for (int i = lastCol; i >= firstCol && count < total; i--)
//         {
//             arr2.push_back(arr[lastRow][i]);
//             cout << arr[lastRow][i] << " ";
//             count++;
//         }
//         lastRow--;
//         for (int i = lastRow; i >= firstRow && count < total; i--)
//         {
//             arr2.push_back(arr[i][firstCol]);
//             cout << arr[i][firstCol] << " ";
//             count++;
//         }
//         firstCol++;
//     }

//     return 0;
// }

// // Rotate 2D Array by 90 degrees
// int main()
// {
//     vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     const int rows = arr.size();
//     const int cols = arr[0].size();
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = i; j < cols; j++)
//         {
//             swap(arr[i][j], arr[j][i]);
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         reverse(arr[i].begin(), arr[i].end());
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// Searching a 2D array
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     if (matrix.empty() || matrix[0].empty())
//     {
//         return false;
//     }
//     int start = 0;
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int end = m * n - 1;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         int midVal = matrix[mid / n][mid % n];
//         if (target == midVal)
//         {
//             return true;
//         }
//         else if (target < midVal)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//     }
//     return false;
// }
// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     cout << searchMatrix(matrix, 12);
// }

// Binary Search in Row and Col Wise Sorted Array
int main()
{

    int target;
    cin >> target;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
    };
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowInd = 0;
    int colInd = cols - 1;
    while (colInd >= 0 && rowInd < rows)
    {
        int curr = matrix[rowInd][colInd];
        if (curr == target)
        {
            cout << "Found";
            return true;
        }
        else if (curr < target)
        {
            rowInd++;
        }
        else
        {
            colInd--;
        }
    }
    cout << "Not Found";
    return false;
}
