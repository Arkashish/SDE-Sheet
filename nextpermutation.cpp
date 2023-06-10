#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &permu, int n)
{
    //  Write your code here.
    if (n == 1)
        return permu;
    if (n == 1)
        return permu;
    int i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (permu[i] < permu[i + 1])
            break;
    }
    if (i < 0)
    {
        reverse(permu.begin(), permu.end());
    }
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (permu[j] > permu[i])
                break;
        }
        swap(permu[i], permu[j]);
        reverse(permu.begin() + i + 1, permu.end());
    }
    return permu;
}