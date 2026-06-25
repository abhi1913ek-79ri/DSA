#include<bits/stdc++.h>
using namespace std;
// countMajoritySubarrays

// optimal
// Boyer–Moore Voting Algorithm
int countMajoritySubarrays_brute(vector<int>& nums, int target) {
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int freq = 0;
        for (int j = i; j < n; j++)
        {
            if(nums[j]==target){
                freq++;
            }else{
                freq--;
            }
            if(freq >= 1) cnt++;
        }
    }

    return cnt;
    // TC = O(n*n)
    // SC = O(1)
}

int main(){
    vector<int>  nums = {1,2,3};
    int target = 3;
    cout << countMajoritySubarrays_brute(nums,target);
    return 0;
}