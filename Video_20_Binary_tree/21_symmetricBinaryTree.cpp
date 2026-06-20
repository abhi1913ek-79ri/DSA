#include <bits/stdc++.h>
using namespace std;
// Symmetric binary tree


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

bool isSameTree2(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p != nullptr && q != nullptr && p->val == q->val)
    {
        return isSameTree2(p->left, q->right) && isSameTree2(p->right, q->left);
    }

    return false;
    // TC = O(n)
    // SC = O(h)
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return isSameTree2(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(2);
    cout << "Symmetric : " << isSymmetric(root) << endl;
    return 0;
}