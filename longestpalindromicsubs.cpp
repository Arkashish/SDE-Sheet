#include <bits/stdc++.h>
using namespace std;
string longestPalinSubstring(string s)
{
    // Write your code here.
    int len = s.length();
    int start = 0;
    int end = 1;

    for (int i = 1; i < len; i++)
    {
        // even
        int low = i - 1;
        int high = i;
        while (low >= 0 and high < len and s[low] == s[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
        // odd
        low = i - 1;
        high = i + 1;
        while (low >= 0 and high < len and s[low] == s[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }
    string str = s.substr(start, end);
    return str;
}