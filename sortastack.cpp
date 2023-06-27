#include <bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &st)
{
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    while (!st.empty())
    {
        pq.push(st.top());
        st.pop();
    }
    while (!pq.empty())
    {
        st.push(pq.top());
        pq.pop();
    }
}