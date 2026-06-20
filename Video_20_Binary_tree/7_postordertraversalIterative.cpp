#include<bits/stdc++.h>
using namespace std;
// postorderd traversal binary tree
// Itertive

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// Iterative way  - O(2N) - TC 
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


// 2 stack 
vector<int> postorderTraversalIterative2(TreeNode* root) {
    if(root == nullptr) return {};

    vector<int> ans;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);
    while(!st1.empty())
    {
        TreeNode* node = st1.top();
        st1.pop();

        st2.push(node);

        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    
    return ans;
    // TC = O(n)
    // SC = O(n)
}


// Single stack iteative
// TreeNode* lastVisited = NULL;
// 🧩 Intuition (Step by Step)
// Left me jaate raho (inorder jaisa)
// 1->Jab left khatam:
// 2->Agar right exist karta hai AND visit nahi hua
//  → right me jao
// warna → node print karo
vector<int> postorderTraversalIterative3(TreeNode* root){
    if(root==nullptr) return {};
    vector<int> post;

    stack<TreeNode*> st;

    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr!=NULL || !st.empty())
    {
        if(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }else{
            TreeNode* node = st.top();

            if(node->right && lastVisited != node->right){
                curr = node->right;
            }else{
                post.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }
    return post;
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

    vector<int> postorderArrItr = postorderTraversalIterative(root);
    cout << "postorder : ";
    printArray(postorderArrItr);
    vector<int> postorderArrItr2 = postorderTraversalIterative2(root);
    cout << "postorder : ";
    printArray(postorderArrItr2);
    vector<int> postorderArrItr3 = postorderTraversalIterative3(root);
    cout << "postorder : ";
    printArray(postorderArrItr3);
    return 0;
}