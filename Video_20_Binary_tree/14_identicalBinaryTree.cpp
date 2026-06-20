#include<bits/stdc++.h>
using namespace std;
// Binary tree structure 
// Identical binary tree

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x) , left(left) , right(right){}
};

// Brute Force BFS tree to array
vector<int> treeToArrayBFS(TreeNode* root){
    if(root==nullptr) return {};
    queue<TreeNode*> q;
    vector<int> arr;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr  = q.front();
        q.pop();

        if(curr == nullptr){
            arr.push_back(-1); // remember that it can reject if value itself is negative
            continue;
        }

        arr.push_back(curr->val);

        q.push(curr->left);
        q.push(curr->right);

    }
    return arr;
    // TC = O(n)
    // SC = O(2n)    
}

//  is same tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int> t1 = treeToArrayBFS(p);
    vector<int> t2 = treeToArrayBFS(q);
    if(t1.size()!=t2.size()) return false;
    
    for(int i=0;i<t1.size();i++){
        if(t1[i]!=t2[i]) return false;
    }

    return true;
    // TC = O(3N)
    // SC = O(6N)
}


// DFS optimal approach
bool isSameTree2(TreeNode* p, TreeNode* q) {
    if(p==nullptr && q==nullptr) return true;

    if(p!=nullptr&& q!=nullptr && p->val == q->val) {
        return isSameTree2(p->left,q->left) && isSameTree2(p->right,q->right);
    }

    return false;
    // TC = O(n)
    // SC = O(h)
}


// print array
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
    root->right->right = new TreeNode(6);

    TreeNode* root2 = new TreeNode(0);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(6);

    cout << "Same Tree : "<< isSameTree(root,root2)<<endl;
    cout << "Same Tree : "<< isSameTree2(root,root2)<<endl;

    return 0;
}