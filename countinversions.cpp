#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
void merge(long long *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainarrayindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainarrayindex++];
    }
    mainarrayindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainarrayindex++];
    }
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainarrayindex++] = first[index1++];
        }
        else
        {
            cnt += len1 - index1;
            arr[mainarrayindex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainarrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainarrayindex++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}
void mergesort(long long *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

long long getInversions(long long *arr, int n)
{
    cnt = 0;
    mergesort(arr, 0, n - 1);
    return cnt;
}
