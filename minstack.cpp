#include <bits/stdc++.h>
// Implement class for minStack.
using namespace std;
class minStack
{
    // Write your code here.

public:
    int mini;
    stack<int> st;
    // Constructor
    minStack()
    {
        // Write your code here.
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        if (st.empty())
        {
            mini = num;
            st.push(num);
        }
        else
        {
            if (num < mini)
            {
                st.push(2 * num - mini);
                mini = num;
            }
            else
            {
                st.push(num);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (!st.empty())
        {
            int data = st.top();
            if (data >= mini)
            {
                st.pop();
                return data;
            }
            else
            {
                int prev = mini;
                mini = 2 * mini - data;
                st.pop();
                return prev;
            }
        }
        return -1;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (st.empty())
            return -1;
        if (mini < st.top())
        {
            return st.top();
        }
        return mini;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (st.empty())
            return -1;
        return mini;
    }
};