#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int count = 0;
    int num1;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            num1 = arr[i];
        if (arr[i] == num1)
            count++;
        else
            count--;
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1 == arr[i])
            count++;
    }
    if (count > (n / 2))
        return num1;
    else
        return -1;
}