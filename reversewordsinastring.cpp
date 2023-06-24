#include <bits/stdc++.h>
using namespace std;
// Approach 1 -> More Optimised
string reverseString(string &str)
{
    // Write your code here.
    stack<string> st;
    string temp = "";
    for (char c : str)
    {
        if (c == ' ')
        {
            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    if (temp != "")
        st.push(temp);
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (!st.empty())
            ans += " ";
    }
    return ans;
}
// Approach 2
string reverseString(string &str)
{
    reverse(str.begin(), str.end());
    int i = 0;
    while (i < str.length() and str[i] == ' ')
    {
        str.erase(str.begin());
    }

    i = str.length() - 1;
    while (i >= 0 and str[i] == ' ')
    {
        str.erase(str.begin() + i);
        i--;
    }
    for (int i = 0; i < str.length(); i++)
    {
        int j = i;
        while (j < str.length() and str[j] != ' ')
        {
            j++;
        }
        reverse(str.begin() + i, str.begin() + j);
        i = j;
    }

    i = 1;
    while (i < str.length())
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
            str.erase(str.begin() + i);
        else
            i++;
    }
    return str;
}