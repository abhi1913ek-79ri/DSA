#include<bits/stdc++.h>
using namespace std;
// Approach - 1 
// SC = O(n)
// TC = O(n)
// visited array
// fixed that : ans lie between 1 to n+1
// in nums array we only interest in 0<num<=n
int firstMissingPositive(vector<int>& nums){
    vector<bool> visited(nums.size()+1,false);

    for(auto num : nums){
        if(num > 0 && num<=nums.size()){
            visited[num]=true;
        }
    }

    for(int i = 1;i<=nums.size();i++){
        if(!visited[i]) return i;
    }

    return nums.size()+1;
    // TC = O(n)
    // SC = O(n)
}

// Optiomal Approach is : using the same array for above things 
// Array Manipulation , index placement , cycle sort
// ALGORITHM
// check for containing 1 or not
// if not - return 1;
// else:
// make all out of bound nums = 1;
// iterate through array num and mark index as negative - visited in same array at num-1 index
// re iterate and found first non-negative and return its index+1;
int firstMissingPositive2(vector<int>& nums){
    // check for 1
    bool isContain1 = false;
    for(auto num : nums){
        if(num==1) isContain1 = true;
    }

    if(!isContain1) return 1;

    // make all out of bound numbers to 1
    // 1 <= num <= n
    int n = nums.size();
    for(int i =0;i<n;i++){
        if(nums[i]<=0 || nums[i]>n) nums[i]=1;
    }

    // mark visited as negative -- index placement
    for(int i= 0;i<n;i++){
        int idx = abs(nums[i])-1;
        if(nums[idx]>0){
            nums[idx] = -1*nums[idx];
        }
    }

    for(int i = 0;i<n;i++){
        if(nums[i]>0){
            return i+1;
        }
    }
    return n+1;
    // TC = O(n)
    // SC = O(1)
}


int main(){
    vector<int> nums1 = {1,2,0}; // 3
    vector<int> nums2 = {3,4,-1,1}; // 2
    vector<int> nums3 = {7,8,9,11,12}; // 1

    cout << "First Missing Positive : " << firstMissingPositive2(nums1)<<endl;
    cout << "First Missing Positive : " << firstMissingPositive2(nums2)<<endl;
    cout << "First Missing Positive : " << firstMissingPositive2(nums3)<<endl;

    return 0;
}


// --------------------------------------------------------------------------

// // wrong assumption
// class Solution {
// public:
// // First Missing positive
// int smalPosNum(vector<int>& nums){
//     int spi = INT_MAX;
//     for(auto num : nums){
//         if(num > 0){
//             spi = min(spi,num);
//         }
//     }
//     return spi;
// }

// int largePosNum(vector<int>& nums){
//     int lpi = -1;
//     for(auto num : nums){
//         if(num > 0){
//             lpi = max(lpi,num);
//         }
//     }
//     return lpi;
// }

// // find Missing num in range -- using XOR
// int xor1ToN(int n){
//     if(n==1) return 1;
//     if(n==2) return n+1;
//     if(n==3) return 0;
//     return n;
//     // TC = O(1)
// }

// int xorLR(int l,int r){
//     return xor1ToN(r)^xor1ToN(l-1);
//     // TC (1)
// }


// int findMissingNum(vector<int>& nums,int l,int r){
//     int xorlr = xorLR(l,r);
//     int xorAll = 0;
//     for(int i=0;i<nums.size();i++){
//        if(nums[i]>0){
//         xorAll^=nums[i];
//        }
//     }

//     return xorAll^xorlr;
//     // if - its give 0 means no missing number;
//     // TC = O(n)
// }
//     int firstMissingPositive(vector<int>& nums) {
//         int spi = smalPosNum(nums);
//         int lpi = largePosNum(nums);

//         if(spi>1) return 1;

//         // find missing num in range spi - lpi
//         int missing = findMissingNum(nums,spi,lpi);

//         if(!missing) return lpi+1;
//         return missing;
//     }
// };