#include <bits/stdc++.h>
using namespace std;
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    map<int, vector<int>> mp;
    q.push({root, 0});
    mp[0].push_back(root->data);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *temp = it.first;
        int distance = it.second;
        if (temp->left)
        {
            q.push({temp->left, distance - 1});
            mp[distance - 1].push_back(temp->left->data);
        }
        if (temp->right)
        {
            q.push({temp->right, distance + 1});
            mp[distance + 1].push_back(temp->right->data);
        }
    }
    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            ans.push_back(i);
        }
    }
    return ans;
}