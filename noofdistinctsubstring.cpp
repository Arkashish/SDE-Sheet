#include <bits/stdc++.h>
using namespace std;
int distinctSubstring(string &word)
{
    //  Write your code here.
    unordered_map<string, int> mp;
    for (int i = 0; i < word.length(); i++)
    {
        for (int j = i; j < word.length(); j++)
        {
            mp[word.substr(i, j - i + 1)]++;
        }
    }

    return mp.size();
}
