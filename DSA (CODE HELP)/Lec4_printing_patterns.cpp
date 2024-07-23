#include <iostream>
using namespace std;

// ______________ Printing Patterns _____________________

// // Pattern 1
// // 1 2 3 4
// // 1 2 3 4
// // 1 2 3 4
// // 1 2 3 4
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             cout << j << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

//_____________________________________________

// Pattern 2
// 1 2 3
// 4 5 6
// 7 8 9
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             cout << (j + (i - 1) * number) << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

//_____________________________________________

// Pattern 3
// *
// * *
// * * *
// * * * *
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << "*" << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 4
// // 1
// // 2 2
// // 3 3 3
// // 4 4 4 4
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << i << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 5
// // 1
// // 2 3
// // 4 5 6
// // 7 8 9 10
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     int sum = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << sum << '\t';
//             j++;
//             sum++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 6
// // 1
// // 2 3
// // 3 4 5
// // 4 5 6 7
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << (i - 1) + j << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 7
// // 1
// // 2 1
// // 3 2 1
// // 4 3 2 1
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << (i) - (j-1) << '\t';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 9
// // a a a
// // b b b
// // c c c
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= 3)
//         {
//             char ch = 'A' + i - 1;
//             cout << ch << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 10
// // a b c
// // a b c
// // a b c
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             char ch = 'A' + j - 1;
//             cout << ch << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 11
// // a b c
// // d e f
// // g h i
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     char ch = 'A';
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             cout << ch << ' ';
//             j++;
//             ch = ch + 1;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 12
// // a b c
// // b c d
// // c d e
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     char ch = 'A';
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             char alphabet = ch + i - 1 + (j - 1);
//             cout << alphabet  << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 13
// // a
// // b b
// // c c c
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         char alphabet = 'A' + i - 1;
//         while (j <= i)
//         {
//             cout << alphabet << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 14
// // a
// // b c
// // d e f
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     char alphabet = 'A';
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << alphabet++ << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// //_____________________________________________

// // Pattern 15
// // d
// // c d
// // b c d
// // a b c d
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         char ch = 'A' + number - i;
//         while (j <= i)
//         {
//             cout << ch++ << " ";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 16
// // a b c
// // b c d
// // c d e
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number)
//         {
//             char alphabet = 'A' + i - 1 + (j - 1);
//             cout << alphabet << ' ';
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// _____________________

// // Pattern 17
// //     *
// //   * *
// // * * *
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number - i)
//         {
//             cout << " ";
//             j++;
//         }
//         int count = 0;
//         while (count < i)
//         {
//             cout << "*";
//             count++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// Pattern 18
// * * *
// * *
// *
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number - (i - 1))
//         {
//             cout << "*";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 19
// // * * *
// //   * *
// //     *
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int count = 1;
//         while (count < i)
//         {
//             cout << " ";
//             count++;
//         }
//         int j = 1;
//         while (j <= number - i + 1)
//         {
//             j++;
//             cout << "*";
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 20
// // 1 1 1
// //   2 2
// //     3
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int count = 1;
//         while (count < i)
//         {
//             cout << " ";
//             count++;
//         }
//         int j = 1;
//         while (j <= number - i + 1)
//         {
//             j++;
//             cout << i;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 21
// //      1
// //    2 2
// //  3 3 3
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number - i + 1)
//         {
//             j++;
//             cout << " ";
//         }
//         int count = 1;
//         while (count <= i)
//         {
//             cout << i;
//             count++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 22
// // 1 1 1
// //   2 2
// //     3
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int count = 1;
//         while (count < i)
//         {
//             cout << " ";
//             count++;
//         }
//         int j = 1;
//         while (j <= number - i + 1)
//         {
//             j++;
//             cout << i;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 23
// //     1
// //   1 2 1
// // 1 2 3 2 1
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         while (j <= number - i + 1)
//         {
//             j++;
//             cout << " ";
//         }
//         int count = 1;
//         while (count <= i)
//         {
//             cout << count;
//             count++;
//         }
//         int count2 = 1;
//         while (count2 < i)
//         {
//             cout << i - count2;
//             count2++;
//         }
//         cout << endl;
//         i++;
//     }
//     return 0;
// }

// // _____________________

// // Pattern 23
// // 1 2 3 4 5 5 4 3 2 1
// // 1 2 3 4 * * 4 3 2 1
// // 1 2 3 * * * * 3 2 1
// // 1 2 * * * * * * 2 1
// // 1 * * * * * * * * 1
// int main()
// {
//     int number;
//     cin >> number;
//     int i = 1;
//     while (i <= number)
//     {
//         int j = 1;
//         int k = number;
//         while (j <= number)
//         {
//             if (j > number - i + 1)
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << j;
//             }
//             j++;
//         }
//         while (k)
//         {
//             if (k > number - i+1)
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << k;
//             }
//             k--;
//         }

//         cout << endl;
//         i++;
//     }
//     return 0;
// }
