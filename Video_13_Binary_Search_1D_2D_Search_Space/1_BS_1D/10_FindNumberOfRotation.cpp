#include<bits/stdc++.h>
using namespace std;
//Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

// Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

// Examples
// Example 1:
// Input Format:
//  arr = [4,5,6,7,0,1,2,3]
// Result:
//  4
int NumberofRotation(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n - 1;
    int mini=INT_MAX;
    int ans=-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[low]<=arr[high]){
            if(arr[low]<=mini){
                mini=arr[low];
                ans=low;
                break;
            }
        }

        if(arr[low]<=arr[mid]){//left sorted
            if(arr[low]<mini){
                mini=arr[low];
                ans=low;
            }
            low=mid+1;
        }else{ //right sorted
            if(arr[mid]<mini){
                mini=arr[mid];
                ans=mid;
            }
            high=mid-1;
        }
    }
    return ans;
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};  // Rotated 4 times
    cout<<"Array : ";printArray(arr);
    cout << "Number of rotations: " << NumberofRotation(arr) << endl;
    return 0;
}