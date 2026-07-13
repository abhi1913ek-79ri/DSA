#include<bits/stdc++.h>
using namespace std;
// Subset II 
// All subset / unique subset
void solve(vector<int>& ip,int idx,vector<int>& op,vector<vector<int>>& ans){
    // base condition
    if(idx == ip.size()){
        ans.push_back(op);
        return;
    }

    op.push_back(ip[idx]);
    solve(ip,idx+1,op,ans);
    op.pop_back();
    solve(ip,idx+1,op,ans);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end()); // need for map -> approach
    vector<int> ip = nums;
    vector<int> op = {};
    vector<vector<int>> powerSet;
    solve(ip,0,op,powerSet);

    map<vector<int>,int> mpp;
    for(auto& sub : powerSet){
        mpp[sub]++;
    }

    vector<vector<int>> ans1;
    for(auto& p : mpp){
        ans1.push_back(p.first);
    }

    return ans1;
}

// standard pattern
// Duplicate branch ko same recursion level par skip karte hain.
void solve_standard(vector<int>& ip,int idx,vector<int>& op,vector<vector<int>>& ans){
    ans.push_back(op);
    for(int i = idx ; i < ip.size();i++){
        if(i>idx && ip[i] == ip [i-1]) continue;
        op.push_back(ip[i]);
        solve_standard(ip,i+1,op,ans);
        op.pop_back();
    }
}
vector<vector<int>> subsetsWithDup_standard(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end()); // need for map -> approach
    vector<int> ip = nums;
    vector<int> op = {};
    vector<vector<int>> powerSet;
    solve_standard(ip,0,op,powerSet);
    return powerSet;
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

        vector<vector<int>> ans = subsetsWithDup_standard(nums);
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