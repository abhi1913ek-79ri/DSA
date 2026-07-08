#include<bits/stdc++.h>
using namespace std;
// Longest subarray with guven sum  = 0
int longestSubarray_brute(vector<int> &nums){
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum == 0) {
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    // TC = O(n^2)
    // SC = O(1)
}


// Using Prefix sum and hashmap
// map<prefixSum,pos> 
int longestSubarray_optimal(vector<int> &nums){
    int n = nums.size();
    unordered_map<int,int> hashMap;
    int maxLen = 0;
    hashMap[0] = -1;
    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum += nums[i];
        // sum - k wheher k = 0
        if(hashMap.find(sum)!=hashMap.end()){
            maxLen = max(maxLen,i-hashMap[sum]);
        }

        if(hashMap.find(sum)==hashMap.end()) hashMap[sum] = i;
    }

    return maxLen;
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

        int ans = longestSubarray_optimal(nums);
        cout << ans << endl;
    }
    
    return 0;
}