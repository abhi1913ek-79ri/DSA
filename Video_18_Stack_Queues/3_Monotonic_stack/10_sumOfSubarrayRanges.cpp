#include<bits/stdc++.h>
using namespace std;

// Brute Force : generate all subarray and compute range and then add to the answer
long long subArrayRanges_brute(vector<int>& nums){
    int n = nums.size();
    long long rangeSum = 0;

    for(int i = 0;i<n;i++){
        int mini = nums[i];
        int maxi = nums[i];

        for (int j = i; j < n; j++)
        {
            mini = min(mini,nums[j]);
            maxi = max(maxi,nums[j]);

            rangeSum += maxi-mini;
        }
    }
    return rangeSum;
    // TC = O(n*n)
    // SC = O(1)
}

// Optimal: PSE , NSE , PGE , NGE , maxSum , minSum , maxSum - minSum
// helper functions
// smaller
vector<int> NSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n,n);  // I am storing nse index not element remember
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i); 
    }
    return nse;
    // TC = O(n) + O(n)
    // SC = O(n) + O(n) - for nse
}

vector<int> PSE(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n,-1);  // I am storing pse index not element remember
    stack<int> st;
    for(int i=0;i<n;i++){
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i); 
    }
    return pse;
    // TC = O(n) + O(n)
    // SC = O(n) + O(n) - for pse
}

// Greater
vector<int> NGE(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n,n);  // I am storing nse index not element remember
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i); 
    }
    return nge;
    // TC = O(n) + O(n)
    // SC = O(n) + O(n) - for nse
}

vector<int> PGE(vector<int>& arr){
    int n = arr.size();
    vector<int> pge(n,-1);  // I am storing pse index not element remember
    stack<int> st;
    for(int i=0;i<n;i++){
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i); 
    }
    return pge;
    // TC = O(n) + O(n)
    // SC = O(n) + O(n) - for pse
}

// minSum 
long long minSumSubarray(vector<int>& arr){
    int n  =  arr.size();
    long long minSum = 0;
    vector<int> nse = NSE(arr);
    vector<int> pse = PSE(arr);
    for(int i =0;i<n;i++){
        int leftChoices = i-pse[i];
        int rightChoices = nse[i] - i;

        minSum+=(long long)arr[i]*leftChoices*rightChoices;
    }
    return minSum;
}

// maxSum 
long long maxSumSubarray(vector<int>& arr){
    int n  =  arr.size();
    long long maxSum = 0;
    vector<int> nge = NGE(arr);
    vector<int> pge = PGE(arr);
    for(int i =0;i<n;i++){
        int leftChoices = i-pge[i];
        int rightChoices = nge[i] - i;

        maxSum+=(long long)arr[i]*leftChoices*rightChoices;
    }
    return maxSum;
}

// main part 
long long subArrayRanges_optimal(vector<int>& nums){
    return  maxSumSubarray(nums)-minSumSubarray(nums);
    // TC = o(n+n+n+n+n+n) = O(6n) = O(n)
    // SC = O(4n) = O(n)
}



int main(){
    vector<int> nums  = {4,-2,-3,4,1};
    long long rS = subArrayRanges_optimal(nums);
    cout << " Range Sum  : " << rS <<endl;
    return 0;
}

// ✅ 1. Final Code Review

// ✔ Contribution formula correct
// ✔ Left / Right span correct
// ✔ Duplicate handling correct (>=, >, <=, <)
// ✔ Overflow handled (long long)
// ✔ Final subtraction correct

// 👉 Conclusion: ✔ Correct + Optimal