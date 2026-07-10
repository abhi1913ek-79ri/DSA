#include<bits/stdc++.h>
using namespace std;
// LC - 523 - Continuous Subarray Sum

// brute
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum%k == 0) {
                if((j-i+1)>=2) return  true;
            }
        }
    }

    return false;
    // TC = O(n^2)
    // SC = O(1)
}
// Optimal : prefix sum , hashmap<rem,position> - to track valid subarray, length
// negaive remainder hadling
bool checkSubarraySum_optimal(vector<int>& nums, int k){
    int n = nums.size();

    unordered_map<int,int> remFirstIdx;
    remFirstIdx[0] = -1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += nums[i];
        int rem = sum%k;
        if(rem<0) rem+=k;
        
        if(remFirstIdx.find(rem)!=remFirstIdx.end()){
            int len = i - remFirstIdx[rem];
            if(len >= 2) return true;
        }else{
            remFirstIdx[rem] = i;
        }
    }
    return false;
    // TC = O(n)
    // SC = O(n)
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

        int k;
        cin >> k;

        cout << checkSubarraySum_optimal(nums,k) << endl;
    }
    
    return 0;
}