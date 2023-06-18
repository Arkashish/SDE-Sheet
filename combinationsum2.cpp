#include <bits/stdc++.h>
using namespace std;
void fun(int idx, vector<int> &arr, int n, int target, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx and arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            return;
        temp.push_back(arr[i]);
        fun(i + 1, arr, n, target - arr[i], ans, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    fun(0, arr, n, target, ans, temp);
    return ans;
}
