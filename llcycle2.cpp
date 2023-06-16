#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *firstNode(Node *head)
{
    //    Write your code here.
    if (head == NULL or head->next == NULL)
        return NULL;

    Node *s = head, *f = head, *tmp = head;
    while (f->next != NULL and f->next->next != NULL)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
        {
            while (s != tmp)
            {
                s = s->next;
                tmp = tmp->next;
            }
            return tmp;
        }
    }
    return NULL;
}