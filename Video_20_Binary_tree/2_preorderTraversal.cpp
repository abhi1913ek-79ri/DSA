#include<bits/stdc++.h>
using namespace std;
// preorderd traversal binary tree
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


// preorder
void preorderHelper(TreeNode* root,vector<int>& ans){
    // Base case :
    if(root == nullptr) return;

    ans.push_back(root->val);
    preorderHelper(root->left,ans);
    preorderHelper(root->right,ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorderHelper(root,ans);
    return ans;
}

// preoredr Iterative 
// Iterative way 
vector<int> preorderTraversalIterative(TreeNode* root) {
    if(root == nullptr) return {};

    vector<int> ans;
    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
    // TC = O(n)
    // SC = O(n)
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

    vector<int> preorderArr = preorderTraversal(root);
    vector<int> preorderArrItr = preorderTraversalIterative(root);

    cout << "preorder : ";
    printArray(preorderArr);
    cout << "preorder : ";
    printArray(preorderArrItr);
    return 0;
}