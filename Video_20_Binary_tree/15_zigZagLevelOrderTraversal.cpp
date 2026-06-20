#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Zig zag level order traversal

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// BFS 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==nullptr) return {};
    vector<vector<int>> zz;

    queue<TreeNode*> q;
    q.push(root);
    int levelNo = -1;
    while (!q.empty())
    {
        int n = q.size();
        levelNo++;
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        if(levelNo&1) reverse(level.begin(),level.end());
        zz.push_back(level);
    }
    return zz;
    // TC = O(n+n+n)
    // SC = O(n)
}

// Slight optimal avoid reverse
vector<vector<int>> zigzagLevelOrderOptimal(TreeNode* root) {
    if(root==nullptr) return {};
    vector<vector<int>> zz;

    queue<TreeNode*> q;
    q.push(root);
    int levelNo = -1;
    while (!q.empty())
    {
        int n = q.size();
        levelNo++;
        vector<int> level(n,0);
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            int index = levelNo&1 ? n-i-1 : i;
            level[index] = curr->val;

            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        zz.push_back(level);
    }
    return zz;
    // TC = O(n+n)
    // SC = O(n)
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
    vector<vector<int>> levelOrder = zigzagLevelOrderOptimal(root);
    int n = levelOrder.size();

    cout << "Level Order : [ ";
    for (int i = 0; i < n; i++)
    {
        printArray(levelOrder[i]);
    }
    cout << "]\n";
    
    return 0;
}