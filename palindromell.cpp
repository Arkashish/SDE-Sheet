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

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head, *temp = NULL, *nex = NULL;
    while (curr)
    {
        nex = curr->next;
        curr->next = temp;
        temp = curr;
        curr = nex;
    }
    return temp;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL or head->next == NULL)
        return true;
    LinkedListNode<int> *slow = head, *fast = head;
    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int> *tmp = head;
    while (slow)
    {
        if (slow->data != tmp->data)
            return false;
        slow = slow->next;
        tmp = tmp->next;
    }
    return true;
}