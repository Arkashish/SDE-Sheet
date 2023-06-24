#include <bits/stdc++.h>
using namespace std;
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    vector<int> lheight(n), rheight(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            lheight[i] = 0;
        else
            lheight[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            rheight[i] = n - 1;
        else
            rheight[i] = st.top() - 1;
        st.push(i);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (rheight[i] - lheight[i] + 1) * heights[i]);
    }
    return maxi;
}