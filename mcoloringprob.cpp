#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &mat, vector<int> &col, int currentindex, int currentcol, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != currentindex && mat[i][currentindex] == 1 && col[i] == currentcol)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &mat, vector<int> &col, int currentindex, int m, int n)
{
    if (currentindex == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(mat, col, currentindex, i, n))
        {
            col[currentindex] = i;
            if (solve(mat, col, currentindex + 1, m, n))
                return true;
            col[currentindex] = -1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> col(n, -1);
    if (solve(mat, col, 0, m, n))
        return "YES";
    return "NO";
}