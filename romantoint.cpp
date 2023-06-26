#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    // Write your code here
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int result = 0;
    int intVal, nextIntVal;

    for (int i = 0; i < s.size(); i++)
    {
        intVal = mp[s[i]];

        if (i != s.size() - 1)
        {
            nextIntVal = mp[s[i + 1]];

            if (nextIntVal > intVal)
            {
                intVal = nextIntVal - intVal;
                i = i + 1;
            }
        }
        result = result + intVal;
    }
    return result;
}
