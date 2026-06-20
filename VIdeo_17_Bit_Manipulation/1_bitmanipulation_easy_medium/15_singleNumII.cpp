#include<bits/stdc++.h>
using namespace std;
// single numbetr -- Thrice 

// brute force - two loops
int singleNum1(vector<int>& nums){
    for(auto num1: nums){
        int cnt = 0;
        for(auto num2:nums){
            if(num1==num2) cnt++;
        }
        if(cnt<2) return num1;
    }

    return -1;
    // TC = O(n²)
    // SC = O(1)
}

// Better -- using HashMap
int singleNum2(vector<int>& nums){
    unordered_map<int,int> mp;

    // count freq
    for(auto num:nums){
        mp[num]++;
    }

    // checking occurence
    for(auto num:nums){
        if(mp[num]<2) return num;
    }

    return -1;
    // TC = O(n)
    // SC = O(1)
}

// Bit manipulation technique - XOR technique
// Observation --
// if(bits inn numbers repeeat 3 times in at a bitindex then  it its note taken in  answer)
// {1,1,2,1}
//  2 1 0
//  0 0 1 - 1
//  0 0 1 - 1
//  0 1 0 - 2
//  0 0 1 - 1
//  0 1 4
//  3's not 3's not 3's 
int singleNum3(vector<int>& nums){
    int ans = 0;
    for(int bi = 0;bi<32;bi++){
        int cnt = 0;
        for(auto num:nums){
            if(num & (1<<bi)){
                cnt++;
            }
        }
        if(cnt%3 != 0) ans = ans | (1<<bi);
    }

    return ans;
    // TC = O(32*n)
    // SC = O(1)
}






int main(){
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << "Single num - II : " << singleNum3(nums) <<endl;
    return 0;
}