#include <iostream>
using namespace std;

void update(int *ptr)
{
     *ptr = *ptr + 1;
}
void print(int *arr, int n) // I can pass arr[] or *arr
{
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
}
int main()
{
     // int arr[6] = {0, 5, 6, 6};
     // cout << "arr " << arr << endl
     //      << "&arr " << &arr << endl
     //      << "&arr[0]" << &arr[0] << endl;

     // arr==&arr
     //  Surprisingly arr[i]==i[arr] You know why?
     //  Because arr[i] means *(arr+i) so it is equal to *(i+arr)
     //  Hence arr[i]==i[arr]
     // int i = 2;
     // cout << arr[i] << " " << i[arr] << endl;

     // Difference between arr and Real Pointer
     // 1: arr can't be changed
     // 2: sizeOf() works differently in case of arr => Returns size of array 24

     //_____________________________________________________________________
     //_______________Difference_in_case_of_Characters_Array________________
     //_____________________________________________________________________
     // char ch[10] = "abasldfjd"; // Size Needs to be 1 more than actual array size due to null ch at the end
     // // cout fiunction is implemented differently in case of char array
     // cout << ch << endl; // prints whole array but in case of int it printed address of first element
     // char *c = &ch[0];
     // cout << c << endl; // Also prints entire array
     // char c2 = 'a';
     // char *cp2 = &c2;
     // cout << cp2 << endl;  // Starts Printing from address until finds a null character
     // cout << *cp2 << endl; // Prints actual Value
     //
     // // What happens in Memory
     // char ch2[12] = "asasd32fasd"; // A temporary memory stores "asasd32fasd" then copied to allocated memory
     // char *p1 = "asdasdf";         // A temporary memory stores "asdasdf" and address of first ch 'a' from that temp memory is stored in pointer
     // // This is totally not recommended
     //
     // // Functions
     // int val = 1;
     // update(&val);
     // cout << val; // Updated using another function passed by reference

     // Function of array
     int pArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Below is benefit of passing address of arr
     print(pArr + 2, 10);                            // As in first argument only address is passed I can pass address of sub array means next elements
}