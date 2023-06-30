#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[2];
};
void insert(Node *root, int elmnt)
{
    int n = elmnt;
    Node *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (curr->links[bit] == NULL)
            curr->links[bit] = new Node();
        curr = curr->links[bit];
    }
}
int getmaxXOR(Node *root, int n)
{
    int xr = 0;
    Node *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (curr->links[1 ^ bit] != NULL)
        {
            xr += (1 << i);
            curr = curr->links[1 ^ bit];
        }
        else
            curr = curr->links[bit];
    }
    return xr;
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    //  Write your coode here.
    Node *root = new Node();
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> q;
    for (int i = 0; i < queries.size(); i++)
        q.push_back({queries[i][1], {queries[i][0], i}});
    sort(q.begin(), q.end());
    vector<int> ans(q.size());
    int idx = 0;
    for (int i = 0; i < q.size(); i++)
    {
        int ai = q[i].first;
        int xi = q[i].second.first;
        int index = q[i].second.second;
        while (idx < arr.size() && arr[idx] <= ai)
        {
            insert(root, arr[idx]);
            idx++;
        }
        if (idx == 0)
            ans[index] = -1;
        else
            ans[index] = getmaxXOR(root, xi);
    }
    return ans;
}