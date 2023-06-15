#include <bits/stdc++.h>
using namespace std;
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] > lmax)
                lmax = arr[l];
            else
                res += (lmax - arr[l]);
            l++;
        }
        else
        {
            if (arr[r] > rmax)
                rmax = arr[r];
            else
                res += (rmax - arr[r]);
            r--;
        }
    }
    return res;
}