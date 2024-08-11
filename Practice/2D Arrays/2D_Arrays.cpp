#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int row = mat.size();
    int col = mat[0].size();

    // Check if reshape operation is possible
    if (row * col != r * c)
    {
        return mat;
    }

    vector<vector<int>> arr(r, vector<int>(c));
    int rC = 0, cC = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[rC][cC] = mat[i][j];
            cC++;
            if (cC == c)
            {
                cC = 0;
                rC++;
            }
        }
    }
    return arr;
}
int fact(int num)
{
    if (num == 0 || num == 1)
    {

        return 1;
    }
    return num * fact(num - 1);
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12}};
    int r = 6;
    int c = 2;
    vector<vector<int>> arr2 = matrixReshape(arr, r, c);
}