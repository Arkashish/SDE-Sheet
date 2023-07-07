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

class BSTiterator
{
public:
    stack<TreeNode<int> *> st;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *tmp = st.top();
        st.pop();
        if (tmp->right)
        {
            pushAll(tmp->right);
        }
        return tmp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
    void pushAll(TreeNode<int> *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/