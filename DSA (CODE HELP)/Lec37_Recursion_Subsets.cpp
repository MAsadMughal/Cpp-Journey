#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int start)
{
     int size = nums.size();
     if (start >= size)
     {
          ans.push_back(output);
          return;
     }
     solve(nums, output, ans, start + 1);
     output.push_back(nums[start]);
     solve(nums, output, ans, start + 1);
}

void subSequence()
{
     string str = "abc";
     int size = str.length();

     for (int i = 0; i < (1 << str.length()); i++)
     {
          cout << "{";
          for (int j = 0; j < size; j++)
          {
               if (i & (1 << j)) // checks if jth bit in i is true
               {
                    cout << str[j];
               }
          }
          cout << "}";
          cout << endl;
     }
}

int main()
{
    subSequence();
}
