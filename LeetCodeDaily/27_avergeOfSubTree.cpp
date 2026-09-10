#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;
pair<int, int> dfs(TreeNode *root)
{
    if (!root)
        return {0, 0};

    auto l = dfs(root->left);
    auto r = dfs(root->right);

    int sum = l.first + r.first + root->val;
    int cnt = l.second + r.second + 1;

    if (root->val == sum / cnt)
        ans++;

    return {sum, cnt};
}
int averageOfSubtree(TreeNode *root)
{
    ans = 0;
    dfs(root);
    return ans;
}


// Tree Build 
TreeNode* buildTree(vector<int> arr) {
    if (arr.empty()) return nullptr;

    vector<TreeNode*> nodes(arr.size(), nullptr);

    // create nodes (null ke liye skip)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != INT_MIN) { // INT_MIN ko null marker maan lo
            nodes[i] = new TreeNode(arr[i]);
        }
    }

    // link children
    for (int i = 0; i < arr.size(); i++) {
        if (nodes[i]) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;
            if (leftIndex < arr.size()) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < arr.size()) nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0]; // root
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& num : arr){
        cin >> num;
    }

    TreeNode* root = buildTree(arr);
    cout << averageOfSubtree(root);
    return 0;
}