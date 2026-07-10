#include<bits/stdc++.h>
using namespace std;
// Subarray sum divisible by k

// brute force
int subArraySum_brute(vector<int>& nums,int k){
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum%k == 0) cnt++;
        }
    }
    
    return cnt;
    // TC = O(n^2)
    // SC = O(1) 
}


// Note : 
// If two prefix sums have the same remainder when divided by k,
// then the subarray between them is divisible by k.

// Optimal : prefix Sum , hashMap , similar to subarray sum == k
// also need to handle negative remainder
// if(rem < 0) rem += k;
// hashMap[0] = 1;
int subArraySum_optimal(vector<int>& nums,int k){
    int n = nums.size();
    unordered_map<int,int> hashMap;
    // Remainder 0 has already occurred once (empty prefix).
    // This handles subarrays starting from index 0.
    hashMap[0] = 1; 
    int sum = 0;
    int cnt = 0;
    for(auto& num : nums){
        sum += num;
        int rem = sum%k;
        // negative rem handling
        if(rem < 0) rem += k;

        if(hashMap.find(rem)!=hashMap.end()){
            cnt +=hashMap[rem];
        }
        hashMap[rem]++; 
    }

    return cnt;
    // TC = O(n)
    // SC = O(n)
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n ;
        cin >> n;
        
        vector<int> nums(n);
        for(auto& num : nums){
            cin >> num;
        }

        int k;
        cin >> k;

        cout << subArraySum_optimal(nums,k) << endl;
    }
    
    return 0;
}


// ⭐ Intuition
// LC560 me
// Current Prefix - Previous Prefix = K
// Tha.
// Yaha
// (Current Prefix % K)
// =
// (Previous Prefix % K)