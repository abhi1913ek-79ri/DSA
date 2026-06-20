#include<bits/stdc++.h>
using namespace std;
// nge - II\
// Next Greater Element II - circularArray // twice array and modulo approach
// 🧠 Intuition (Gold Level)
// 👉 first pass:
// future elements stack me bhar lo
// 👉 second pass:
// actual answer calculate karo

vector<int> ngeII(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--){
        int curr = nums[i%n];
        while (!st.empty() && st.top() <= curr){
            st.pop();
        }

        if(i<n){
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(curr);
        
    }

    return ans;
    // TC = O(2n)
    // SC = O(n)

}



// printArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num:nums) cout << num << " ";
    cout << "]\n";
}


int main(){
    vector<int> nums = {1,2,1};
    vector<int> nGE = ngeII(nums);
    cout << "nums = ";
    printArray(nums);
    cout << "nge = ";
    printArray(nGE);
    return 0;
}