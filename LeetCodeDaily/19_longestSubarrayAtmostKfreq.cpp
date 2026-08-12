#include<bits/stdc++.h>
using namespace std;
// 2958. Length of Longest Subarray With at Most K Frequency
int maxSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int,int> freq;

    int l = 0;
    int maxLen = 1;
    for(int r=0;r<n;r++){
        freq[nums[r]]++;
        while (l<=r && freq[nums[r]] > k)
        {
            freq[nums[l++]]--;
        }

        maxLen = max(maxLen,r-l+1);
    }

    return maxLen;
    // TC = O(n)
    // SC = O(n)
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    int k;
    cin >> k;

    cout << maxSubarrayLength(nums,k);
    return 0;
}