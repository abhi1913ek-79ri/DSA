#include<bits/stdc++.h>
using namespace std;
// Top View 
// Idea vertical order me har column ka first element 

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(root == nullptr) return {};
    // DS that store visited and processed nodes
    map<int,map<int,multiset<int>>> nodes; // < x-asix,<y-axis,set>>

    // level order traveral - BFS
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        TreeNode* node = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        nodes[x][y].insert(node->val); // logn

        if(node->left != nullptr){
            q.push({node->left,{x-1,y+1}});
        }

        if(node->right != nullptr){
            q.push({node->right,{x+1,y+1}});
        }
    }

    vector<vector<int>> ans;

    // preparing ans
    for (auto& p : nodes)
    {
        vector<int> currVertical;
        for (auto& ele : p.second)
        {
            auto& mS = ele.second;
            for(auto &x : mS)
            {
                currVertical.push_back(x);
            }
        }
        ans.push_back(currVertical);
    }
    return ans;
    // TC = O(n*logn)
    // SC - O(n)
}

vector<int> topViewBrute(TreeNode* root){
    vector<vector<int>> verticalOrder = verticalTraversal(root);
    vector<int> ans;
    for(auto& col : verticalOrder){
        ans.push_back(col[0]);
    }
    return ans;
    // TC = O(nlogn + n)
    // SC = O(n)
}

// optimal
vector<int> topView(TreeNode* root){
    if(root==nullptr) return {};
    map<int,int> mpp; // < vertical , node->val>

    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        auto currPair = q.front();
        q.pop();

        TreeNode* node = currPair.first;
        int vertical = currPair.second;

        if(mpp.find(vertical)==mpp.end()){
            mpp[vertical] = node->val;
        }

        if(node->left!=nullptr) q.push({node->left,vertical-1});
        if(node->right!=nullptr) q.push({node->right,vertical+1});
    }
    // prepare ans
    vector<int> ans;
    for(auto p : mpp){
        ans.push_back(p.second);
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
    vector<int> topViewArr = topView(root);
    cout << "Top View : ";
    printArray(topViewArr);
    return 0;
}