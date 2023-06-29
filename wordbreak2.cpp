#include <bits/stdc++.h>
using namespace std;
void generate(string &s, string &t, unordered_map<string, bool> &mp, int idx, vector<string> &ans)
{
    if (idx == s.length())
    {
        ans.push_back(t);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (mp[s.substr(idx, i - idx + 1)])
        {
            t.append(s.substr(idx, i - idx + 1));
            t.push_back(' ');
            generate(s, t, mp, i + 1, ans);
            int sz = t.length();
            t = t.substr(0, sz - (i - idx + 2));
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string, bool> mp;
    for (auto it : dictionary)
        mp[it] = true;
    vector<string> ans;
    string t;
    generate(s, t, mp, 0, ans);
    return ans;
}