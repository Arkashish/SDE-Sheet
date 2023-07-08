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
    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

TreeNode<int> *solve(vector<int> &v, int &i, int bound)
{
    if (i == v.size() or v[i] > bound)
        return NULL;
    TreeNode<int> *newnode = new TreeNode<int>(v[i++]);
    newnode->left = solve(v, i, newnode->data);
    newnode->right = solve(v, i, bound);
    return newnode;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int i = 0;
    return solve(preOrder, i, INT_MAX);
}