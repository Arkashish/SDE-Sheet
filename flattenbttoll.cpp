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

void flatten(TreeNode<int> *root, TreeNode<int> *&prev)
{

    if (root == NULL)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->left = NULL;
    root->right = prev;
    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *next = NULL;
    flatten(root, next);
    return root;
}