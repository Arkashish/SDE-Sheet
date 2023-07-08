#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void flatten(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prev)
{
    if (!root)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // Write your code here
    BinaryTreeNode<int> *head = NULL;
    BinaryTreeNode<int> *prev = NULL;
    BinaryTreeNode<int> *curr = root;

    while (curr)
    {
        if (!curr->left)
        {

            if (!head)
                head = curr;
            curr->left = prev;
            if (prev)
                prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            BinaryTreeNode<int> *next = curr->left;

            while (next->right && next->right != curr)
                next = next->right;
            if (next->right == NULL)
            {
                next->right = curr;
                curr = curr->left;
            }
            else
            {
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return head;
}