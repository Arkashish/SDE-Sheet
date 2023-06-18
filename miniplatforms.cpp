#include <bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int start[], int end[], int n)
{
    // Write your code here.
    sort(start, start + n);
    sort(end, end + n);

    int i = 0, j = 0, platform = 0;
    int maxiplat = 0;
    while (i < n and j < n)
    {
        if (start[i] <= end[j])
        {
            i++;
            platform++;
        }
        else
        {
            j++;
            platform--;
        }
        maxiplat = max(maxiplat, platform);
    }
    return maxiplat;
}