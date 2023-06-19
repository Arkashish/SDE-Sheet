#include <bits/stdc++.h>
using namespace std;
void subsets(int idx, int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    for (int i = idx; i < n; i++)
    {
        if (i == idx or arr[i] != arr[i - 1])
        {
            ds.push_back(arr[i]);
            subsets(i + 1, n, arr, ans, ds);
            ds.pop_back();
        }
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    subsets(0, n, arr, ans, ds);
    return ans;
}