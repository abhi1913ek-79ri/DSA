#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array of integers and an integer k,
//return the total number of subarrays whose sum equals k.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

int subArraySumKBrute1(vector<int>& arr,int k){
    // all subarray sum calculation
    int cnt=0;
    int n= arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++) sum+=arr[k];
            if(sum==k) cnt++;
        }
    }

    return cnt;
    // TC = O(n*n*n)
}
int subArraySumKBrute2(vector<int>& arr,int k){
    // all subarray sum calculation
    int cnt=0;
    int n= arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                cnt++;
            }
        }
        
    }
    return cnt;
    // TC = O(n*n)
}
int subArraySumKOptimal(vector<int>& arr,int k){
    int n=arr.size();int cnt=0;int prefixSum=0;
    unordered_map<int,int> mapp;
    mapp[0]=1; //important thing as prefix sum=0 is cnt = 1 for empty array
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        int remove=prefixSum-k;
        cnt+=mapp[remove];
        mapp[prefixSum]++;

    }
    return cnt;
}
void printArray(vector<int> & arr){
    for(auto num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr ={1,1,1};int k=2;
    cout<<"Array : ";printArray(arr);
    cout<<"Number of Sub Array with sum  = "<<k<<" : "<<subArraySumKOptimal(arr,k)<<endl;
    vector<int> arr2 ={1,2,3};int k2=3;
    cout<<"Array : ";printArray(arr2);
    cout<<"Number of Sub Array with sum  = "<<k2<<" : "<<subArraySumKOptimal(arr2,k2)<<endl;
    return 0;
}