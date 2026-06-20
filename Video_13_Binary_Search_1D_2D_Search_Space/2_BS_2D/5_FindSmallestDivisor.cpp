#include<bits/stdc++.h>
using namespace std;
//Problem Statement: You are given an array of integers 'arr' and an integer i.e. 
//a threshold value 'limit'. Your task is to find the smallest positive integer divisor,
// such that upon dividing all the elements of the given array by it, the sum of the division's
// result is less than or equal to the given threshold value.

// Examples
// Example 1:
// Input Format:
//  N = 5, arr[] = {1,2,3,4,5}, limit = 8
// Result:
//  3

bool isPossible(vector<int>& arr,int divisor,int limit){
    long long sum=0;
    for(auto num:arr){
        sum += (num + divisor - 1) / divisor;
    }
    if(sum<=limit) return true;
    return false;
}

int findSmallestDivisorBrute(vector<int>& arr,int limit){
    // search space -- optimisation of divisor
    int ans=-1;
    int high=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=high;i++){
        if(isPossible(arr,i,limit)){
            return i; //smallest divisor
        }
    }
    return ans;
}

int findSmallestDivisorOptimal(vector<int>& arr,int limit){
    // search space -- optimisation of divisor
    int low = 1;
    int ans=-1;
    int high=*max_element(arr.begin(),arr.end());
    while (low<=high){
        int mid = low+ (high-low)/2;
        
        if(isPossible(arr,mid,limit)){
            ans = mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
void printArray(vector<int>& arr){for(auto num : arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr = {1,2,3,4,5}; int limit = 8;
    cout<<"Array : ";printArray(arr);
    cout<<"Min divisor Brute : "<<findSmallestDivisorBrute(arr,limit)<<endl;
    cout<<"Min divisor Optimal : "<<findSmallestDivisorOptimal(arr,limit)<<endl;

    
    return 0;
}