#include <iostream>
using namespace std;

// Bitwise Operators
// Gate   Symbol     True Condition
// AND      &        both are 1
// OR       |        At least 1, 1
// NOT      ~        Inverted bit
// XOR      ^        One 1
// // _________________________________
// // AND OR AND XOR Operator
// int main()
// {
//     int num1;
//     int num2;
//     cin >> num1 >> num2;
//     // Convert num1 and num2 to binary and then solve them.
//     cout << (num1 & num2) << endl; // small number
//     cout << (num1 | num2) << endl; // large number
//     cout << (num1 ^ num2) << endl; // after solution
// }

// //___________________________________
// // NOT Operator
// int main()
// {
//     int num;
//     cin >> num;
//     cout << ~num; // usually num + 1 with -ve sign
//     // How does this happen
//     // for example for 100;
//     // 1111111111...111011 // reversed bits
//     // when printed
//     // it takes first bit as 1 and prints negative sign
//     // for remaining it takes 2's compliment
//     // by reversing all bits and adding 1
//     // 100+1=>000000000...0000101
//     // Hence NOT operator works
// }

// //_________________________________
// // Left and Right Shift
// int main()
// {
//     int num1;
//     int num2;
//     cin >> num1 >> num2;
//     // for 5>>2  => 000000..00101 when right shift two times two zeros are added at start removing last two digits.
//     // for 5<<2  => 000000..00101 when left shift two times two zeros are added at end removing first two digits.
//     // Right shift results in dividing number by 2 shift times. 5>>2  (5/2)/2=1
//     // Left shift results in multiplying number by 2 shift times. 5<<2 5*2*2=20
//     cout << "Right Shift " << (num1 >> num2) << endl; // small number
//     cout << "Left Shift " << (num1 << num2) << endl;  // large number
// }

// //_________________________________
// // For Loop with multiple conditions
// int main()
// {
//     for (int i = 0, j = 0, k = 0; i < 5 || j < 10 || k < 15;)
//     {
//         cout << i << " " << j << " " << k << endl;
//         i < 5 && i++;
//         j < 10 && j++;
//         k < 15 && k++;
//     }
// // Loop works like this => initialization=>check condition=>execute=>increment=>check condition=>execute=> check condition=>end
// }

//_________________________________
// Fibonacci series
int main()
{
    int a = 0;
    int b = 1;
    int number;
    cin >> number;
    cout << a << " ";
    cout << b << " ";
    for (int i = 1; i <= number-2; i++)
    {
        int sum = a + b;
        cout << sum << " ";
        a = b;
        b = sum;
    }
}

// // _____________________________
// int main()
// {
//     int number;
//     cin >> number;
//     int sum = 0;
//     int pro = 1;
//     while (number != 0)
//     {
//         sum += number % 10;
//         pro *= number % 10;
//         number = number / 10;
//     }
//     cout << pro - sum << endl;
//     return 0;
// }