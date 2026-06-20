#include<bits/stdc++.h>
using namespace std;
// postorderd traversal binary tree
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


// postorder
void postorderHelper(TreeNode* root,vector<int>& ans){
    // Base case :
    if(root == nullptr) return;

    postorderHelper(root->left,ans);
    postorderHelper(root->right,ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorderHelper(root,ans);
    return ans;
}

// preoredr Iterative 
// Iterative way 
vector<int> postorderTraversalIterative(TreeNode* root) {
    if(root == nullptr) return {};

    vector<int> ans;
    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    reverse(ans.begin(),ans.end());
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

    vector<int> postorderArr = postorderTraversal(root);
    vector<int> postorderArrItr = postorderTraversalIterative(root);
    cout << "postorder : ";
    printArray(postorderArr);
    cout << "postorder : ";
    printArray(postorderArrItr);
    return 0;
}