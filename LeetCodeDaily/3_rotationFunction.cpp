#include<bits/stdc++.h>
using namespace std;
// TOIC : Array + Math + Contribution Analysis
// not a specific pattern

// helper sum function
int sum(deque<int> q){
    int currSum = 0;
    int i = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();
        currSum += i*curr;
        i++;
    }
    return currSum;
    // TC = O(n)
}
// Max Rotate Function
int maxRotateFunctionBrute(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    deque<int> q;
    int maxSum = 0;
    // insert all in q
    for (int i=0;i<n;i++)
    {
        q.push_back(nums[i]);
        maxSum += nums[i]*i;
    }

    // rotation
    for (int i = 1; i < n; i++)
    {
        int back = q.back();
        q.pop_back();
        q.push_front(back);
        int currSum = sum(q);
        maxSum = max(maxSum,currSum);
    }
    return maxSum;
    // TC = O(n^2)
    // SC = O(n)
}


int maxRotateFunctionOptimal(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int F = 0;
    int sumALL = 0;
    int maxSum = 0;
    // for first F(0)
    for (int i = 0; i < n; i++)
    {
        F += i*nums[i];
        sumALL += nums[i];
    }

    maxSum = F;

    // further F(K)  ke liye 
    for (int i = 1; i < n; i++)
    {
        F = F + sumALL - n*nums[n-i]; // reset last ele contribution -to  0 --  loss = n-1*x + x
        maxSum = max(maxSum,F);
    }
    
    
    return maxSum;
    // TC = O(n)
    // SC = O(1)
}

int main(){
    vector<int> nums1 = {4,3,2,6}; // 26
    vector<int> nums2 = {100}; // 0
    cout << "Max sum : " << maxRotateFunctionBrute(nums1) << endl;
    cout << "Max sum : " << maxRotateFunctionBrute(nums2) << endl;
    cout << "Max sum : " << maxRotateFunctionOptimal(nums1) << endl;
    cout << "Max sum : " << maxRotateFunctionOptimal(nums2) << endl;

    return 0;
}




// Intituion
// F(k)=∑i⋅nums[i]
// 🧠 Step 3: Contribution samajh
// 👉 Sab elements ka effect:
// Agar sabka index +1 hua:
// Total increase = sum of all elements
//📌 General Form
// F(k)=F(k−1)+sum−n⋅nums[n−k]


// Last element ke saath 2 cheeze hui:

// ✅ (1) Addition part
// + x   (because sabka index +1 hua)
// ❌ (2) Reset part
// - (n-1) * x
// 🔥 Net effect (combine both)
// +x  - (n-1)x  =  -nx