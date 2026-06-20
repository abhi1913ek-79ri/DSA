#include<bits/stdc++.h>
using namespace std;
// Inorderd traversal binary tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// Iterative way 
vector<int> inorderTraversalItr(TreeNode* root){
    vector<int> in;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while (true)
    {
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            in.push_back(node->val);
            node = node->right;
        }
    }
    return in;
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

    vector<int> inorederArrItr = inorderTraversalItr(root);
    cout << "Inorder : ";
    printArray(inorederArrItr);
    return 0;
}