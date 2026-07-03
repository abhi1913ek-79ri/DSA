#include<bits/stdc++.h>
using namespace std;

// brute
vector<int> twoSum_brute(vector<int>& nums,int target){
    int n = nums.size();
    
    for(int i=0;i<n;i++){
        int a = nums[i];
        for (int j = i+1; j < n; j++)
        {
            int b = nums[j];
            int sum = a+b;
            if(sum == target) return {i,j};
        }
    }

    return {};
    // TC = O(n^2)
    // SC = O(1)
}


 
// Optimal : hashMap two pointers work nhi karega kyunki index mang ra hain
vector<int> twoSum_optimal(vector<int>& nums,int target){
    int n = nums.size();
    unordered_map<int,int> mpp;
    int i = 0;
    for(auto& num : nums){
        int need = target-num;
        if(mpp.find(need)!=mpp.end()) return {mpp[need],i};
        mpp[num] = i;
        i++;
    }

    return {};
    // TC = O(n) - average
    // SC = O(n)
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto& num : nums){
            cin >> num;
        }

        int target;
        cin >> target;

        vector<int> ans = twoSum_optimal(nums,target);
        sort(ans.begin(),ans.end());
        cout << ans[0] << " " << ans[1] <<endl;

    }
    return 0;
}