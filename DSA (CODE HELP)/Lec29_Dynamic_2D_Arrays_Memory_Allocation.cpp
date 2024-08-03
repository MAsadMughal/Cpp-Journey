#include <iostream>
#include <algorithm>
using namespace std;

// int main()
// {
//      int rows;
//      int cols;
//      cout << "Enter Rows " << endl;
//      cin >> rows;
//      cout << "Enter Columns " << endl;
//      cin >> cols;

//      int **arr = new int *[rows];

//      for (int i = 0; i < rows; i++)
//      {
//           arr[i] = new int[cols];
//      }

//      for (int i = 0; i < rows; i++)
//      {
//           for (int j = 0; j < cols; j++)
//           {
//                cout << "Enter " << j + 1 << "th item of " << i + 1 << "row" << endl;
//                cin >> arr[i][j];
//           }
//      }
//      for (int i = 0; i < rows; i++)
//      {
//           for (int j = 0; j < cols; j++)
//           {
//                cout << arr[i][j] << " ";
//           }
//           cout << endl;
//      }

//      for (int i = 0; i < rows; i++)
//      {
//           delete[] arr[i];
//      }

//      delete[] arr;
// }

int main()
{
     int numRows;
     std::cout << "Enter the number of rows: ";
     std::cin >> numRows;

     // Step 1: Create an array of pointers
     int **jaggedArray = new int *[numRows];

     // Step 2: Allocate memory for each row
     for (int i = 0; i < numRows; ++i)
     {
          int numCols;
          std::cout << "Enter the number of elements in row " << i + 1 << ": ";
          std::cin >> numCols;
          jaggedArray[i] = new int[numCols];

          // Step 3: Take input for each element in the current row
          std::cout << "Enter elements for row " << i + 1 << ": ";
          for (int j = 0; j < numCols; ++j)
          {
               std::cin >> jaggedArray[i][j];
          }
     }

     // Display the jagged array
     std::cout << "The jagged array is:" << std::endl;
     for (int i = 0; i < numRows; ++i)
     {
          int j = 0;
          while (jaggedArray[i][j] != '\0')
          {
               std::cout << jaggedArray[i][j] << " ";
               j++;
          }
          std::cout << std::endl;
     }

     // Step 4: Deallocate memory
     for (int i = 0; i < numRows; ++i)
     {
          delete[] jaggedArray[i];
     }
     delete[] jaggedArray;

     return 0;
}
