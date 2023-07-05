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
            delete left;
        if (right)
            delete right;
    }
};
bool isleaf(TreeNode<int> *root)
{
    return !root->right and !root->left;
}
void lbt(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isleaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void rbt(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    TreeNode<int> *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isleaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}
void midd(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    if (isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    midd(root->left, ans);
    midd(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (!root)
        return ans;
    if (!isleaf(root))
        ans.push_back(root->data);
    lbt(root, ans);
    midd(root, ans);
    rbt(root, ans);
    return ans;
}