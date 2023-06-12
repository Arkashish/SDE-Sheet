#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    int slow, fast;
    slow = arr[0];
    fast = arr[0];
    while (true)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if (slow == fast)
        {
            break;
        }
    }
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
