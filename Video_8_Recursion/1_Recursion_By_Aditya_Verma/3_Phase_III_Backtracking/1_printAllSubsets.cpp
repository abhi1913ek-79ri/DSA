#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& ip,int idx ,vector<int> op,vector<vector<int>>& ans){
    // base condition
    if(idx  == ip.size()) {
        ans.push_back(op);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[idx]);

    // Recursive Calls
    solve(ip,idx+1,op1,ans);
    solve(ip,idx+1,op2,ans);
}

// standard backtracking
void solve_standard(vector<int>& ip,int idx ,vector<int>& op,vector<vector<int>>& ans){
    // base condition
    if(idx  == ip.size()) {
        ans.push_back(op);
        return;
    }

    // push_back
    op.push_back(ip[idx]);

    // Recursive Calls
    solve_standard(ip,idx+1,op,ans);

    // pop_back
    op.pop_back();

    solve_standard(ip,idx+1,op,ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ip = nums;
    vector<int> op = {};
    solve_standard(ip,0,op,ans);
    return ans;
}

// TC = O(n*2^n)
// T(n) = 2T(n-1) + O(1)
// SC = O(n) recusive call stack
// Auxiliary Space = O(n)
// Output Space = O(n × 2^n)

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums){
            cin >> num;
        }

        vector<vector<int>> ans = subsets(nums);
        sort(ans.begin(),ans.end());
        bool flag1 = false;
        for(auto& arr : ans){
            if(flag1) cout << endl;
            bool flag = false;
            for(auto& ele : arr){
                if(flag) cout << " ";
                cout << ele;
                flag = true;
            }
            flag1 = true;
        }
    }
    
    return 0;
}

/*
Standard Solution
⭐⭐⭐⭐⭐ Logic Review
Base Condition
if(idx == ip.size()){
    ans.push_back(op);
    return;
}

✅ Perfect

Choose
op.push_back(ip[idx]);

✅ Perfect

Explore
solve_standard(ip, idx+1, op, ans);

✅ Perfect

Undo
op.pop_back();

✅ This is the heart of Backtracking.

Explore Second Choice
solve_standard(ip, idx+1, op, ans);

✅ Perfect.
*/
