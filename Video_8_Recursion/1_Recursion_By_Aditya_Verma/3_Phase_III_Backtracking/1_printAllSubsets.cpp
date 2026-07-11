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

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ip = nums;
    vector<int> op = {};
    solve(ip,0,op,ans);
    return ans;
}

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