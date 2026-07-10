#include<bits/stdc++.h>
using namespace std;
// Binary Subarrays With Sum
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum == goal) cnt++;
        }
    }

    return cnt;
    // TC = O(n^2)
    // SC = O(1)
}

// Better : hashMap and prefix sum 
int numSubarraysWithSum_better(vector<int>& nums, int goal){
    int n = nums.size();
    int cnt =0;
    unordered_map<int,int> sumFreq;
    sumFreq[0] = 1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += nums[i];
        int target = sum - goal;
        if(sumFreq.find(target)!=sumFreq.end()){
            cnt += sumFreq[target];
        }
        // <sum , freq> store karta hain hashmap
        sumFreq[sum]++;
    }

    return cnt;
    // TC = O(n)
    // SC = O(n)
}


// optimal : sliding window atmost pattern
// only positive elements
// This function returns number of subarray sum with atmost goal 
int atMostGoal(vector<int>& nums,int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int cnt = 0;

    int l = 0;

    int sum = 0;
    for(int r = 0;r<n;r++){
        sum += nums[r];
        while(sum > goal && l<=r){
            sum -= nums[l];
            l++;
        }
        cnt +=(r-l+1);
    }

    return cnt;
    // Tc = O(n)
    // SC = O(1)
}


// 
int numSubarraysWithSum_optimal(vector<int>& nums, int goal){
    return atMostGoal(nums,goal) - atMostGoal(nums,goal-1);
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

        int goal;
        cin >> goal;

        cout << numSubarraysWithSum_optimal(nums,goal)<<endl;
    }
    
    return 0;
}