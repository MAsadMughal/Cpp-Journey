#include <iostream>
#include <vector>
using namespace std;

//________________Arrays________________

// Display array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// // Swapping alternate elements
// void swappArrays(int arr[], int size)
// {
//     for (int i = 0; i < size - 1; i += 2)
//     {
//         swap(arr[i], arr[i + 1]);
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 5, 6, 9};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     swappArrays(arr, size);
//     display(arr, size);
//     return 0;
// }

// //_________________________
// // Finding unique element in array where all other elements are duplicate
// int findUnique(int arr[], int size)
// {
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 2, 4, 1};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     cout << findUnique(arr, size);
//     return 0;
// }

// //_________________________
// // Finding unique element in array where all other elements are duplicate
// int findUnique(int arr[], int size)
// {
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 2, 4, 1};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     cout << findUnique(arr, size);
//     return 0;
// }

// //_________________________
// // Check if Unique occurences of elements in array
// bool hasVal(int arr[], int size, int num)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == num)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool uniqueOccurences(int arr[], int size)
// {
//     int values[1000] = {};
//     int occurences[1000] = {};
//     int sizeArr = 0;
//     for (int i = 0; i < size; i++)
//     {

//         if (hasVal(values, sizeArr, arr[i]))
//         {
//             continue;
//         }
//         int currCount = 0;
//         for (int j = 0; j < size; j++)
//         {

//             if (arr[j] == arr[i])
//             {
//                 currCount++;
//             }
//         }

//         values[sizeArr] = arr[i];
//         occurences[sizeArr] = currCount;
//         sizeArr++;
//     }
//     for (int i = 0; i < sizeArr - 1; i++)
//     {
//         for (int j = i + 1; j < sizeArr; j++)
//         {
//             if (occurences[j] == occurences[i])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     int arr[] = {1, 3, 2, 2, 2, 2, 4, 9, 2, 4, 1, 4, 2, 2, 3, 4, 4, 5, 5, 3, 8, 5, 9, 9, 9, 9, 9, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     cout << uniqueOccurences(arr, size);
//     return 0;
// }

// // //_________________________
// // // Finding Duplicate in array with 1 to n-1 elements all elements are unique
// int findDuplicateWithinN(int arr[], int size)
// {
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     // giving 5 as ans equal to arr excluding duplicate
//     for (int i = 1; i < size; i++)
//     {
//         ans = ans ^ i;
//         // left with duplicate all other uniques cancelled
//     }
//     return ans;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 2, 5, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     cout << findDuplicateWithinN(arr, size);
//     return 0;
// }

// //_________________________
// // Finding Duplicate elements in array
// bool hasVal(int arr[], int size, int num)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == num)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int findDuplicatesInArr(int arr[], int size)
// {

//     int arr2[10000] = {};
//     int count = 0;

//     for (int i = 0; i < size - 1; i++)
//     {
//         if (hasVal(arr2, count, arr[i]))
//         {
//             continue;
//         }
//         for (int j = i + 1; j < size; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 arr2[count] = arr[i];
//                 count++;
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     int arr[] = {1, 2, 1, 4, 2, 5, 6, 6, 7, 3};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     findDuplicatesInArr(arr, size);
//     return 0;
// }

// //__________________
// // Find intersection using two pointers
// vector<int> intersectionofArr(vector<int> arr1, vector<int> arr2)
// {
//     vector<int> arr3;
//     int size1 = arr1.size();
//     int size2 = arr2.size();
//     int i = 0, j = 0;

//     while (i < size1 && j < size2)
//     {

//         if (arr1[i] == arr2[j])
//         {
//             arr3.push_back(arr1[i]);
//             i++;
//             j++;
//         }
//         else if (arr1[i] > arr2[j])
//         {
//             j++;
//         }
//         else if (arr1[i] < arr2[j])
//         {
//             i++;
//         }
//     }
//     for (int i = 0; i < arr3.size(); i++)
//     {
//         cout << arr3[i] << " ";
//     }
//     return arr3;
// }
// int main()
// {
//     vector<int> arr1 = {1, 2, 3, 4, 5};
//     vector<int> arr2 = {1, 2, 3, 4};
//     intersectionofArr(arr1, arr2);
//     return 0;
// }

// //__________________
// // Pair Sum
// vector<vector<int>> pairSum(vector<int> arr, int num)
// {
//     vector<int> arr2;
//     int size = arr.size();
//     for (int i = 0; i < size - 1; i++)
//     {
//         if (arr[i] > num)
//         {
//             continue;
//         }

//         for (int j = i + 1; j < size; j++)
//         {
//             if (arr[i] + arr[j] == num)
//             {
//                 arr2.push_back(arr[i]);
//             }
//             else if (arr[i] + arr[j] > num)
//             {
//                 break;
//             }
//         }
//     }
//      for (int i = 0; i < arr2.size(); i++)
//     {
//         cout << arr2[i] << " ";
//     }

// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int num = 5;
//     pairSum(arr, num);
//     return 0;
// }

// //__________________
// // Sorting 1 and 0 using two pointers
// vector<int> sortOneZeros(vector<int> arr)
// {
//     int i = 0;
//     int j = arr.size() - 1;
//     while (i < j)
//     {
//         if (arr[i] == 1 && arr[j] == 0)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else if (arr[i] == 0 && arr[j] == 0)
//         {
//             i++;
//         }
//         else if (arr[i] == 1 && arr[j] == 1)
//         {
//             j--;
//         }
//         else
//         {
//             i++;
//             j--;
//         }
//     }
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return arr;
// }
// int main()
// {
//     vector<int> arr = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
//     sortOneZeros(arr);
//     return 0;
// }

//__________________
// Sorting 2, 1 and 0 using three pointers
void sortColors(vector<int> &nums)
{
    int countZero = 0, countOne = 0, countTwo = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            countZero++;
        }
        else if (nums[i] == 1)
        {
            countOne++;
        }
        else if (nums[i] == 2)
        {
            countTwo++;
        }
    }
    std::vector<int> vec;

    // Initialize first 3 elements to 1
    vec.insert(vec.end(), countZero, 0);

    // Initialize next 5 elements to 2
    vec.insert(vec.end(), countOne, 1);

    // Initialize next 6 elements to 7
    vec.insert(vec.end(), countTwo, 2);

    // Print the vector
    for (int i : vec)
    {
        std::cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {1, 0, 0, 2, 2, 1, 0, 1, 0, 1};
    sortColors(arr);
    return 0;
}
