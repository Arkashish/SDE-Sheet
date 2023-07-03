#include <bits/stdc++.h>
using namespace std;
int atoi(string str)
{
    // Write your code here.
    bool flag = true;
    int digit = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int rem = (int)str[i] - 48;
        if (rem == -3)
        {
            flag = false;
        }
        else if (rem >= 0 && rem <= 9)
        {
            digit = digit * 10 + rem;
        }
        else
        {
            continue;
        }
    }
    if (flag == false)
        digit = -1 * digit;
    return digit;
}