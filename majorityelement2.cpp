#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for (auto it : arr)
    {
        if (it == num1)
            c1++;
        else if (it == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = it;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = it;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1 = c2 = 0;
    for (auto it : arr)
    {
        if (it == num1)
            c1++;
        else if (it == num2)
            c2++;
    }
    if (c1 > (arr.size() / 3))
        ans.push_back(num1);
    if (c2 > (arr.size() / 3))
        ans.push_back(num2);
    return ans;
}