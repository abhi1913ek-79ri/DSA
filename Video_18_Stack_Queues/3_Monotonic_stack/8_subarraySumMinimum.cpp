#include<bits/stdc++.h>
using namespace std;
// Subarray sum minimum 

// brute
int sumSubarrayMins_brute(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    int mod = 1e9+7;
    for (int i = 0; i < n; i++)
    {
        int minii = arr[i];
        for (int j = i; j < n; j++)
        {
            minii = min(minii,arr[j]);
            sum  = (sum+minii)%mod;
        }   
    }
    return sum;
}

// optimal PSE , NSE
// count that arr[i] partcipate as minnimum in that number of subarrays
// 👉 LEFT = kitne start bana sakta hai -- left choices
// 👉 RIGHT = kitne end bana sakta hai -- right choices
// 👉 start × end = total subarrays -- total possible outcomes
// arr  =  3  1  2  4: now take -> 1  kitne arrays ke liye minimum act karega 
// 2*3 = 6 arrays ke liye 1 minimum ki tarah act karega 6*1  add kardo sum  me

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

// ❌ Problem (Duplicate handling galat hai)
// Tera PSE code:
// while (!st.empty() && arr[st.top()] >= arr[i])
// 👉 Ye galat hai ❌
// ⚠️ Kyun galat?
// Agar array me duplicates aaye (jaise [2,2,2]),
// to dono side same condition use karne se double counting ho jayegi 😵
// ✅ Correct Rule (VERY IMPORTANT)
// Side	Condition
// PSE	>
// NSE	>=

int sumSubarrayMins_optimal(vector<int>& arr){
    int sum = 0;
    int n = arr.size();
    vector<int> nse = NSE(arr);
    vector<int> pse = PSE(arr);
    int mod = 1e9+7;

    for(int i=0;i<n;i++){
        int leftChoices = i - pse[i];
        int rightChoices = nse[i]-i;
        sum = (sum + (long long)arr[i]*leftChoices*rightChoices)%mod;
    }
    return sum;
}

int main(){
    vector<int> arr = {3,1,2,4};
    cout << "Minimums sum : " << sumSubarrayMins_optimal(arr);
    return 0;
}

//let no. of elements in subarray from :  left = a and right = b

// no. of subarrays that contain min element = (no. of subarrays from left side elements = a) +  (no. of subarrays from right side elements = b) - (no. of the element itself  = 1) + ( { no. of elements from left side excluding the element = a-1) * (no. of elements from right side excluding the element = b-1) } 

// = (a+b-1)*{(a-1)*(b-1)} = a*b         [ expand yourself , u will get the intuition of the proof   ]