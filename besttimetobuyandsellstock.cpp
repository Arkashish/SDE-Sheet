#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int mini = INT_MAX, pro = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < mini)
        {
            mini = prices[i];
        }
        else if ((prices[i] - mini) >= pro)
        {
            pro = prices[i] - mini;
        }
    }
    return pro;
}