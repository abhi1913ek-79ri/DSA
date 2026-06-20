#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Diameter Binary Tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// heightOf bt
int dfsHeight(TreeNode* root){
    if(root==nullptr) return 0;
    return 1 + max(dfsHeight(root->left),dfsHeight(root->right));
    // TC = O(n)
    // SC = O(h)
}

// Brute force
int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int diameter = 0;

    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();

        int leftH = 0;
        int rightH = 0;
        
        if(curr->left) {
            q.push(curr->left);
            leftH = dfsHeight(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
            rightH = dfsHeight(curr->right);
        }

        diameter = max(diameter,leftH+rightH);
    }
    
    return diameter;
    // TC = O(n*n)
    // SC = (h))
}

// global variable
int diameter = 0;

// Optimal approch use Global varible and use dfs height
int dfs(TreeNode* root){
    if(root == nullptr) return 0;

    int leftH = dfs(root->left);
    int rightH = dfs(root->right);

    diameter = max(diameter,rightH+leftH);
    return 1+ max(rightH,leftH);
    // TC = O(n)
    // SC = O(h)
}

int diameterOfBinaryTree2(TreeNode* root){
    dfs(root);
    return diameter;
}


int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Diameter : " << diameterOfBinaryTree(root)<< endl;
    cout << "Diameter : " << diameterOfBinaryTree2(root) <<  endl;
    return 0;
}