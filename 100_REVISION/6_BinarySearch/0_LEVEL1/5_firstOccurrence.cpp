#include<bits/stdc++.h>
using namespace std;
// first occurrence
int firstOccurrence(vector<int>& nums,int target){
    int n = nums.size();

    int idx = -1;

    int l = 0;
    int h = n-1;

    while (l<=h)
    {
        int mid = l + (h-l)/2;
        if(target == nums[mid]){
            idx = mid;
            h=mid-1;
        }else if(target < nums[mid]){
            h = mid-1;
        }else{
            l = mid + 1;
        }
    }

    return idx;
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

    cout << firstOccurrence(nums,target);
    return 0;
}