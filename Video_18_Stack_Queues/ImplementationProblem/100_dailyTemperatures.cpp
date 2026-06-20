#include<bits/stdc++.h>
using namespace std;
// daily temperatures
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// NGE
vector<int> NGE(vector<int>& arr){
    int n= arr.size();
    stack<int> st;
    vector<int> ans(arr.size(),n);
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return ans;
    // TC = O(n+n)
    // SC = O(n+n)
}

vector<int> dailyTemperatures(vector<int> arr, int n) {
    vector<int> ans;
    vector<int> nge = NGE(arr);
    for (int i = 0; i < n; i++)
    {
        if(nge[i] == n) ans.push_back(0);   // fix
        else ans.push_back(nge[i] - i);
    }
    return ans;
}

void printArray(vector<int>& nums){
    cout << "[";
    for(auto num : nums) cout << num << " ";
    cout << "]\n";
}
int main(){
    vector<int> arr = {73,74,75,71,69,72,76,73};
    int n = arr.size();
    cout << "Arr         : ";
    printArray(arr);
    vector<int> dailTempArr = dailyTemperatures(arr,n);
    cout << "Daily Temp  : ";
    printArray(dailTempArr);
    return 0;
}