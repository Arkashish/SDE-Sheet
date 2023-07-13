#include <bits/stdc++.h>
using namespace std;
void create(vector<vector<int>> &edges, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
bool solve(int node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &vis)
{
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(node);
    vis[node] = true;
    parent[node] = -1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto neighbour : adjList[curr])
        {
            if (!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour] = true;
                parent[neighbour] = curr;
            }
            else
            {
                if (neighbour != parent[curr])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> vis;
    create(edges, adjList);
    string answer = "No";
    bool ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            ans = solve(i, adjList, vis);
        if (ans)
            answer = "Yes";
    }
    return answer;
}