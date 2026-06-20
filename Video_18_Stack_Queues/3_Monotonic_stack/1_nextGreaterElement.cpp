#include<bits/stdc++.h>
using namespace std;
// Next Greater Element : striver Question
// LeetCode Question is a bit different : nge + map for element of nums2 ele -> nge  give answer accpording to ele in nums1
vector<int> nge_brute(vector<int>& nums){
    vector<int> ans(nums.size(),INT_MIN);
    for(int i=0 ; i<nums.size();i++){
        for(int j = i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                ans[i]=nums[j];
                break;
            }
        }
        if(ans[i]==INT_MIN) ans[i]=-1;
    }
    return ans;
    // TC = O(N*N)
    // SC = O(n)
}


vector<int> nge_optimal(vector<int>& nums){
    // Idea monotonic stack + backtraversal

    stack<int> st;
    vector<int> ans(nums.size(),0);

    for(int i=nums.size()-1;i>=0;i--){
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }

        st.push(nums[i]);
    }
    return ans;
    // TC = O(2n)
    // SC = O(n) + O(n){for answer}
}

// printArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num:nums) cout << num << " ";
    cout << "]\n";
}

int main(){
    vector<int> nums = {1, 3, 2, 4}; // [3, 4, 4, -1]
    vector<int> nGE = nge_brute(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "nge = ";
    printArray(nGE);
    return 0;
}
