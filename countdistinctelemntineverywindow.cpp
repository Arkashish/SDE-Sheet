#include <bits/stdc++.h>
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (i + 1 == k)
        {
            ans.push_back(mp.size());
        }
        if (i >= k)
        {
            mp[arr[i - k]]--;
            if (mp[arr[i - k]] == 0)
                mp.erase(arr[i - k]);
            ans.push_back(mp.size());
        }
    }
    return ans;
}
