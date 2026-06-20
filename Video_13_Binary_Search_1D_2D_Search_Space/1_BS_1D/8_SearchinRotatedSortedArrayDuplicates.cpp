#include<bits/stdc++.h>
using namespace std;
//Search Element in Rotated Sorted Array II
// 1
// Problem Statement: Given an integer array arr of size N, sorted in ascending 
// order (may contain duplicate values) and a target value k. Now the array is
//  rotated at some pivot point unknown to you.
//  Return True if k is present and otherwise, return False. 
// Pre-requisite: Search Element in Rotated Sorted Array I & Binary Search algorithm

// Examples
// Example 1:
// Input Format:
//  arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result:
//  True
// Explanation:
//  The element 3 is present in the array. So, the answer is True.
bool searchRotatedBSOptimal(vector<int>& arr,int k){// ensure which part is to be eleminated first
    int n=arr.size();
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==k) return true;
        if(arr[low]==arr[mid]&&arr[mid]==arr[high]){//this is need to be solved for duplicity
            low++;
            high--;
            continue;
        }
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
    return false;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}
int main(){
    vector<int> arr={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k=3;bool ans=searchRotatedBSOptimal(arr,k);
    cout<<"Array : ";printArray(arr);
    cout<<"k = "<<k<<" is "<<(ans==1?"Found.":"Not Found.")<<endl;
    return 0;
}