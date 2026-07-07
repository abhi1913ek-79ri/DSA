#include<bits/stdc++.h>
using namespace std;
// Longest subarray with sum == k
int longestSubarraySumk(vector<int>& nums,int k){
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += nums[j];
            if(sum == k) maxLen = max(maxLen,j-i+1);
        }
    }

    return maxLen;
    // TC = O(n^2)
    // SC = O(1)
}

// better - stores first index where it is true not last
int longestSubarraySumk_better(vector<int>& nums,int k){
    int n = nums.size();
    int maxLen = 0;
    unordered_map<int,int> prefix;
    prefix[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(prefix.find(sum-k)!=prefix.end()){
            maxLen = max(maxLen,i - prefix[sum - k]);
        }
        if(prefix.find(sum) == prefix.end()) prefix[sum] =i;
    }

    return maxLen;
    // TC = O(n)
    // SC = O(n)
}

// Optimal : work only for if array contains onyl positive 

int longestSubarraySumk_optimal(vector<int>& nums,int k){
    int n = nums.size();
    int maxLen = 0;
    int l = 0;
    int r = 0;

    int sum = 0;
    while(r<n){
        sum += nums[r];
        while (l<=r && sum >k)
        {
            sum -= nums[l++];
        }
        if(sum == k) maxLen = max(maxLen,r-l+1);
        r++;
    }

    return maxLen;
    // TC = O(n)
    // SC = O(1)
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int k;
        cin >> k;

        cout << longestSubarraySumk_optimal(nums,k) << endl;
    }
    return 0;
}