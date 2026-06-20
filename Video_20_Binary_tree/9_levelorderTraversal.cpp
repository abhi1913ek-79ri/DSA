#include<bits/stdc++.h>
using namespace std;
// Inorder traversal binary tree
// BFS
// Idea = queue + level

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// Two pass Approach
// Tu abhi ye kar raha hai:

// Step 1:
// BFS → store in aux (node + level)
// Step 2:
// aux traverse → build answer

// 👉 Matlab:

// 2 passes
// extra memory (aux)
vector<vector<int>> levelOrderFun(TreeNode* root) {
    if(root==nullptr) return {};
    queue<pair<TreeNode*,int>> q;
    q.push({root,0}); // pair<node,level>

    vector<pair<TreeNode*,int>> aux;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        aux.push_back(curr);

        if(curr.first->left!=NULL){
            q.push({curr.first->left,curr.second+1});
        }
        if(curr.first->right!=NULL){
            q.push({curr.first->right,curr.second+1});
        }
    }

    vector<vector<int>> levelOrder;
    vector<int> temp;
    int level = 0;
    for(auto p :aux){
        if(p.second == level){
            temp.push_back(p.first->val);
        }else{
            level = p.second;
            levelOrder.push_back(temp);
            temp = {p.first->val};
        }
    }
    // last level push
    levelOrder.push_back(temp);
    return levelOrder;
    // TC = O(2N)
    // SC = O(3N)
}


// Single pass solution 
// bhai bus mere solution me level identify karne me problem aa rahi thi jiski 
// wajah se aux array ka use karna pada + extra pass 
// instead of that here i used 
// q.size() to get same level element to single array
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
    vector<vector<int>> levelOrder = levelOrderFun(root);
    int n = levelOrder.size();

    cout << "Level Order : [ ";
    for (int i = 0; i < n; i++)
    {
        printArray(levelOrder[i]);
    }
    cout << "]\n";
    
    return 0;
}