#include <bits/stdc++.h>
using namespace std;
int fun(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return 1 + fun(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(fun(i - 1, j, s1, s2, dp), fun(i, j - 1, s1, s2, dp));
}
int lcs(string s, string t)
{
    // Write your code here
    int x = s.size();
    int y = t.size();
    vector<vector<int>> dp(x, vector<int>(y, -1));
    return fun(x - 1, y - 1, s, t, dp);
}