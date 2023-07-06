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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return 0;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    int ans = 0;
    while (!q.empty())
    {
        int sz = q.size();
        ans = max(ans, sz);
        for (int i = 0; i < sz; i++)
        {
            TreeNode<int> *temp = q.front().first;
            int index = q.front().second;
            q.pop();

            if (temp->left)
                q.push({temp->left, 2 * index + 1});

            if (temp->right)
                q.push({temp->right, 2 * index + 2});
        }
    }
    return ans;
}