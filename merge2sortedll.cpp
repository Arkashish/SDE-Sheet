#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data >= second->data)
        std::swap(first, second);
    Node<int> *res = first;
    while (first and second)
    {
        Node<int> *temp;
        if (first and first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        std::swap(first, second);
    }
    return res;
}
