#include<bits/stdc++.h>
using namespace std;
// Recursive Binary search
// divide and conquer
int binarySearchRecur(vector<int>& nums,int low,int high,int target){
    // base condition
    if(low > high) return -1;

    int mid = low + (high-low)/2;

    if(nums[mid] == target) return mid;

    if(target < nums[mid]) return binarySearchRecur(nums,low,mid-1,target);
    else return binarySearchRecur(nums,mid+1,high,target);
}


int solve(vector<int>& nums,int target){
    int n = nums.size();
    return binarySearchRecur(nums,0,n-1,target);
}


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    
    int target;
    cin >> target;

    cout << solve(nums,target);
    return 0;
}