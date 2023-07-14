#include <bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int p = 1;
    int maxi = INT_MIN, maxe = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        p *= arr[i];
        maxi = max(maxi, p);
        if (p == 0)
            p = 1;
    }
    p = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        p *= arr[i];
        maxe = max(maxe, p);
        if (p == 0)
            p = 1;
    }
    return max(maxi, maxe);
}
