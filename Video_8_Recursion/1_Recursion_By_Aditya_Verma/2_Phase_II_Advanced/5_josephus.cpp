#include<bits/stdc++.h>
using namespace std;
// josephus

// Hypothesis
// j(arr,n-1,idx,k) correctly gives winner for n-1 elements

// induction
// j(arr,n,idx,k) = correctly gives winner for n elements

// Base condition
//  n == 1 return ans;
void solve(vector<int>& nums,int idx,int k, int& ans){
    // base condition
    if(nums.size() == 1){
        ans = nums[0];
        return;
    }

    // induction
    idx  = (idx + k)%(nums.size());
    nums.erase(nums.begin()+idx);
    solve(nums,idx,k,ans);
}

int findTheWinner(int n, int k) {
    vector<int> nums;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
    }
    int ans = -1;
    solve(nums,0,k-1,ans);
    return ans;
}

// TC = O(n^2)
// SC = O(n)

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        cout << findTheWinner(n, k) << '\n';
    }

    return 0;
}