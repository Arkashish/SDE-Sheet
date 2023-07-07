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

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
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
            node = node->right;
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
            node = node->left;
        }
    }
    return -1;
}
