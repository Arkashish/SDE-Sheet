#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.

    if (n == 0 || n == 1)
        return n;

    int i = 0, j = i + 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i + 1;
}