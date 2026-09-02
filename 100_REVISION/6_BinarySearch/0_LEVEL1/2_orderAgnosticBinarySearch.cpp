#include<bits/stdc++.h>
using namespace std;
// bs asc
int binarySearchAsc(vector<int>& nums,int target){
    int n = nums.size();

    int l = 0;
    int h = n-1;

    while (l <= h)
    {
        int mid = l + (h-l)/2;

        if(target == nums[mid]) return mid;
        else if(target > nums[mid]) l = mid+1;
        else h = mid-1;
    }
    
    return -1;
    // TC = O(logn)
    // SC = O(1)
}


// bs desc
int binarySearchDesc(vector<int>& nums,int target){
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




// Order agnostic binary search
int orderAgnosticBinarySearch(vector<int>& nums,int target){
    int n = nums.size();
    if(n == 0) return -1;

    bool isAsc = nums[0] < nums[n-1];
    
    if(isAsc){
        return binarySearchAsc(nums,target);
    }
    return binarySearchDesc(nums,target);
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

    cout << orderAgnosticBinarySearch(nums,target);
    return 0;
}