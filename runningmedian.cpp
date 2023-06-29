#include <bits/stdc++.h>
using namespace std;
priority_queue<int> maxhp;
priority_queue<int, vector<int>, greater<int>> minhp;
void addnum(int num)
{
    int lsize = maxhp.size();
    int rsize = minhp.size();

    if (lsize == 0)
    {
        maxhp.push(num);
    }
    else if (lsize == rsize)
    {
        if (num > minhp.top())
        {
            int tmp = minhp.top();
            minhp.pop();
            minhp.push(num);
            maxhp.push(tmp);
        }
        else
        {
            maxhp.push(num);
        }
    }
    else
    {
        if (minhp.size() == 0)
        {
            if (num > maxhp.top())
                minhp.push(num);
            else
            {
                int tmp = maxhp.top();
                maxhp.pop();
                maxhp.push(num);
                minhp.push(tmp);
            }
        }
        else if (num >= minhp.top())
            minhp.push(num);
        else
        {
            if (num < maxhp.top())
            {
                int tmp = maxhp.top();
                maxhp.pop();
                maxhp.push(num);
                minhp.push(tmp);
            }
            else
                minhp.push(num);
        }
    }
}
int findMedianfromhp()
{
    int lsize = maxhp.size();
    int rsize = minhp.size();
    if (lsize > rsize)
        return (maxhp.top());
    else
        return (maxhp.top() + minhp.top()) / 2;
}
void findMedian(int *arr, int n)
{
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        addnum(arr[i]);
        cout << findMedianfromhp() << " ";
    }
}