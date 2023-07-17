#include <bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<pair<float, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({float(float(price[i]) / float((i + 1))), {price[i], i + 1}});
    }
    sort(v.begin(), v.end());
    int res = 0;
    int temp = n - 1;
    while (n != 0)
    {
        if (v[temp].second.second > n)
        {
            while (v[temp].second.second > n && temp > -1)
                temp--;
        }
        res += v[temp].second.first;
        n -= v[temp].second.second;
    }
    return res;
}
