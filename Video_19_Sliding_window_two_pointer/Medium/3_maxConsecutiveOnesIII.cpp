#include <bits/stdc++.h>
using namespace std;
// Max Consecutive Ones III-or loneget subarray with atmost k zeroes

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6

// Bruteforce
int longestOnes_brute(vector<int> &nums, int k)
{
    int n = nums.size();

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt0 = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                cnt0++;
            if (cnt0 <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }else{
                break;
            }
        }
    }
    return maxLen;
    // TC = O(n*n)
    // SC = O(1)
}

// Optimal Using Sliding window
int longestOnes_optimal(vector<int> &nums, int k){
    int n = nums.size();

    int l = 0;
    int cnt0 = 0;
    int maxLen = 0;
    for(int r = 0;r<n;r++){
        if(nums[r]==0) cnt0++;
        while (cnt0>k&&l<=r)
        {
            if(nums[l]==0) cnt0--;
            l++;
        }
        maxLen = max(maxLen,r-l+1);
    }
    return maxLen;
    // TC = O(n)
    // SC = O(1)
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Max consicutive one's : " << longestOnes_optimal(nums,k) << endl;

    return 0;
}