#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'
//   denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. 
// You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

// Examples
// Example 1:
// Input Format:
//  N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result:
//  12

bool isPossible(vector<int>& arr,int days,int m,int k){
    int n = arr.size();
    int buckets = 0;
    int flower=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=days){
            flower++;
            if (flower == k) { // If we have k adjacent bloomed flowers
                buckets++;
                flower = 0; // Reset for next bouquet
                if (buckets >= m) return true; // ✅ Early exit
            }
        }else{
            flower=0;
        }
    }
    return false; 
}
int minDaysMBucketBrute(vector<int>& arr,int m,int k){
    //Linear search
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    for(int i=low;i<=high;i++){
        if(isPossible(arr,i,m,k)==true) return i;
    }
    return -1;
}
int minDaysMBucketOptimal(vector<int>& arr,int m,int k){
    //binary search on search space
    if (1LL*m * k > arr.size()) return -1; // Not enough roses to make m bouquets
    int ans=-1;
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    while(low<=high){
        int mid=low+(high-low)/2;
        bool check=isPossible(arr,mid,m,k);
        if(check==true){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
void printArray(vector<int>& arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    cout<<"Array : ";printArray(arr);
    cout<<"Min Buckets : "<<m<<", Roses : "<<k<<endl;
    cout <<"Min Brute days to make "<<m<<" buckets is : "<<minDaysMBucketBrute(arr, m, k) << endl; // Output: 12
    cout <<"Min Optimal days to make "<<m<<" buckets is : "<<minDaysMBucketOptimal(arr, m, k) << endl; // Output: 12

    return 0;
}