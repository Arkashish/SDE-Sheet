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
        this->next = NULL;
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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int carry = 0;
    Node *res = new Node(0);
    Node *tmp = res;
    while (num1 or num2 or carry)
    {
        int sum = 0;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *temp = new Node(sum % 10);
        tmp->next = temp;
        tmp = tmp->next;
    }
    return res->next;
}
