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
int main()
{
     vector<int> arr = {1, 6, 5, 1, 3, 9, 1};
     int size = arr.size();
     mergeSort(arr, 0, size - 1);
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
