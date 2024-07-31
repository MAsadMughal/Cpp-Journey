#include <iostream>
#include <vector>
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

// Printing Spiral
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int rows = arr.size();
    int cols = arr[0].size();
    int count = 0;
    int total = rows * cols;
    int firstRow = 0;
    int lastCol = cols - 1;
    int lastRow = rows - 1;
    int firstCol = 0;

    while (count < total)
    {
        for (int i = firstCol; i <= lastCol; i++)
        {
            cout << arr[firstRow][i] << " ";
            count++;
        }
        firstRow++;

        for (int i = firstRow; i <= lastRow; i++)
        {
            cout << arr[i][lastCol] << " ";
            count++;
        }
        lastCol--;

        for (int i = lastCol; i >= firstCol; i--)
        {
            cout << arr[lastRow][i] << " ";
            count++;
        }
        lastRow--;
        for (int i = lastRow; i >= firstRow; i--)
        {
            cout << arr[i][firstCol] << " ";
            count++;
        }
        firstCol++;
    }

    return 0;
}
