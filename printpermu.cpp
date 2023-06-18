#include <bits/stdc++.h>
using namespace std;
void permu(int idx, string &a, vector<string> &ans)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permu(idx + 1, a, ans);
        swap(a[i], a[idx]);
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> ans;
    permu(0, s, ans);
    return ans;
}