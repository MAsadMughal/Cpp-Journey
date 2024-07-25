#include <iostream>
using namespace std;
// binary search
int main()
{
    const int size = 6;
    int arr[size] = {3, 7, 9, 11, 13, 19};
    int mid = size / 2;
    // if we do start+(end-start)/2 we can escape out of bound int problem instead of using (start+end)/2
    int key = 7;
    while (true)
    {
        if (arr[mid] == key)
        {
            cout << mid;
            break;
        }
        else if (key > arr[mid] && mid != size - 1)
        {
            mid = ((mid + 1) + (size - 1)) / 2;
        }
        else if (key < arr[mid] && mid != 0)
        {
            mid = (mid - 1) / 2;
        }
        else
        {
            cout << "not found";
            break;
        }
    }
}