#include <bits/stdc++.h>
using namespace std;
void subset(vector<int> &num, vector<int> &ans, int sum, int idx)
{
    if (idx == num.size())
    {
        ans.push_back(sum);
        return;
    }
    subset(num, ans, sum, idx + 1);
    subset(num, ans, sum + num[idx], idx + 1);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    subset(num, ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}