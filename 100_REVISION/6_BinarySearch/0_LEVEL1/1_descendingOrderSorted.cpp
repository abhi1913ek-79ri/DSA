#include<bits/stdc++.h>
using namespace std;
// Basic Pattern Binary Search
// retutn idx if found else return -1 indicates not found
int binarySearch(vector<int>& nums,int target){
    int n = nums.size();

    int l = 0;
    int h = n-1;

    while (l <= h)
    {
        int mid = l + (h-l)/2;

        if(target == nums[mid]) return mid;
        else if(target < nums[mid]) l = mid+1;
        else h = mid-1;
    }
    
    return -1;
    // TC = O(logn)
    // SC = O(1)
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

    cout << binarySearch(nums,target);
    return 0;
}