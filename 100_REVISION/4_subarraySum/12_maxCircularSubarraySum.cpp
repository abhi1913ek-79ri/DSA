#include<bits/stdc++.h>
using namespace std;
// LC918
// Maximum Sum Circular Subarray
// ALGORITHM
// Two Cases:
// if ( all are negatives) - normal kadane ka max hi answer hoga
// else :
// maxKadane
// totalSum.
// minKadane
// max(maxKadane,totalSum - minKadane)
int sumTotal(vector<int>& nums){
    int sum = 0;
    for(auto& num : nums) sum+=num;
    return sum;
    // TC = O(n)
    // SC = O(1)
}

int minKadane(vector<int>& nums){
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

int maxKadane(vector<int>& nums){
    int maxi = INT_MIN;
    int sum = 0;
    for(auto& num : nums){
        sum += num;
        maxi = max(maxi,sum);
        if(sum < 0) sum = 0;
    }
    return maxi;
    // TC = O(n)
    // SC = O(1)
}

bool isAllElementNeg(vector<int>& nums){
    for(auto& num : nums){
        if(num>0) return false;
    }
    return true;
}

int maxSubarraySumCircular(vector<int>& nums) {
    if(isAllElementNeg(nums)){
        return maxKadane(nums);
    }
    return max(maxKadane(nums),sumTotal(nums)-minKadane(nums));
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
        for (auto& num : nums)
        {
            cin >> num;
        }
        cout << maxSubarraySumCircular(nums) << endl;
    }
    
    return 0;
}

/*
Case 1
Normal Maximum
↓
Kadane
Case 2
Circular Maximum
↓
Total Sum
-
Minimum Subarray
Edge Case
All Negative
↓
\
Return Normal Kadane
*/