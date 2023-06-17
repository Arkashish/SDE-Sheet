#include <bits/stdc++.h>
using namespace std;
bool isvalid(int matrix[9][9], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (matrix[row][i] == c or matrix[i][col] == c)
            return false;
        if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9])
{
    // Write your code here.
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isvalid(matrix, i, j, k))
                    {
                        matrix[i][j] = k;
                        if (isItSudoku(matrix) == true)
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
