#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Given an integer array arr of size N,
// sorted in ascending order (with distinct values) and a target value k.
// Now the array is rotated at some pivot point unknown to you.
// Find the index at which k is present and if k is not present return -1.

// Examples
// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
// Result: 4
// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
int searchRotatedLinearBrute(vector<int>& arr,int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==k) return i;
    }
    return -1;
}
int searchRotatedBSOptimal(vector<int>& arr,int k){// ensure which part is to be eleminated first
    int n=arr.size();
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==k) return mid;
        if(arr[low]<=arr[mid]){//LEFT SORTED
            if(arr[low]<=k&&k<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{ //right sorted
            if(arr[mid]<=k&&k<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

    } 
    return -1;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3}; int k = 0;
    cout<<"Array : ";printArray(arr);
    cout<<k<<" is Found at idx : "<<searchRotatedBSOptimal(arr,k)<<endl;
    return 0;
}