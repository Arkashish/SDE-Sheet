#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if (!root)
        return -1;
    if (root->data == x || root->data == y)
        return root->data;
    int l = lowestCommonAncestor(root->left, x, y);
    int r = lowestCommonAncestor(root->right, x, y);
    if (l != -1 && r != -1)
        return root->data;
    if (l == -1)
        return r;
    return l;
}