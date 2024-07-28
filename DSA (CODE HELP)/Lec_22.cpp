#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Leetcode Problems
// char toLowerCase(char ch)
// {
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         return ch - 'A' + 'a'; // Convert to lowercase
//     }
//     return ch;
// }
// bool isAlphanumeric(char ch)
// {
//     return ((ch >= 'A' && ch <= 'Z') || // Check if uppercase letter
//             (ch >= 'a' && ch <= 'z') || // Check if lowercase letter
//             (ch >= '0' && ch <= '9'));  // Check if digit
// }
// bool isAlphabet(char ch)
// {
//     return ((ch >= 'A' && ch <= 'Z') || // Check if uppercase letter
//             (ch >= 'a' && ch <= 'z'));
// }

// bool isPalindrome(const string &s)
// {
//     string str2;
//     if (s.length() <= 1)
//     {
//         return true;
//     }
//     for (char ch : s)
//     {
//         if (isAlphanumeric(ch))
//         {
//             if (isAlphabet(ch))
//             {
//                 str2 += toLowerCase(ch); // Convert to lowercase and append
//             }
//             else
//             {
//                 str2 += ch; // Append digit as is
//             }
//         }
//     }

//     int st = 0;
//     int en = str2.length() - 1;
//     while (st <= en)
//     {

//         if (str2[st++] != str2[en--])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     string str = "A man, a plan, a canal: Panama";
//     cout << isPalindrome(str);
// }

//_____________________
// Remove All Occurences of string
string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
//_________________
// check permutations
bool sameArr(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkPermutation(string str1, string str2)
{
    str1 = "abd";
    str2 = "adasdba";
    int arr1[26] = {0};
    int arr2[26] = {0};
    int size1 = str1.length();
    int size2 = str2.length();
    if (size2 < size1)
    {
        return false;
    }
    for (int i = 0; i < size1; i++)
    {
        arr1[str1[i] - 'a'] += 1;
    }

    for (int i = 0; i < size2; i++)
    {
        arr2[str2[i] - 'a']++;

        if (i >= size1)
        {
            arr2[str2[i - size1] - 'a']--;
        }

        // Check if the current window matches arr1
        if (i >= size1 - 1 && sameArr(arr1, arr2))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cout << checkPermutation("", "");
}
