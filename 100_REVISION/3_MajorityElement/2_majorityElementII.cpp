#include<bits/stdc++.h>
using namespace std;
// 2. Majority Element II (LeetCode 229)
// Problem: Return all elements appearing more than n/3 times.
// Observation: At most TWO elements can appear more than n/3 times.

// Brute  - nested loops
vector<int> majorityElement_brute(vector<int>& nums){
    int n = nums.size();
    unordered_set<int> ans;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(nums[i] == nums[j]) cnt++;
        }
        if(cnt>(n/3)) ans.insert(nums[i]);
    }
    return vector<int>(ans.begin(),ans.end());
    // TC = O(n^2)
    // SC = O(1)
}

// Better : hashMap
vector<int> majorityElement_better(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    unordered_map<int,int> freq;
    for(auto& num : nums){
        freq[num]++;
    }

    for(auto& p: freq){
        if(p.second>(n/3)) ans.push_back(p.first);
    }

    return ans;
    // TC = O(2n)
    // SC = O(n)
}

// Optimal : extended moore's voting algo 
vector<int> majorityElement_optimal(vector<int>& nums){
    int n = nums.size();

    int candidate1 = INT_MIN;
    int candidate2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;

    for(auto& num : nums){
        if(cnt1 == 0 && num != candidate2){
            cnt1 = 1;
            candidate1 = num;
        }else if(cnt2 == 0 && num != candidate1){
            cnt2 = 1;
            candidate2 = num;
        }else if(num == candidate1) cnt1++;
        else if(num == candidate2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    // candidate1 and candidate2 are possible answers 
    // need to verify manually
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for(auto& num : nums){
        if(num == candidate1) cnt1++;
        if(num == candidate2) cnt2++;
    }

    int mini = (int)(n/3) +1;
    if(cnt1>=mini) ls.push_back(candidate1);
    if(cnt2>=mini) ls.push_back(candidate2);

    return ls;
    // TC = o(n)
    // SC = o(1)
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

        vector<int> ans = majorityElement_optimal(nums);
        sort(ans.begin(),ans.end());
        for(auto& num : ans){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}