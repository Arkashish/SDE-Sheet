#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Approach 1
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *ans;
    bool f = 1;
    while (head != NULL)
    {
        LinkedListNode<int> *tmp = new LinkedListNode<int>(head->data);
        if (f)
            ans = tmp, f = 0;
        tmp->next = head->next;
        tmp->random = head->random;
        head = head->next;
        tmp = tmp->next;
    }
    return ans;
}

// Approach 2
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *iter = head, *front = head;

    // LinkedListNode<int> *temp=copy;
    while (iter)
    {
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    iter = head;
    while (iter)
    {
        if (iter->random)
        {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    iter = head;
    LinkedListNode<int> *pseudohead = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = pseudohead;
    while (iter)
    {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }

    return pseudohead->next;
}
