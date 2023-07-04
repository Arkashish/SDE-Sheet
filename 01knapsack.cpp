#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{

    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = weights[0]; i <= w; i++)
        prev[i] = values[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = prev[j];
            int take = -1e9;
            if (weights[i] <= j)
                take = values[i] + prev[j - weights[i]];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
}