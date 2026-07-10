#include<bits/stdc++.h>
using namespace std;
// LC1248 : Number of Nice subarrays

// Brute 
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int numberOfOdds = 0;
        for(int j=i;j<n;j++){
            if(nums[j]&1) numberOfOdds++;

            if(numberOfOdds == k) cnt++;
        }
    }

    return cnt;
    // TC = O(n^2)
    // SC = O(1)
}

// better : hashMap ,prefix sum -(sum as number odd)
int numberOfSubarrays_better(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int> numOddFreq; // <numOdd,cnt>
    numOddFreq[0] = 1;
    int preOdds = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        preOdds += (nums[i]&1)?1:0;
        int need = preOdds - k;
        if(numOddFreq.find(need)!=numOddFreq.end()){
            cnt += numOddFreq[need];
        }

        numOddFreq[preOdds]++;
    }

    return cnt;
    // TC = O(n)
    // SC = O(n)
}

// Optimal : sliding window monotonic behaviour
int atMostKodds(vector<int>& nums,int k){
    int n = nums.size();
    int cnt = 0;
    int l = 0;

    int numOdds = 0;
    for(int r=0;r<n;r++){
        numOdds += (nums[r]&1)?1:0;

        while (l<=r && numOdds>k)
        {
            numOdds -= (nums[l]&1)?1:0;
            l++;
        }

        cnt += r-l+1;
    }

    return cnt;
    // TC = O(n)
    // SC = O(1)
}

int numberOfSubarrays_optimal(vector<int>& nums,int k){
    if(k < 0) return 0;
    return atMostKodds(nums,k) - atMostKodds(nums,k-1);
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
        for(auto& num : nums){
            cin >> num;
        }

        int k;
        cin >> k;

        cout << numberOfSubarrays_optimal(nums,k) << endl;
    }
    
    return 0;
}