#include<bits/stdc++.h>
using namespace std;
// Missing Number 0 to n

// brute force -- sorting approach
int missingNum1(vector<int>& nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i!=nums[i]) return i;
    }
    return nums.size();
    // TC = O(nlogn)
    // SC = O(1)
}

// Gausian Approach -- summation
int missingNum2(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for(auto num:nums){
        sum += num;
    }
    return n*(n+1)/2-sum;
    // TC = O(n)
    // SC = O(1)
}



// Bit manipulation approach -- XOR in range approach
// XOR 1 to N approach
int xor1toN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
}


// repeating xor to get missing
int missingNum3(vector<int>& nums){
    int n = nums.size();
    int ansHelper = 0;
    for(auto num : nums){
        ansHelper^=num;
    }
    return ansHelper^xor1toN(n);
    //TC = O(n)
    // SC = O(1)
}


int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int missingNum = missingNum2(nums);
    cout << "Missing num : " << missingNum<<endl;
    return 0;
}