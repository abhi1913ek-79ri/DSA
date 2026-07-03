#include<bits/stdc++.h>
using namespace std;

/* 1. Majority Element (LeetCode 169)
Problem: Find the element occurring more than n/2 times.
Example:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

// Brute  - nested loops
// know that there is only one element whose freq > n/2
int majorityElement_brute(vector<int>& nums){
    int n = nums.size();

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(nums[i] == nums[j]) cnt++;
        }
        if(cnt>n/2) return nums[i];
    }

    return 0;
    // TC = O(n^2)
    // SC = O(1)
}


// Better - hashmap
int majorityElement_better(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>(n/2)) return nums[i];
    }

    return 0;
    // TC = O(n)
    // SC = O(n) - hashmap
}


// Optimal : Moore's Voting Algorithm
// Idea: Maintain a candidate and a counter.
int majorityElement_optimal(vector<int>& nums){
    int n = nums.size();
    int candidate = -1;
    int cnt = 0;

    for(auto& num : nums){
        if(cnt == 0){
            candidate = num;
        }

        if(num == candidate) cnt++;
        else cnt--;
    }

    return candidate;
    // TC = O(n)
    // SC = O(1)
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

        int ans = majorityElement_optimal(nums);
        cout << ans << endl;
    }
    return 0;
}


// Optimal : Moore's Voting Algorithm
// Idea:
// Maintain a candidate and a counter.
// Whenever count becomes zero, choose the current element as the new candidate.
// Increase the count if the current element equals the candidate, otherwise decrease it.
// The final candidate is the majority element (problem guarantees existence).
// Pseudo Steps:
// • candidate = -1, count = 0
// • For every element:
//   - if count == 0 → candidate = current element
//   - if current == candidate → count++
//   - else → count--
// Time Complexity: O(n)
// Space Complexity: O(1)