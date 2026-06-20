#include<bits/stdc++.h>
using namespace std;
// Next Smaller Element
vector<int> nse_brute(vector<int>& nums){
    vector<int> ans(nums.size(),-1);
    for(int i=0 ; i<nums.size();i++){
        for(int j = i+1;j<nums.size();j++){
            if(nums[j]<nums[i]){
                ans[i]=nums[j];
                break;
            }
        }
    }
    return ans;
    // TC = O(N*N)
    // SC = O(n)
}


vector<int> nse_optimal(vector<int>& nums){
    // Idea monotonic stack + backtraversal

    stack<int> st;
    vector<int> ans(nums.size(),-1);

    for(int i=nums.size()-1;i>=0;i--){
        while (!st.empty() && st.top() >= nums[i])
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
    vector<int> nums = {1, 3, 2, 4};
    vector<int> nSE = nse_optimal(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "nse = ";
    printArray(nSE);
    return 0;
}
