#include <bits/stdc++.h>
using namespace std;
int cntsmaller(vector<int> &row, int mid)
{
    int lo = 0, hi = row.size() - 1;
    while (lo <= hi)
    {
        int md = lo + (hi - lo) / 2;
        if (row[md] <= mid)
        {
            lo = md + 1;
        }
        else
        {
            hi = md - 1;
        }
    }
    return lo;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += cntsmaller(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}