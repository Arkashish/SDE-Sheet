#include <bits/stdc++.h>
using namespace std;
void solve(int i, int sum, int k, vector<int> &num, vector<vector<int>> &ans, vector<int> &v)
{
    if (i == num.size())
    {
        if (sum == k)
            ans.push_back(v);
        return;
    }

    solve(i + 1, sum, k, num, ans, v);
    v.push_back(num[i]);
    solve(i + 1, sum + num[i], k, num, ans, v);
    v.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(0, 0, k, arr, ans, v);
    return ans;
}