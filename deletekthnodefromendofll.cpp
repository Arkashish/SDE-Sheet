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

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    int flag = 0;
    Node *temp = new Node();
    temp->next = head;
    Node *slow = temp, *fast = temp;
    for (int i = 0; i < K; i++)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return head->next;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return temp->next;
}
