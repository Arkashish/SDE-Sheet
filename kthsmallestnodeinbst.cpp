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

int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    stack<TreeNode<int> *> st;
    if (!root)
        return -1;
    TreeNode<int> *node = root;
    int cnt = 0;
    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            cnt++;
            if (cnt == k)
                return node->data;
            node = node->right;
        }
    }
    return -1;
}