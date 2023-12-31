#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (qfront == rear)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear != size)
            arr[rear++] = data;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (rear == qfront)
            return -1;
        else
        {
            int temp = arr[qfront++];
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return temp;
        }
    }

    int front()
    {
        // Implement the front() function
        if (rear == qfront)
            return -1;
        return arr[qfront];
    }
};