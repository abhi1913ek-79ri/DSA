#include<bits/stdc++.h>
using namespace std;
// Min sum subarray

// Brute
int minSumSubArray_brute(vector<int>& nums){
    int n = nums.size();

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum  = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            mini = min(mini,sum);
        } 
    }
    return mini;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimal :
// min kadane
int minSumSubarray_optimal(vector<int>& nums){
    int mini = INT_MAX;
    
    int sum = 0;
    for(auto& num : nums){
        sum += num;
        mini = min(mini,sum);
        if(sum > 0) sum = 0;
    }

    return mini;
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
        for (auto& num : nums){
            cin >> num;
        }
        
        cout << minSumSubArray_brute(nums) << endl;
    }
    
    return 0;
}