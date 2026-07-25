#include<bits/stdc++.h>
using namespace std;
// in-place 
// remove all occurrences of val
// not to remove just pull its out of range
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();

    int i = 0;
    int j = 0;

    while (j < n)
    {
        if(nums[j] != val){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
    return  i;
    // TC = O(n)
    // SC = O(1)
}
int main(){
    int n ;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    int val;
    cin >> val;

    int k = removeElement(nums,val);
    bool flag = false;
    for(int i=0;i<k;i++){
        if(flag) cout << " ";
        cout << nums[i];
        flag = true;
    }
    
    return 0;
}