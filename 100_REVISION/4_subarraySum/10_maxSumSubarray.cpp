#include<bits/stdc++.h>
using namespace std;
// maxSumSubarray

// Brute : cal. sum of all subarray
int maxSubArray_brute(vector<int>& nums) {
    int n = nums.size();

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum  = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxSum = max(maxSum,sum); // accumulating maximum
        }
    }
    return maxSum;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimal : kadane's algorithm
// running sum 
// reset if sum < 0
// before reset store maximum
int maxSubArray_optimal(vector<int>& nums){
    int maxi = INT_MIN;
    int sum = 0;
    for(auto& num:nums){
        sum += num;
        maxi = max(maxi,sum);
        if(sum<0) sum = 0;
    }

    return maxi;
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

        cout << maxSubArray_optimal(nums) <<endl;
    }
    
    return 0;
}