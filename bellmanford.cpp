#include <bits/stdc++.h>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    int maxi = 1e9;
    vector<int> dist(n + 1, maxi);
    dist[src] = 0;
    for (int t = 1; t < n; t++)
    {
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            if (dist[edges[i][0]] != maxi && dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2])
            {
                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
                flag = false;
            }
        }
        if (flag)
            return dist[dest];
    }
    // Step 2: Iterate one more time
    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        if (dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2])
        {
            dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            flag = false;
        }
    }
    // Negitive Cycle Detected
    if (!flag)
        return INT_MIN;
    return dist[dest];
}