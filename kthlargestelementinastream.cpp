#include <bits/stdc++.h>
using namespace std;
class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> minhp;
    int sz = 0;
    Kthlargest(int k, vector<int> &nums)
    {
        // Write your code here.
        int n = nums.size();
        while (n--)
        {
            minhp.push(nums[n]);
        }
        while (minhp.size() > k)
        {
            minhp.pop();
        }
        sz = k;
    }

    void add(int num)
    {
        // Write your code here.
        minhp.push(num);
        if (minhp.size() > sz)
            minhp.pop();
    }

    int getKthLargest()
    {
        // Write your code here.
        return minhp.top();
    }
};