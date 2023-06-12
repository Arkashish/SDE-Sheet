#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    LinkedListNode<int> *nex = node;
    nex->data = node->next->data;
    nex->next = nex->next->next;
    // delete node;
}