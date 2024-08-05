#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseString(string str, int i, int j)
{
     if (i > j)
     {
          return str;
     }
     cout << str << endl;
     swap(str[i], str[j]);
     i++;
     j--;
     return reverseString(str, i, j);
}

string reverseStringOnePointer(string str, int i)
{
     int l = str.length();
     if (i >= l / 2)
     {
          return str;
     }
     cout << str << endl;
     swap(str[i], str[(str.length() - 1) - i]);
     i++;
     return reverseStringOnePointer(str, i);
}

bool checkPalindrome(string str, int i)
{
     int length = str.length();
     if (i >= length / 2)
     {
          return true;
     }

     cout << str << endl;
     if (str[i] != str[(str.length() - 1) - i])
     {
          return false;
     }
     i++;
     return checkPalindrome(str, i);
}

int calcSquare(int x, int n)
{
     if (n == 0)
     {
          return 1;
     }
     if (n == 1)
     {
          return x;
     }
     if (n % 2 == 0)
     {
          return calcSquare(x, n / 2) * calcSquare(x, n / 2);
     }
     else
     {
          return x * calcSquare(x, n / 2) * calcSquare(x, n / 2);
     }
}

void selectionSort(vector<int> &arr, int i)
{
     int size = arr.size();
     if (i == size - 1)
     {
          return;
     }
     int minInd = i;
     for (int j = i + 1; j < size; j++)
     {
          if (arr[j] < arr[minInd])
          {
               minInd = j;
          }
     }
     for (int k = 0; k < size; k++)
     {
          cout << arr[k] << " ";
     }
     cout << "Round " << i + 1 << endl;
     swap(arr[minInd], arr[i]);
     return selectionSort(arr, i + 1);
}

void bubbleSort(vector<int> &arr, int i)
{
     int count = 0;
     int size = arr.size();
     if (i == size - 1)
     {
          return;
     }
     for (int j = 0; j < size - i - 1; j++)
     {
          if (arr[j] > arr[j + 1])
          {
               count++;
               swap(arr[j], arr[j + 1]);
          }
     }
     for (int k = 0; k < size; k++)
     {
          cout << arr[k] << " ";
     }
     cout << "Round " << i + 1 << endl;
     if (count == 0)
     {
          return;
     }
     return bubbleSort(arr, i + 1);
}
void insertionSort(vector<int> &arr, int i)
{
     int size = arr.size();
     if (i == size)
     {
          return;
     }

     int j = i - 1;
     int key = arr[i];
     while (j >= 0 && arr[j] > key)
     {
          arr[j + 1] = arr[j];
          j--;
     }
     arr[j + 1] = key;

     return insertionSort(arr, i + 1);
}
int main()
{
     vector<int> arr = {2, 1, 3, 15, 5, 101, 15, 12};
     int size = arr.size();
     insertionSort(arr, 1);
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
