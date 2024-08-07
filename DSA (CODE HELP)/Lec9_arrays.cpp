#include <iostream>
using namespace std;

//________________Arrays________________
// Array takes consecutive blocks of memory.
// If few elements are initialized all other elements are auto 0.
// void min_and_max(int arr[], int size)
// {
//     int mini = arr[0];
//     int maxi = arr[0];
//     for (int i = 1; i < size; i++)
//     {
//         mini = min(mini, arr[i]);
//         maxi = max(maxi, arr[i]);
//     }
//     cout << mini << endl
//          << maxi;
// }

// int main()
// {
//     int arr[4] = {2, 4, 1, 5};
//     // fill_n(arr, 4, 3); for initializing array
//     min_and_max(arr, 4); // here keep in mind changing this array in another function will change original array because address of first element is being passed.
// }

// //________________________
// // Reversing an array
// void reverse_arr(int arr[], int size)
// {
//     for (int i = 0; i < size / 2; i++)
//     {
//         swap(arr[i], arr[size - i - 1]);
//     }
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void reverse_arr_babbar_method(int arr[], int size)
// {
//     int start = 0;
//     int end = size - 1;
//     while (start < end)
//     {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 5, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     reverse_arr_babbar_method(arr, size);
//     return 0;
// }