#include <iostream>
#include <string>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e)
{
     int mid = s + (e - s) / 2;
     int len1 = mid - s + 1;
     int len2 = e - mid;
     int *arr1 = new int[len1];
     int *arr2 = new int[len2];

     int i = 0;
     int j = 0;
     int ind = s;
     for (int i = 0; i < len1; i++)
     {
          arr1[i] = arr[ind++];
     }
     for (int i = 0; i < len2; i++)
     {
          arr2[i] = arr[ind++];
     }
     ind = s;
     while (i < len1 && j < len2)
     {
          if (arr1[i] < arr2[j])
          {
               arr[ind++] = arr1[i++];
          }
          else
          {
               arr[ind++] = arr2[j++];
          }
     }
     while (i < len1)
     {
          arr[ind++] = arr1[i++];
     }
     while (j < len2)
     {
          arr[ind++] = arr2[j++];
     }

     delete[] arr1;
     delete[] arr2;
}
void mergeSort(vector<int> &arr, int s, int e)
{

     if (s >= e)
     {
          return;
     }

     int mid = s + (e - s) / 2;
     mergeSort(arr, s, mid);
     mergeSort(arr, mid + 1, e);
     merge(arr, s, e);
}
int partition(vector<int> &arr, int s, int e)
{
     int pivotIndex = s;
     int pivotValue = arr[pivotIndex];
     int c = 0;
     for (int i = s + 1; i <= e; i++)
     {
          if (arr[i] < pivotValue)
          {
               c++;
          }
     }
     pivotIndex = s + c;
     swap(arr[pivotIndex], arr[s]);
     int i = s;
     int j = e;
     while (i < pivotIndex && j > pivotIndex)
     {
          while (arr[i] < pivotValue)
          {
               i++;
          }
          while (arr[j] > pivotValue)
          {
               j--;
          }
          if (i < pivotIndex && j > pivotIndex)
          {
               swap(arr[i], arr[j]);
               i++;
               j--;
          }
     }
     return pivotIndex;
}
void quickSort(vector<int> &arr, int s, int e)
{

     if (s >= e)
     {
          return;
     }

     int pivot = partition(arr, s, e);

     quickSort(arr, s, pivot - 1);
     quickSort(arr, pivot + 1, e);
}

int main()
{
     vector<int> arr = {5, 3, 1, 7, 4, 5, 13, 22, 6, 1, 8, 4};
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
