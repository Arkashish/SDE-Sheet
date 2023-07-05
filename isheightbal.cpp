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
int isbal(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    int lh = isbal(root->left);
    if (lh == -1)
        return -1;
    int rh = isbal(root->right);
    if (rh == -1)
        return -1;
    if (abs(rh - lh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int val = isbal(root);
    if (val == -1)
        return false;
    else
        true;
}