#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (!root)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int line = q.front().second;
        q.pop();
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->val;
        }
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}