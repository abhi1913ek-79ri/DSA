#include<bits/stdc++.h>
using namespace std;
// LC : 3727. Maximum Alternating Sum of Squares
// ALGORITHM
// map every ele in nums to abs(ele)
// sort them 
// subtract left half ele squres
// add right half ele sqaures

int solve(vector<int>& nums){
    int n = nums.size();

    for(auto& num : nums){
        num = abs(num);
    }

    sort(nums.begin(),nums.end());
    long long sum = 0;
    for(int i =0;i<n;i++){
        if(i < n/2){
            sum -= nums[i]*nums[i];
        }else{
            sum += nums[i]*nums[i];
        }
    }
    return sum;
    // TC = O(nlogn)
    // SC = O(1)
}   

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    cout << solve(nums);
    return 0;
}