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

// using stack + num(state)
vector<vector<int>> preInPostTraversal(TreeNode* root) {
    if(root==NULL) return {};
    vector<vector<int>> ans;
    vector<int> pre,in,post;

    stack<pair<TreeNode*,int>> st;
    st.push({root,1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1){ // preorder
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->val);
        }
    }
    return {pre,in,post};
    // TC = O(3N)
    // SC = O(4N)
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