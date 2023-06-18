#include <bits/stdc++.h>
using namespace std;
int search(int *nums, int n, int target)
{
    // Write your code here.
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target and target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (nums[mid] <= nums[high])
        {
            if (nums[mid] <= target and target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}