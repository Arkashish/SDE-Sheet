#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int lo = 0, hi = (m * n - 1);
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (mat[mid / m][mid % m] == target)
            return true;
        else if (mat[mid / m][mid % m] > target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}