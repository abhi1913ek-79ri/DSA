#include<bits/stdc++.h>
using namespace std;
// Minimum size subarray sum
// sliding window
int minSubArrayLen(int target,vector<int>& nums){
    int n = nums.size();
    int minLen = nums.size()+1;
    int l = 0;
    int sum = 0;
    for(int r = 0;r<n;r++){
        sum += nums[r];
        while (sum >= target && l<=r)
        {
            minLen = min(minLen,r-l+1);
            sum -= nums[l];
            l++;
        }
    }

    return (minLen == n + 1) ? 0 : minLen;
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
        for(auto& num : nums){
            cin >> num;
        }
        int target;
        cin >> target;

        cout << minSubArrayLen(target,nums) << endl;
    }
    
    return 0;
}