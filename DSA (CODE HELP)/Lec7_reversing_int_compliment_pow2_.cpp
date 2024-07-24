#include <iostream>
#include <math.h>
using namespace std;

// //_________________________________
// // Reversing Integer
// int main()
// {
//     int number;
//     cin >> number;
//     int answer = 0;
//     while (number != 0)
//     {

//         int digit = number % 10;
//         if (answer > INT_MAX / 10 || answer < INT_MIN / 10)
//         {
//             return 0;
//         }
//         answer = (answer * 10) + digit;
//         number = number / 10;
//     }
//     cout << answer;
// }

// //_________________________________
// // Complement
// int main()
// {

//     int number;
//     cin >> number;
//     int binary = 0;
//     int i = 0;
//     if (number == 0)
//     {
//         cout << 1;
//         return 0;
//     }
//     while (number != 0)
//     {
//         int digit = number & 1;
//         digit = !digit;
//         binary = ((digit)*pow(10, i)) + binary;
//         number = number >> 1;
//         i++;
//     }
//     int answer = 0;
//     i = 0;
//     while (binary != 0)
//     {
//         int digit = binary & 1;

//         if (digit)
//         {
//             answer += (pow(2, i));
//         }
//         binary = binary / 10;
//         i++;
//     }
//     cout << answer;
// }

// //_________________________________
// // Optimized solution for compliment
// int main()
// {
//     int n;
//     cin >> n;
//     int m = n;
//     int mask = 0;

//     if (n == 0)
//     {
//         cout << 1;
//         return 0;
//     }
//     // Create a mask with all bits set to 1 up to the most significant bit of n
//     while (m != 0)
//     {
//         mask = (mask << 1) | 1;
//         m = m >> 1;
//     }

//     // Calculate the complement of n using the mask
//     int ans = (~n) & mask;
//     cout << ans;
//     return 0;
// }

//_________________________________
// Check if Power of 2
int main()
{
    int n;
    cin >> n;
    int curr = 2;
    while (curr < n)
    {
        curr *= 2;
    }
    if (curr == n)
    {
        cout << "power of 2";
    }
    else
    {
        cout << "not power of 2";
    }
    return 0;
}