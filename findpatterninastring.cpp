#include <bits/stdc++.h>
using namespace std;
bool findPattern(string p, string s)
{
    // Write your code here.

    //Approach 1
    return strstr(s.c_str(), p.c_str());

    //Approach 2
    int m = p.size(), n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string str = s.substr(i, m);
        if (str == p)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    if (count > 0)
        return true;
    else if (count == 0)
        return false;
}