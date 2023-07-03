#include <bits/stdc++.h>
using namespace std;

// ## Revise VIMP Code

vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    vector<int> nse(n), pse(n), ans(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        pse[i] = i;
        nse[i] = n - i - 1;
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            nse[st.top()] = i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            pse[st.top()] = st.top() - i - 1;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int d = nse[i] + pse[i];
        ans[d] = max(ans[d], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
        if (ans[i] < ans[i + 1])
            ans[i] = ans[i + 1];

    return ans;
}