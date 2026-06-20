#include<bits/stdc++.h>
using namespace std;
// Inorderd traversal binary tree
// Reciusive functions


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};


// INORDER
void inorderHelper(TreeNode* root,vector<int>& ans){
    // Base case :
    if(root == nullptr) return;

    inorderHelper(root->left,ans);
    ans.push_back(root->val);
    inorderHelper(root->right,ans);
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorderHelper(root,ans);
    return ans;
}

// Iterative way 
void printArray(vector<int>& nums){
    cout <<"[";
    for(auto num : nums){
        cout << num << " ";
    }
    cout <<"]\n";
}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> inorederArr = inorderTraversal(root);
    cout << "Inorder : ";
    printArray(inorederArr);
    // cout << "Inorder : ";
    // printArray(inorederArrIterative);
    return 0;
}