#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Balanced Binary Tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// height of binary tree
int heightBT(TreeNode* root){
    if(root==nullptr) return 0;
    return 1 + max(heightBT(root->left),heightBT(root->right));
    // TC = O(n)
    // SC = O(n)
}

bool isBalanced(TreeNode* root) {
    if(root==NULL) return  true;
    int leftH = heightBT(root->left);
    int rightH = heightBT(root->right);
    int diff  = abs(leftH-rightH);
    if(diff>1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// modified dfsHeight
int dfsHeight(TreeNode* root){
    if(root==nullptr) return 0;

    int leftHeight = dfsHeight(root->left);
    if(leftHeight==-1) return -1;
    int rightHeight = dfsHeight(root->right);
    if(rightHeight==-1) return -1;
    if(abs(leftHeight-rightHeight)>1) return -1;
    return 1 + max(leftHeight,rightHeight);
    // TC = O(n)
    // SC = O(H)
}

bool isBalanced1(TreeNode* root){
    return dfsHeight(root) != -1;
    // TC = O(n)
    // SC = O(H)
}


int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Is Balanced : " << isBalanced1(root);
    return 0;
}