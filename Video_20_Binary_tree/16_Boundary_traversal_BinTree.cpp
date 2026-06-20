#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Boundary Travesal 

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// DFS traversal

// Left boundary
void dfsLeft(TreeNode* root, vector<int>& left){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    left.push_back(root->val);

    if(root->left) dfsLeft(root->left, left);
    else dfsLeft(root->right, left);
}
// Leaf nodes 
void dfsLeafNodes(TreeNode* root,vector<int>& leaf){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) {
        leaf.push_back(root->val);
        return;
    }
    dfsLeafNodes(root->left,leaf);
    dfsLeafNodes(root->right,leaf);
    // TC = o(n)
    // SC = O(h)
}
// Right boundary
void dfsRight(TreeNode* root, vector<int>& right){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    right.push_back(root->val);

    if(root->right) dfsRight(root->right, right);
    else dfsRight(root->left, right);
}


vector<int> boundaryTraversal(TreeNode* root){
    vector<int> left;
    vector<int> leaf;
    vector<int> right;
    vector<int> boundary;

    if(root==nullptr) return boundary;

    if(!(root->left == NULL && root->right == NULL)) boundary.push_back(root->val);

    dfsLeft(root->left,left);
    dfsLeafNodes(root,leaf);
    dfsRight(root->right,right);

    for(auto ele : left){
        boundary.push_back(ele);
    }
    for(auto ele : leaf){
        boundary.push_back(ele);
    }
    for(int i=right.size()-1;i>=0;i--){
        boundary.push_back(right[i]);
    }
    // boundary.pop_back();
    return boundary;
}


// print array
void printArray(vector<int>& nums){
    cout <<"[";
    for(auto num : nums){
        cout << num << " ";
    }
    cout <<"] ";
}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> boundary = boundaryTraversal(root);
    cout << "Boundary ele  : " ;
    printArray(boundary);
    return 0;
}




// remember 
// ✅ Tera Idea (Conceptually Sahi)
// Left boundary → non-leaf only
// Leaf nodes → separately
// Right boundary → non-leaf only (reverse)

// 👉 Ye hi standard approach hai ✔️
// 👉 Isme koi issue nahi


// mistake done by me 
// 💥 Core Mistake
// 👉 Tu assume kar raha hai:
// “Left boundary = only left pointers”
// ❌ GALAT