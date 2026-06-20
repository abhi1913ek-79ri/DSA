#include<bits/stdc++.h>
using namespace std;
// Subarrays with K Different Integers
// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
int subarraysWithKDistinct_brute(vector<int>& nums, int k){
    int n = nums.size();

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        set<int> st = {};
        for (int j = i; j < n; j++)
        {
            st.emplace(nums[j]);
            if(st.size()==k) cnt++;
            if(st.size()>k) break;
        }
    }
    return cnt;
    // TC = O(n*n)
    // SC = O(n)
}
// Optimal : approach
// Sliding window atmost trick (exactly k conditon)
int atMost(vector<int>& nums, int k){
    int n = nums.size();
    int cnt = 0;

    int l=0;
    unordered_map<int,int> freq;
    for(int r = 0; r < n; r++)
    {
        freq[nums[r]]++;
        while (freq.size() > k)
        {
            freq[nums[l]]--;
            if(freq[nums[l]] == 0) freq.erase(nums[l]);
            l++;
        }
        cnt += r-l+1;
    }
    return cnt;
    // TC = O(n)
    // SC = O(n)
}

int subarraysWithKDistinct_optimal(vector<int>& nums, int k){
    return atMost(nums,k) - atMost(nums,k-1);
}

int main(){
    vector<int> nums1 = {1,2,1,2,3}; // 7
    int k1 = 2;
    vector<int> nums2 = {1,2,1,3,4}; // 3
    int k2 = 3;
    cout << "Number of good Subarrays : " << subarraysWithKDistinct_brute(nums1,k1) << endl;
    cout << "Number of good Subarrays : " << subarraysWithKDistinct_brute(nums2,k2) << endl;
    cout << "Number of good Subarrays : " << subarraysWithKDistinct_optimal(nums1,k1) << endl;
    cout << "Number of good Subarrays : " << subarraysWithKDistinct_optimal(nums2,k2) << endl;
    return 0;
}