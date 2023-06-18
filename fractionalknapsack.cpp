#include <bits/stdc++.h>
using namespace std;
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return ((double)a.second / a.first) > ((double)b.second / b.first); });

    double maxprofit = 0;
    int currweight = 0;
    for (auto p : items)
    {
        if (p.first + currweight <= w)
        {
            currweight += p.first;
            maxprofit += p.second;
        }
        else
        {
            maxprofit += double((double)p.second * (w - currweight)) / p.first;
            break;
        }
    }
    return maxprofit;
}