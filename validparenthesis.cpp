#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string str)
{
    // Write your code here.
    int n = str.size();
    int c = 0;
    if (n == 0)
        return false;
    stack<char> st;
    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == '(' or str[i] == '[' or str[i] == '{')
        {
            st.push(str[i]);
            continue;
        }
        if (st.empty())
            return false;
        if ((str[i] == ')' and st.top() != '(') or
            (str[i] == ']' and st.top() != '[') or
            (str[i] == '}' and st.top() != '{'))
        {
            c = 1;
            break;
        }
        if ((str[i] == ')' and st.top() == '(') or
            (str[i] == ']' and st.top() == '[') or
            (str[i] == '}' and st.top() == '{'))
        {
            st.pop();
        }
    }
    if (c == 0 and st.empty())
        return true;
    return false;
}