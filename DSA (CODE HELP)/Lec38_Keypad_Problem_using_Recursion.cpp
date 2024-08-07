#include <iostream>
#include <string>
#include <vector>
using namespace std;

void problem(string question, vector<string> mapping, string output, vector<string> &ans, int ind)
{
     if (ind >= question.length())
     {
          // cout << output << endl;
          ans.push_back(output);
          return;
     }
     int num = question[ind] - '0';
     string curr = mapping[num];
     int len = curr.length();
     for (int i = 0; i < len; i++)
     {
          output = output + curr[i];
          problem(question, mapping, output, ans, ind + 1);
          output.pop_back();
     }
}
int main()
{
     string question = "23";
     vector<string> mapping = {
         "",
         "",
         "abc",
         "def",
         "ghi",
         "jkl",
         "mno",
         "pqrs",
         "tuv",
         "wxyz",
     };
     string output;
     vector<string> ans;
     int ind = 0;
     problem(question, mapping, output, ans, ind);
     for (int i = 0; i < ans.size(); i++)
     {
          cout << ans[i] << endl;
     }
}
