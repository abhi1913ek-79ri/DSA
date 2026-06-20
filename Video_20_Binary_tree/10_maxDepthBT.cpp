#include<bits/stdc++.h>
using namespace std;
// Max Depth Binary Tree
// no of nodes from root to farthest leaf node 

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};


// Using BFS
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        depth++;
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

    return depth;
    // TC = O(n)
    // SC = O(n) 
}


// using recursive approach / DFS  
int maxDepth2(TreeNode* root){
    if(root==nullptr) return 0;
    return 1+max(maxDepth2(root->left),maxDepth2(root->right));
    // TC = O(N)
    // SC = O(H)  (H = height of tree)
    // -> O(log N) for balanced tree
    // -> O(N) for skewed tree/
}


int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    cout << "Max Depth = " << maxDepth2(root) << endl;
    return 0;
}