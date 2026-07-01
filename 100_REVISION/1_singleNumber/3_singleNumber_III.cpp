#include<bits/stdc++.h>
using namespace std;
// 260. Single Number III

vector<int> singleNumber_II_brute(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    for(auto& num : nums){
        int cnt = 0;
        for(auto& num2:nums){
            if(num==num2) cnt++;
        }
        if(cnt==1) ans.push_back(num);
    }
    return ans;
    // TC = O(n^2)
    // SC = O(2) - for ans
}

vector<int> singleNumber_II_better(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    unordered_map<int,int> freq;
    for(auto& num : nums){
        freq[num]++;
    }

    for(auto& num : nums){
        if(freq[num] == 1) ans.push_back(num);
    }
    
    return ans;
    // TC = O(n)
    // SC = O(n) for -  , hashmap
}

vector<int> singleNumber_III_optimal(vector<int>& nums){
    int n  = nums.size();
    int xorAll = 0;
    for(auto& num : nums){
        xorAll ^= num;
    }

    // find rightmost set bit so that we can do partion based on that 
    unsigned int mask = (unsigned int)xorAll & (-(unsigned int)xorAll); // used for filteration or check bit 

    int a = 0;
    int b = 0;
    for(auto& num : nums){
        if(mask&num) b^=num;
        else a^=num;
    }

    return {a,b};
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
        for (auto &num : nums)
        {
            cin >> num;
        }

        vector<int> ans = singleNumber_III_optimal(nums);
        sort(ans.begin(),ans.end());
        for(auto& num : ans){
            cout << num << " ";
        }
        cout<<"\n";
    }

    return 0;
}
