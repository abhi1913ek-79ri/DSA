#include<bits/stdc++.h>
using namespace std;
// LC - 2333. Minimum Sum of Squared Difference
long long solve_brute(vector<int>& nums1, vector<int>& nums2, int k1, int k2){
    // max heap 
    int n = nums1.size();
    int K = k1+k2;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(abs(nums1[i]-nums2[i]));
    }
    
    while (K>0 && !pq.empty())
    {
        int largestDiff = pq.top();
        pq.pop();
        if(largestDiff== 0) break;
        largestDiff--;
        K--;

        pq.push(largestDiff);
    }

    long long result = 0;
    while (!pq.empty())
    {
        long long d = pq.top();
        pq.pop();
        result += d*d;
    }
    
    return result;
    // klogn = TLE
}


// APPROACH 2- OPTIMAL
// USING DIFF -> COUNT
long long solve_optimal(vector<int>& nums1, vector<int>& nums2, int k1, int k2){
    int n = nums1.size();

    int K = k1+k2;
    vector<int> diff(1e5+1,0);

    for(int i=0;i<n;i++){
        int d = abs(nums1[i]-nums2[i]);
        diff[d]++;
    }

    for(int i=1e5;i>0 && K>0 ;i--){
        int countOp = min(K,diff[i]);

        diff[i] -= countOp;
        diff[i-1] += countOp;
        K -= countOp;
    }

    long long result = 0;
    for(long long d = 1;d<=1e5;d++){
        result += diff[d]*d*d;
    }
    return result;
}

int main(){
    int n1;
    cin >> n1;
    vector<int> nums1(n1);
    for(auto& num:nums1){
        cin >> num;
    }

    int n2;
    cin >> n2;
    vector<int> nums2(n2);
    for(auto& num:nums2){
        cin >> num;
    }

    int k1;
    cin >> k1;
    
    int k2;
    cin >> k2;

    cout << solve_optimal(nums1,nums2,k1,k2);
    return 0;
}