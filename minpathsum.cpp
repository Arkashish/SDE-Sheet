#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> dp)
{
    if (i >= m || j >= n)
        return INT_MAX;
    if (i == m - 1 && j == n - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = 0, right = 0;
    if (i < m)
        left = solve(grid, i + 1, j, m, n, dp);
    if (j < n)
        right = solve(grid, i, j + 1, m, n, dp);

    return dp[i][j] = grid[i][j] + min(left, right);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int left = 0, right = 0;
            if (i > 0)
                left = dp[i - 1][j];
            else
                left = INT_MAX;
            if (j > 0)
                right = dp[i][j - 1];
            else
                right = INT_MAX;
            dp[i][j] = grid[i][j] + min(left, right);
        }
    }
    return dp[m - 1][n - 1];
}
