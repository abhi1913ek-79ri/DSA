#include<bits/stdc++.h>
using namespace std;
// LC : 3644. Maximum K to Sort a Permutation
int solve(vector<int>& nums){
    int n = nums.size();

    int K = -1;

    for(int i=0;i<n;i++){
        if(nums[i]!=i){
            K &= nums[i];
        }
    }

    return K == -1 ? 0 : K;
    //  TC = O(N)
    //  SC = O(1)
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    cout << solve(nums);
    return 0;
}