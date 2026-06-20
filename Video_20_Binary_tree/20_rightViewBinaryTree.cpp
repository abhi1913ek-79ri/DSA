#include<bits/stdc++.h>
using namespace std;
// right view
// Idea level oorder me level[n-1]
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// level order
vector<vector<int>> levelOrderFun(TreeNode* root) {
    if(root==nullptr) return {};
    vector<vector<int>> levelOrder;
    queue<TreeNode*> q;

    q.push(root); 

    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        levelOrder.push_back(level);
    }
    return levelOrder;
    // TC = O(2N)
    // SC = O(3N)
}

// rightView
vector<int> rightViewBrute(TreeNode* root){
    if(root==nullptr) return {};
    vector<vector<int>> levelOrder = levelOrderFun(root);
    vector<int> ans;
    for (auto arr : levelOrder)
    {
        ans.push_back(arr[arr.size()-1]);
    }
    return ans;
    // TC = O(3N)
    // SC = O(3N)
}

// optimal
vector<int> rightView(TreeNode* root){
    if(root==nullptr) return {};
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(root); 
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            if(i == n - 1){
                ans.push_back(curr->val);
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
    // TC = O(2N)
    // SC = O(n)
}


// OptimL : using dfs
void solve(TreeNode* root, int level, vector<int>& ans){
    if(!root) return;

    // first time visiting this level
    if(level == ans.size()){
        ans.push_back(root->val);
    }

    // go right first
    solve(root->right, level + 1, ans);
    solve(root->left, level + 1, ans);
}

// right view 
vector<int> rightViewOptimal(TreeNode* root){
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}

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
    vector<int> rightViewArr = rightViewOptimal(root);
    cout << "Right View : ";
    printArray(rightViewArr);
    return 0;
}