#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() >= arr[i % n])
            st.pop();

        if (!st.empty() and i < n)
        {
            nge[i] = st.top();
        }
        st.push(arr[i % n]);
    }
    return nge;
}