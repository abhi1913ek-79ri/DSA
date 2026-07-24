#include<bits/stdc++.h>
using namespace std;
// Remove duplicates
int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
    return 0;
    int n = nums.size();
    int i = 1; // valid position
    int j = 1; // explore for valid elemenets need to swap
    while (j<n)
    {
        if(nums[j]!=nums[i-1]){ // valid element condition
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }

    return i;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    int k = removeDuplicates(nums);
    bool flag = false;
    for(int i = 0;i < k ; i++){
        if(flag) cout << " ";
        cout << nums[i];
        flag = true;
    }
    return 0;
}