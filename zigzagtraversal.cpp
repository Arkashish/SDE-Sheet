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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if (!root)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> lvl;
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            lvl.push_back(node->data);
        }
        if (flag)
        {
            reverse(lvl.begin(), lvl.end());
        }
        flag = 1 - flag;
        for (auto it : lvl)
        {
            ans.push_back(it);
        }
    }
    return ans;
}
