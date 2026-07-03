#include<bits/stdc++.h>
using namespace std;
/*18. 4Sum Medium
Given an array nums of n integers, return an array of all 
the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

// Brute Force
vector<vector<int>> fourSum_brute(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                for (int l = k+1; l < n; l++)
                {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == 1LL*target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
                
            }
            
        }
        
    }
    return vector<vector<int>>(ans.begin(),ans.end());
    // TC = O(n^4*logM)
    // SC = O(M)
}

// Better
vector<vector<int>> fourSum_better(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++){
            unordered_set<int> seen;
            for(int k = j+1;k<n;k++){
                long long required = (long long)target - nums[i]-nums[j]-nums[k];
                if(required >= INT_MIN &&
   required <= INT_MAX && seen.count(required)){
                    vector<int> temp = {nums[i],nums[j],nums[k],(int)required};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp); // logM
                }
                seen.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(ans.begin(),ans.end());
    // TC = O(n^3*logm);
    // SC = (number of quad)*2
}


// Optimal : Sorting , two pointer
vector<vector<int>> fourSum_optimal(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1;j<n;j++){
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = 1LL * nums[i]+nums[j]+nums[k]+nums[l];
                if(sum < 1LL*target) k++;
                else if(sum > 1LL*target) l--;
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }

    return ans;
    // TC = O(n^3+nlogn)
    // SC = O(n) - for ans
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

        vector<vector<int>> ans = fourSum_optimal(nums,target);
        sort(ans.begin(),ans.end());
        for(auto& arr : ans){
            cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
        }
    }
    return 0;
}