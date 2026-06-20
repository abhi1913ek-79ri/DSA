#include<bits/stdc++.h>
using namespace std;
// stock span 
// Input: n = 7, arr = [120, 100, 60, 80, 90, 110, 115]
// Output: [1, 1, 1, 2, 3, 5, 6]


// PGE
vector<int> PGE(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(),-1);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
    // TC = O(n+n)
    // SC = O(n+n)
}

vector<int> stockSpan(vector<int> arr, int n) {
    vector<int> ans;
    vector<int> pge = PGE(arr);
    for (int i = 0; i < n; i++)
    {
        ans.push_back(i-pge[i]);
    }
    return ans;
}

void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums) cout << num << " ";
    cout << "]\n";
}
int main(){
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    int n = 7;
    cout << "Arr         : ";
    printArray(arr);
    vector<int> stockSpanArray = stockSpan(arr,n);
    cout << "Stock span  : ";
    printArray(stockSpanArray);
    return 0;
}