#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

void preInPostHelper(TreeNode* root,vector<int>& pre,vector<int>& in,vector<int>& post){
    // Base case :
    if(root == nullptr) return;

    pre.push_back(root->val);
    preInPostHelper(root->left,pre,in,post);
    in.push_back(root->val);
    preInPostHelper(root->right,pre,in,post);
    post.push_back(root->val);
}

vector<vector<int>> preInPostTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    preInPostHelper(root,pre,in,post);
    return {pre,in,post};
}

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

    vector<vector<int>> ans = preInPostTraversal(root);
    cout << "Preorder : ";
    printArray(ans[0]);
    cout << "Inorder : ";
    printArray(ans[1]);
    cout << "Postorder : ";
    printArray(ans[2]);
    return 0;
}