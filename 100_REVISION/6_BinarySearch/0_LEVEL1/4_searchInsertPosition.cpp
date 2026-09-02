#include<bits/stdc++.h>
using namespace std;
// Search insert position
int linearSearchInsertPos(vector<int>& nums,int target){
    int n = nums.size();
    if(n == 0) return 0;

    int sip = n;
    for(int i= 0;i<n;i++){
        int curr = nums[i];
        if (curr == target) return i;
        if(curr > target) sip = min(sip,i);
    }
    return sip;
}

// Binary search 
int binarySearchInsertPos(vector<int>& nums,int target){
    int n = nums.size();

    int l = 0;
    int h = n-1;

    if(nums[n-1]<target) return n;
    if(nums[0]>target) return 0;

    int sip = -1;
    while (l<=h)
    {
        int mid = l + (h-l)/2;
        if(nums[mid] == target) return mid;
        else if(target<nums[mid]){
            h = mid-1;
            sip = mid;
        }else{
            l = mid+1;
        }
    }

    return sip;
    // TC = O(logN)
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

    cout << binarySearchInsertPos(nums,target);
    return 0;
}