#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    if (root->left)
        preorder(root->left, ans);
    if (root->right)
        preorder(root->right, ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    preorder(root, ans);
    return ans;
}