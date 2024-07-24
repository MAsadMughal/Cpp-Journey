#include <iostream>
using namespace std;

// //_________________________________
// // Calculator
// // Cannot use continue and break to terminate loop inside switch=>use exit(1) to exit function
// int main()
// {
//     int num1;
//     int num2;
//     char op;
//     cin >> num1;
//     cin >> num2;
//     cin >> op;

//     switch (op)
//     {
//     case '+':
//         cout << num1 + num2;
//         break;
//     case '-':
//         cout << num1 - num2;
//         break;
//     case '*':
//         cout << num1 * num2;
//         break;
//     case '/':
//         cout << num1 / num2;
//         break;
//     case '%':
//         cout << num1 % num2;
//         break;

//     default:
//         cout << "Invalid operator.";
//         break;
//     }
// }

// //_________________________________
// // Money Notes using switch
// int main()
// {
//     int money;
//     int fth = 0, thousand = 0, fhun = 0, hund = 0, fifty = 0, twenty = 0, ten = 0;
//     cin >> money;
//     switch (money >= 5000)
//     {
//     case 1:
//         fth = money / 5000;
//         money = money - (fth * 5000);
//         break;
//     }

//     switch (money >= 1000)
//     {
//     case 1:
//         thousand = money / 1000;
//         money = money - (thousand * 1000);
//         break;
//     }

//     switch (money >= 500)
//     {
//     case 1:
//         fhun = money / 500;
//         money = money - (fhun * 500);
//         break;
//     }

//     switch (money >= 100)
//     {
//     case 1:
//         hund = money / 100;
//         money = money - (hund * 100);
//         break;
//     }

//     switch (money >= 50)
//     {
//     case 1:
//         fifty = money / 50;
//         money = money - (fifty * 50);
//         break;
//     }

//     switch (money >= 20)
//     {
//     case 1:
//         twenty = money / 20;
//         money = money - (twenty * 20);
//         break;
//     }
//     switch (money >= 10)
//     {
//     case 1:
//         ten = money / 10;
//         money = money - (ten * 10);
//         break;
//     }

//     cout << fth << " notes of 5 thousand, " << thousand << " notes of 1 thousand, " << fhun << " notes of 5 hundred, " << endl;
//     cout << hund << " notes of 1 hundred, " << fifty << " notes of fifty, " << twenty << " notes of twenty, " << ten << " notes of ten, " << money << " extra coins of one each." << endl;
// }

// //_________________________________
// // ___Functions____

// // Factorial Function
// int factorial(int num)
// {
//     if (num == 0)
//     {
//         return 1;
//     }
//     int ans = num;
//     while (num > 2)
//     {
//         ans = ans * (--num);
//     }
//     return ans;
// }

// // Combination nCr n!/r! *(n-r)!*
// int Combination(int n, int r)
// {
//     return (factorial(n)) / (factorial(r) * (factorial(n - r)));
// }

// int main()
// {
//     int num1, num2;
//     cin >> num1 >> num2;
//     cout << Combination(num1, num2);
// }

// //________________
// // 1 bits counter
// int bitsCounter(int num)
// {
//     int bits = 0;
//     while (num != 0)
//     {
//         int bit = num & 1;
//         if (bit)
//         {
//             bits++;
//         }
//         num = num >> 1;
//     }
//     return bits;
// }

// int main()
// {
//     int num1, num2;
//     cin >> num1 >> num2;
//     cout << bitsCounter(num1) + bitsCounter(num2);
// }

// //________________
// // Nth number of Fibonacci Series
// // These functions are passing value by pass by value so new copy is created..

// int nthFibonacci(int num)
// {
//     int a = 0;
//     int b = 1;
//     int sum = 0;
//     for (int i = 0; i < num - 2; i++)
//     {
//         sum = a + b;
//         a = b;
//         b = sum;
//     }
//     return sum;
// }

// int main()
// {
//     nthFibonacii(10);
// }


//________________
// Nth number of Fibonacci Series
// These functions are passing value by pass by value so new copy is created..

int nthFibonacci(int num)
{
    int a = 0;
    int b = 1;
    int sum = 0;
    for (int i = 0; i < num - 2; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main()
{
    nthFibonacci(10);
}



