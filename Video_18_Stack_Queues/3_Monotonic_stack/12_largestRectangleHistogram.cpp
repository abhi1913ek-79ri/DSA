#include<bits/stdc++.h>
using namespace std;
// Largest Rectangle possible in  histogram
// for every bar of histogram find max area that can be formed by including this bar
// like min subarary
// pse , nse 

vector<int> NSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
    // TC = O(n)
    // SC = O(n)
}

vector<int> PSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while (!st.empty() && arr[st.top()] >= arr[i]) // yad rahe stack me and ans me index use ho rahe hain na ki element
        { // arr[st.top()] >= arr[i] & arr[st.top()] > arr[i]  - ye bhi kar skte hain kyunki yahan max fund karna hian na ki sum wagera ki do bar add ho  jayega
            st.pop();
        }
        ans[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
    // TC = O(n)
    // SC = O(n)
}

int largestRectangleArea_brute(vector<int>& heights){
    int n = heights.size();
    vector<int> pse = PSE(heights);
    vector<int> nse = NSE(heights);

    int maxAreaArray = 0;

    for(int i=0;i<n;i++){
        int width = nse[i]-pse[i]-1;
        int maxAreaElement = heights[i]*width;
        maxAreaArray = max(maxAreaArray,maxAreaElement);
    }

    return maxAreaArray;
    // TC =- O(3n)
    // SC =- O(2n)
}

// 

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Max area of reactangle in histogram : " << largestRectangleArea(heights) << endl;
    return 0;
}