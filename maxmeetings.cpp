#include <bits/stdc++.h>
using namespace std;
static bool paircompare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    if (a.first.second != b.first.second)
        return a.first.second < b.first.second;
    return a.second < b.second;
}
//
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<int>ans;
    vector<vector<int>>v(start.size());
    for(int i=0;i<v.size();i++) {
        v[i]={end[i],i+1,start[i]};
    }
    sort(v.begin(),v.end());
    int finish=v[0][0];
    ans.push_back(v[0][1]);
    for(int i=1;i<v.size();i++) {
        if(v[i][2]>finish) {
            finish=v[i][0];
            ans.push_back(v[i][1]);
        }
    }
    return ans;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<pair<int, int>, int>> x;
    int n = start.size();

    for (int i = 0; i < n; i++)
    {
        x.push_back({{start[i], end[i]}, i});
    }
    sort(x.begin(), x.end(), paircompare);
    int last = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (x[i].first.first > last)
        {
            // res++;
            last = x[i].first.second;
            ans.push_back(x[i].second);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}