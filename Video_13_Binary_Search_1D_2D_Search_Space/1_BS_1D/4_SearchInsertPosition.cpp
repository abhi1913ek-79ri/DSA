#include<bits/stdc++.h>
using namespace std;
// Problem Statement: You are given a sorted array arr of distinct values and a target value x. 
// You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise,
//  determine the index where it would be inserted in the array while maintaining the sorted order.

// Pre-requisite: Lower Bound & Binary Search

// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will 
// insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// Example 2:
// Input Format: arr[] = {1,2,4,7}, x = 2
// Result: 1
// Explanation: 2 is present in the array
//  and so we will return its index i.e. 1.


//------------------------INTUTION JUST RETURN LOWER_BOUND------------------------------------

int searchInsertPosition(vector<int>& arr,int target){
    return (lower_bound(arr.begin(),arr.end(),target)-arr.begin());
}
void printArray(vector<int> arr){for(auto num: arr)cout<<num<<" ";cout<<endl;}

int main(){
    vector<int> arr={1,2,4,7};
    int target=6;
    int ans=searchInsertPosition(arr,target);
    cout<<"Array : ";printArray(arr);
    cout<<"ans idx  : "<<ans<<endl;
    return 0;
}