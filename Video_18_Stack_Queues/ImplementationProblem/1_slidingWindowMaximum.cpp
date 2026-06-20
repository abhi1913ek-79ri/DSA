#include<bits/stdc++.h>
using namespace std;
// brute force
vector<int> maxSlidingWindow_brute(vector<int>& nums, int k){
    vector<int> ans;
    for(int i= 0;i<=nums.size()-k;i++){
        int maxi = nums[i];
        for (int j = i+1; j <= i+k-1 ; j++)
        {
            maxi = max(maxi,nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
    // TC  = O((n-k)*k)
    // SC = O(n-k)
}

// sliding Window maximum - optimal
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(!dq.empty() && dq.front() <= i-k){ // size bada ho gyaa
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i])
        { // decreasing q maintain karna hai
            dq.pop_back();
        }

        dq.push_back(i);

        if(i>=k-1) ans.push_back(nums[dq.front()]);
        
    }

    return ans;
    // TC = O(n) + O(n)
    // SC = O(k) + O(n-k)
    
}

void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums) cout << num << " ";
    cout << "]\n";
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow_brute(nums,k);
    cout << "Max sliding window : ";
    printArray(ans);
    return 0;
}