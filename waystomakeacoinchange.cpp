#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int t = 0; t <= value; t++)
    {
        dp[0][t] = (t % denominations[0] == 0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= value; t++)
        {
            long not_take = dp[i - 1][t];
            long take = 0;
            if (denominations[i] <= t)
                take = dp[i][t - denominations[i]];
            dp[i][t] = take + not_take;
        }
    }
    return dp[n - 1][value];
}