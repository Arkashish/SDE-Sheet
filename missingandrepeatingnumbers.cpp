#include <bits/stdc++.h>
using namespace std;
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    // int *res = new int[2];
    pair<int, int> ans;
    int xor1 = arr[0];
    for (int i = 1; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }
    int setbitno = (xor1) & (~(xor1 - 1));
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setbitno)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & setbitno)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }
    int xcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            xcount++;
    }
    if (xcount == 0)
    {
        ans.first = x;
        ans.second = y;
    }
    else
    {
        ans.first = y;
        ans.second = x;
    }
    return ans;
}
