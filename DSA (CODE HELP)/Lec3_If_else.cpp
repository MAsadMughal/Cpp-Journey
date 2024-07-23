#include <iostream>
using namespace std;

// ______________ IF__ELSE and Loops _____________________

// int main()
// {
//     int a = 2;
//     if ((a = 3) == 3)
//     {
//         cout << a;
//     }
//     else
//     {
//         cout << a + 1;
//     }
//     cout << a << endl;
//     return 0;
// }

// ASCII CHECK
// int main()
// {
//     char ch;
//     ch = cin.get();
//     int intch = ch;
//     if (intch >= 97 && intch <= 122)
//     {
//         cout << "LOWERCASE" << endl;
//     }
//     else if (intch >= 65 && intch <= 90)
//     {
//         cout << "UPPERCASE" << endl;
//     }
//     else if (intch >= 48 && intch <= 57)
//     {
//         cout << "NUMERIC" << endl;
//     }
//     return 0;
// }

// SUM OF EVEN NUMBERS
// int main()
// {
//     int n;
//     cin >> n;
//     int sum = 0;
//     int i = 0;
//     while (i <= n)
//     {
//         if (i % 2 == 0)
//         {
//             sum += i;
//             cout << sum << endl;
//         }
//         i++;
//     }
//     return 0;
// }

// F TO C SCALE
// int main()
// {
//     double farenhiet;
//     cin >> farenhiet;
//     cout << farenhiet << " Farenhiet in Celcius is " << (farenhiet - 32) / 1.8 << endl;
//     return 0;
// }

// Prime Number using While Loop
// int main()
// {
//     int primeOrNot;
//     cin >> primeOrNot;
//     int i = 2;
//     bool prime = true;
//     if (primeOrNot == 1)
//     {
//         prime = false;
//     }
//     else
//     {
//         while (i < primeOrNot)
//         {
//             if (primeOrNot % i == 0)
//             {
//                 prime = false;
//                 break;
//             }
//             i++;
//         }
//     }
//     if (prime)
//     {
//         cout << "Number is Prime";
//     }
//     else
//         cout << "Number is not Prime";
//     {
//     }

//     return 0;
// }

// Printing Pattern 
int main()
{
    int order;
    cin >> order;
    int i = 0;
    while (i < order)
    {
        int j = 0;
        while (j < order)
        {
            cout << i + 1 << '\t';
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}