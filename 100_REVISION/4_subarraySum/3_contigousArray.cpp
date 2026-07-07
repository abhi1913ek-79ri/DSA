#include<bits/stdc++.h>
using namespace std;

// contigous subarray
// length of lonest subarray with equal number of 0,1
// brute force
int findMaxLength_brute(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    

    for (int i = 0; i < n; i++)
    {
        int cnt1s = 0;
        int cnt0s = 0;
        for(int j = i;j<n;j++){
            cnt1s += (nums[j] == 1);
            cnt0s += (nums[j] == 0);
            if(cnt1s == cnt0s) maxLen = max(maxLen,j-i+1);
        }
    }

    return maxLen;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimal
int findMaxLength_optimal(vector<int>& nums){
    int n = nums.size();
    // // preprocessing  
    // // converting 0's to -1
    // for(auto& num : nums){
    //     if(!num) num = -1;
    // }


    // prefix sum and hashmap 
    unordered_map<int,int> prefix;
    prefix[0] = -1;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ((nums[i] == 0 )? -1 :1);
        if(prefix.find(sum)!=prefix.end()){
            maxLen = max(maxLen,i - prefix[sum]);
        }

        if(prefix.find(sum) == prefix.end()) prefix[sum] = i;
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums){
            cin >> num;
        }
        cout << findMaxLength_optimal(nums) << endl;
    }
    
    return 0;
}