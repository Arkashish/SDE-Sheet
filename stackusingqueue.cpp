#include <bits/stdc++.h>
using namespace std;
class Stack
{
    // Define the data members.
    queue<int> q;
    int size;

public:
    Stack()
    {
        // Implement the Constructor.
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return size == 0;
    }

    void push(int element)
    {
        // Implement the push() function.
        q.push(element);
        size++;
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (!size)
            return -1;
        else
        {
            size--;
            int num = q.front();
            q.pop();
            return num;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (!size)
            return -1;
        else
        {
            return q.front();
        }
    }
};