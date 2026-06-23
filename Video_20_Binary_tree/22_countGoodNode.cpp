#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int maxi, int& cnt)
{
    if (root == nullptr)
        return;

    if (root->val >= maxi)
        cnt++;

    maxi = max(maxi, root->val);

    dfs(root->left, maxi, cnt);
    dfs(root->right, maxi, cnt);
    // TC = O(n)
    // SC = O(h)
}

int goodNodes(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    int cnt = 0;
    dfs(root, root->val, cnt);

    return cnt;
}

int main()
{

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << "Good Nodes : " << goodNodes(root) << endl;

    return 0;
}

// DFS - Brute Force ,  instead of passing
// reefrence passes value in recusion call of maxi parameter

// RECURSION maintains the state  of max (passed as value) in recusrsion stack memory no need to hahndle 
// mannually


// Since 'maxi' is passed by value, every recursive call gets its own copy.
// The recursion stack automatically preserves the previous value of 'maxi',
// so we don't need to manually backtrack or restore it.


// dfs(3, 3)
//     |
//     +-- dfs(1, 3)
//     |       |
//     |       +-- dfs(3, 3)
//     |
//     +-- dfs(4, 3)
//             |
//             +-- dfs(1, 4)
//             |
//             +-- dfs(5, 4)