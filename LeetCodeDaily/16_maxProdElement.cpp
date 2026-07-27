#include<bits/stdc++.h>
using namespace std;
// 1464. Maximum Product of Two Elements in an Array

// Brute : nested loop
int maxProduct1(vector<int>& nums) {
    int n = nums.size();
    int maxi = -1;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            maxi = max(maxi,(nums[i]-1)*(nums[j]-1));
        }
    }

    return maxi;
    // TC = O(n^2)
    // SC = O(1)
}

// Better : Heap , without array manipulation
int maxProduct2(vector<int>& nums) {
    int n = nums.size();

    priority_queue<int> pq;

    for(auto& num : nums){
        pq.push(num);
    }

    int l1 = pq.top();
    pq.pop();
    int l2 = pq.top();

    return (l1-1)*(l2-1);
    // TC = O(nlogn)
    // SC = O(n)
}

// Better : sorting , array manipulation
int maxProduct3(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(),nums.end());

    int l1 = nums[n-1];
    int l2 = nums[n-2];

    return (l1-1)*(l2-1);
    // TC = O(nlogn)
    // SC = O(1)
}

// Optimal : find first , second largest
int maxProduct4(vector<int>& nums){
    int n = nums.size();

    int first = 0;
    int second = 0;

    for(auto& num : nums){
        if(num > first){
            second = first; // ye pahle ayega yaaad rakhna 
            first = num;
        }else if(num > second){
            second = num;
        }
    }

    return (first-1)*(second-1);
    // TC = O(n)
    // SC = O(1)
}



int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    cout << maxProduct4(nums);
    return 0;
}