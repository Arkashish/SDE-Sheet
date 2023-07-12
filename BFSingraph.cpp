#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<set<int>> adj(vertex);
    for (auto e : edges)
    {
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }
    vector<int> res;
    vector<bool> vis(vertex, false);
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                if (vis[curr])
                    continue;
                vis[curr] = true;
                res.push_back(curr);
                for (auto it : adj[curr])
                {
                    if (!vis[it])
                        q.push(it);
                }
            }
        }
    }
    return res;
}