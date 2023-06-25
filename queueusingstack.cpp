#include <bits/stdc++.h>
using namespace std;
class Queue
{
    // Define the data members(if any) here.
    stack<int> st;

public:
    Queue() {}

    void enQueue(int val)
    {
        st.push(val);
    }

    int deQueue()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            int bottom = -1;
            FindBottom(st, bottom, 0);
            return bottom;
        }
    }
    void FindBottom(stack<int> &st, int &y, int see)
    {
        if (st.size() == 1)
        {
            y = st.top();
            if (see == 0)
            {
                st.pop();
            }
            return;
        }
        int val = st.top();
        st.pop();
        FindBottom(st, y, see);
        st.push(val);
    }

    int peek()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            int bottom = -1;
            FindBottom(st, bottom, 1);
            return bottom;
        }
    }

    bool isEmpty()
    {
        return st.empty();
    }
};