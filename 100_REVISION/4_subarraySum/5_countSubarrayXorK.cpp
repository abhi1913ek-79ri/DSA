#include<bits/stdc++.h>
using namespace std;
// count subarrays with xor equal k
int countSubarrays_brute(vector<int>& nums, int k){
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int xorCurr = 0;
        for(int j = i;j<n;j++){
           xorCurr ^= nums[j];
           if(xorCurr == k) cnt++;
        }
    }

    return cnt;
    // TC = O(n^2)
    // SC = O(1)
}

// Using prefix sum 
int countSubarrays_optimal(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int> hashMap;
    hashMap[0] = 1; // empty prefix me already exist karta hai
    int xorAll = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        xorAll ^= nums[i];
        int target = xorAll^k;
        if(hashMap.find(target)!=hashMap.end()){
            cnt += hashMap[target];
        }

        hashMap[xorAll]++;
    }

    return cnt;
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
        for (auto& num : nums)
        {
            cin >> num;
        }
        int k;
        cin >> k;
        
        cout << countSubarrays_optimal(nums,k) << endl;
    }
    
    return 0;
}