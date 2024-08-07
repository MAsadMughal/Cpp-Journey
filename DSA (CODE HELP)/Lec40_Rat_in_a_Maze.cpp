#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> maze, int x, int y, vector<vector<int>> &visited)
{
     int size = maze.size();
     if (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1 && visited[x][y] == 0)
     {
          return true;
     }
     return false;
}
void ratInMaze(vector<vector<int>> maze, int x, int y, vector<vector<int>> &visited, string currAns, vector<string> &ans)
{
     int size = maze.size();
     if (x == size - 1 && y == size - 1)
     {
          ans.push_back(currAns);
          return;
     }
     visited[x][y] = 1;
     // down
     if (isSafe(maze, x + 1, y, visited))
     {
          currAns.push_back('D');
          ratInMaze(maze, x + 1, y, visited, currAns, ans);
          currAns.pop_back();
     }
     // right
     if (isSafe(maze, x, y + 1, visited))
     {
          currAns.push_back('R');
          ratInMaze(maze, x, y + 1, visited, currAns, ans);
          currAns.pop_back();
     }
     // left
     if (isSafe(maze, x, y - 1, visited))
     {
          currAns.push_back('L');
          ratInMaze(maze, x, y - 1, visited, currAns, ans);
          currAns.pop_back();
     }
     // up
     if (isSafe(maze, x - 1, y, visited))
     {
          currAns.push_back('U');
          ratInMaze(maze, x - 1, y, visited, currAns, ans);
          currAns.pop_back();
     }
     visited[x][y] = 0;
}
int main()
{
     vector<vector<int>> maze = {{1, 0, 0},
                                 {1, 1, 1},
                                 {1, 0, 1}};
     int size = maze.size();
     vector<vector<int>> visited(size, vector<int>(size, 0));
     vector<string> ans;
     string curr = "";
     if (maze[0][0] == 0)
     {
          return;
     }
     ratInMaze(maze, 0, 0, visited, curr, ans);
     for (int i = 0; i < ans.size(); i++)
     {
          cout << ans[i] << endl;
     }
}
