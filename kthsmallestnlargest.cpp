#include <bits/stdc++.h>
using namespace std;
// Approach 1
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int maxi = arr[k - 1];
    int mini = arr[n - k];
    return {maxi, mini};
}
// Approach 2
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
        maxheap.push(arr[i]);
    }
    while (minheap.size() > k)
    {
        minheap.pop();
    }
    while (maxheap.size() > k)
    {
        maxheap.pop();
    }
    return {maxheap.top(), minheap.top()};
}