#include<bits/stdc++.h>
using namespace std;
// 137. Single Number II

// important Note
/*
Ek important interview point ⚠️
Agar question me negative numbers bhi ho sakte hain 
(LeetCode 137 me ho sakte hain),
to ye code C++ me generally sahi work karta hai because int is
32-bit and tum saare 32 bits reconstruct kar rahe ho, including
the sign bit.
*/

int singleNumber_II_brute(vector<int>& nums){
    int n = nums.size();

    for(auto& num : nums){
        int cnt = 0;
        for(auto& num2:nums){
            if(num==num2) cnt++;
        }
        if(cnt==1) return num;
    }
    return -1;
    // TC = O(n^2)
    // SC = O(1)
}

int singleNumber_II_better(vector<int>& nums){
    int n = nums.size();

    unordered_map<int,int> freq;
    for(auto& num : nums){
        freq[num]++;
    }

    for(auto& num : nums){
        if(freq[num] == 1) return num;
    }
    
    return -1;
    // TC = O(n)
    // SC = O(n)
}

int singleNumber_II_optimal(vector<int>& nums){
    int n = nums.size();
    int ans = 0; // ith bit ko set karte rahenge 
    for(int i= 0;i<32;i++){
        int cnt = 0;
        for(auto& num:nums){
            if((num>>i)&1) cnt++;
        }

        if(cnt%3!=0) ans = ans | (1<<i); // setting i th bit
    }
    return ans;
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

        cout << singleNumber_II_optimal(nums) << "\n";
    }

    return 0;
}

// Solved
// Medium
// Topics

// Given an integer array nums where every element appears three
//  times except for one, which appears exactly once. Find the single 
// element and return it.

// You must implement a solution with a linear 
// runtime complexity and use only constant extra space.

/*
Single Number II (LC 137)
Every element appears three times except one.
Brute Force
Intuition: Count every element.
Algorithm:
Nested loops.
Return frequency 1.
Time: O(n^2) Space: O(1)
Code:
// same brute counting
Better (Hash Map)
Intuition: Frequency map.
Algorithm:
Store counts.
Return freq==1.
Time: O(n) Space: O(n)
Code:
unordered_map<int,int> mp; for(int x:nums) mp[x]++;
Optimal (Bit Counting)
Intuition: Bits of triplicates contribute multiples of 3.






Algorithm:
For each bit 0..31 count set bits.
If count%3!=0 set bit in answer.
Time: O(32*n)=O(n) Space: O(1)
Code:
int ans=0; /--- baad me set kar karke number aa jayega 
for(int b=0;b<32;b++){
int c=0;
for(int x:nums) if((x>>b)&1) c++;
if(c%3) ans|=(1<<b); // setting bit
}
return ans;

*/