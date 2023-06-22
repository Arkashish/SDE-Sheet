#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *flatten(Node *a, Node *b)
{
    Node *res = new Node(0);
    Node *tmp = res;
    while (a and b)
    {
        if (a->data < b->data)
        {
            tmp->child = a;
            a = a->child;
            tmp = tmp->child;
        }
        else
        {
            tmp->child = b;
            b = b->child;
            tmp = tmp->child;
        }
    }
    if (a)
        tmp->child = a;
    else if (b)
        tmp->child = b;
    return res->child;
}
Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (!head or !head->next)
        return head;
    Node *temp = flattenLinkedList(head->next);
    head->next = NULL;
    Node *newhead = flatten(head, temp);
    return newhead;
}
