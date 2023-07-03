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
void solve(TreeNode<int> *root, vector<int> &ans, int lvl)
{
    if (!root)
        return;
    if (lvl == ans.size())
        ans.push_back(root->data);
    if (root->left)
        solve(root->left, ans, lvl + 1);
    if (root->right)
        solve(root->right, ans, lvl + 1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}