#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void permutation(string &s, int currInd, vector<string> &ans)
{
     if (currInd >= s.length() - 1)
     {
          ans.push_back(s);
          cout << s << endl;
          return;
     }
     for (int j = currInd; j < s.length(); j++)
     {
          swap(s[currInd], s[j]);
          permutation(s, currInd + 1, ans);
          swap(s[currInd], s[j]);
     }
}
void NumsPermutation(vector<int> nums, int currInd, vector<vector<int>> &ans)
{
     if (currInd >= nums.size())
     {
          ans.push_back(nums);
          return;
     }
     for (int j = currInd; j < nums.size(); j++)
     {
          swap(nums[currInd], nums[j]);
          NumsPermutation(nums, currInd + 1, ans);
          swap(nums[currInd], nums[j]);
     }
}
int main()
{
     vector<int> question = {};
     vector<vector<int>> ans;
     NumsPermutation(question, 0, ans);
     for (int i = 0; i < ans.size(); i++)
     {
          for (int j = 0; j < ans[0].size(); j++)
          {
               cout << ans[i][j];
          }
          cout << endl;
     }
}
