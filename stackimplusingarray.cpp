#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack
{

    int *arr;
    int tail;
    int maxi;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        tail = 0;
        maxi = capacity;
    }

    void push(int num)
    {
        if (tail != maxi)
        {
            arr[tail] = num;
            tail++;
        }
    }

    int pop()
    {
        if (tail != 0)
        {
            tail--;
            return arr[tail];
        }
        return -1;
    }

    int top()
    {
        return (tail != 0) ? (arr[tail - 1]) : (-1);
    }

    int isEmpty()
    {
        return (tail == 0) ? (1) : (0);
    }

    int isFull()
    {
        return (tail == maxi);
    }
};