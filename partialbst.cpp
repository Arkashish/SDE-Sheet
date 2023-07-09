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

bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (!root or (!root->left and !root->right))
        return true;
    bool lefttree = validateBST(root->left);
    bool righttree = validateBST(root->right);

    bool ans = true;
    if (root->left)
    {
        ans = ans and (root->data >= root->left->data);
    }
    if (root->right)
    {
        ans = ans and (root->data <= root->right->data);
    }

    return ans and lefttree and righttree;
}