#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pwset(vector<int> v)
{
    // Write your code here
    vector<vector<int>> ans;
    int n = v.size();
    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> str;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                str.push_back(v[i]);
        }
        if (str.size() > 0)
            ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    return ans;
}