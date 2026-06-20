#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Max path sum 


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};


// Brute force 
// Helper function
int maxPathFromNode(TreeNode* root){
    if(root == NULL) return 0;

    int left = max(0, maxPathFromNode(root->left));
    int right = max(0, maxPathFromNode(root->right));

    return root->val + max(left, right);
    // TC = O(n)
    // SC = O(n)
}

int brute(TreeNode* root){
    if(root == nullptr) return INT_MIN;

    int leftPath  = max(0, maxPathFromNode(root->left));
    int rightPath = max(0, maxPathFromNode(root->right));

    int curr  = root->val + leftPath + rightPath;

    int leftSubtree  = brute(root->left);
    int rightSubtree  = brute(root->right);

    return max({curr,leftSubtree,rightSubtree});
    // TC = O(n*n)
    // SC = O(n) - height of binary tree
}

// Optimal approch use Global varible and use dfs height
// I used the same logic i used for maxWidth 
// changing just one thing i rembering maxL as well as maxR
int dfs(TreeNode* root,int& maxi){
    if(root == nullptr) return 0;

    int leftSum = max(0,dfs(root->left,maxi)); // not take negative sums
    int rightSum = max(0,dfs(root->right,maxi)); // not take negative sums

    maxi = max(maxi,leftSum+rightSum+root->val);
    return root->val + max(leftSum,rightSum);
    // TC = O(n)
    // SC = O(h)
}

int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    dfs(root,maxi);
    return maxi;
}



int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Max Paths sum : " << brute(root) << endl;
    return 0;
}