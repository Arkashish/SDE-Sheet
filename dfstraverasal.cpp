#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    map<int, set<int>> adj;
    map<int, bool> vis;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].insert(edges[i][1]);
        adj[edges[i][1]].insert(edges[i][0]);
    }
    vector<vector<int>> v;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            stack<int> st;
            st.push(i);
            int top;
            vis[i] = 1;
            vector<int> tmp;
            while (!st.empty())
            {
                top = st.top();
                st.pop();
                tmp.push_back(top);
                for (auto it : adj[top])
                {
                    if (vis[it] == 0)
                    {
                        st.push(it);
                        vis[it] = 1;
                    }
                }
            }
            v.push_back(tmp);
        }
    }
    return v;
}
