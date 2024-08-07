#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(std::vector<int> &arr, int s, int e)
{
     int pivotValue = arr[s];
     int pivotIndex = s;

     for (int i = s + 1; i <= e; i++)
     {
          if (arr[i] < pivotValue)
          {
               cout << "Before " << pivotIndex << " => " << arr[pivotIndex] << endl;
               for (int j = 0; j < arr.size(); j++)
               {
                    cout << arr[j] << " ";
               }
               cout << endl;
               pivotIndex++;
               std::swap(arr[i], arr[pivotIndex]);
               cout << "After " << pivotIndex << " => " << arr[pivotIndex] << endl;
               for (int j = 0; j < arr.size(); j++)
               {
                    cout << arr[j] << " ";
               }
               cout << endl;
          }
     }

     std::swap(arr[s], arr[pivotIndex]);

     return pivotIndex;
}
void quickSort(vector<int> &arr, int s, int e)
{
     if (s >= e)
     {
          return;
     }
     int pivot = partition(arr, s, e);

     cout << arr[s] << " " << arr[pivot] << " " << arr[e] << endl;
     cout << s << " " << pivot << " " << e << endl;
     quickSort(arr, s, pivot - 1);
     quickSort(arr, pivot + 1, e);
}
int main()
{
     vector<int> arr = {1, 6, 5, 1, 3, 9, 1};
     int size = arr.size();
     quickSort(arr, 0, size - 1);
     cout << endl;
     cout << endl;
     for (int k = 0; k < size; k++)
     {
          cout << arr[k] << " ";
     }
     cout << endl;
     cout << endl;
     cout << endl;
}
