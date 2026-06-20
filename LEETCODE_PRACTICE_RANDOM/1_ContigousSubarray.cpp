#include<bits/stdc++.h>
using namespace std;
// Contigous subarray
// lonegest subarray with equal number of zeoroes and ones 

// Brute Force
int findMaxLengthBrute(vector<int>& nums){
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int j = i; j < n; j++)
        {
            cnt0 += nums[j] == 0? 1 : 0;
            cnt1 += nums[j] == 1? 1 : 0;
            if(cnt1 == cnt0) maxLen = max(maxLen,j-i+1);
        }
    }
    return maxLen;
    // TC = O(n^2);
    // SC = O(1);
}


// Using prefix sum and hashmap
int findMaxLengthBetter(vector<int>& nums) {
    int n = nums.size();

    // prefix
    map<int,int> mpp;
    int maxLen = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        // 0 to i
        int val = (nums[i] == 0) ? -1 : 1;
        prefixSum += val;
        if(prefixSum == 0){
            maxLen = i+1;
        }

        // seen before
        if(mpp.find(prefixSum)!=mpp.end()){
            maxLen = max(maxLen,i-mpp[prefixSum]);
        }else{
            mpp[prefixSum] = i;
        }
    }
    return maxLen;
    // TC = O(n)
    // SC = O(n)
}

int main(){
    vector<int> nums1 = {0,1,1,1,1,1,0,0,0}; // 6
    vector<int> nums2 = {0,1}; // 2
    vector<int> nums3 = {0,1,0}; // 2
    cout << "Max Countigous array len : " << findMaxLengthBrute(nums1)<<endl;
    cout << "Max Countigous array len : " << findMaxLengthBrute(nums2)<<endl;
    cout << "Max Countigous array len : " << findMaxLengthBrute(nums3)<<endl;
    cout << "Max Countigous array len : " << findMaxLengthBetter(nums1)<<endl;
    cout << "Max Countigous array len : " << findMaxLengthBetter(nums2)<<endl;
    cout << "Max Countigous array len : " << findMaxLengthBetter(nums3)<<endl;
    return 0;
}

// count ke liye 
// always cnt store karte hain map me 
// isme maxlen  ya len chahiye thi isliye isme position store kiya 
// map<prefix,kuch interested value> store karte hian