#include <bits/stdc++.h>
using namespace std;
string kthPermutation(int n, int k)
{
    // Write your code here.
    int fact = 1;
    string ans = "";
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        num.push_back(i);
        fact *= i;
    }
    num.push_back(n);
    k--;
    while (true)
    {
        ans += to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);
        if (!num.size())
            break;
        k = k % fact;
        fact = fact / num.size();
    }
    return ans;
}
