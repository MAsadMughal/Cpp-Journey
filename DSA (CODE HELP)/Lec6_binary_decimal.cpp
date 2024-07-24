#include <iostream>
#include <math.h>
using namespace std;

// //_________________________________
// // Decimal to Binary Conversions
// int main()
// {
//     int number;
//     cin >> number;
//     int answer = 0;
//     int i = 0;
//     while (number != 0)
//     {
//         int lastbit = number & 1;
//         answer = (lastbit * pow(10, i)) + answer;
//         number = number >> 1;
//         i++;
//     }

//     cout << endl;
//     cout << answer;
// }

// //_________________________________
// // Decimal to Binary Conversion for -ve (Pending)
// int main()
// {
//     unsigned int number;
//     cin >> number;
//     unsigned int answer = 0;
//     int i = 0;
//     number=number<<1;
//     // number=number>>1;
//     cout<<number;

//     while (number != 0)
//     {
//         int lastbit = number & 1;
//         // cout<<lastbit;
//         answer = (lastbit * pow(10, i)) + answer;
//         number = number >> 1;
//         i++;
//     }

//     cout << endl;
//     cout << answer;
// }

//_________________________________
//  Binary to Decimal Conversion
int main()
{
    int number;
    cin >> number;
    int i = 0;
    int answer = 0;
    while (number != 0)
    {
        int lastbit = number & 1;
        if (lastbit)
        {
            answer += pow(2, i);
        }
        i++;
        number = number / 10;
    }

    cout << answer << endl;
}
