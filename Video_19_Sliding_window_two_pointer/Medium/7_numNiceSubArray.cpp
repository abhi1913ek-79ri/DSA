#include<bits/stdc++.h>
using namespace std;
// Count Number of Nice Subarrays : subarray with exact k = odd nums
int numberOfSubarrays_brute1(vector<int>& nums, int k){
    int n = nums.size();

    int cntNice = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cntOdd = 0;
            for (int k = i; k <= j; k++)
            {
                if(nums[k]&1) cntOdd++;
            }
            if(cntOdd==k) cntNice++;
        }
    }
    return cntNice;
    // TC  = O(n*n*n)
    // SC = O(1)
}

// Brute 2
int numberOfSubarrays_brute2(vector<int>& nums, int k){
    int n = nums.size();

    int cntNice = 0;

    for (int i = 0; i < n; i++)
    {
        int cntOdd = 0;
        for (int j = i; j < n; j++)
        {
            if(nums[j]&1) cntOdd++;
            if(cntOdd==k) cntNice++;
        }
    }
    return cntNice;
    // TC  = O(n*n)
    // SC = O(1)
}

// Optimal 1 sliding window 2 ptr
int atmostKOddSubarrays(vector<int>& nums, int k){
    int n = nums.size();

    int cnt = 0;

    int l = 0;

    int cntOdd = 0;
    for (int r = 0; r < n; r++)
    {
        if(nums[r]&1) cntOdd++;
        while (cntOdd > k)
        {
            if(nums[l]&1) cntOdd--;
            l++;
        }
        cnt += r-l+1;
    }
    return  cnt;
    // TC = O(n+n)
    // SC = O(1)
}


int numberOfSubarrays_Optimal(vector<int>& nums, int k){
    return atmostKOddSubarrays(nums,k) - atmostKOddSubarrays(nums,k-1);
}

int main(){
    vector<int> nums1 = {2,4,6};int k1 = 1; // 0
    vector<int> nums2 = {1,1,2,1,1};int k2 = 3; // 2
    cout <<"Nice subarrays : " << numberOfSubarrays_brute1(nums1,k1) << "\n";
    cout <<"Nice subarrays : " << numberOfSubarrays_brute1(nums2,k2) << "\n";
    cout <<"Nice subarrays : " << numberOfSubarrays_brute2(nums1,k1) << "\n";
    cout <<"Nice subarrays : " << numberOfSubarrays_brute2(nums2,k2) << "\n";
    cout <<"Nice subarrays : " << numberOfSubarrays_Optimal(nums1,k1) << "\n";
    cout <<"Nice subarrays : " << numberOfSubarrays_Optimal(nums2,k2) << "\n";
    return 0;
}