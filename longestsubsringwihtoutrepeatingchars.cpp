#include <bits/stdc++.h>
using namespace std;
int uniqueSubstrings(string input)
{
    // Write your code here
    vector<int> mp(256, -1);
    int right = 0, left = 0;
    int n = input.size();
    int len = 0;
    while (right < n)
    {
        if (mp[input[right]] != -1)
        {
            left = max(left, mp[input[right]] + 1);
        }
        mp[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}