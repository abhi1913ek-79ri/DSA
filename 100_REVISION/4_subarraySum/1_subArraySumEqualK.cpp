#include<bits/stdc++.h>
using namespace std;
// Subarray sum equal to k

// Brute Force : trying out all subarray
int subarraySum_brute(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum == k ) cnt++;
        }
    }
    return cnt;
    // TC = O(n^2)
    // SC = O(1)
}

// Optimal/better -(any integer,only positives): prefix sum and hashMap
int subarraySum_optimal(vector<int>& nums,int k){
    int n = nums.size();
    unordered_map<int,int> prefix;
    // prefix[sum] = frequency
    // Frequency batati hai ki ye prefix sum ab tak kitni baar aaya hai.
    // Agar currentSum - k pehle x baar mila hai,
    // to current index par x naye subarrays milenge jinka sum = k hoga.
    prefix[0] = 1;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(prefix.find(sum-k)!=prefix.end()){
            cnt+=prefix[sum-k];
        }
        prefix[sum]++; 
    }

    return cnt;
    // TC = O(n)
    // SC = O(n)
}


// Optimal : only positive - slinding window variable size
// Optimal : work only for if array contains onyl positive 
// First find for atmost k 
int numSubarraySumAtMostk(vector<int>& nums,int k){
    if(!nums.size()) return 0;
    if(k<0) return 0;
    int n = nums.size();
    
    int l = 0;
    int r = 0;

    int sum = 0;
    int cnt = 0;
    while (r<n)
    {
       
        sum += nums[r];
        while(l<=r && sum >k){
            sum -= nums[l];
            l++;
        }
        // cnt++; wrong -- all karke hain sirf ek nhi
        cnt += r-l+1;
        r++;
    }
    return cnt;
    // TC = O(n)
    // SC = O(1)
}

int numSubarraySumk(vector<int>& nums,int k){
    return numSubarraySumAtMostk(nums,k) - numSubarraySumAtMostk(nums,k-1);
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
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int k;
        cin >> k;

        cout << numSubarraySumk(nums,k) << endl;
    }
    
    return 0;
}